#include "Medidor.h"

// Resetea las métricas al iniciar un ciclo
void Medidor::reiniciar() {
    energiaTotalKWh_ = 0.0;
    costoTotalCOP_ = 0.0;
}

// Acumula la energía y el costo de la hora actual
void Medidor::registrarHora(double potenciaEncendidaKW, double precioCOPkWh) {
    if (potenciaEncendidaKW > 0.0 && precioCOPkWh >= 0.0) {
        energiaTotalKWh_ += potenciaEncendidaKW; // 1 hora de consumo: kWh = kW * 1h
        costoTotalCOP_ += (potenciaEncendidaKW * precioCOPkWh);
    }
}

// Retorna la energía total acumulada
double Medidor::energiaTotalKWh() const {
    return energiaTotalKWh_;
}

// Retorna el costo financiero acumulado en COP
double Medidor::costoTotalCOP() const {
    return costoTotalCOP_;
}