#pragma once

// B02: Composicion en Negocio. Cuenta consumo y costo CON gestor.
class Medidor {
private:
    double energiaTotalKWh_ = 0.0;
    double costoTotalCOP_ = 0.0;

public:
    // Método para reiniciar los acumuladores a cero
    void reiniciar();

    // Método para registrar el consumo de una hora de simulación
    void registrarHora(double potenciaEncendidaKW, double precioCOPkWh);

    // Getters para consultar las métricas acumuladas
    double energiaTotalKWh() const;
    double costoTotalCOP() const;
};