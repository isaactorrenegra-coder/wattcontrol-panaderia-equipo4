# Pruebas de la EA2 (completar con resultados REALES y capturas)

**No completar la columna "Obtenido" hasta ejecutar el programa terminado.** Guardar capturas en `docs/pruebas/capturas/` y enlazarlas en este archivo o en el PDF.

| ID | Opción | Entrada / preparación | Resultado esperado | Obtenido | Captura |
|---|---|---|---|---|---|
| P01 | 1 | Hora 24 o -1, precio <=0 o embalses 101 | Rechazo y nueva solicitud de dato válido | PENDIENTE | PENDIENTE |
| P02 | 2 | 19 h, 750 COP/kWh, 60 % | Nevera ON; horno y amasadora OFF por hora pico | PENDIENTE | PENDIENTE |
| P03 | 2 | 10 h, 550 COP/kWh, 35 % | Nevera ON; aplazables OFF y alerta por embalses | PENDIENTE | PENDIENTE |
| P04 | 2 | 10 h, 550 COP/kWh, 60 % | Solicitud 10,4 kW; se apaga horno (7 kW); quedan 3,4 kW | PENDIENTE | PENDIENTE |
| P05 | 3 y 4 | Simulación 24 horas sin emergencia | Se procesan 24 horas; costos y ahorro verificables, alerta según horas reales | PENDIENTE | PENDIENTE |
| P06 | 1, 3, 4 | Embalses 35 %, una hora con precio >1500 | `break`: emergencia declarada y fin anticipado | PENDIENTE | PENDIENTE |
| P07 (extra) | 3 | Forzar/testear fallo de precio (1 de 20) | `continue`: solo nevera, consumo registrado y siguiente hora | PENDIENTE | PENDIENTE |

**Importante:** P04 es un caso lógico obligatorio. P05/P06/P07 requieren controlar o documentar cómo reproducir `rand()` (semilla fija, registro de salida o prueba controlada). El comportamiento exacto no se debe inventar en el informe. Cada prueba se debe ejecutar con el código final.
