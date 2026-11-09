# WattControl

Proyecto académico en **C++17** para modelar y analizar el consumo eléctrico de una panadería. La propuesta considera equipos prioritarios, como la nevera, y equipos cuyo uso puede programarse, como el horno y la amasadora.

> **Estado:** el repositorio contiene una plantilla de trabajo en desarrollo. Algunos métodos todavía están pendientes. Que el código compile no significa que todas las reglas del proyecto estén implementadas.

## ¿Qué encontrarás aquí?

- Una base de programación orientada a objetos en C++.
- Clases para representar equipos, consumo eléctrico, mercado de energía y negocio.
- Una simulación y reportes en desarrollo.
- Documentación del equipo, reparto de tareas, diagramas y pruebas.

## Estructura

```text
wattcontrol-panaderia-equipo4/
├── include/   # Declaraciones de clases (.h)
├── src/       # Implementación de las clases (.cpp)
├── docs/      # Guías, equipo, UML y pruebas
├── scripts/   # Ayudas para compilar y preparar el proyecto
└── wattcontrol.cpp
```

## Requisitos

- Git.
- Un compilador de C++ que soporte C++17, como `g++`.
- Una terminal. En Windows puedes usar Git Bash o MSYS2.

## Descargar y ejecutar

1. Clona el repositorio:

   ```bash
   git clone https://github.com/isaactorrenegra-coder/wattcontrol-panaderia-equipo4.git
   ```

2. Entra a la carpeta:

   ```bash
   cd wattcontrol-panaderia-equipo4
   ```

3. Compila:

   ```bash
   bash scripts/compilar.sh
   ```

4. Ejecuta el programa:

   ```bash
   ./wattcontrol
   ```

   En Windows, el ejecutable puede llamarse `wattcontrol.exe`.

## Colaborar con Git y GitHub

El equipo trabaja con ramas para evitar que los cambios incompletos afecten a `main` (la rama principal). No hagas cambios directamente en `main`.

**1. Actualiza la versión principal y crea tu rama:**

```bash
git checkout main
git pull origin main
git checkout -b feat/nombre-de-tu-tarea
```

**2. Guarda tus cambios:**

```bash
git status
git add ruta/del/archivo
git commit -m "Describe el cambio"
```

**3. Sube tu rama a GitHub:**

```bash
git push -u origin feat/nombre-de-tu-tarea
```

**4. Abre una Pull Request (PR) en GitHub:** selecciona tu rama como origen y `main` como destino. Una PR permite que otra persona revise tus cambios antes de incorporarlos al proyecto. Atiende los comentarios y espera la aprobación del equipo antes de hacer merge.

En palabras sencillas:

- **Rama:** espacio separado para trabajar en una tarea.
- **Commit:** registro de un conjunto de cambios.
- **Push:** envío de tus commits a GitHub.
- **Pull Request:** solicitud para revisar e integrar tus cambios.

Para una explicación más detallada, consulta la [guía de Git y GitHub](docs/GUIA_GITHUB.md).

## Documentación

- [Integrantes del equipo](docs/EQUIPO.md)
- [Reparto de tareas](docs/REPARTO.md)
- [Guía de GitHub](docs/GUIA_GITHUB.md)
- [Guía de entrega](docs/GUIA_ENTREGA.md)
- [Decisiones del proyecto](docs/DECISIONES.md)

## Nota académica

La guía original de la actividad señala un máximo de tres integrantes. El repositorio está organizado para cuatro personas; el equipo debe confirmar con el docente si esa conformación está autorizada.

---

Proyecto académico de la IU Digital de Antioquia.
