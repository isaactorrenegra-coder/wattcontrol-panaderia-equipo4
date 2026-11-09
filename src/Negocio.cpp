#include "Negocio.h"
#include <iostream>

Negocio::Negocio(const std::string& nombre, Mercado* mercado)
    : nombre_(nombre), mercado_(mercado) {}

bool Negocio::agregarCarga(Carga* carga) {
    // TODO B03: revisar punteros nulos y capacidad maxima.
    if (carga == nullptr || numeroCargas_ >= MAX_CARGAS) return false;
    cargas_[numeroCargas_++] = carga;
    return true;
}
void Negocio::evaluarCargas(int hora, double precioCOPkWh, double embalsesPct) {
    (void)hora; (void)precioCOPkWh; (void)embalsesPct;
    // TODO B03: recorrer cargas_[i]->debeEncender(...) usando polimorfismo,
    // cambiar el estado y aplicar la regla 6 (desconectar aplazable mas potente).
    std::cout << "[PENDIENTE B03] Evaluacion de cargas\n";
}
void Negocio::registrarConsumoHora(double precioCOPkWh) {
    (void)precioCOPkWh;
    // TODO B04: para cada carga encendida registrar hora/kWh y enviar potencia al Medidor.
}
