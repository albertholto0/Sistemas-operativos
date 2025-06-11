#!/bin/bash

# Configuración
BASE_DIR="/home/albertholto/Sistemas-operativos/PCL/Proyectos/P03/A03.1"
LOG_FILE="ejecucion_paralela.log"
PROGRAMS=("sim_C02" "sim_H20" "sim_pos")

# Iniciar registro
echo "Inicio de ejecución paralela - $(date)" > "$LOG_FILE"
start_time=$(date +%s.%N)

# Archivos temporales para los resultados de time
TIME_FILES=()
for program in "${PROGRAMS[@]}"; do
    temp_file=$(mktemp)
    TIME_FILES+=("$temp_file")
    /usr/bin/time -v "$BASE_DIR/$program" 2> "$temp_file" &
done

# Esperar a que todos los procesos terminen
wait

# Registrar resultados
for i in "${!PROGRAMS[@]}"; do
    echo -e "\n=== Resultados de ${PROGRAMS[$i]} ===" >> "$LOG_FILE"
    cat "${TIME_FILES[$i]}" >> "$LOG_FILE"
    rm "${TIME_FILES[$i]}"
done

# Calcular tiempo total
end_time=$(date +%s.%N)
elapsed_time=$(echo "$end_time - $start_time" | bc)

# Resumen final
echo -e "\n=== RESUMEN FINAL ===" | tee -a "$LOG_FILE"
echo "Tiempo total de ejecución paralela: $elapsed_time segundos" | tee -a "$LOG_FILE"
echo "Uso máximo de memoria por programa:" | tee -a "$LOG_FILE"
grep "Maximum resident set size" "$LOG_FILE" | tee -a "$LOG_FILE"

echo "Ejecución paralela completada. Detalles en $LOG_FILE"
