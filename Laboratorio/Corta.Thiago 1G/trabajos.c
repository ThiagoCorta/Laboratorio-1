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

    for(int i = 0 ; i < lenT; i++)
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
    int indice=-1;
    int todoOk=-1;
    int esta=-1;
    int auxInt;
    int dia;
    int mes;
    int anio;
    char patente[20];


    indice=findEmptyTrabajo(list,lenT);

    printAutos(autos,lenA,marca,lenM,color,lenC);

    if( preguntarSiEstaSeguro("Desea ingresar nuevo trabajo? s/n", "Error ing s/n")=='s')
    {
         printf("\n\nIngrese La patente del auto:\n ");
            getCadena(patente,7);
            Tstrupr(patente);
        while(findAutoByPatente(autos,lenA,patente)==-1)
        {
            printf("\n\nError, la patente no existe ingrese La patente del auto:\n ");
            getCadena(patente,7);
            Tstrupr(patente);

        }

        esta = findAutoByPatente(autos,lenA,patente);

        if(indice!=-1 && esta!=-1)
        {
            list[indice].idTrabajo=getIdTrabajo();

            strcpy(list[indice].patente,patente);

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
            printf("\nNo se puede cargar nuevos trabajos.\n");
        }
    }



    return todoOk;
}

int obtenerServicios(eServicio* servicio, int lenS, int idServicio, char* desc)
{
    int todoOk=-1;
    for(int i= 0 ; i<lenS; i++)
    {
        if(idServicio == servicio[i].idServicio)
        {
            strcpy(desc,servicio[i].descripcion);
            todoOk=i;
            break;
        }
    }
    return todoOk;
}

void printTrabajo(eTrabajo list, eServicio* servicios, int lenS, eAuto* autos, int lenA,eMarca* marcas, int lenM)
{
    char nombreServicio[20];
    char marca[20];
    int indice;
    int consigioServicio;
    int consigioMarca;

    indice = findAutoByPatente(autos,lenA,list.patente);
    consigioMarca = obtenerMarcas(marcas,lenM,autos[indice].idMarca,marca);
    consigioServicio = obtenerServicios(servicios,lenS,list.idServicio,nombreServicio);


    if(consigioServicio==-1)
    {
        strcpy(nombreServicio, "Sin definir");
    }
    if(!consigioMarca)
    {
        strcpy(marca, "Sin definir");
    }

    printf("%5d %12s %12s %12s %7.02d/%02d/%4d %12d$\n", list.idTrabajo, list.patente,marca,nombreServicio,list.fechaIng.dia,list.fechaIng.mes,list.fechaIng.anio,servicios[consigioServicio].precioServicio);
}


void printTrabajos(eTrabajo* list, int len, eServicio* servicios, int lenS,eAuto* autos,int lenA,eMarca* marcas,int lenM)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printTrabajo(list[i], servicios,lenS,autos,lenA,marcas,lenM);
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

void hardCodearTrabajos(eTrabajo* works, int tam)
{
    eTrabajo workss [36]= {
     {1, "AAA201", 20000, {12,3,2019}, 1},
       {2, "DFR234", 20000, {2,4,2019}, 1},
       {3, "GFT564", 20001, {7,1,2019}, 1},
       {4, "ACD321", 20002, {9,11,2019}, 1},
       {5, "HTD656", 20003, {12,12,2019}, 1},
       {6, "QSZ435", 20001, {21,7,2019}, 1},
       {7, "LGX201", 20001, {29,8,2019}, 1},
       {8, "SUZ324", 20004, {31,5,2019}, 1},
       {9, "HCU762", 20004, {2,2,2019}, 1},
       {10, "DYC735", 20000, {18,2,2019}, 1},
       {11, "JJK879", 20001, {17,3,2019}, 1},
       {12, "AAA201", 20000, {17,4,2019}, 1},
       {13, "DFR234", 20000, {2,6,2019}, 1},
       {14, "GFT564", 20001, {7,3,2019}, 1},
       {15, "ACD321", 20002, {21,7,2019}, 1},
       {16, "HTD656", 20003, {11,9,2019}, 1},
       {17, "QSZ435", 20001, {3,7,2019}, 1},
       {18, "LGX201", 20001, {21,8,2019}, 1},
       {19, "SUZ324", 20004, {28,5,2019}, 1},
       {20, "HCU762", 20004, {2,8,2019}, 1},
       {21, "DYC735", 20000, {8,2,2019}, 1},
       {22, "JJK879", 20001, {17,3,2019}, 1},
       {23, "KOD220", 20003, {17,4,2019}, 1},
       {24, "QSZ305", 20000, {21,3,2019}, 1},
       {25, "SSD128", 20002, {16,4,2019}, 1},
       {26, "SSD240", 20000, {17,4,2019}, 1},
       {27, "EDF213", 20001, {23,3,2019}, 1},
       {28, "AAA201", 20000, {12,2,2019}, 1},
       {29, "DFR234", 20000, {2,3,2019}, 1},
       {30, "GFT564", 20001, {7,2,2019}, 1},
       {31, "ACD321", 20002, {9,12,2019}, 1},
       {32, "HTD656", 20003, {12,9,2019}, 1},
       {33, "QSZ435", 20001, {21,5,2019}, 1},
       {34, "HTD656", 20002, {12,2,2019}, 1},
       {35, "QSZ435", 20000, {21,1,2019}, 1}};
    for(int i=0;i<tam;i++)
    {
        works[i]= workss[i];
    }

}







