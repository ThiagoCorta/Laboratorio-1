#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int suma=0;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    for(numero=numero-1;numero>0;numero--)
    {
        suma=suma+numero;
    }

    printf("El resultado de la suma de todos los numeros que lo anteceden es : %d", suma);
}
