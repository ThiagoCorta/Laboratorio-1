#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    int contadorP=0;
    int contadorN=0;

    for(contador=0;contador<10;contador++)
    {
        printf("Ingresar un numero: \n");
        fflush(stdin);
        scanf("%d", &numero);

        if(numero>0)
        {
            contadorP++;
        }
        else
        {
            contadorN++;
        }
    }

    system("cls");

    printf("La cantidad de numeros Positivos ingresados: %d \n", contadorP);
    printf("La cantidad de numeros Negativos ingresados: %d", contadorN);

    return 0;
}
