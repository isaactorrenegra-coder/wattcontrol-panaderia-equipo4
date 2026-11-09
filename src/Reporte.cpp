#include "Reporte.h"
#include <iostream>
#include <iomanip>

// Implementación de la función de reporte
void generarReporteConsumo(double energiaTotalKWh, double costoTotalCOP) {
    std::cout << "\n==============================================" << std::endl;
    std::cout << "         REPORTE FINAL DE CONSUMO - WATTCONTROL " << std::endl;
    std::cout << "==============================================" << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << " * Energia total consumida : " << energiaTotalKWh << " kWh" << std::endl;
    std::cout << " * Costo total estimado    : $" << costoTotalCOP << " COP" << std::endl;
    
    if (energiaTotalKWh > 0) {
        double costoPromedio = costoTotalCOP / energiaTotalKWh;
        std::cout << " * Costo promedio por kWh  : $" << costoPromedio << " COP/kWh" << std::endl;
    } else {
        std::cout << " * Costo promedio por kWh  : $0.00 COP/kWh" << std::endl;
    }

    std::cout << "==============================================" << std::endl;
    std::cout << " Estado del reporte: Generado correctamente." << std::endl;
    std::cout << "==============================================\n" << std::endl;
}
