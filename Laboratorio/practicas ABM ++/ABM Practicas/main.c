#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

#define TAM 12
#define tamSec 5
#define TAMC 5
#define TamA 14

int obtenerSectores(eSector sectores[], int tam, int idSector, char desc[]);

int main()
{

    eEmpleado empleados[TAM];
    char seguir='s';
    int flag=0;


    inicializarEmpleados(empleados,TAM);
    hardCodearEmpleados(empleados,TAM);
    eSector sectores[]= {{1,"Sistemas"},{2,"RRHH"},{3,"ATCliente"},{4,"FrontEnd"},{5,"BackEnd"}};
    eComida comidas[] = {{1,"Milanesa"},{2,"Fideos"},{3,"Pizza"},{4,"Sopa"},{5,"Pescado"}};
    eAlmuerzo almuerzos[]={
                {100,1324,1},
                {101,8294,2},
                {102,5648,3},
                {103,1954,4},
                {104,9874,5},
                {105,8294,5},
                {106,5648,4},
                {107,1954,3},
                {108,9874,2},
                {109,1954,1},
                {110,9874,2},
                {111,8294,3},
                {112,5648,4},
                {113,1954,5},
                {114,9874,1}};

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
            printf("\n\n");
            mostrarAlmuerzos(almuerzos,TamA,empleados,TAM,comidas,TAMC);

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
            switchConsultas(empleados,TAM,sectores,tamSec);
            system("pause");
            break;

        case 9:
            seguir='n';
            break;

        }
    }
    while(seguir=='s');


    return 0;

}

/*void queAlmorzaronEmpleados(eEmpleado emp[], int tam, eSector sec[], int tamsec, eAlmuerzo almuerzo[], eComida comida[], int tamC)
{

    int legajo;
    int esta;

    mostrarEmpleados(vec,tam,sec,tamsec);

    printf("\n\nIngrese legajo del empleado que desea modificar:\n ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {

    }
*/




int obtenerComidas(eComida comida[], int tam, int idComida, char desc[])
{
    int funciona=-1;
    for(int i= 0 ; i<tam;i++)
    {
        if(idComida == comida[i].id)
        {
            strcpy(desc,comida[i].descripcion);
            funciona=1;
            break;
        }
    }
    return funciona;
}


void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamc, eEmpleado emp[], int tam)
{
    char nombreComida[20];
    int consigioNombre;

   consigioNombre =  obtenerComidas(comidas,tamc,comidas.id,nombreComida);

    if( !consigioNombre){
         strcpy(nombreComida, "Sin definir");
     }

    printf("%15s \n", nombreComida);


}

void mostrarAlmuerzos(eAlmuerzo almuerzo[], int tamA, eEmpleado empleados[], int tam, eComida comida[], int tamc)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%15s \n", "Almuerzos");
    printf("%15s \n",  "------");

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].ocupado==1)
        {
            mostrarAlmuerzo(almuerzo[i],comida,tamc,empleados,tam);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.\n");

    }

}




