# Reparto de trabajo — propuesta para 4 integrantes

Este reparto asigna **3 issues por estudiante**, con entregables reales y revisiones cruzadas. La guía original indica un **máximo de 3 integrantes**; validar primero con el docente si se admite un cuarto.

| Integrante | Issues | Archivos principales | Qué demuestra |
|---|---|---|---|
| 1 | A01–A03 | `include/configuracion.h`, `include/Carga*.h`, `src/Carga*.cpp` | Constantes, clase abstracta, herencia y polimorfismo |
| 2 | B01–B03 | `Mercado*`, `Medidor*`, `include/Negocio.h`, `src/Negocio.cpp` | Asociación, composición, agregación, potencia contratada |
| 3 | C01–C03 | `wattcontrol.cpp`, `src/Simulacion.cpp`, `src/Reporte.cpp` | Menú, validación, ciclo de 24 horas, resumen y ahorro |
| 4 | A04, B04, C04 | `docs/uml/`, `src/Negocio.cpp`, `include/Negocio.h`, `docs/pruebas/` | UML final, integración de consumo, pruebas y evidencias |

**Dependencias importantes:** A04 se cierra después de A03 y B03; B04 requiere B02 y B03, y debe acordar los cambios en `Negocio.h`/`Negocio.cpp` con integrantes 2 y 3; C04 requiere A04, B04, C02 y C03. Mientras espera dependencias, el integrante 4 puede preparar formatos de pruebas, revisar el diagrama y colaborar en revisiones de PR, sin inventar resultados.

## Evidencia real del trabajo

- Una rama por issue, por ejemplo `feat/a02-carga-abstracta`, `feat/b03-negocio` o `docs/c04-pruebas`.
- **Al menos 3 commits propios, auténticos y explicables por integrante** dentro del periodo indicado en la actividad (26 de octubre–11 de noviembre de 2026 según los documentos de origen).
- Nunca usar cuentas ajenas ni crear commits vacíos para alcanzar la cuota.
- Incluir `Closes #NÚMERO_REAL` en la descripción de la PR si esta completa la issue.
- Pedir revisión a otra persona antes de fusionar con `main` y comprobar la compilación.
- Cada integrante debe poder explicar claramente su contribución y una relación de POO en su video.

## Decisiones técnicas pendientes

1. **Capacidad:** nevera 1,2 + horno 7 + amasadora 2,2 = **10,4 kW**, más que los 9 kW contratados. Si ambas cargas aplazables solicitan encendido simultáneo, la regla indicada apaga el **horno (7 kW)**. Si no se alcanzan las horas propuestas, informar `produccion incompleta`.
2. **Lectura fallida:** `rand() % 20 == 0` equivale a probabilidad de 1 entre 20 por hora, no una falla programada cada 20 horas.
3. **Emergencia:** `precio > 1500 && embalses < 40` detiene el ciclo con `break`. Comparar costos sobre **las mismas horas realmente procesadas**.
4. **Lectura manual:** la opción 1 guarda hora, precio y embalses; la opción 2 usa esos valores sin sumar horas a la simulación.
5. **Precios por franja:** seguir los rangos de `PASO_A_PASO.md` reflejados en `configuracion.h`.
