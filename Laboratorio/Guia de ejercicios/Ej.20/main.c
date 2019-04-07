#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Ingresar un numero: ");
    scanf("%d", &numero);

    for(numero=numero-1;numero>0;numero--)
    {
        printf("Numero: %d \n", numero);
    }
    return 0;
}
