#!/bin/bash
echo "Iniciando bash..."
/home/albertholto/Sistemas-operativos/PCL/Proyectos/P02/A02.3/salida_cifrada > para_descifrar
./descifrador < para_descifrar salida_descifrada
rm para_descifrar
echo "Resultado exitoso"
