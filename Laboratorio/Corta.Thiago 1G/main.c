#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#include "trabajos.h"

#define TAMC 5
#define TamS 5
#define tamM 5
#define TAMA 1000
#define TAMT 1000

//17/04/2019
int main()
{
   char seguir='s';
    int flagA=0;
    int flagT=0;
    eAuto autos[TAMA];
    eTrabajo trabajos[TAMT];
    eMarca marcas[tamM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[TamS] ={
       {20000, "Lavado", 250},
       {20001, "Pulido", 300},
       {20002, "Encerado", 400},
       {20003, "Completo", 600},
       {20004, "Teflonado", 800}
       };



    initAutos(autos,TAMA);
    initTrabajos(trabajos,TAMT);
    hardCodearAutos(autos,23);
    hardCodearTrabajos(trabajos,36);

    do{

        if(findArrayAuto(autos,TAMA)==1)
        {
            flagA=1;
        }
        else
        {
            flagA=0;
        }

        if(findArrayTrabajo(trabajos,TAMT)==1)
        {
            flagT=1;
        }
        else
        {
            flagT=0;
        }



        switch(menuAbm())
        {
            case 1:
                addAuto(autos,TAMA,marcas,tamM,colores,TAMC);
                system("pause");
                break;
            case 2:
                if(validateFlag(&flagA,"\nPara poder dar de baja autos primero hay que ingresarlos.\n")==0)
                {
                    printAutos(autos,TAMA,marcas,tamM,colores,TAMC);
                    removeAuto(autos,TAMA);
                    system("pause");
                }
                break;

            case 3:
                if(validateFlag(&flagA,"\nPara poder modificar autos primero hay que ingresarlos.\n")==0)
                {
                    modifyAuto(autos,TAMA,colores,TAMC,marcas,tamM);
                    system("pause");
                }

                break;
            case 4:
                if(validateFlag(&flagA,"\nPara poder mostrar Autos primero hay que ingresarlos.\n")==0)
                {
                    sortAutos(autos,TAMA);
                    printAutos(autos,TAMA,marcas,tamM,colores,TAMC);
                    system("pause");
                }

                break;
            case 5:
                mostrarModelos(marcas,tamM);
                system("pause");
                break;
            case 6:
                mostrarColores(colores,TAMC);
                system("pause");
                break;
            case 7:
                mostrarServicios(servicios,TamS);
                system("pause");
                break;
            case 8:
                if(validateFlag(&flagA,"\nPara poder cargar trabajos hay que ingresar autos.\n")==0)
                {
                   addTrabajo(trabajos,TAMT,autos,TAMA,servicios,TamS,marcas,tamM,colores,TAMC);
                    system("pause");
                }

                break;

            case 9:
                if(validateFlag(&flagT,"\nPara poder mostrar trabajos primero hay que ingresarlos.\n")==0)
                {
                    printTrabajos(trabajos,TAMT,servicios,TamS,autos,TAMA,marcas,tamM);
                    system("pause");
                }

                break;
            case 10:
                funcConsultas(autos,TAMA,trabajos,TAMT,servicios,TamS,colores,TAMC,marcas,tamM);
                break;

            case 11:
                seguir='n';
                break;

            default:
                printf("\nIngresar opcion valida\n");
                break;

        }

    }while(seguir=='s');

    return 0;


}

void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{

    int acumulador[lenS];
    int contador[lenS];
    int mayor;
    int flag=0;

    for(int i = 0 ; i < lenS ; i ++)
    {
        acumulador[i]=0;
        contador[i]=0;

            for(int j = 0 ; j < lenT; j++)
            {

                for(int k=0;k<lenA;k++)
                {
                    if(trabajos[j].idServicio==servicios[i].idServicio && strcmp(trabajos[j].patente,autos[k].patente)==0)
                    {
                       // printTrabajo(trabajos[k],servicios,lenS,autos,lenA,marcas,lenM);
                        acumulador[i]+=servicios[i].precioServicio;
                        contador[i]++;

                    }


                }

            }
       // printf("Este servicio fue contratado %d veces.\n\n", contador[i]);
    }

    for(int i = 0; i< lenS;i++)
    {
        for(int j = i+1; i< lenS;i++)
        {
            if(flag == 0 || contador[i]>contador[j])
            {
                mayor=contador[i];
                flag=1;
            }
            else
            {
                if(contador[i]<contador[j])
                {
                    mayor=contador[j];
                }

            }
        }

    }

    for(int i = 0 ; i < lenS;i++)
    {
        if( contador[i] >= mayor){

            printf("El servicio mas popular es : %s con %d trabajos\n", servicios[i].descripcion,contador[i]);
        }

    }

}


void autosPorTrabajo(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{

    int auxInt;

    mostrarServicios(servicios,lenS);
            utn_getEntero(&auxInt,20,"Ingresar servicio que desea contratar : \n", "Error ingresar servicio valido \n",20000,20004);

    printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
    for(int i=0;i<lenT;i++)
        {
            if(trabajos[i].idServicio==auxInt && trabajos[i].isEmpty==1)
            {
                printTrabajo(trabajos[i],servicios,lenS,autos,lenA,marcas,lenM);

            }

        }

}


void recaudacionPorFecha(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int acumulador=0;
    int dia;
    int mes;
    int anio;


    pedirFecha(&dia,&mes,&anio);


    for(int i = 0 ; i < lenS ; i ++)
        {

            for(int j = 0 ; j < lenT; j++)
            {

                if(trabajos[j].idServicio==servicios[i].idServicio && trabajos[j].fechaIng.dia==dia &&trabajos[j].fechaIng.mes == mes&&trabajos[j].fechaIng.anio==anio && trabajos[j].isEmpty==1)
                    {
                        printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);
                        acumulador+=servicios[i].precioServicio;

                    }

                }

            }
    printf("Este dia se facturo : %d\n\n", acumulador);
}

void trabajosAutosColor(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int auxInt;


    mostrarColores(colores,lenC);

        utn_getEntero(&auxInt,20,"Ingresar color del auto : \n", "Error ingresar color Valida \n",5000,5004);

    printf("%5s %11s %12s %10s %10s\n\n","IDAuto","Marca","Color","Modelo","Patente");

    for(int i = 0 ; i < lenT ; i++)
    {
        for(int j=0;j<lenA;j++)
        {
            if(strcmp(trabajos[i].patente,autos[i].patente) && autos[j].idColor==auxInt&&trabajos[i].isEmpty==1)
            {
                printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);

            }

        }
    }

}

