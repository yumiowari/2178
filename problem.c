#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    long p, q,         // potências
         a,            // auxiliar
         x,            // valor inicial
         y,            // cópia de x
         z,            // cópia de y
         i;            // inversão de y
    
    scanf("%ld", &x);

    FILE *f = fopen(argv[1], "w+");

    fprintf(f, "%ld\n", x);

    fclose(f);

    y = x;
    while(y != 0          &&
          y != 2178       &&
          y != 21978      &&
          y != 219978     &&
          y != 2199978    &&
          y != 21999978   &&
          y != 219999978  &&
          y != 2199999978){
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
        y -= i;
    }

    printf("%ld\n", y);

    f = fopen(argv[2], "w+");

    fprintf(f, "%ld\n", y);

    fclose(f);

    return 0;
}