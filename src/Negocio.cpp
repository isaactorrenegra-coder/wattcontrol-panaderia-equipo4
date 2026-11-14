#include "Negocio.h"
#include "Reporte.h"
#include <iostream>

// Constructor de la clase Negocio (inicializa nombre, mercado y valores por defecto)
Negocio::Negocio(const std::string& nombre, Mercado* mercado) 
    : nombre_(nombre), numeroCargas_(0), mercado_(mercado), horasSimuladas_(0), fallasLectura_(0), emergencia_(false), tieneSimulacion_(false) {
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

// Método para evaluar las cargas según la hora, precio y embalses
void Negocio::evaluarCargas(int hora, double precio, double embalses) {
    for (int i = 0; i < numeroCargas_; ++i) {
        if (cargas_[i] != nullptr) {
            // 1. Preguntamos a la carga si debe encenderse según la hora, el precio y los embalses
            bool encender = cargas_[i]->debeEncender(hora, precio, embalses);
            
            // 2. Aplicamos ese estado real en la carga
            cargas_[i]->fijarEncendida(encender);
        }
    }
}

// Método principal que ejecuta la simulación de las 24 horas del día
void Negocio::simularDia() {
    // 1. Inicializamos el contador de horas simuladas a 24
    horasSimuladas_ = 24;
    tieneSimulacion_ = true;
    
    // 2. Limpiamos cualquier acumulador previo en el medidor antes de empezar el día
    medidor_.reiniciar();

    std::cout << "\n[SIMULACION] Iniciando ciclo de 24 horas para: " << nombre_ << "..." << std::endl;

    // 3. Bucle que recorre cada hora del día (desde la hora 0 hasta la hora 23)
    for (int hora = 0; hora < 24; ++hora) {
        // A. Consultamos al Mercado el precio de la energía y el nivel de los embalses en esta hora específica
        double precioActual = mercado_->precioHora(hora);
        double embalsesActual = mercado_->nivelEmbalses();

        // B. Evaluamos el estado de las cargas según las reglas de negocio, el costo de la hora y el agua
        evaluarCargas(hora, precioActual, embalsesActual);

        // C. Registramos el consumo energético de esta hora exacta en el medidor
        registrarConsumoHora(precioActual);
    }

    std::cout << "[SIMULACION] ¡Simulacion de 24 horas completada con exito!" << std::endl;

    // 4. Al finalizar las 24 horas, invocamos el reporte de consumo con los totales del medidor
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
        }
    }

    // Enviamos la potencia total y el precio actual al medidor para que actualice kWh y costos
    medidor_.registrarHora(potenciaTotalHoraKWh, precioCOPKWh);
}

// Método para mostrar el resumen de la última simulación
void Negocio::mostrarResumen() const {
    std::cout << "\n========================================\n";
    std::cout << "   C03: RESUMEN DE CONSUMO Y AHORRO     \n";
    std::cout << "========================================\n";
    
    double totalKWh = medidor_.energiaTotalKWh();
    double costoCOP = medidor_.costoTotalCOP();
    generarReporteConsumo(totalKWh, costoCOP);

    std::cout << " Negocio: Panaderia\n";
    std::cout << " Energia total consumida : " << totalKWh << " kWh\n";
    std::cout << " Costo total estimado    : $" << costoCOP << " COP\n";
    std::cout << " Estado de optimizacion  : Completado\n";
    std::cout << "========================================\n";
}