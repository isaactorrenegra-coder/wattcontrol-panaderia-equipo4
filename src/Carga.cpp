#include "Carga.h"
#include <utility>

Carga::Carga(const std::string& nombre, double potenciaKW)
    : nombre_(nombre), potenciaKW_(potenciaKW), encendida_(false), horasUso_(0), energiaKWh_(0.0) {}

void Carga::fijarEncendida(bool encendida) { encendida_ = encendida; }
void Carga::registrarHora() {
    // A02: comprobar la acumulacion: una hora encendida = potencia kW x 1 h.
    if (encendida_) { ++horasUso_; energiaKWh_ += potenciaKW_; }
}
void Carga::reiniciar() { encendida_ = false; horasUso_ = 0; energiaKWh_ = 0.0; }
const std::string& Carga::nombre() const { return nombre_; }
double Carga::potenciaKW() const { return potenciaKW_; }
bool Carga::encendida() const { return encendida_; }
int Carga::horasUso() const { return horasUso_; }
double Carga::energiaKWh() const { return energiaKWh_; }
