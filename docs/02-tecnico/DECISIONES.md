# Decisiones técnicas del proyecto

Este documento reúne los criterios del caso que deben mantenerse coherentes en el código, las pruebas y el informe.

## Reglas del modelo

- Potencias: nevera **1,2 kW**, horno **7 kW**, amasadora **2,2 kW**.
- Potencia contratada: **9 kW**. Si las tres cargas solicitan encendido (10,4 kW), desconectar la carga aplazable de mayor potencia: el horno.
- Precio alto: **>800 COP/kWh**.
- Alerta de embalses: **<40 %**.
- Emergencia: precio **>1500 COP/kWh** y embalses **<40 %**.
- Falla de lectura: probabilidad **1/20 por hora**; durante la falla se mantiene la nevera y se contabiliza su consumo.
- Precios por franja (COP/kWh): 0–6 (398–640), 7–14 (456–970), 15–17 (596–1040), 18–20 (705–1612), 21–23 (565–970).

## Criterios que requieren justificación

Las horas mínimas propuestas son horno 6 h/día y amasadora 4 h/día. Son supuestos de planificación del equipo, no datos oficiales. Justificarlos según el proceso de la panadería y reportar producción incompleta si no se cumplen.
- **Justificación del horno (6 h/día):** Incluye el tiempo de precalentamiento inicial de la cámara térmica (aproximadamente 1 hora para alcanzar entre 180 °C y 220 °C) y varias tandas continuas de cocción para cubrir la demanda diaria de pan fresco (primera producción de la mañana y reposición de la tarde) sin perder inercia térmica por encendidos y apagados frecuentes.
  - **Justificación de la amasadora (4 h/día):** Responde al trabajo por lotes previos al horneado (mezclado de ingredientes, amasado para desarrollo del gluten y sobado de distintas masas: pan corriente, pan aliñado y repostería), que requiere menor tiempo continuo que la cocción porque las masas pasan luego a reposo y fermentación.
  - **Criterio operativo:** Si al finalizar las 24 horas alguna de estas cargas no alcanza su mínimo diario, el sistema reporta producción incompleta.
Con las reglas actuales, las dos cargas aplazables solicitan encendido juntas. En esas horas, la regla de 9 kW desconecta el horno y este queda con 0 horas de uso. Reflejar ese resultado en la alerta y en el análisis del ahorro. Consultar al docente antes de incorporar turnos alternos.

El nivel inicial de embalses del 60 % es un valor de demostración de la plantilla; la simulación debe respetar el valor que se ingrese.

## Cálculo del consumo y ahorro

Registrar solo cargas encendidas. Una carga de potencia P kW activa durante una hora consume P kWh. En la falla simulada, usar el precio generado para contabilizar ambos escenarios y mantener solo la nevera encendida. Si hay emergencia, detenerse antes de contabilizar esa hora en cualquiera de los escenarios. Mostrar las horas procesadas y comparar ambos costos sobre ese mismo periodo.

No cambiar los umbrales ni inventar resultados de simulación sin justificarlo en el informe.
