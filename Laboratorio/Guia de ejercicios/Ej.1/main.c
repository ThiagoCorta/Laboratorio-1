#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    int numeros;
    int acumulador=0;
    float promedio;


    for(contador=0;contador<5;contador++)
    {
        printf("Ingresar un numero: ");
        fflush(stdin);
        scanf("%d", &numeros);

        acumulador=acumulador+numeros;

    }

    promedio=(float)acumulador/contador;
    printf("El promedio de los numeros ingresado es: %.2f", promedio);

    return 0;
}
