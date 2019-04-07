#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int numero1;
    int numero2;
    int producto;
    int cuadrado;

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &numero1);

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &numero2);

    producto=numero1*numero2;

    cuadrado= 1 + pow(numero1, 2);

    system("cls");

    printf("El producto de ambos numeros ingresados es : %d \n", producto);
    printf("El cuadrado del primer numero es : %d\n", cuadrado);


    return 0;
}
