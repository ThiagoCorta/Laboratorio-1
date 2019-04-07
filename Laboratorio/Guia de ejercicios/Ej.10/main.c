#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorImpares=0;

    for(numero=0;numero<=100;numero++)
    {
        if(numero%2!=0)
        {
            contadorImpares++;
            printf("Numero impar: %d\n", numero);
        }
    }

    printf("Cantidad de impares: %d", contadorImpares);


    return 0;
}
