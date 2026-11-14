#include "Negocio.h"
#include "Reporte.h"
#include <iomanip>
#include <iostream>

// Constructor de la clase Negocio (inicializa nombre, mercado y valores por defecto)
Negocio::Negocio(const std::string& nombre, Mercado* mercado)
    : nombre_(nombre), numeroCargas_(0), mercado_(mercado),
      horasSimuladas_(0), fallasLectura_(0), emergencia_(false),
      tieneSimulacion_(false) {
    // Inicializa el arreglo de cargas en nullptr
    for (int i = 0; i < MAX_CARGAS; ++i) {
        cargas_[i] = nullptr;
    }
}

// Método para agregar cargas al negocio (necesario para el main)
bool Negocio::agregarCarga(Carga* carga) {
    if (numeroCargas_ < MAX_CARGAS && carga != nullptr) {
        cargas_[numeroCargas_++] = carga;
        return true;  // Retorna verdadero si se agregó con éxito
    }
    return false;     // Retorna falso si el arreglo está lleno o la carga es nula
}

// Método para evaluar las cargas según la hora, precio y embalses.
void Negocio::evaluarCargas(int hora, double precio, double embalses) {
    const bool riesgoEmbalses = embalses < config::EMBALSE_ALERTA_PCT;

    if (riesgoEmbalses) {
        std::cout << "[ALERTA] Riesgo: embalses por debajo de "
                  << config::EMBALSE_ALERTA_PCT
                  << "%. Solo se mantendran las cargas no aplazables.\n";
    }

    // Esta es la unica consulta de decision: cada carga responde de forma
    // polimorfica y Negocio aplica despues las reglas generales del negocio.
    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr) {
            bool encender = cargas_[i]->debeEncender(hora, precio, embalses);
            if (riesgoEmbalses && cargas_[i]->esAplazable()) {
                encender = false;
            }
            cargas_[i]->fijarEncendida(encender);
        }
    }

    double potenciaTotalKW = 0.0;
    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr && cargas_[i]->encendida()) {
            potenciaTotalKW += cargas_[i]->potenciaKW();
        }
    }

    if (potenciaTotalKW > config::POTENCIA_CONTRATADA_KW) {
        int indiceMayor = -1;
        double mayorPotenciaKW = 0.0;

        for (int i = 0; i < numeroCargas_; ++i) {
            if (cargas_[i] != nullptr && cargas_[i]->encendida()
                && cargas_[i]->potenciaKW() > mayorPotenciaKW) {
                indiceMayor = i;
                mayorPotenciaKW = cargas_[i]->potenciaKW();
            }
        }

        if (indiceMayor >= 0) {
            std::cout << "[ALERTA] Potencia solicitada: " << potenciaTotalKW
                      << " kW. Supera los "
                      << config::POTENCIA_CONTRATADA_KW
                      << " kW contratados.\n";
            cargas_[indiceMayor]->fijarEncendida(false);
            potenciaTotalKW -= mayorPotenciaKW;
            std::cout << "[CONTROL] Se apaga " << cargas_[indiceMayor]->nombre()
                      << " (" << mayorPotenciaKW << " kW). Potencia restante: "
                      << potenciaTotalKW << " kW.\n";
        }
    }

    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr) {
            std::cout << "[DECISION] " << cargas_[i]->nombre() << ": "
                      << (cargas_[i]->encendida() ? "encendida" : "aplazada")
                      << ".\n";
        }
    }
}

