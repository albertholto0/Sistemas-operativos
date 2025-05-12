#!/bin/bash
echo "Iniciando bash..."
./stee < ~/PCL/dev/CO2 | ../A02.2/./FCMCPV > para_cifrar
./cencriptador < para_cifrar salida_cifrada
rm para_cifrar
echo "Resultado exitoso"
