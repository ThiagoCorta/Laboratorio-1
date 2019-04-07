#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    float resultado;

    printf("Ingresar la base de un triangulo: ");
    fflush(stdin);
    scanf("%d", &base);

    printf("Ingresar la altura de un triangulo: ");
    fflush(stdin);
    scanf("%d", &altura);

    resultado=(float)base * (altura/2);

    printf("La superficie del triangulo es : %.2f", resultado);





    return 0;
}
