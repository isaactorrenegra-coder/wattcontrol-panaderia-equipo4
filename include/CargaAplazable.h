#pragma once
#include "Carga.h"

class CargaAplazable : public Carga {
public:
    CargaAplazable(const std::string& nombre, double potenciaKW);
    bool debeEncender(int hora, double precioCOPkWh, double embalsesPct) const override;
    bool esAplazable() const override;
};
