#include "Mercado.h"
#include <cstdlib>

double Mercado::precioHora(int hora) const {
    int minimo;
    int maximo;

    if (hora >= 0 && hora <= 6) {
        minimo = config::PRECIO_MADRUGADA_MIN;
        maximo = config::PRECIO_MADRUGADA_MAX;
    } else if (hora >= 7 && hora <= 14) {
        minimo = config::PRECIO_MANANA_MIN;
        maximo = config::PRECIO_MANANA_MAX;
    } else if (hora >= 15 && hora <= 17) {
        minimo = config::PRECIO_TARDE_MIN;
        maximo = config::PRECIO_TARDE_MAX;
    } else if (hora >= 18 && hora <= 20) {
        minimo = config::PRECIO_PICO_MIN;
        maximo = config::PRECIO_PICO_MAX;
    } else if (hora >= 21 && hora <= 23) {
        minimo = config::PRECIO_NOCHE_MIN;
        maximo = config::PRECIO_NOCHE_MAX;
    } else {
        return 0.0;
    }

    return minimo + rand() % (maximo - minimo + 1);
}
double Mercado::nivelEmbalses() const { return embalsesPct_; }
void Mercado::actualizarNivelEmbalses(double nivelPct) {

    if (nivelPct >= 0.0 && nivelPct <= 100.0) embalsesPct_ = nivelPct;
}
