#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool checkArgs(int argc, char **argv);
// verifica os parâmetros da função main

int main(int argc, char **argv){
    if(!checkArgs(argc, argv)){
        printf("Argumentos inválidos.\n");

        return 1;
    }else printf("Argumentos válidos.\n");

    return 0;
}

bool checkArgs(int argc, char **argv){
// verifica os parâmetros da função main
    if(argc < 3){
        fprintf(stderr, "Argumentos insuficientes.\n"
                        "Uso: ./2178 <mínimo> <máximo>");

        return false;
    }else if(argc > 3){
        fprintf(stderr, "Argumentos excedentes.\n"
            "Uso: ./2178 <mínimo> <máximo>");

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