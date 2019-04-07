#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "corta.h"


int obtenerMaximo (int x, int y, int z)
{
   int max;

   max=x;

    if(y>max && y>z)
    {
        max=y;
    }
    else
    {
        if(z>max)
        {
            max=z;
        }

    }

    return max;
}

int mostrarMenu()
{
    int opcion;




    printf("3- Calcular todas las operaciones.: \n");
    printf("4- Informar resultados. : \n");
    printf("5- Salir.\n");
    scanf("%d", &opcion);

    return opcion;

}

int thiagoSuma(int x, int y)
{

    return x + y;

}

int thiagoResta(int x, int y)
{

    return x - y;

}

float thiagoDivide(int x, int y)
{
    float division;
    division= (float) x / y;
    return division;
}

int thiagoMultiplica(int x, int y)
{

    return x*y;
}


double thiagoFactorial(int x)
{
   double factorial=1;

    for(;x>1;x--)
    {
        factorial=factorial*x;
    }
    return factorial;
}

int menuOperaciones()
{

    int opcion;

    system("cls");

    printf("1- Calcular la suma. (A+B): \n");
    printf("2- Calcular la resta. (A-B): \n");
    printf("3- Calcular la division. (A/B): \n");
    printf("4- Calcular la multiplicacion. (A*B): \n");
    printf("5- Calcular el factorial. (A!): \n");
    printf("6- Volver al menu principal.\n");
    scanf("%d", &opcion);

    return opcion;

}

void pedirSexo(char sexo[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        system("cls");
        printf("Ingrese el sexo Nro#%d : \n",i);
        fflush(stdin);
        sexo[i]=getchar();
        sexo[i]=tolower(sexo[i]);

        while(sexo[i]!='f' && sexo[i]!='m')
        {
            printf("Error, ingrese sexo valido  : \n", i);
            fflush(stdin);
            sexo[i]=getchar();
            sexo[i]=tolower(sexo[i]);
        }
    }

}

void pedirEdad(int edad[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese edad NRO : #%d : ", i);
        scanf("%d", &edad[i]);

        while(edad[i]<0 || edad[i]>110){
            printf("Error ingrese edad valida: ", i);
            scanf("%d", &edad[i]);
        }
    }
}




void pedirNomApe(char nomApe[][50], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese nombre y apellido NRO: %d : \n", i);
        fflush(stdin);
        gets(nomApe[i]);
        strlwr(nomApe[i]);
        nomApe[i][0]=toupper(nomApe[i][0]);


        for(int j=0;j<50;j++)
        if(nomApe[i][j] != '\0')
        {
            if(nomApe[i][j] == ' ')
                {
                    nomApe[i][j+1] = toupper(nomApe[i][j+1]);
                }

        }


    }
}

void pedirLegajos(int legajos[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese legajo NRO : #%d : ", i);
        scanf("%d", &legajos[i]);

        while(legajos[i]<1000 || legajos[i]>9999){
            printf("Ingrese legajo valido : ", i);
            scanf("%d", &legajos[i]);
        }
    }
}

void duplicarVector(int vector[], int tam){

    int i;

    for(i=0 ; i<tam ; i++){
        vector[i]*=2;
    }
}

void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam)
{

    int auxInt;
    char auxChar;
    char auxString[50];
    float auxFloat;



    for(int i=0; i < tam - 1; i++)
    {
        for(int j= i+1; j < tam; j++ )
        {
            if( vectorSex[i] > vectorSex[j])
            {

                auxInt = vector[i];
                vector[i] = vector[j];
                vector[j] = auxInt;

                auxInt = vector2[i];
                vector2[i] = vector2[j];
                vector2[j] = auxInt;

                auxInt = vector3[i];
                vector3[i] = vector3[j];
                vector3[j] = auxInt;

                auxChar = vectorSex[i];
                vectorSex[i] = vectorSex[j];
                vectorSex[j] = auxChar;

                auxInt = vector4[i];
                vector4[i] = vector4[j];
                vector4[j] = auxInt;

               auxFloat = vectorFloat[i];
               vectorFloat[i] = vectorFloat[j];
               vectorFloat[j] = auxFloat;

                strcpy(auxString, nomApe[i]);
                strcpy(nomApe[i], nomApe[j]);
                strcpy(nomApe[j], auxString);


            }
            else
            {
                if(vectorSex[i]==vectorSex[j] && vector[i]>vector[j])
                {
                    auxInt = vector[i];
                    vector[i] = vector[j];
                    vector[j] = auxInt;

                    auxInt = vector2[i];
                    vector2[i] = vector2[j];
                    vector2[j] = auxInt;

                    auxInt = vector3[i];
                    vector3[i] = vector3[j];
                    vector3[j] = auxInt;

                    auxChar = vectorSex[i];
                    vectorSex[i] = vectorSex[j];
                    vectorSex[j] = auxChar;

                  auxFloat = vectorFloat[i];
                    vectorFloat[i] = vectorFloat[j];
                    vectorFloat[j] = auxFloat;

                    auxInt = vector4[i];
                    vector4[i] = vector4[j];
                    vector4[j] = auxInt;

                    strcpy(auxString, nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], auxString);

                }

            }

        }
    }
}





