#!/bin/bash
echo "Iniciando bash..."

./stee para_cifrar < /home/albertholto/Sistemas-operativos/PCL/dev/CO2 | /home/albertholto/Sistemas-operativos/PCL/Proyectos/P02/./MCPV
/home/albertholto/Sistemas-operativos/PCL/Proyectos/P02/A02.3/./cencriptador < para_cifrar salida_cifrada
rm para_cifrar


