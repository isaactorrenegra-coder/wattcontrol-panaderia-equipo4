#pragma once
#include "configuracion.h"

// B01: el Negocio lo conoce, pero no es dueno de este objeto (asociacion).
class Mercado {
private:
    double embalsesPct_ = config::EMBALSE_INICIAL_PCT;
public:
    double precioHora(int hora) const;
    double nivelEmbalses() const;
    void actualizarNivelEmbalses(double nivelPct);
};
