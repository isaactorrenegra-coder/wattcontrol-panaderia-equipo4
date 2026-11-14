#include "Mercado.h"
#include <cstdlib>

double Mercado::precioHora(int hora) const {
    (void)hora;
    // TODO B01: elegir rango por franja y generar el precio con rand(),
    // incluyendo minimos y maximos del PASO_A_PASO.md (configuracion.h).
    return 0.0;  // Marcador temporal; precio NO VALIDO para simulacion.
}
double Mercado::nivelEmbalses() const { return embalsesPct_; }
void Mercado::actualizarNivelEmbalses(double nivelPct) {
    // TODO B01: verificar que la entrada este entre 0 y 100.
    if (nivelPct >= 0.0 && nivelPct <= 100.0) embalsesPct_ = nivelPct;
}
