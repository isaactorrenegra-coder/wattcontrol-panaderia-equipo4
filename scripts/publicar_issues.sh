#!/usr/bin/env bash
# Ejecutar una vez DESPUES de publicar el repo: bash scripts/publicar_issues.sh USUARIO/REPO
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
if ! command -v gh >/dev/null 2>&1; then
  echo "Falta GitHub CLI (gh). Instala gh y ejecuta gh auth login." >&2; exit 1
fi
if ! gh auth status >/dev/null 2>&1; then
  echo "Inicia sesion con: gh auth login" >&2; exit 1
fi
if [ "${1:-}" != "" ]; then
  REPO="$1"
else
  REPO="$(gh repo view --json nameWithOwner --jq '.nameWithOwner')"
fi
if [ -z "$REPO" ]; then
  echo "No se pudo determinar repositorio. Indica USUARIO/REPO." >&2; exit 1
fi

gh label create integrante-1 -R "$REPO" --color "0969DA" --description "Responsable: configuracion y jerarquia de cargas" --force
gh label create integrante-2 -R "$REPO" --color "1A7F37" --description "Responsable: Mercado, Medidor y potencia" --force
gh label create integrante-3 -R "$REPO" --color "8250DF" --description "Responsable: menu, simulacion y reporte" --force
gh label create integrante-4 -R "$REPO" --color "BF3989" --description "Responsable: UML, registro de consumo y pruebas" --force
gh label create modelo -R "$REPO" --color "DDEEFF" --description "POO y configuracion" --force
gh label create negocio -R "$REPO" --color "D6F2DB" --description "Logica del negocio y medicion" --force
gh label create interfaz -R "$REPO" --color "F3E6FF" --description "Menu y entradas" --force
gh label create simulacion -R "$REPO" --color "FFF2CC" --description "Simulacion y reportes" --force
gh label create documentacion -R "$REPO" --color "EAEAEA" --description "UML, pruebas, entrega" --force

EXISTENTES="$(gh issue list -R "$REPO" --state all --limit 1000 --json title --jq '.[].title')"
CREADAS=0
OMITIDAS=0
while IFS='|' read -r slug titulo responsable area archivo; do
  [ "$slug" = "slug" ] && continue
  [ -z "$slug" ] && continue
  if printf '%s\n' "$EXISTENTES" | grep -Fxq "$titulo"; then
    echo "Ya existe: $titulo"
    OMITIDAS=$((OMITIDAS + 1))
    continue
  fi
  gh issue create -R "$REPO" --title "$titulo" \
      --body-file "$ROOT/.github/issue-data/$archivo" \
      --label "$responsable" --label "$area"
  CREADAS=$((CREADAS + 1))
done < "$ROOT/.github/issue-data/manifest.psv"
echo "Listo: $CREADAS issues nuevas; $OMITIDAS ya existian. Repositorio: $REPO"
