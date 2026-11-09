# Decisiones técnicas del proyecto

Este documento reúne los criterios del caso que deben mantenerse coherentes en el código, las pruebas y el informe.

## Reglas del modelo

- Potencias: nevera **1,2 kW**, horno **7 kW**, amasadora **2,2 kW**.
- Potencia contratada: **9 kW**. Si las tres cargas solicitan encendido (10,4 kW), desconectar la carga aplazable de mayor potencia: el horno.
- Precio alto: **>800 COP/kWh**.
- Alerta de embalses: **<40 %**.
- Emergencia: precio **>1500 COP/kWh** y embalses **<40 %**.
- Falla de lectura: probabilidad **1/20 por hora**; durante la falla se mantiene la nevera y se contabiliza su consumo.
- Precios por franja (COP/kWh): 0–6 (398–640), 7–14 (456–970), 15–17 (596–1040), 18–20 (705–1612), 21–23 (565–970). Verificar contra el material oficial de clase antes de entregar.

## Criterios que requieren justificación

Las horas mínimas propuestas son horno 6 h/día y amasadora 4 h/día. Son supuestos de planificación del equipo, no datos oficiales. Justificarlos según el proceso de la panadería y reportar producción incompleta si no se cumplen.

El nivel inicial de embalses del 60 % es un valor de demostración de la plantilla; la simulación debe respetar el valor que se ingrese.

## Cálculo del consumo y ahorro

Registrar solo cargas encendidas. Una carga de potencia P kW activa durante una hora consume P kWh. Si la emergencia interrumpe el ciclo, informar las horas realmente procesadas y comparar el costo con y sin gestor sobre el mismo periodo.

No cambiar los umbrales ni inventar resultados de simulación sin justificarlo en el informe.
