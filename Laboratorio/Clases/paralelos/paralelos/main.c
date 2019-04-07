#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void ordenarAlumnos( int leg[], int n1[], int n2[], char sex[], float prom[], int tam );

int main()
{
   int auxInt;
   int legajos[TAM]= { 1233, 2345, 6543, 7864, 6578};
   int notas1[TAM]= { 5, 7, 8, 3, 5 };
   int notas2[TAM] = { 9, 5, 2, 9,5};
   float auxFloat;
   float promedios[TAM] = { 7, 6, 5, 6, 5 };
   char auxChar;
   char sexos[TAM] = { 'f', 'f', 'm', 'f', 'm'};


  /* for( int i= 0; i < TAM; i++){

        printf("\nIngrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese nota Parcial 1: ");
        scanf("%d", &notas1[i]);

        printf("Ingrese nota Parcial 2: ");
        scanf("%d", &notas2[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);
for(int i=0; i < 4; i++){
    for(int j= i+1; j < 5; j++ ){
        if( vec[i] < vec[j]){
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
        }
    }
        promedios[i] = (float) (notas1[i] + notas2[i]) / 2;

   }*/

   printf("*** Listado de Alumnos ***\n\n");
   printf("Legajo Sexo Nota1  Nota2  Promedio\n\n");


    for( int i= 0; i < TAM; i++){

        printf(" %d    %c    %d    %d      %.2f\n", legajos[i], sexos[i], notas1[i], notas2[i], promedios[i] );
    }

    printf("\n\n");


        ordenarAlumnos(legajos, notas1, notas2, sexos, promedios, TAM);


    printf("**** Listado ordenado por Promedio ****\n\n");
     printf("Legajo Sexo Nota1  Nota2  Promedio\n\n");


    for( int i= 0; i < TAM; i++){

        printf(" %d    %c    %d    %d      %.2f\n", legajos[i], sexos[i], notas1[i], notas2[i], promedios[i] );
    }

    printf("\n\n");




    return 0;
}


void ordenarAlumnos( int leg[], int n1[], int n2[], char sex[], float prom[], int tam ){

int auxInt;
char auxChar;
float auxFloat;

for(int i=0; i < tam - 1; i++){
    for(int j= i+1; j < tam; j++ ){
        if( sex[i] < sex[j]){

            auxInt = leg[i];
        leg[i] = leg[j];
        leg[j] = auxInt;

            auxInt = n1[i];
         n1[i] = n1[j];
         n1[j] = auxInt;

          auxInt = n2[i];
         n2[i] = n2[j];
         n2[j] = auxInt;

          auxChar = sex[i];
          sex[i] = sex[j];
          sex[j] = auxChar;

         auxFloat = prom[i];
         prom[i] = prom[j];
         prom[j] = auxFloat;


        }
    }
    }








}


