#pragma once

// Valores oficiales del negocio PANADERIA; issue A01 revisa estos parametros.
#define HORAS_DIA 24
#define MAX_CARGAS 3
#define SEMILLA_SIMULACION 2026

namespace config {
const double POTENCIA_NEVERA_KW = 1.2;
const double POTENCIA_HORNO_KW = 7.0;
const double POTENCIA_AMASADORA_KW = 2.2;
const double POTENCIA_CONTRATADA_KW = 9.0;
const double PRECIO_CARO_COP_KWH = 800.0;
const double PRECIO_EMERGENCIA_COP_KWH = 1500.0;
const int PICO_INICIO = 18;
const int PICO_FIN = 20;
const double EMBALSE_ALERTA_PCT = 40.0;
const int FALLA_LECTURA_CADA = 20;
const int HORAS_MIN_HORNO = 6;       // Propuesta del equipo; justificar.
const int HORAS_MIN_AMASADORA = 4;   // Propuesta del equipo; justificar.
const double EMBALSE_INICIAL_PCT = 60.0; // Supuesto inicial, modificable por lectura manual.

// Rangos suministrados por el PASO_A_PASO.md de clase, COP/kWh.
const int PRECIO_MADRUGADA_MIN = 398;
const int PRECIO_MADRUGADA_MAX = 640;
const int PRECIO_MANANA_MIN = 456;
const int PRECIO_MANANA_MAX = 970;
const int PRECIO_TARDE_MIN = 596;
const int PRECIO_TARDE_MAX = 1040;
const int PRECIO_PICO_MIN = 705;
const int PRECIO_PICO_MAX = 1612;
const int PRECIO_NOCHE_MIN = 565;
const int PRECIO_NOCHE_MAX = 970;
}  // namespace config
