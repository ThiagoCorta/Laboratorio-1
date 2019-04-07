#include <stdio.h>
#include <stdlib.h>

int main()
{
    int importe;
    int vendedor;
    int contador;
    int acumulador1=0;
    int acumulador2=0;
    int acumulador3=0;
    float comision1;
    float comision2;
    float comision3;
    char seguir;

    do
    {
        printf("Ingresar el vendedor sea 1, 2 o 3 : ");
        fflush(stdin);
        scanf("%d", &vendedor);

        while(vendedor<0 || vendedor>3)
        {
            printf("Error, ingresar vendedor valido sea 1, 2 o 3: ");
            fflush(stdin);
            scanf("%d", &vendedor);
        }

        printf("Ingresar el importe: ");
        fflush(stdin);
        scanf("%d", &importe);

        switch(vendedor)
        {
            case 1:
                acumulador1=acumulador1+importe;
                break;

            case 2:
                acumulador2=acumulador2+importe;
                break;

            case 3:
                acumulador3=acumulador3+importe;
                break;

        }

        printf("Para ingresar otro empleado ingrese s...");
        fflush(stdin);
        seguir=tolower(seguir);
        scanf("%c", &seguir);

    }while(seguir=='s');

    comision1=acumulador1*0.05;
     comision2=acumulador2*0.05;
      comision3=acumulador3*0.05;

    printf("Comision vendedor 1: %.2f\n", comision1);
    printf("Comision vendedor 2: %.2f\n", comision2);
    printf("Comision vendedor 3: %.2f", comision3);

}
