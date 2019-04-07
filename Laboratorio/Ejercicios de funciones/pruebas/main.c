#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
int buscarEntero(int numIng, int vec[], int tam);

int main()
{
    int auxInt;
    int legajoIng;
    int legajos[TAM]= { 1233, 2345, 6543, 7864, 6578, 5555, 1111, 1115, 2588, 9845};
    int notas1[TAM]= { 5, 7, 8, 3, 5, 6,8, 8, 9, 10};
    int notas2[TAM] = { 9, 5, 2, 9,5, 4, 2, 3, 8, 9};
    float auxFloat;
    float promedios[TAM] = { 7, 6, 5, 6, 5, 8, 10, 9, 9, 9 };
    char auxChar;
    char sexos[TAM] = { 'f', 'f', 'm', 'f', 'm','f', 'f', 'm', 'f', 'm'};
    int i;


    printf("Ingrese legajo: ");
    scanf("%d", &legajoIng);
    i = buscarEntero(legajoIng, legajos, TAM);
    if( i == -1){
        printf("\nEl legajo %d no esta registrado en el sistema\n\n", legajoIng);
    }
    else{
    printf(" %d    %c    %d    %d      %.2f\n", legajos[i], sexos[i], notas1[i], notas2[i], promedios[i] );
    }




}


int buscarEntero(int numIng, int vec[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {
        if( numIng == vec[i])
        {
            indice = i;
            break;
        }
    }

    return indice;

}
