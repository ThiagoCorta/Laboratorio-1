#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#include "trabajos.h"

#define TAMC 5
#define TamS 4
#define tamM 5
#define TAMA 1000
#define TAMT 1000


int main()
{
    char seguir='s';
    int auxInt;
    int flagA=0;
    int flagT=0;
    eAuto autos[TAMA];
    eTrabajo trabajos[TAMT];
    eMarca marcas[tamM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[TamS]={
                {20000,"Lavado",250},
                {20001,"Pulido",300},
                {20002,"Encerado",400},
                {20003,"Completo",600}};



    initAutos(autos,TAMA);
    initTrabajos(trabajos,TAMT);

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
                    utn_getEntero(&auxInt,20,"Ingresar ID del Auto que quiere dar de baja : \n", "\n Error ingresar auto valido\n",0,1000);
                    removeAuto(autos,TAMA,auxInt);
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
                    printTrabajos(trabajos,TAMT,servicios,TamS);
                    system("pause");
                }

                break;
            case 10:
                seguir='n';
                break;

            default:
                printf("\nIngresar opcion valida\n");
                break;

        }

    }while(seguir=='s');


}



