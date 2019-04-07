#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[20];
    char apellido[25];
    char nombreCompleto[50];
    int contador=0;


   printf("Ingresar su nombre : ");
    gets(nombre);

    printf("Ingresar el apellido : ");
    gets(apellido);


    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, ", " );
    strcat(nombreCompleto,nombre);
    nombreCompleto[0]=toupper(nombreCompleto[0]);


    while(nombreCompleto[contador] != '\0')
    {
            if(nombreCompleto[contador] == ' ')
                {
                    nombreCompleto[contador+1] = toupper(nombreCompleto[contador+1]);
                }
                contador++;
    }



    printf("%s", nombreCompleto);


    return 0;
}
