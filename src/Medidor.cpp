#include "Medidor.h"

void Medidor::reiniciar() { energiaTotalKWh_ = 0.0; costoTotalCOP_ = 0.0; }
void Medidor::registrarHora(double potenciaEncendidaKW, double precioCOPkWh) {
    (void)potenciaEncendidaKW; (void)precioCOPkWh;
    // TODO B02: actualizar kWh y COP en una hora de operacion.
}
double Medidor::energiaTotalKWh() const { return energiaTotalKWh_; }
double Medidor::costoTotalCOP() const { return costoTotalCOP_; }
