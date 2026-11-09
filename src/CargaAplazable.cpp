#include "CargaAplazable.h"
#include "configuracion.h"

CargaAplazable::CargaAplazable(const std::string& nombre, double potenciaKW)
    : Carga(nombre, potenciaKW) {}

bool CargaAplazable::debeEncender(int hora, double precioCOPkWh, double embalsesPct) const {
    (void)hora; (void)precioCOPkWh; (void)embalsesPct;
    // TODO A03: condicion compuesta con &&, || y !:
    // embalses < 40%, hora pico 18..20, precio > 800 COP/kWh -> aplazar.
    return false;  // Marcador temporal: NO es la regla definitiva.
}
bool CargaAplazable::esAplazable() const { return true; }
