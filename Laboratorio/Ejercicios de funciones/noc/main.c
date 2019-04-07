#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

void ordenarAlumnos( int leg[], int n1[], int n2[], char sex[], float prom[], int tam );
void ordenarNombre(char nombre[], char apellido[],char nombreCompleto[]);
int main()
{

char nombre[20];
char apellido[20];
char nombreCompleto[50];


   printf("Ingresar su nombre : ");
    gets(nombre);

    printf("Ingresar el apellido : ");
    gets(apellido);



    ordenarNombre(nombre,apellido,nombreCompleto);

    printf("%s",nombreCompleto);










}


void ordenarAlumnos( int leg[], int n1[], int n2[], char sex[], float prom[], int tam )
{

    int auxInt;
    char auxChar;
    float auxFloat;

    for(int i=0; i < tam - 1; i++)
    {
        for(int j= i+1; j < tam; j++ )
        {
            if( sex[i] > sex[j])
            {

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
            else
            {
                if(sex[i]==sex[j] && leg[i]>leg[j])
                {
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
}

void ordenarNombre(char nombre[], char apellido[],char nombreCompleto[])
{


    int i=0;

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, ", " );
    strcat(nombreCompleto,nombre);
    nombreCompleto[0]=toupper(nombreCompleto[0]);


    while(nombreCompleto[i] != '\0')
    {
            if(nombreCompleto[i] == ' ')
                {
                    nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
                }
                i++;
    }

}

