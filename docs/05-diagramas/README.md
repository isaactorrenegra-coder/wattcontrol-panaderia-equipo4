# UML de WattControl

El archivo [`UML-WattControl.drawio`](UML-WattControl.drawio) es el diagrama UML editable del proyecto. Se puede abrir directamente en [diagrams.net/draw.io](https://app.diagrams.net/) mediante **File → Open From → Device**.

## Cómo se elaboró

El diagrama se generó a partir de la versión integrada del código del repositorio, revisando las declaraciones en `include/`, las implementaciones en `src/` y el flujo de `wattcontrol.cpp`. Para producir el XML editable se utilizó **GitHub Copilot** como asistente de análisis y generación, y después se contrastaron manualmente las clases, firmas, herencia, multiplicidades y relaciones con el código real.

El alcance incluye:

- `Carga`, `CargaAplazable` y `CargaCritica`, incluida su herencia y polimorfismo.
- `Negocio`, `Medidor` y `Mercado`, con composición, agregación y asociación.
- El namespace `config`, la función libre `generarReporteConsumo` y el punto de entrada `main()`.

El diagrama representa el diseño estructural; las reglas de simulación y los umbrales permanecen documentados en [`DECISIONES.md`](../02-tecnico/DECISIONES.md).
