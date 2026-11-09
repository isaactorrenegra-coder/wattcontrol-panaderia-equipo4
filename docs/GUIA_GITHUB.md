# Publicar el repositorio y las 12 issues

## Requisitos previos

- Confirmar que el último dígito del documento del creador es **0 o 1**.
- Elegir el número del equipo y reemplazar `equipoN` en el nombre real del repositorio.
- Instalar Git, `g++` y, para crear issues automáticamente, **GitHub CLI (`gh`)**.

## Paso 1 — Crear repositorio público vacío

En GitHub: **New repository** → `wattcontrol-panaderia-equipoN` (sustituir `N`) → **Public** → crear **sin README ni .gitignore** (los aporta el ZIP). Extraer esta plantilla a una carpeta local.

## Paso 2 — Subir archivos al nuevo repositorio

Situado en la carpeta extraída, ejecutar (sustituir `USUARIO` y nombre real):

```bash
git init
git add .
git commit -m "chore: crear plantilla inicial de WattControl"
git branch -M main
git remote add origin https://github.com/USUARIO/wattcontrol-panaderia-equipoN.git
git push -u origin main
```

También es posible usar **Add file → Upload files** en el repositorio para subir el contenido de la carpeta extraída. El ZIP por sí mismo **no** importa issues ni crea el repositorio.

## Paso 3 — Crear las issues reales

```bash
gh auth login
bash scripts/publicar_issues.sh USUARIO/wattcontrol-panaderia-equipoN
```

El script crea etiquetas de responsables y de áreas, y hasta **12 issues**. No asigna cuentas de usuario porque no conocemos los handles reales; abrir cada issue y elegir **Assignees** según `docs/EQUIPO.md`.

## Paso 4 — Colaborar

Desde **Settings → Collaborators** invitar a los demás integrantes. **El README es la guía principal** de ramas, GitHub Desktop, revisiones y Projects. La plantilla ya distribuye 12 issues entre cuatro responsables, sujetos a autorización docente. Para cada tarea:

```bash
git checkout main
git pull origin main
git checkout -b feat/a02-carga-abstracta
# trabajar, compilar y revisar
git add include/Carga.h src/Carga.cpp
git commit -m "feat: implementar estado y metodos base de Carga"
git push -u origin feat/a02-carga-abstracta
```

Abrir una **Pull Request** a `main`, pedir revisión a otro integrante y fusionar **solo tras aprobarse la revisión y la compilación**. Si las 12 issues ya existían, corregir manualmente las etiquetas y asignaciones de A04, B04 y C04: el script no actualiza las issues existentes. El administrador debe proteger `main` para exigir una PR. Sustituir los archivos/branch por los de su issue. El siguiente integrante hace `git pull origin main` antes de empezar.

## Paso 5 — Etiqueta de entrega (solo al terminar)

```bash
git checkout main
git pull origin main
git tag ea2
git push origin ea2
```

No crear la etiqueta antes de comprobar compilación, pruebas, documento y código final.

> ⚠️ **Requisito académico:** el documento original indica máximo 3 integrantes; confirmar autorización para 4 antes de entregar.
