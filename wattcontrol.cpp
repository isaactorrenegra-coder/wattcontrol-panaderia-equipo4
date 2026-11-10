#include <iostream>
#include <limits>
#include <cstdlib>
#include "configuracion.h"
#include "CargaCritica.h"
#include "CargaAplazable.h"
#include "Negocio.h"
#include "Mercado.h"
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
        case 1:
            // TODO C01: leer hora 0..23, precio >0 y embalses 0..100
            // con TRES validaciones do-while y actualizar mercado.
            std::cout << "[PENDIENTE C01] Validacion de lectura manual\n";
            break;
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
