#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#include "trabajos.h"

void initTrabajos(eTrabajo* list, int lenT)
{
    for(int i = 0; i < lenT ; i++)
    {
        list[i].isEmpty=0;
    }
}

int findEmptyTrabajo(eTrabajo* list, int lenT)
{
    int indice = -1;

    for(int i = 0 ; i < lenT;i++)
    {
        if(list[i].isEmpty==0)
        {
            indice=i;
        }
    }

    return indice;
}

int getIdTrabajo()
{
    static int id = 10;
    id++;
    return id;
}

int addTrabajo(eTrabajo* list, int lenT, eAuto* autos, int lenA, eServicio* servicio, int lenS, eMarca* marca, int lenM, eColor* color, int lenC)
{
    int indice;
    int todoOk=-1;
    int auxInt;
    int dia;
    int mes;
    int anio;


    indice=findEmptyTrabajo(list,lenT);

    if(indice!=-1)
    {
        list[indice].idTrabajo=getIdTrabajo();


        printAutos(autos,lenA,marca,lenM,color,lenC);

        utn_getEntero(&auxInt,20,"Ingresar patente del auto : \n", "Error ingresar patente Valida \n",0,999);

        while(findAutoById(autos,lenA,auxInt)==-1)
        {
        utn_getEntero(&auxInt,20,"Ingresar patente del auto : \n", "Error ingresar patente Valida \n",0,999);

        }

        list[indice].patente=auxInt;

        mostrarServicios(servicio,lenS);

        utn_getEntero(&auxInt,20,"Ingresar servicio que desea contratar : \n", "Error ingresar servicio valido \n",20000,20005);

        while(findServicioById(servicio,lenS,auxInt)==-1)
        {
            utn_getEntero(&auxInt,20,"Ingresar servicio que desea contratar : \n", "Error ingresar servicio valido \n",0,5);

        }

        list[indice].idServicio=auxInt;

        pedirFecha(&dia,&mes,&anio);

        list[indice].fechaIng.dia=dia;
        list[indice].fechaIng.mes=mes;
        list[indice].fechaIng.anio=anio;


        list[indice].isEmpty=1;

        printf("\nTrabajo ingresado con Exito!!.\n");
        todoOk=0;
    }
    else
    {
        printf("\nNo hay mas espacio para nuevos Autos.\n");
    }

    return todoOk;
}

int obtenerServicios(eServicio* servicio, int lenS, int idServicio, char* desc)
{
    int todoOk=-1;
    for(int i= 0 ; i<lenS;i++)
    {
        if(idServicio == servicio[i].idServicio)
        {
            strcpy(desc,servicio[i].descripcion);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void printTrabajo(eTrabajo list, eServicio* servicios, int lenS)
{
    char nombreServicio[20];
    int consigioServicio;

    consigioServicio = obtenerServicios(servicios,lenS,list.idServicio,nombreServicio);

    if(!consigioServicio)
    {
        strcpy(nombreServicio, "Sin definir");
    }

    printf("%5d %12d %12s %7.02d/%02d/%4d\n", list.idTrabajo, list.patente,nombreServicio,list.fechaIng.dia,list.fechaIng.mes,list.fechaIng.anio);
}


void printTrabajos(eTrabajo* list, int len, eServicio* servicios, int lenS)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %15s \n", "ID Trabajo", "Patente", "Servicio","Fecha");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printTrabajo(list[i], servicios,lenS);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay Trabajos que mostrar.\n");

    }
}

int findArrayTrabajo(eTrabajo* list, int lent)
{
    int esta =-1;

    for(int i = 0 ; i< lent ; i++)
    {
        if(list[i].isEmpty==1)
        {
            esta=1;
            break;
        }
    }
    return esta;
}

