#include "CargaCritica.h"

CargaCritica::CargaCritica(const std::string& nombre, double potenciaKW)
    : Carga(nombre, potenciaKW) {}

bool CargaCritica::debeEncender(int hora, double precioCOPkWh, double embalsesPct) const {
    (void)hora; (void)precioCOPkWh; (void)embalsesPct;
    // TODO A03: implementar regla 1 (nunca se apaga, incluso en falla).
    return false;  // Marcador temporal: NO es la regla definitiva.
}
bool CargaCritica::esAplazable() const { return false; }
