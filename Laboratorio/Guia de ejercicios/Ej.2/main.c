#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int suma;

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &numero1);

    printf("Ingresar otro numero: ");
    fflush(stdin);
    scanf("%d", &numero2);

    suma=numero1+numero2;

    printf("La suma de ambos numeros es : %d", suma);
    return 0;
}
