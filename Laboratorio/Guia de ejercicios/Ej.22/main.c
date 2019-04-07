#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;

    printf("Ingresar un numero: ");
    fflush(stdin);
    scanf("%d", &num1);

    printf("Ingresar otro numero: ");
    fflush(stdin);
    scanf("%d", &num2);

    system("cls");
    printf("El primer numero ingresado es %d y el segundo numero ingresado es %d", num2,num1);


}
