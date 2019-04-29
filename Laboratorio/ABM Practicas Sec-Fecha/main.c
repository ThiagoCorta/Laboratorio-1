#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define tamSec 6

int obtenerSectores(eSector sectores[], int tam, int idSector, char desc[]);

int main()
{

    eEmpleado empleados[TAM];
    //eSector sectores[tamSec];
    char seguir='s';
    int flag=0;


    inicializarEmpleados(empleados,TAM);
    hardCodearEmpleados(empleados,12);
    eSector sectores[]= {{1,"Sistemas"},{2,"RRHH"},{3,"ATCliente"},{4,"FrontEnd"},{5,"BackEnd"},{6,"Random"}};


    do
    {


        switch(menuAbm())
        {
        case 1:
            altaEmpleado(empleados,TAM,sectores,tamSec);
            flag=1;
            system("pause");
            break;

        case 2:
            //if(flag==0)
            //{
            bajaEmpleado(empleados,TAM,sectores,tamSec);
            //inicializarSectores(sectores,tamSec);
            system("pause");
            /*  }
              else
              {
                   printf("Para poder dar de baja empleados primero debe ingresarlos.\n\n");
                  system("pause");
              }*/

            break;

        case 3:
            //if(flag==0)
            //  {
            modificarEmpleado(empleados,TAM,sectores,tamSec);
            system("pause");
            /*  }
              else
              {
                  printf("Para poder modificar empleados primero debe ingresarlos.\n\n");
                  system("pause");
              }*/


            break;

        case 4:
            // if(flag==0)
            // {
            ordenarEstructura(empleados,TAM);
            mostrarEmpleados(empleados,TAM,sectores,tamSec);
            printf("\nTotal salarios : %.2f\n", totalSalarios(empleados,TAM));
            printf("Promedio de sueldos : %.2f\n", promedioSueldos(empleados,TAM));
            printf("Total empleados que superan el salario promedio : %d\n\n", cantidadSuperaPromedio(empleados,TAM));
            system("pause");
            /*}
            else
            {
                printf("Para poder mostrar los empleados primero debe ingresarlos. \n\n");
                system("pause");
            }*/

            break;

        case 5:
            mostrarCantEmpleadosXSector(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 6:
            SectorMasEmpleados(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 7:
            sectorConMayorPromedioSueldo(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 8:
            cantidadMyFPorSector(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 9:
            empleadoMayorSueldoSec(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 10:
            seguir='n';
            break;

        }
    }while(seguir=='s');


    return 0;

}


void inicializarSectores(eSector sectores[], int tamsec)
{
    char auxChar[150];
    char seguir;
    for(int i=0; i<tamsec; i++)
    {
        getValidString("Ingresar Sector: ", "Error ingresar sector valido: \n", auxChar);

        while(strlen(auxChar)>20)
        {
            getValidString("Error ingresar sector valido: ", "Error ingresar sector valido: \n", auxChar);
        }

        sectores[i].id=i+1;
        strcpy(sectores[i].descripcion,auxChar);

        printf("Desea ingresar otro sector ? s/n \n");
        scanf("%c", &seguir);

        while(seguir!='s' && seguir!='n')
        {
            printf("Desea ingresar otro sector ? s/n \n");
            scanf("%c", &seguir);
        }
        if(seguir=='n')
        {
            break;
        }

    }


}






