#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numero1;
    int cuadrado;


    printf("Ingresar un numero: ");
    scanf("%d", &numero1);

    while(numero1<=0)
    {
        printf("Error, ingresar un numero: ");
        scanf("%d", &numero1);
    }

    cuadrado=1+pow(numero1,2);

    system("cls");

    printf("El cuadrado del numero ingresado es: %d", cuadrado);

    return 0;
}
