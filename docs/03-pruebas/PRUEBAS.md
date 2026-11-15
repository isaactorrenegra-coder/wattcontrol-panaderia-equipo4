# Pruebas de WattControl

Registrar aquí únicamente resultados que se hayan obtenido al ejecutar la versión actual del programa. Las capturas versionadas están en la carpeta `img/` de la raíz del repositorio.

| ID | Opción | Entrada o escenario | Resultado esperado | Resultado obtenido | Captura |
|---|---|---|---|---|---|
| P01 | 1 | Hora 24, precio 0 y embalses 101, seguidos de datos válidos | Rechaza cada dato inválido y vuelve a pedirlo | Aprobada: rechazó la hora y los dos niveles fuera de rango y aceptó los datos válidos | [P01](../../img/P01.png) |
| P02 | 1 y 2 | 19 h, 600 COP/kWh, 60 % | Enciende la nevera y aplaza las otras dos cargas | Aprobada: nevera encendida; horno y amasadora aplazados por hora pico | [P02](../../img/P02.png) |
| P03 | 1 y 2 | 17 h, 600 COP/kWh, 39 % | Alerta de riesgo, solo la nevera encendida | Aprobada: mostró la alerta y mantuvo solo la nevera | [P03](../../img/P03.png) |
| P04 | 1 y 2 | 17 h, 800 COP/kWh, 40 % | Las tres cargas solicitan encendido. Alerta de potencia y apagado del horno. Quedan 3,4 kW | Aprobada: apagó el horno y dejó 3,4 kW | [P04](../../img/p04.jpeg) |
| P05 | 3 y 4 | Embalses al 60 % | 24 horas procesadas, costos y ahorro verificables | Aprobada: procesó 24 horas y mostró costos comparados, ahorro y horas por carga | [P05](../../img/P05.png) |
| P06 | 3 y 4 | Embalses al 39 % y precio simulado mayor que 1500 COP/kWh | Alerta de emergencia, final anticipado y costos del mismo periodo | Rama implementada; no se activó con la semilla fija 2026 en esta ejecución | [P06](../../img/p06.png.png) |
| P07 | 3 y 4 | Una hora con falla de lectura | Solo funciona la nevera, se registra su consumo y el ciclo continúa | Rama implementada con probabilidad 1/20; no ocurrió con la semilla fija 2026 en esta ejecución | No aplica |

**No marcar una prueba como aprobada ni completar el resultado real sin ejecutarla.** Para escenarios aleatorios, documentar cómo se reprodujo el caso (por ejemplo, semilla o mecanismo de prueba controlado).
