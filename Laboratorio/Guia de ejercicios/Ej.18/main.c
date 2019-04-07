#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    int acumuladorP=0;
    int productoN=1;

    for(contador=0;contador<=10;contador++)
    {
        printf("Ingresar un numero: \n");
        fflush(stdin);
        scanf("%d", &numero);

        while(numero==0)
        {
            printf("Error, ingresar un numero: \n");
            fflush(stdin);
            scanf("%d", &numero);
        }

        if(numero>0)
        {
            acumuladorP=acumuladorP+numero;
        }
        else
        {
            productoN=productoN*numero;
        }
    }

    printf("La suma de los numeros positivos es : %d\n", acumuladorP);
    printf("El producto de los numeros negativos es : %d", productoN);
    return 0;
}
