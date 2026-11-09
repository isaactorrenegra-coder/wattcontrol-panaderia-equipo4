# Reparto de trabajo

Cada integrante tiene tres issues. Consulta la issue antes de modificar archivos y coordina los cambios compartidos.

| Integrante | Issues | Responsabilidad | Archivos principales |
|---|---|---|---|
| **Daniela (1)** | A01–A03 | Configuración, clase abstracta `Carga`, herencia y polimorfismo | `include/configuracion.h`, `include/Carga*.h`, `src/Carga*.cpp` |
| **Gisell (2)** | B01–B03 | Mercado, medidor, relaciones entre clases y límite de potencia | `Mercado*`, `Medidor*`, `include/Negocio.h`, `src/Negocio.cpp` |
| **Nestor (3)** | C01–C03 | Menú, validaciones, simulación de 24 horas y reportes | `wattcontrol.cpp`, `src/Simulacion.cpp`, `src/Reporte.cpp` |
| **Isaac (4)** | A04, B04, C04 | UML, integración del registro de consumo, pruebas y evidencias | `docs/02-tecnico/uml/`, `src/Negocio.cpp`, `include/Negocio.h`, `docs/03-pruebas/` |

## Dependencias y coordinación

- **A04 (Isaac):** finalizar después de A03 y B03; el UML debe coincidir con el código real.
- **B04 (Isaac):** requiere B02 y B03. Coordinar con Gisell los cambios en `Negocio.h/.cpp`; Nestor debe acordar la interfaz que usará la simulación.
- **C04 (Isaac):** requiere A04, B04, C02 y C03. Preparar antes la plantilla de pruebas, pero registrar resultados solo después de ejecutar el programa.
- **Archivos compartidos:** `Negocio.h` y `Negocio.cpp` no deben modificarse simultáneamente sin coordinación. Acordar primero firmas, responsabilidades y método de integración.

## Reglas de colaboración

1. Una rama por tarea, por ejemplo `feat/a02-carga-abstracta`.
2. Commits pequeños que describan cambios reales y propios.
3. Abrir Pull Request hacia `main` y pedir revisión a otro integrante.
4. Corregir observaciones en la misma rama; integrar solo tras revisión y compilación.
5. Cada persona debe poder explicar su contribución. No crear commits vacíos o atribuir trabajo ajeno.

## Decisiones del caso que el equipo debe respetar

- Potencia máxima contratada: **9 kW**. Las tres cargas suman 10,4 kW; al superar el límite se apaga la carga aplazable de mayor potencia (horno, 7 kW).
- Falla de lectura: probabilidad 1/20 por hora; mantener la nevera y registrar su consumo.
- Emergencia: precio >1500 COP/kWh y embalses <40 %; detener el ciclo con `break`.
- Si el ciclo termina antes de 24 horas, reportar las horas reales y comparar costos sobre periodos equivalentes.
- Las horas mínimas propuestas (horno 6 h y amasadora 4 h) deben justificarse y no presentarse como datos oficiales si no lo son.

> La consigna original indica máximo 3 integrantes. Confirmar autorización docente para trabajar como equipo de cuatro antes de la entrega.
