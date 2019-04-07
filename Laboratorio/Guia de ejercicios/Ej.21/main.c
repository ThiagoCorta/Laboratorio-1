#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorMultiplos=0;

    printf("Ingresar un numero: ");
    scanf("%d", &numero);

    for(;numero>0;numero--)
    {
        if(numero%3==0)
        {
            contadorMultiplos++;
            printf("El numero: %d es multiplo de 3. \n", numero);
        }

    }

    printf("La cantidad de multiplos de 3 es: %d", contadorMultiplos);
    return 0;
}
