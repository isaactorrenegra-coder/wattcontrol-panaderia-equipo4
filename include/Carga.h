#pragma once
#include <string>

// A02: clase abstracta que representa una carga electrica.
class Carga {
protected:
    std::string nombre_;
    double potenciaKW_;
    bool encendida_;
    int horasUso_;
    double energiaKWh_;

public:
    Carga(const std::string& nombre, double potenciaKW);
    virtual ~Carga() = default;
    virtual bool debeEncender(int hora, double precioCOPkWh, double embalsesPct) const = 0; // A02: regla de encendido/apagado de la carga de la asbtracta.
    virtual bool esAplazable() const = 0;
    void fijarEncendida(bool encendida);
    void registrarHora();
    void reiniciar();
    const std::string& nombre() const;
    double potenciaKW() const;
    bool encendida() const;
    int horasUso() const;
    double energiaKWh() const;
};
