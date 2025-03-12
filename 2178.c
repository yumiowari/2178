#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool debug = false;

bool checkArgs(int argc, char **argv);
// verifica os parâmetros da função main

int main(int argc, char **argv){
    if(!checkArgs(argc, argv)){
        printf("Argumentos inválidos.\n");

        return 1;
    }else printf("Argumentos válidos.\n");

    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    if(min == 0 || max == 0){
        fprintf(stderr, "Somente valores positivos são válidos.\n");

        return 1;
    }else if(min >= max){
        fprintf(stderr, "O valor mínimo deve ser menor que o valor máximo.\n");

        return 1;
    }

    int R = 0, S = 0; // somatórios
    int p, q;         // potências
    int a;            // auxiliar
    int y;            // cópia de x
    int z;            // cópai de y
    int i;            // inversão de y

    printf("Iniciando o procedimento...\n");
    for(int x = min; x <= max; x++){
    // calcula o somatório de iterações terminadas em zero e iterações terminadas em repetição

        y = x;
        while(
              y != 0          &&
              y != 2178       &&
              y != 21978      &&
              y != 219978     &&
              y != 2199978    &&
              y != 21999978   &&
              y != 219999978  &&
              y != 2199999978
             ){

            p = 1;
            while(y / p != 0){
            // calcula a quantidade de dígitos em y
        
                p *= 10;
            }
            p /= 10;

            z = y;
            i = 0;
            q = 1;
            while(p > 0){
            // inverte z e armazena em i

                a = z / p;
                z -= a * p;
                i += a * q;

                p /= 10;
                q *= 10;
            }
            if(debug)printf("%d - %d = %d\n", y, i, y - i);
            y -= i;
        }

        if(y == 0){
            S++;
        }else{
            R++;
        }
    }

    printf("Quantidade de iterações: %d\n"
           "    Terminadas em zero: %d\n"
           "    Terminadas em repetição: %d\n", S + R,
                                            S,
                                            R);

    return 0;
}

bool checkArgs(int argc, char **argv){
// verifica os parâmetros da função main
    if(argc < 3){
        fprintf(stderr, "Argumentos insuficientes.\n"
                        "Uso: ./2178 <número mínimo> <número máximo>\n");

        return false;
    }else if(argc > 3){
        if(argc > 4){
            fprintf(stderr, "Argumentos excedentes.\n"
                            "Uso: ./2178 <número mínimo> <número máximo>\n");
        }else if(argv[3][0] == '-'){
            if(
               strcmp(argv[3], "-debug") == 0 ||
               strcmp(argv[3], "-d") == 0
              ){
                printf("Modo de depuração ativado.\n");

                debug = true;
              }else{
                fprintf(stderr, "Parâmetro opcional inválido.\n"
                                "Uso: ./2178 <número mínimo> <número máximo> -debug\n");

                return false;
              }

            return true;
        }else{
            fprintf(stderr, "Argumentos excedentes.\n"
                            "Uso: ./2178 <número mínimo> <número máximo>\n");
        }

        return false;
    }else{
        for(int i = 0; i < strlen(argv[1]); i++){
            if(!isdigit(argv[1][i])){
                fprintf(stderr, "O valor mínimo deve ser um número inteiro.\n");

                return false;
            }
        }

        for(int i = 0; i < strlen(argv[2]); i++){
            if(!isdigit(argv[2][i])){
                fprintf(stderr, "O valor máximo deve ser um número inteiro.\n");

                return false;
            }
        }

        return true;
    }
}