# Limpieza de historial y flujo del equipo Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Publicar un historial limpio, aplazar el UML, reasignar B02 a Néstor y documentar el flujo Git obligatorio para Bash y CMD.

**Architecture:** Se conservarán los commits con aportes reales y se reconstruirán únicamente los commits que contienen artefactos descartados. Los cambios vigentes se concentrarán en la documentación del reparto y en el README, sin tocar el comportamiento del programa.

**Tech Stack:** Git, GitHub CLI, Markdown, Mermaid, Bash, CMD y C++17.

**Spec:** `docs/superpowers/specs/2026-11-11-limpieza-historial-y-flujo-equipo-design.md`

## Global Constraints

- El UML se realizará al final y no debe existir como archivo histórico ni vigente.
- B02 · Medidor pertenece a Néstor; A04 · UML permanece con Isaac al final.
- Conservar autores y commits con aportes reales.
- Publicar mediante `git push --force-with-lease` contra el SHA remoto verificado.

## Review Focus

- El historial no debe contener `simulacion.exe` ni diagramas UML.
- El README no debe enlazar archivos UML inexistentes.
- Todos los textos del reparto deben asignar B02 a Néstor.
- Los comandos Bash y CMD deben crear ramas desde un `main` actualizado y nunca trabajar directamente en `main`.
- La compilación debe seguir funcionando después de la limpieza.

---

### Task 1: Establecer línea base y respaldo

**Files:**
- Inspect: árbol e historial completo del repositorio

**Interfaces:**
- Consumes: `origin/main` en `5edc658962d8c711b178632845b55d64204f8ce9`
- Produces: referencia local de respaldo y evidencia de compilación inicial

- [ ] **Step 1:** Registrar el SHA remoto, el estado limpio y una referencia local de respaldo.
- [ ] **Step 2:** Ejecutar `bash scripts/compilar.sh` y confirmar salida exitosa.

### Task 2: Reconstruir el historial sin artefactos

**Files:**
- Remove from all history: `simulacion.exe`
- Remove from all history: `docs/02-tecnico/uml/*.drawio`
- Remove from all history: `docs/02-tecnico/uml/*.png`

**Interfaces:**
- Consumes: respaldo de Task 1
- Produces: historial reescrito que conserva los cambios reales y sus autores

- [ ] **Step 1:** Reescribir el historial excluyendo los artefactos acordados y podando commits vacíos.
- [ ] **Step 2:** Eliminar o reformular los commits dedicados al UML sin descartar sus cambios documentales útiles.
- [ ] **Step 3:** Comparar el árbol reconstruido con el respaldo y revisar cada diferencia.

### Task 3: Actualizar reparto y tutorial Git

**Files:**
- Modify: `README.md`
- Modify: `docs/01-equipo/REPARTO.md`
- Modify: `docs/02-tecnico/uml/LEEME.md`
- Modify: `docs/README.md`

**Interfaces:**
- Consumes: historial limpio de Task 2
- Produces: documentación coherente y comandos esenciales para Bash y CMD

- [ ] **Step 1:** Cambiar B02 · Medidor de Isaac a Néstor en todos los textos y en el diagrama Mermaid.
- [ ] **Step 2:** Mover A04 · UML al final del flujo y marcar el diagrama como pendiente.
- [ ] **Step 3:** Sustituir los enlaces al UML por una nota de trabajo pendiente.
- [ ] **Step 4:** Añadir el tutorial obligatorio para actualizar `main`, crear rama, compilar, revisar, confirmar, subir y sincronizar en Bash y CMD.
- [ ] **Step 5:** Verificar enlaces, asignaciones y comandos mediante búsquedas dirigidas.
- [ ] **Step 6:** Crear un commit documental con un mensaje descriptivo.

### Task 4: Verificar y publicar

**Files:**
- Verify: repositorio completo
- Update externally: GitHub issue #9 y `origin/main`

**Interfaces:**
- Consumes: rama validada de Task 3
- Produces: `main` remoto limpio y issue #9 asignado a `stify362`

- [ ] **Step 1:** Ejecutar la compilación completa y comprobar el ejecutable generado.
- [ ] **Step 2:** Verificar con `git rev-list --objects main` que los artefactos eliminados no estén en el historial publicable; las referencias locales de respaldo se excluyen deliberadamente de esta comprobación.
- [ ] **Step 3:** Confirmar que el remoto todavía apunta al SHA registrado en Task 1.
- [ ] **Step 4:** Publicar con `git push --force-with-lease`.
- [ ] **Step 5:** Reasignar el issue #9 a `stify362` y verificar su estado.
- [ ] **Step 6:** Volver a clonar `main`, compilar y revisar el historial publicado.
