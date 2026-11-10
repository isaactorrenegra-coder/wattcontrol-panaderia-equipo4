#pragma once
#include <string>
#include "configuracion.h"
#include "Carga.h"
#include "Medidor.h"
#include "Mercado.h"

// B03/B04: Negocio posee Medidor; agrega Carga* externas; conoce Mercado* externo.
class Negocio {
private:
    std::string nombre_;
    Medidor medidor_;                       // Composicion
    Carga* cargas_[MAX_CARGAS] = {};       // Agregacion (no se hace delete)
    int numeroCargas_ = 0;
    Mercado* mercado_;                      // Asociacion (no se hace delete)
    double costoSinGestorCOP_ = 0.0;
    int horasSimuladas_ = 0;
    int fallasLectura_ = 0;
    bool emergencia_ = false;
    bool tieneSimulacion_ = false;

public:
    Negocio(const std::string& nombre, Mercado* mercado);
    bool agregarCarga(Carga* carga);
    void evaluarCargas(int hora, double precioCOPkWh, double embalsesPct);
    void registrarConsumoHora(double precioCOPkWh);
    void simularDia();                     // C02
    void mostrarResumen() const;           // C03
};
