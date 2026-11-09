#pragma once

// B02: Composicion en Negocio. Cuenta consumo y costo CON gestor.
class Medidor {
private:
    double energiaTotalKWh_ = 0.0;
    double costoTotalCOP_ = 0.0;
public:
    void reiniciar();
    void registrarHora(double potenciaEncendidaKW, double precioCOPkWh);
    double energiaTotalKWh() const;
    double costoTotalCOP() const;
};
