#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero1;
   int numero2;
   int resta;

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &numero1);

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &numero2);

    resta=numero1-numero2;

    system("cls");

    if(resta>0)
    {
        printf("Resultado positivo: %d", resta);
    }
    else
    {
        printf("Resultado negativo: %d", resta);
    }


    return 0;
}