// Método principal que ejecuta la simulación de las 24 horas del día
void Negocio::simularDia() {
    if (mercado_ == nullptr) {
        std::cout << "[ERROR] No se puede simular: el mercado no esta disponible.\n";
        return;
    }

    horasSimuladas_ = 0;
    fallasLectura_ = 0;
    emergencia_ = false;
    costoSinGestorCOP_ = 0.0;
    tieneSimulacion_ = true;
    medidor_.reiniciar();
    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr) {
            cargas_[i]->reiniciar();
        }
    }

    std::cout << "\n[SIMULACION] Iniciando ciclo de 24 horas para: " << nombre_ << "...\n";

    for (int hora = 0; hora < HORAS_DIA; ++hora) {
        double precioActual = mercado_->precioHora(hora);
        double embalsesActual = mercado_->nivelEmbalses();

        if (precioActual > config::PRECIO_EMERGENCIA_COP_KWH
            && embalsesActual < config::EMBALSE_ALERTA_PCT) {
            emergencia_ = true;
            std::cout << "[EMERGENCIA] Precio de " << precioActual
                      << " COP/kWh con embalses en " << embalsesActual
                      << "%. La simulacion se detiene antes de contabilizar esta hora.\n";
            break;
        }

        const bool fallaLectura = (std::rand() % config::FALLA_LECTURA_CADA) == 0;
        if (fallaLectura) {
            ++fallasLectura_;
            std::cout << "[FALLA] Lectura no disponible en la hora " << hora
                      << ". Se mantiene solo la carga critica.\n";
        }

        evaluarCargas(hora, precioActual, embalsesActual);
        if (fallaLectura) {
            for (int i = 0; i < numeroCargas_; ++i) {
                if (cargas_[i] != nullptr && cargas_[i]->esAplazable()) {
                    cargas_[i]->fijarEncendida(false);
                }
            }
        }

        double potenciaSinGestorKW = 0.0;
        for (int i = 0; i < numeroCargas_; ++i) {
            if (cargas_[i] != nullptr && (!fallaLectura || !cargas_[i]->esAplazable())) {
                potenciaSinGestorKW += cargas_[i]->potenciaKW();
            }
        }
        costoSinGestorCOP_ += potenciaSinGestorKW * precioActual;
        registrarConsumoHora(precioActual);
        ++horasSimuladas_;
    }

    std::cout << "[SIMULACION] Horas procesadas: " << horasSimuladas_ << " de "
              << HORAS_DIA << ".\n";
    if (emergencia_) {
        std::cout << "[SIMULACION] Finalizada anticipadamente por emergencia.\n";
    } else {
        std::cout << "[SIMULACION] Simulacion de 24 horas completada con exito.\n";
    }

    generarReporteConsumo(medidor_.energiaTotalKWh(), medidor_.costoTotalCOP());
}

// Método para calcular y registrar el consumo de una hora dada en el medidor
void Negocio::registrarConsumoHora(double precioCOPKWh) {
    double potenciaTotalHoraKWh = 0.0;

    // Recorremos todas las cargas agregadas al negocio
    for (int i = 0; i < numeroCargas_; ++i) {
        // Verificamos que la carga exista y que se encuentre encendida en esta hora
        if (cargas_[i] != nullptr && cargas_[i]->encendida()) {
            potenciaTotalHoraKWh += cargas_[i]->potenciaKW();
            cargas_[i]->registrarHora();
        }
    }

    // Enviamos la potencia total y el precio actual al medidor para que
    // actualice energia y costo.
    medidor_.registrarHora(potenciaTotalHoraKWh, precioCOPKWh);
}

// Método para mostrar el resumen de la última simulación
void Negocio::mostrarResumen() const {
    std::cout << "\n========================================\n";
    std::cout << "   C03: RESUMEN DE CONSUMO Y AHORRO     \n";
    std::cout << "========================================\n";
    
    if (!tieneSimulacion_) {
        std::cout << "No hay una simulacion disponible. Ejecute primero la opcion 3.\n";
        return;
    }

    const double totalKWh = medidor_.energiaTotalKWh();
    const double costoCOP = medidor_.costoTotalCOP();
    generarReporteConsumo(totalKWh, costoCOP);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << " Negocio: " << nombre_ << "\n";
    std::cout << " Horas procesadas        : " << horasSimuladas_ << "\n";
    std::cout << " Fallas de lectura       : " << fallasLectura_ << "\n";
    std::cout << " Costo sin gestor        : $" << costoSinGestorCOP_ << " COP\n";
    std::cout << " Costo con gestor        : $" << costoCOP << " COP\n";
    std::cout << " Ahorro                  : $" << ahorroCOP() << " COP\n";
    std::cout << " Estado                  : "
              << (emergencia_ ? "Detenida por emergencia" : "Completada") << "\n";
    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr) {
            int horasMinimas = 0;
            if (cargas_[i]->nombre() == "Horno electrico") {
                horasMinimas = config::HORAS_MIN_HORNO;
            } else if (cargas_[i]->nombre() == "Amasadora") {
                horasMinimas = config::HORAS_MIN_AMASADORA;
            }
            std::cout << " " << cargas_[i]->nombre() << ": "
                      << cargas_[i]->horasUso() << " h, "
                      << cargas_[i]->energiaKWh() << " kWh";
            if (horasMinimas > 0) {
                std::cout << " (minimo " << horasMinimas << " h: "
                          << (cargas_[i]->horasUso() >= horasMinimas
                                  ? "cumplido" : "produccion incompleta")
                          << ")";
            }
            std::cout << "\n";
        }
    }
    std::cout << "========================================\n";
}