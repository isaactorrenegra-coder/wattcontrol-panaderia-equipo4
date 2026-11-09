#include "Negocio.h"
#include <cstdlib>
#include <iostream>

int main() {
    // Creamos una instancia de Negocio con su nombre y el mercado asociado
    // (Asegúrate de pasar los parámetros correctos según tu constructor)
    Mercado mercado; // O el puntero/objeto de mercado que maneje tu proyecto
    Negocio miNegocio("Panaderia El Trigo", &mercado);
    
    // Ejecutamos la simulación del día que corre hacia src/Negocio.cpp
    miNegocio.simularDia();
    
    return 0;
}