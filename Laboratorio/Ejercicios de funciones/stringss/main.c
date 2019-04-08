#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM 5


void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam);
void pedirNomApe(char nomApe[][50], int tam);
void pedirSexo(char sexo[], int tam);
void pedirLegajos(int legajos[], int tam);

int main()
{

    char nombreApellido[TAM][50]= {"Diego tomas","Aiego tomas","Aawea culia", "Aose qponer", "Aose denuevo"};
    char sexo[TAM]= {'f','m','m','f','m'};
    int legajos[TAM]= {8000,3000,5000,1845,2568};
    int edad[TAM]= {11,15,16,18,20};
    int notas1[TAM]= { 5, 7, 8, 3, 5 };
    int notas2[TAM] = { 9, 5, 2, 9,5};
    float auxFloat;
    float promedios[TAM] = { 7, 6, 5, 6, 5 };
    char auxChar;



    //  pedirNomApe(nombreApellido,TAM);
    // pedirLegajos(legajos,TAM);
    // pedirSexo(sexo,TAM);
    // pedirEdad(edad,TAM);

    printf("*** Listado de Alumnos ***\n\n");
    printf("Legajo Sexo Nota1  Nota2  Promedio\n\n");

    for(int i=0; i<TAM ; i++)
    {

        printf("%s     %d    %c    %d    %d    %d    %.2f  \n", nombreApellido[i], legajos[i], sexo[i], edad[i], notas1[i],notas2[i],promedios[i]);
    }

    ordenarVectores(legajos,notas1,notas2,sexo,promedios,nombreApellido,edad,TAM);

    printf("\nAhora ordenados ndeaaa\n\n");

    printf("*** Listado de Alumnos ***\n\n");
    printf("Legajo Sexo Nota1  Nota2  Promedio\n\n");

    for(int i=0; i<TAM ; i++)
    {

        printf("%s     %d    %c    %d    %d    %d    %.2f  \n", nombreApellido[i], legajos[i], sexo[i], edad[i], notas1[i],notas2[i],promedios[i]);
    }


}

/*
void mostrarVectores(char nomApe[][20], int legajos[], int notas[], int notas2[], float promedios[], char sexos[], int tam){

    printf("\n\tSex\tNom y ape\tLegajos\tNotas\tNotas2\tProm");
    for(int i=0 ; i<tam ; i++){
        printf("\n\t%c\t%s\t%d\t%d\t%d\t%.2f", sexos[i], nomApe[i], legajos[i], notas[i], notas2[i], promedios[i]);
    }
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





*/

/*void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam)
{

    int auxInt;
    char auxChar;
    char auxString[tam][50];
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

                strcpy(auxString[0], nomApe[i]);
                strcpy(nomApe[i], nomApe[j]);
                strcpy(nomApe[j], auxString[0]);


            }
            else
            {
               if(vectorSex[i]==vectorSex[j] && (stricmp(nomApe[i], nomApe[j])==1))
            {

                    strcpy(auxString[0], nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], auxString[0]);

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
                }


            }
        }

    }

}

*/


