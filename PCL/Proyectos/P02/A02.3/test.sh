#!/bin/bash
echo "Iniciando bash..."
./stee < /home/albertholto/Sistemas-operativos/PCL/dev/CO2 | /home/albertholto/Sistemas-operativos/PCL/Proyectos/P02/A02.3/./MCPV > para_cifrar
./cencriptador < para_cifrar salida_cifrada
rm para_cifrar
echo "Resultado exitoso"
