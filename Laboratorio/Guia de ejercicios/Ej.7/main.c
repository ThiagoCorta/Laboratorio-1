#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

int main()
{
    float radio;
    float circunferencia;
    float area;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    circunferencia=2*pi*radio;
    area=pi*(radio*radio);

    printf("Circunferencia: %.2f\n", circunferencia);
    printf("Area: %.2f", area);

    return 0;
}
