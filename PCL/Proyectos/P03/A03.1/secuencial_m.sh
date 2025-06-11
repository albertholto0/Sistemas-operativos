#!/bin/bash

# Configuración
BASE_DIR="/home/albertholto/Sistemas-operativos/PCL/Proyectos/P03/A03.1"
LOG_FILE="ejecucion_secuencial.log"
PROGRAMS=("sim_C02" "sim_H20" "sim_pos")

# Iniciar registro
echo "Inicio de ejecución secuencial - $(date)" > "$LOG_FILE"
start_time=$(date +%s.%N)

# Ejecutar cada programa secuencialmente
for program in "${PROGRAMS[@]}"; do
    echo -e "\n=== Ejecutando $program ===" | tee -a "$LOG_FILE"
    /usr/bin/time -v "$BASE_DIR/$program" 2>> "$LOG_FILE"
done

# Calcular tiempo total
end_time=$(date +%s.%N)
elapsed_time=$(echo "$end_time - $start_time" | bc)

# Resumen final
echo -e "\n=== RESUMEN FINAL ===" | tee -a "$LOG_FILE"
echo "Tiempo total de ejecución: $elapsed_time segundos" | tee -a "$LOG_FILE"
echo "Uso máximo de memoria:" | tee -a "$LOG_FILE"
grep "Maximum resident set size" "$LOG_FILE" | tee -a "$LOG_FILE"

echo "Ejecución secuencial completada. Detalles en $LOG_FILE"
