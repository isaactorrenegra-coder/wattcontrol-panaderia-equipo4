#include "CargaAplazable.h"
#include "configuracion.h"

CargaAplazable::CargaAplazable(const std::string& nombre, double potenciaKW)
    : Carga(nombre, potenciaKW) {}

bool CargaAplazable::debeEncender(int hora, double precioCOPKWh, double embalsesPct) const {
    // Definimos un umbral de precio o de embalses crítico
    double precioMaximoPermitido = 450.0; // Ajusta este valor según la moneda/escala de tu mercado
    double embalsesMinimos = 30.0;       // Porcentaje mínimo de agua

    // Si la energía está muy cara o los embalses están muy bajos, la carga se aplaza (retorna false)
    if (precioCOPKWh > precioMaximoPermitido || embalsesPct < embalsesMinimos) {
        return false; // Se apaga en esta hora para ahorrar costos/agua
    }

    // Si las condiciones son normales, la carga opera con normalidad
    return true;
}
bool CargaAplazable::esAplazable() const { return true; }
