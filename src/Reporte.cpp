#include "Reporte.h"
#include <iostream>
#include <iomanip>

// Implementación de la función de reporte
// Si es una función libre (sin clase):
void generarReporteConsumo(double energiaTotalKWh, double costoTotalCOP) {
    std::cout << "\n===== REPORTE DE CONSUMO =====\n";
    std::cout << "Energia Total: " << energiaTotalKWh << " kWh\n";
    std::cout << "Costo Total Financiero: $" << costoTotalCOP << " COP\n";
    std::cout << "==============================\n";
    
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
