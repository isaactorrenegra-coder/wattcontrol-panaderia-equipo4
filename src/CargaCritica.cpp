#include "CargaCritica.h"

CargaCritica::CargaCritica(const std::string& nombre, double potenciaKW)
    : Carga(nombre, potenciaKW) {}

bool CargaCritica::debeEncender(int hora, double precioCOPkWh, double embalsesPct) const {
    (void)hora;
    (void)precioCOPkWh;
    (void)embalsesPct;
    return true;
}

bool CargaCritica::esAplazable() const {
    return false;
}