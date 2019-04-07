#include <stdio.h>
#include <stdlib.h>

int main()
{

    char seguir;

    do
    {
        printf("Ingresar S o N para seguir...");
        fflush(stdin);
        scanf("%c", &seguir);

        while(seguir!='S' && seguir!='N')
        {
            printf("Error, ingresar S o N para seguir...");
            fflush(stdin);
            scanf("%c", &seguir);
        }

    }while(seguir=='S');
}
