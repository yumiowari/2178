#!/bin/bash

echo "Compilando código-fonte..."

gcc problem.c -o problem
gcc solution.c -o solution

echo
echo "Gerando bateria de testes..."

rm -rf battery
mkdir -p battery/in battery/out

for i in $(seq 1 998); do
    echo "$RANDOM" | ./problem "battery/in/$i" "battery/out/$i"
done

echo "-2147483648" | ./problem "battery/in/999" "battery/out/999"
echo "2147483647"  | ./problem "battery/in/1000" "battery/out/1000"

echo
echo "Procedimento concluído."
