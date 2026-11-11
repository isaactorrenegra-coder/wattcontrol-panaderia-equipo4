# Limpieza de historial y flujo del equipo

## Intención

Dejar `main` sin los artefactos prematuros del UML ni el ejecutable `simulacion.exe`, conservar todos los aportes reales del equipo y actualizar la asignación de B02 (Medidor) de Isaac a Néstor. El UML se elaborará al final de la implementación.

## Alcance

- Eliminar de todo el historial los PNG, Draw.io y borradores del UML.
- Eliminar el commit dedicado exclusivamente a publicar el UML, conservando los cambios documentales útiles de commits mixtos.
- Eliminar `simulacion.exe` de todo el historial y podar commits que queden vacíos.
- Mantener el código y los commits con aportes reales, junto con sus autores.
- Asignar B02 a Néstor en el README, el reparto y el issue #9.
- Mantener A04 con Isaac, pero ubicarla al final del flujo.
- Añadir al README un tutorial obligatorio con comandos equivalentes para Bash y CMD.

## Fuera de alcance

- Crear el UML definitivo.
- Compactar todos los aportes del equipo en uno o pocos commits.
- Cambiar otras responsabilidades o modificar el código funcional.

## Enfoques considerados

1. **Reescritura quirúrgica (elegido):** reconstruir el historial conservando aportes reales y excluyendo únicamente los artefactos y commits acordados. Protege la autoría y el requisito académico de conservar contribuciones.
2. **Eliminar commits completos:** descartado porque los commits que introdujeron el UML también contienen documentación y ajustes útiles.
3. **Borrar archivos solo en un commit nuevo:** descartado porque dejaría los binarios y el UML recuperables en el historial y no cumpliría la limpieza solicitada.

## Restricciones y comprobaciones

- Crear una referencia local de respaldo antes de reescribir.
- Verificar que el árbol funcional, salvo la documentación acordada, no pierda archivos.
- Compilar el proyecto antes y después de la reescritura.
- Confirmar que ningún objeto histórico conserve `simulacion.exe` ni archivos de diagramas.
- Publicar con `--force-with-lease`, nunca con un force push ciego.
