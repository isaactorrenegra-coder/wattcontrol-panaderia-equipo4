#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude wattcontrol.cpp src/*.cpp -o wattcontrol
echo "Compilacion correcta (estructura). Metodos TODO aun pendientes."
