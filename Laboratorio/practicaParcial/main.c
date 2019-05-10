#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include <conio.h>
#include "Autores.h"
#include "libros.h"
#include "socios.h"
#include <ctype.h>
#include "prestamos.h"

#define TAM 1000
#define TAMAu 1000
#define TAMP 1000
#define TAML 1000

void pedirFecha(int* dia, int* mes, int* anio);
int menuAbm();



int main ()
{

    int seguir='s';
    eSocios socios[TAM];
    ePrestamos prestamos[TAMP];
    eAutor autores[TAMAu];
    eLibros libros[TAML];

    initAutor(autores,TAMAu);
    initLibro(libros,TAML);
    initSocios(socios,TAM);
    initPrestamos(prestamos,TAMP);
    hardCodearAutores(autores,21);
    hardCodearLibros(libros,21);

    do
    {

        switch(menuAbm())
        {
            case 1:
                funcAutores(autores,TAMAu);
                system("pause");
                break;
            case 2:
                funcLibros(libros,TAML,autores,TAMAu);
                system("pause");
                break;
            case 3:
                funcSocios(socios,TAM);
                system("pause");
                break;
            case 4:
                funcPrestamos(prestamos,TAMP,libros,TAML,socios,TAM);
                system("pause");
                break;
            case 5:
                seguir='n';
                break;

        }
    }while(seguir=='s');
}





int menuAbm()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU ABM PARCIAL**************|\n");
    printf("\n 1- Autores:\n");
    printf(" 2- Libros:\n");
    printf(" 3- Socios:\n");
    printf(" 4- Prestamos \n");
    printf(" 5- Salir:");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}



















