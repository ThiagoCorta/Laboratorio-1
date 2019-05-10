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

void initPrestamos(ePrestamos* list, int len)
{
    for(int i=0; i<len;i++)
    {
        list[i].isEmpty=0;
    }
}


int idPrestamo()
{
    static int id  = 9999;
    id++;
    return id;

}

int findEmptySlotPrestamo(ePrestamos* list, int len)
{
    int indice=-1;

    for(int i =0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            indice=i;
        }
    }

    return indice;
}
int altaPrestamo(ePrestamos* list, int len, eLibros* libros, int tamL, eSocios* socios, int tams)
{
    int indice ;
    int todoOk=-1;
    int idSocio;
    int idLibro;
    int dia, mes, anio;

    indice=findEmptySlotPrestamo(list,len);

    if(indice != -1)
    {
        list[indice].idPrestamo=idPrestamo();
        printLibros(libros,tamL);
        utn_getEntero(&idLibro,20,"\n Ingresar ID del libro. : \n\n ", "\nError, ingresar ID libro valido",0,tamL);
        while(findLibroById(libros,tamL,idLibro)==-1)
        {
            utn_getEntero(&idLibro,20,"\n Ingresar ID del libro. : \n\n ", "\nError, ingresar ID libro valido",0,tamL);
        }
        list[indice].idLibro=idLibro;


        printSocios(socios,tams);

        utn_getEntero(&idSocio,20,"\n Ingresar ID del socio que solicia el prestamo. : \n\n ", "\nError, ingresar ID socio valido",0,tams);

        while(findSocioById(socios,tams,idSocio)==-1)
        {
             utn_getEntero(&idSocio,20,"\n Ingresar ID del socio que solicia el prestamo. : \n\n ", "\nError, ingresar ID socio valido",0,tams);
        }

        list[indice].idSocio=idSocio;


        pedirFecha(&dia,&mes,&anio);

        list[indice].fechaPrestamo.dia=dia;
        list[indice].fechaPrestamo.mes=mes;
        list[indice].fechaPrestamo.anio=anio;


        list[indice].isEmpty=1;

        printf("\nPrestamo cargado con exito \n\n.");

        todoOk=0;
    }
    else
    {
        printf("\n\nNo hay mas espacio para nuevos Prestamos. \n\n");
    }

    return todoOk;

}

void printPrestamo(ePrestamos list)
{
    printf("%5d %12d %12d %10d %7.02d/%02d/%4d  \n", list.idPrestamo, list.idSocio,list.idLibro,list.fechaPrestamo.dia,list.fechaPrestamo.mes,list.fechaPrestamo.anio);
}


void printPrestamos(ePrestamos* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %10s %15s  \n", "ID", "IDSOCIO", "IDLIBRO", "Fecha prestamo");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printPrestamo(list[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay prestamos que mostrar.\n");

}

}

int menuPrestamo()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU AUTORES**************|\n");
    printf("\n 1- Alta prestamo:\n");
    printf(" 2- listar prestamos:\n");
    printf(" 3- Salir:");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}

void funcPrestamos(ePrestamos* list, int len, eLibros* libros, int taml, eSocios* socios,int tams)
{
    int seguir='s';

    do
    {
        switch(menuPrestamo())
        {
            case 1:
                altaPrestamo(list,len,libros,taml,socios,tams);
                system("pause");
                break;
            case 2:
                printPrestamos(list,len);
                system("pause");
                break;
            case 3:
                seguir='n';
                break;

            default:
                printf("Ingresar opc valida \n");
                break;
        }

    }while(seguir=='s');
}