void recaudacionPorServicio(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int acumulador=0;
    int auxInt;

   mostrarServicios(servicios,lenS);

    utn_getEntero(&auxInt,20,"Ingresar servicio que desea contratar : \n", "Error ingresar servicio valido \n",20000,20005);

    printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
    for(int i = 0 ; i < lenS ; i ++)
        {

            for(int j = 0 ; j < lenT; j++)
            {

                if(trabajos[j].idServicio==servicios[i].idServicio && trabajos[j].idServicio==auxInt && trabajos[j].isEmpty==1)
                    {
                        printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);
                        acumulador+=servicios[i].precioServicio;

                    }

                }

            }
    printf("Este dia se facturo : %d\n\n", acumulador);
}

void autosQueRecibieronTrabajosFecha(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM)
{
    int acumulador=0;
    int dia;
    int mes;
    int anio;


    pedirFecha(&dia,&mes,&anio);

    printf("%5s %12s %12s %12s %15s %13s\n", "IDT", "Patente","Marca", "Servicio","Fecha", "Precio");
    for(int i = 0 ; i < lenS ; i ++)
        {

            for(int j = 0 ; j < lenT; j++)
            {

                if(trabajos[j].idServicio==servicios[i].idServicio && trabajos[j].fechaIng.dia==dia &&trabajos[j].fechaIng.mes == mes&&trabajos[j].fechaIng.anio==anio && trabajos[j].isEmpty==1)
                    {
                        printTrabajo(trabajos[j],servicios,lenS,autos,lenA,marcas,lenM);


                    }

                }

            }

}




