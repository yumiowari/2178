#!/bin/bash

echo "Compilando código-fonte..."

g++ problem.cpp -o problem

echo
echo "Gerando bateria de testes..."

rm -rf battery
mkdir -p battery/in battery/out

for i in $(seq 1 98); do
    echo "$RANDOM" > battery/in/$i

    ./problem  < battery/in/$i > battery/out/$i
done

echo "-2147483648" > battery/in/99
./problem < battery/in/99 > battery/out/99

echo "2147483647" > battery/in/100
./problem < battery/in/100 > battery/out/100

echo
echo "Procedimento concluído."
