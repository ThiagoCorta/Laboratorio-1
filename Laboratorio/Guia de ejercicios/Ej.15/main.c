#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorMultiplos=0;

    for(numero=0;numero<=100;numero++)
    {
        if(numero%6==0 && numero!=0)
        {
            contadorMultiplos++;
            printf("Numero multiplo de 6: %d \n", numero);
        }
    }
    printf("Cantidad de multiplos: %d", contadorMultiplos);


    return 0;
}
