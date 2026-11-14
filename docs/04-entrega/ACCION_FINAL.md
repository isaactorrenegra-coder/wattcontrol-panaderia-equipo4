# Acción final del repositorio

## Alcance

Este cierre integra y corrige lo que faltaba en la versión final de WattControl, sin modificar ni elaborar el UML. El UML queda a cargo del equipo y debe validarse contra las firmas y relaciones de las clases que aparecen en el código integrado.

## Correcciones realizadas

- Se completó el ciclo de simulación con alerta de emergencia cuando el precio supera 1500 COP/kWh y los embalses están por debajo de 40 %.
- Se incorporó la falla de lectura con probabilidad 1/20 por hora: durante una falla se mantiene únicamente la carga crítica y la hora se contabiliza con el precio generado.
- Se reinician cargas, medidor, fallas y acumuladores antes de cada simulación para evitar resultados acumulados al repetir la opción 3.
- Se agregó la comparación entre costo sin gestor, costo gestionado y ahorro, usando el mismo periodo procesado.
- El resumen ahora informa horas procesadas, fallas, estado de emergencia, consumo por carga y cumplimiento de las horas mínimas propuestas.
- Se retiraron los marcadores visibles de plantilla y se actualizaron los enlaces de documentación.

## Validación final

La rama `fix/final-ea2` se validó con:

```bash
bash scripts/compilar.sh
git diff --check
printf '4\n3\n4\n0\n' | ./wattcontrol
```

También se verificaron la consulta del resumen antes de simular, la simulación completa de 24 horas y la repetición de la simulación sin duplicar los acumuladores.

## Aclaración sobre asistencia

Se utilizó GitHub Copilot para revisar el código integrado, corregir detalles de implementación, detectar errores finales y apoyar la documentación de este cierre. Las decisiones del modelo, las pruebas y la responsabilidad de la entrega corresponden al equipo.
