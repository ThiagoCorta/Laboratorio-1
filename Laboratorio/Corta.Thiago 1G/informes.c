#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#include "trabajos.h"
#include "informes.h"


int menuAbmConsultas()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU ABM CONSULTAS**************|\n");
    printf("\n 1- Autos de color ;\n");
    printf(" 2- Autos marca sel:\n");
    printf(" 3- trabajos por auto sel:\n");
    printf(" 4- ---- \n");
    printf(" 5- informar importe total de los trabajos a un auto: \n");
    printf(" 6- mostrar servicio mas pedido: \n");
    printf(" 7- mostrar la recaudacion en una fecha en particular: \n");
    printf(" 8- mostrar lo sautos que realizaron encerado y fecha: \n");
    printf(" 9- trabajos a autos blancos: \n");
    printf(" 10- facturacion total por servicio: \n");
    printf(" 11- marca de autos con mas servicios: \n");
    printf(" 12- autos que recibieron trabajos en fecha determinada: \n");
    printf(" 13-  Salir: \n");
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
                autosDeColorNegro(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 2:
                autosPorMarcaSel(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 3:
                trabajosPorAutoSel(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 4:
               // autosQueNoTuvieronTrabajos(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 5:
                pagadoPorAuto(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 6:
                servicioMasPopular(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 7:
                recaudacionPorFecha(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;
            case 8:
                autosPorTrabajo(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;

            case 9:
                trabajosAutosColor(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;

            case 10:
                recaudacionPorServicio(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");
                break;

            case 11:

                break;

            case 12:
                autosQueRecibieronTrabajosFecha(autos,lenA,trabajos,lenT,servicios,lenS,colores,lenC,marcas,lenM);
                system("pause");

                break;

            case 13:
                seguir='n';
                break;
        }

    }while(seguir=='s');
}


/*void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    char auxServicio[25];
    int acumulador[lenS];
    int contador[lenS];
    int mayor;

    for(int i = 0 ; i < lenS ; i ++)
    {
        strcpy(auxServicio,servicios[i].descripcion);
        printf("\nServicio: : %s\n\n", auxServicio);
        printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
        acumulador[i]=0;
        contador[i]=0;


            for(int j = 0 ; j < lenT; j++)
            {

                for(int k=0;k<lenA;k++)
                {
                    if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,autos[k].patente)==0)
                    {
                        printTrabajo(trabajos[k],servicios,lenS,autos,lenA,marcas,lenM);
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

}*/



void acumuladorAnual(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    char auxServicio[25];
    int acumulador[lenS];
    int contador[lenS];
    int mayor;
    int anio;

    printf("Ingresar anio : ");
    getInt(&anio);

    for(int i = 0 ; i < lenS ; i ++)
    {
        strcpy(auxServicio,servicios[i].descripcion);
        printf("\nServicio: : %s\n\n", auxServicio);
        printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
        acumulador[i]=0;
        contador[i]=0;


            for(int j = 0 ; j < lenT; j++)
            {

                for(int k=0;k<lenA;k++)
                {
                    if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,autos[k].patente)==0 && anio==trabajos[j].fechaIng.anio && trabajos[j].isEmpty==1)
                    {
                        printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);
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
        if( contador[i] >= mayor && contador[i]!=0){

            printf("El servicio mas popular es : %s\n", servicios[i].descripcion);
        }

    }


}


void autosDeColorNegro(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int auxInt;


    mostrarColores(colores,lenC);

        utn_getEntero(&auxInt,20,"Ingresar color del auto : \n", "Error ingresar color Valida \n",5000,5004);

    printf("%5s %11s %12s %10s %10s\n\n","IDAuto","Marca","Color","Modelo","Patente");
    for(int k=0;k<lenA;k++)
        {
            if(autos[k].idColor==auxInt && autos[k].isEmpty==1)
            {
                printAuto(autos[k],colores,lenC,marcas,lenM);

            }

        }

}

void autosPorMarcaSel(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{

    int auxInt;

    mostrarModelos(marcas,lenM);
        utn_getEntero(&auxInt,20,"Ingresar Marca : \n", "Error ingresar marca valida \n",1000,1004);

    printf("%5s %11s %12s %10s %10s\n","IDAuto","Marca","Color","Modelo","Patente");
    for(int k=0;k<lenA;k++)
        {
            if(autos[k].idMarca==auxInt && autos[k].isEmpty==1)
            {
                printAuto(autos[k],colores,lenC,marcas,lenM);

            }

        }

}

void trabajosPorAutoSel(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{

    int esta = -1;
    char patente[10];


            printAutos(autos,lenA,marcas,lenM,colores,lenC);
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

    printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
    if(esta!=-1)
    {
        for(int i = 0 ; i < lenT ; i++)
        {
            if(strcmp(trabajos[i].patente,patente)==0 && trabajos[i].isEmpty==1)
            {
                printTrabajo(trabajos[i],servicios,lenS,autos,lenA,marcas,lenM);

            }


        }
    }

}

void pagadoPorAuto(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int acumulador=0;
    int esta = -1;
    char patente[10];


            printAutos(autos,lenA,marcas,lenM,colores,lenC);
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
        if(esta!=-1)
        {
            for(int i = 0 ; i < lenS ; i ++)
            {

                for(int j = 0 ; j < lenT; j++)
                {

                        if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,patente)==0)
                        {
                            printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);
                            acumulador+=servicios[i].precioServicio;

                        }

                }

            }
            printf("Importe total : %d\n\n", acumulador);
        }

}
