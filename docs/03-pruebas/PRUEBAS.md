# Pruebas de WattControl

Registrar aquí únicamente resultados que se hayan obtenido al ejecutar la versión actual del programa. Guardar capturas en esta misma carpeta, en `capturas/`.

| ID | Opción | Entrada o escenario | Resultado esperado | Resultado obtenido | Captura |
|---|---|---|---|---|---|
| P01 | 1 | Hora 24, precio 0 y embalses 101, seguidos de datos válidos | Rechaza cada dato inválido y vuelve a pedirlo | Pendiente | Pendiente |
| P02 | 1 y 2 | 19 h, 600 COP/kWh, 60 % | Enciende la nevera y aplaza las otras dos cargas | Pendiente | Pendiente |
| P03 | 1 y 2 | 17 h, 600 COP/kWh, 39 % | Alerta de riesgo, solo la nevera encendida | Pendiente | Pendiente |
| P04 | 1 y 2 | 17 h, 800 COP/kWh, 40 % | Las tres cargas solicitan encendido. Alerta de potencia y apagado del horno. Quedan 3,4 kW | Pendiente | Pendiente |
| P05 | 3 y 4 | Embalses al 60 % | 24 horas procesadas, costos y ahorro verificables | Pendiente | Pendiente |
| P06 | 3 y 4 | Embalses al 39 % y precio simulado mayor que 1500 COP/kWh | Alerta de emergencia, final anticipado y costos del mismo periodo | Pendiente | Pendiente |
| P07 | 3 y 4 | Una hora con falla de lectura | Solo funciona la nevera, se registra su consumo y el ciclo continúa | Pendiente | Pendiente |

**No marcar una prueba como aprobada ni completar el resultado real sin ejecutarla.** Para escenarios aleatorios, documentar cómo se reprodujo el caso (por ejemplo, semilla o mecanismo de prueba controlado).
