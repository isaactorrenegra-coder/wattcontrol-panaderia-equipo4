#include <iostream>
#include <limits>
#include <cstdlib>
#include "configuracion.h"
#include "CargaCritica.h"
#include "CargaAplazable.h"
#include "Negocio.h"
#include "Mercado.h"
#include "Medidor.h"
#include "Reporte.h"

int main() {
    std::srand(SEMILLA_SIMULACION);
    Mercado mercado;
    CargaCritica nevera("Nevera de insumos", config::POTENCIA_NEVERA_KW);
    CargaAplazable horno("Horno electrico", config::POTENCIA_HORNO_KW);
    CargaAplazable amasadora("Amasadora", config::POTENCIA_AMASADORA_KW);
    Negocio panaderia("Panaderia", &mercado);
    panaderia.agregarCarga(&nevera);
    panaderia.agregarCarga(&horno);
    panaderia.agregarCarga(&amasadora);

    int opcion = -1;
    int horaManual = 0;
    double precioManual = 600.0;
    double embalsesManual = mercado.nivelEmbalses();
    do {
        std::cout << "\n===== WATTCONTROL PANADERIA (PLANTILLA EA2) =====\n"
                  << "1. Ingresar lectura manual\n"
                  << "2. Evaluar decision de cada carga\n"
                  << "3. Simular un dia completo\n"
                  << "4. Ver resumen de la ultima simulacion\n"
                  << "0. Salir\nOpcion: ";
        if (!(std::cin >> opcion)) {
            if (std::cin.eof()) {
                return 0;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        }
        switch (opcion) {
        case 1: {
            // ==========================================
            // C01: COMPLETAR EL MENÚ Y VALIDAR LAS ENTRADAS
            // ==========================================
            std::cout << "\n--- INGRESO DE LECTURA MANUAL ---\n";
            
            // 1. Validar Hora (0 a 23)
            do {
                std::cout << "Ingrese la hora (0 - 23): ";
                if (!(std::cin >> horaManual)) {
                    std::cout << "[Error] Entrada no valida. Ingrese un numero entero.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    horaManual = -1;
                } else if (horaManual < 0 || horaManual > 23) {
                    std::cout << "[Error] La hora debe estar entre 0 y 23.\n";
                }
            } while (horaManual < 0 || horaManual > 23);

            // 2. Validar Precio (> 0)
            do {
                std::cout << "Ingrese el precio del kilovatio (> 0): ";
                if (!(std::cin >> precioManual)) {
                    std::cout << "[Error] Entrada no valida. Ingrese un valor numerico.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    precioManual = -1.0;
                } else if (precioManual <= 0) {
                    std::cout << "[Error] El precio debe ser mayor a 0.\n";
                }
            } while (precioManual <= 0);

            // 3. Validar Embalses (0 a 100)
            do {
                std::cout << "Ingrese el nivel de embalses (0 - 100 %): ";
                if (!(std::cin >> embalsesManual)) {
                    std::cout << "[Error] Entrada no valida. Ingrese un valor numerico.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    embalsesManual = -1.0;
                } else if (embalsesManual < 0 || embalsesManual > 100) {
                    std::cout << "[Error] El nivel de embalses debe estar entre 0 y 100.\n";
                }
            } while (embalsesManual < 0 || embalsesManual > 100);

            // Actualizar el nivel de embalses usando el método de la clase Mercado
            mercado.actualizarNivelEmbalses(embalsesManual);
            
            std::cout << "[Exito] Lectura manual registrada y validada correctamente.\n";
            break;
        }
        case 2:
            panaderia.evaluarCargas(horaManual, precioManual, embalsesManual);
            break;
        case 3:
            panaderia.simularDia();
            break;
        case 4:
            panaderia.mostrarResumen();
            break;
        case 0:
            std::cout << "Hasta luego.\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
            break;
        }
    } while (opcion != 0);
    return 0;
}
