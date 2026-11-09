#pragma once
#include "Carga.h"

class CargaCritica : public Carga {
public:
    CargaCritica(const std::string& nombre, double potenciaKW);
    bool debeEncender(int hora, double precioCOPkWh, double embalsesPct) const override;
    bool esAplazable() const override;
};
