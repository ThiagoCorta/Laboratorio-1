#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador;
    int numeroMayor;

    for(contador=0;contador<3;contador++)
    {
        printf("Ingresar un numero: ");
        fflush(stdin);
        scanf("%d", &numero);

        if(contador==1)
        {
            numeroMayor=numero;
        }
        else
        {
            if(numero>numeroMayor)
            {
                numeroMayor=numero;
            }
        }
    }

    system("cls");

    printf("El numero mayor entre los 3 ingresados es : %d", numeroMayor);
    return 0;
}
