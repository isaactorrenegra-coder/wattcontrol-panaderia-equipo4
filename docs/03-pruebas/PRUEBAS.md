# Pruebas de WattControl

Registrar aquí únicamente resultados que se hayan obtenido al ejecutar la versión actual del programa. Guardar capturas en esta misma carpeta, en `capturas/`.

| ID | Escenario | Resultado esperado | Resultado real | Evidencia |
|---|---|---|---|---|
| P01 | Entradas fuera de rango (hora, precio, embalses) | Rechazo y nueva solicitud | Pendiente | Pendiente |
| P02 | Hora pico (19 h) | Nevera encendida; aplazables apagadas | Pendiente | Pendiente |
| P03 | Embalses por debajo del 40 % | Nevera encendida; alerta y aplazables apagadas según regla | Pendiente | Pendiente |
| P04 | Las tres cargas solicitan encendido (10,4 kW) | Se apaga horno; quedan 3,4 kW | Pendiente | Pendiente |
| P05 | Simulación normal de 24 horas | 24 horas procesadas y costos/ahorro verificables | Pendiente | Pendiente |
| P06 | Emergencia: precio >1500 y embalses <40 % | Se informa emergencia y termina el ciclo | Pendiente | Pendiente |
| P07 | Falla de lectura (1 de 20) | Solo nevera activa; se registra consumo y continúa | Pendiente | Pendiente |

**No marcar una prueba como aprobada ni completar el resultado real sin ejecutarla.** Para escenarios aleatorios, documentar cómo se reprodujo el caso (por ejemplo, semilla o mecanismo de prueba controlado).
