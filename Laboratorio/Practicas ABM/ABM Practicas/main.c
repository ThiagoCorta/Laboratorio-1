#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

#define TAM 12
#define tamSec 5

int obtenerSectores(eSector sectores[], int tam, int idSector, char desc[]);

int main()
{

    eEmpleado empleados[TAM];
    char seguir='s';
    int flag=0;

    inicializarEmpleados(empleados,TAM);
    hardCodearEmpleados(empleados,TAM);
    eSector sectores[]= {{1,"Sistemas"},{2,"RRHH"},{3,"ATCliente"},{4,"FrontEnd"},{5,"BackEnd"}};

    mostrarSectores(sectores,tamSec);

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
            seguir='n';
            break;

        }
    }
    while(seguir=='s');


    return 0;

}




