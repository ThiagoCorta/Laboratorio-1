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
    eTrabajo workss [13]= {
    {50,"AWP141",20000 ,{12,3,2000},1},
    {51,"ABP252",20001 ,{13,3,2000},1},
    {52,"ASS303",20002 ,{14,3,2000},1},
    {53,"AFN494",20003 ,{15,3,2000},1},
    {54,"AQA585",20000 ,{12,3,2000},1},
    {55,"ARR676",20001 ,{13,3,2000},1},
    {56,"AWQ767",20002 ,{14,3,2000},1},
    {57,"PAW848",20003 ,{15,3,2000},1},
    {58,"NAD949",20000 ,{12,3,2000},1},
    {59,"QAF030",20001 ,{13,3,2000},1},
    {60,"LDA521",20002 ,{14,3,2000},1},
    {61,"LAA616",20003 ,{15,3,2000},1}};
    for(int i=0;i<tam;i++)
    {
        works[i]= workss[i];
    }

}

int menuAbmConsultas()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU ABM CONSULTAS**************|\n");
    printf("\n 1- Servicios Por Marcas;\n");
    printf(" 2- :\n");
    printf(" 3- :\n");
    printf(" 4- : \n");
    printf(" 5- : \n");
    printf(" 6- : \n");
    printf(" 7- : \n");
    printf(" 8- : \n");
    printf(" 9- Salir: \n");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}

void trabajosPorServicios(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    char auxServicio[25];
    int acumulador[lenS];

    for(int i = 0 ; i < lenS ; i ++)
    {
        strcpy(auxServicio,servicios[i].descripcion);
        printf("\nServicio: : %s\n\n", auxServicio);
        printf("%5s %11s %12s %10s %10s\n","IDAuto","Marca","Color","Modelo","Patente");
        acumulador[i]=0;

            for(int j = 0 ; j < lenT; j++)
            {

                for(int k=0;k<lenA;k++)
                {
                    if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,autos[k].patente)==0)
                    {
                        printAuto(autos[k],colores,lenC,marcas,lenM);
                        acumulador[i]+=servicios[i].precioServicio;

                    }


                }

            }
        printf("Este servicio genero $ %d\n",acumulador[i]);

    }
}
void funcConsultas(eAuto* autos,int lenA,eTrabajo* trabajos,int lenT,eServicio* servicios,int lenS,eColor* colores,int lenC,eMarca*marcas,int lenM)
{
    char seguir='s';

    do
    {

        switch(menuAbmConsultas())
        {
            case 1:
                trabajosPorServicios(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 2:
                servicioMasPopular(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");

                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir='n';

                break;
        }

    }while(seguir=='s');
}

void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    char auxServicio[25];
    int acumulador[lenS];
    int contador[lenS];
    int mayor;

    for(int i = 0 ; i < lenS ; i ++)
    {
        strcpy(auxServicio,servicios[i].descripcion);
        printf("\nServicio: : %s\n\n", auxServicio);
        printf("%5s %11s %12s %10s %10s\n","IDAuto","Marca","Color","Modelo","Patente");
        acumulador[i]=0;
        contador[i]=0;


            for(int j = 0 ; j < lenT; j++)
            {

                for(int k=0;k<lenA;k++)
                {
                    if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,autos[k].patente)==0)
                    {
                        printAuto(autos[k],colores,lenC,marcas,lenM);
                        acumulador[i]+=servicios[i].precioServicio;
                        contador[i]++;

                    }


                }

            }
        printf("Este servicio genero $ %d\n",acumulador[i]);
        printf("Este servicio fue contratado %d veces.\n\n", contador[i]);
    }

    for(int i = 0; i< lenS;i++)
    {
        if(i == 0 || contador[i]>contador[i+1])
        {
            mayor=contador[i];
        }
    }

    for(int i = 0 ; i < lenS;i++)
    {
        if( contador[i] >= mayor){

            printf("El servicio mas popular es : %s\n", servicios[i].descripcion);
        }

    }

}











