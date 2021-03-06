#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

#define TAM 12
#define tamSec 6
#define TAMC 5
#define TamA 16

int obtenerSectores(eSector sectores[], int tam, int idSector, char desc[]);

int main()
{

    eEmpleado empleados[TAM];
   // eComida comidas[TAMC];
    //eAlmuerzo almuerzos[TamA];
    //eSector sectores[tamSec];
    char seguir='s';
    int flag=0;


    inicializarEmpleados(empleados,TAM);
//    IdComidasCero(comidas,TAMC);
    hardCodearEmpleados(empleados,12);
    eSector sectores[]= {{1,"Sistemas"},{2,"RRHH"},{3,"ATCliente"},{4,"FrontEnd"},{5,"BackEnd"},{6,"Random"}};
    eComida comidas[] = {{6,"Milanesa"},{7,"Fideos"},{8,"Pizza"},{9,"Sopa"},{10,"Pescado"}};
    eAlmuerzo almuerzos[]={
                {100,1234,6,{1,8,2017}},
                {101,1234,7,{1,8,2017}},
                {102,5648,6,{1,8,2017}},
                {103,1954,9,{1,8,2017}},
                {104,9874,8,{1,8,2017}},
                {105,8294,8,{1,8,2017}},
                {106,5648,10,{1,8,2017}},
                {107,5657,7,{1,8,2017}},
                {108,9874,9,{1,8,2017}},
                {109,9999,6,{1,8,2017}},
                {110,1358,8,{1,8,2017}},
                {111,8294,10,{1,8,2017}},
                {112,5648,10,{1,8,2017}},
                {113,1564,6,{1,8,2017}},
                {114,5668,10,{1,8,2017}},
                {000,0,0,{0,0,0000}}};



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
            mostrarAlmuerzos(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
            break;

        case 11:
            inicializarComidas(comidas,TAMC);
            mostrarComidas(comidas,TAMC);
            system("pause");
            break;

            case 12:
            empleadosPorComidas(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
            break;

            case 13:
            empleadosPorComidasYnombre(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
            break;

            case 14:
            cargarAlmuerzo(almuerzos,TamA,comidas,TAMC,empleados,TAM,sectores,tamSec);
           // mostrarComidas(comidas,TAMC);
            system("pause");
            break;

            case 15:
            almuerzosPorSector(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
            break;

            case 16:
            almuerzosPorFemenino(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
            break;

            case 17:
            comidaFavPorSec(almuerzos,TamA,empleados,TAM,comidas,TAMC,sectores,tamSec);
            system("pause");
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

int obtenerEmpleado(eEmpleado emp[], int tam, int LegEmp)
{
    int funciona=-1;
    for(int i= 0 ; i<tam;i++)
    {
        if(LegEmp == emp[i].legajo)
        {
            funciona=i;
            break;
        }
    }
    return funciona;


}

int obtenerComidas(eComida comida[], int tamc, int idComida, char desc[])
{
    int funciona=-1;
    for(int i= 0 ; i<tamc;i++)
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


void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comida[], int tamc, eEmpleado emp[], int tam, eSector sec[], int tamsec)
{
    char nombreC[20];
    char nombreSector[20];
    int consigioNombre;
    int consigioSec;
    int indice;

   consigioNombre =  obtenerComidas(comida,tamc,almuerzo.idComida,nombreC);
   indice = obtenerEmpleado(emp,tam,almuerzo.idEmpleado);
   consigioNombre =  obtenerSectores(sec,tamsec,emp[indice].sector, nombreSector);

    if( !consigioNombre ){
         strcpy(nombreC, "Sin definir");

     }
     else
     {
         if(!consigioSec)
         {
             strcpy(nombreSector, "Sin definir");
         }
     }


    printf("%3d %10d %12s %12s %10s %7.02d/%02d/%4d %10s \n", almuerzo.id,almuerzo.idEmpleado, emp[indice].nombre, emp[indice].apellido ,nombreC,almuerzo.fecha.dia,almuerzo.fecha.mes,almuerzo.fecha.anio ,nombreSector);


}

void mostrarAlmuerzos(eAlmuerzo almuerzo[], int tamA, eEmpleado empleados[], int tam, eComida comida[], int tamc, eSector sec[], int tamsec)
{
    int cont=0;


    printf("\n");
    printf("%3s %10s %12s %12s %10s %15s %10s \n", "ID", "Legajo", "Nombre", "Apellido", "Comida", "Fecha", "Sector");
    printf("%3s %10s %12s %12s %10s %15s %10s \n", "---","------", "------", "--------", "------", "-----", "------");

    for(int i = 0 ; i < tamA ; i++)
    {
        mostrarAlmuerzo(almuerzo[i],comida,tamc,empleados,tam,sec,tamsec);
        cont++;

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.\n");

    }

}

void inicializarComidas(eComida comidas[], int tamc)
{
    char auxChar[150];
    char seguir='s';
    int indice;

   indice = buscarComidasVacias(comidas,tamc);

   if(indice!=-1)
   {
       do
       {
            getValidString("Ingresar Comida: ", "Error ingresar comida valida: \n", auxChar);
            fflush(stdin);

            while(strlen(auxChar)>20)
            {
                getValidString("Error ingresar comida valida: ", "Error ingresar comida valida: \n", auxChar);
                fflush(stdin);
            }

            comidas[indice].id=indice+1;
            strcpy(comidas[indice].descripcion,auxChar);
            fflush(stdin);

            printf("Desea ingresar otra comida ? s/n\n");
            fflush(stdin);
            scanf("%d", &seguir);
       }while(seguir=='s');


   }





}

void mostrarComidas( eComida comidas[], int tamc){

    printf("\n    Comidas\n");

    for(int i=0; i < tamc; i++){
            if(comidas[i].id!=0)
            {
                printf("%d:      %10s\n", comidas[i].id, comidas[i].descripcion);
            }

    }
}

void cargarAlmuerzo(eAlmuerzo almuerzo[], int tamAlmuerzo, eComida comidas[], int tamComidas, eEmpleado emp[], int tam, eSector sec[], int tamsec)
{
    int leg;
    int esta;
    int auxInt;
    int indice;
    mostrarEmpleados(emp,tam,sec,tamsec);

    leg=pedirEntero("Ingresar legajo del Empleado que desea agregar un almuerzo : ");

    esta = buscarEmpleado(emp,tam,leg);


    if(esta!=-1)
    {
       indice= buscarAlmuerzoVacio(almuerzo,tamAlmuerzo);

        almuerzo[indice].idEmpleado=leg;

        auxInt = pedirEntero("Ingreasar ID comida: \n");

        almuerzo[indice].id=auxInt;

        mostrarComidas(comidas,tamComidas),

        auxInt= pedirEntero("Ingresar comida : \n");

        almuerzo[indice].idComida=auxInt;

        printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &almuerzo[indice].fecha.dia, &almuerzo[indice].fecha.mes, &almuerzo[indice].fecha.anio);

            printf("\nAlmuerzo cargado con exito!!.\n");
    }
    else
    {
        printf("\nEl legajo de empleado ingresado NO EXISTE.\n");
    }



}

void inicializarAlmuerzos(eAlmuerzo almuerzo[], int tamAlmuerzo){

    for(int i=0;i<tamAlmuerzo;i++)
        {
            almuerzo[i].id=0;
        }

}

int buscarAlmuerzoVacio(eAlmuerzo almuerzo[], int tamAlmuerzo)
{
    int indice=-1;

    for(int i = 0; i<tamAlmuerzo; i++)
    {
        if(almuerzo[i].id==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void IdComidasCero(eComida comidas[], int tamComidas){

    for(int i=0;i<tamComidas;i++)
        {
            comidas[i].id=0;
        }

}

int buscarComidasVacias(eComida comidas[], int tamComidas)
{
    int indice=-1;

    for(int i = 0; i<tamComidas; i++)
    {
        if(comidas[i].id==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int empleadosPorComidas(eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado emp[], int tam, eComida comidas[], int tamComida, eSector sec[], int tamsec)
{
    char auxComida[25];

    for(int i = 0 ; i < tamComida ; i ++)
    {
        strcpy(auxComida,comidas[i].descripcion);
        printf("Comida : %s\n", auxComida);

        for(int j = 0 ; j < tamAlmuerzo; j++)
        {

            if(almuerzo[j].idComida==comidas[i].id)
            {
                mostrarAlmuerzo(almuerzo[j],comidas,tamComida,emp,tam,sec,tamsec);
            }

        }
    }

}

int empleadosPorComidasYnombre(eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado emp[], int tam, eComida comidas[], int tamComida, eSector sec[], int tamsec)
{
    char auxComida[25];
    int indice;

    for(int i = 0 ; i < tamComida ; i ++)
    {
        strcpy(auxComida,comidas[i].descripcion);
        printf("\nComida : %s\n\n", auxComida);

        for(int j = 0 ; j < tamAlmuerzo; j++)
        {

            if(almuerzo[j].idComida==comidas[i].id)
            {
                indice=obtenerEmpleado(emp,tamAlmuerzo,almuerzo[j].idEmpleado);
                printf("Empleado > %10s %10s > Sexo :  %c\n", emp[indice].nombre,emp[indice].apellido, emp[indice].sexo);
            }

        }
    }

}

int almuerzosPorSector(eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado emp[], int tam, eComida comidas[], int tamComida, eSector sec[], int tamsec)
{
    char auxSector[25];
    char auxComida[25];
    int indice;

    for(int i = 0 ; i < tamsec ; i ++)
    {
        strcpy(auxSector,sec[i].descripcion);
        printf("\nSector: : %s\n\n", auxSector);

        for(int k = 0; k<tamComida;k++)
        {
            strcpy(auxComida,comidas[k].descripcion);

            for(int j = 0 ; j < tamAlmuerzo; j++)
            {
                indice=obtenerEmpleado(emp,tamAlmuerzo,almuerzo[j].idEmpleado);

            if(almuerzo[j].idComida==comidas[k].id && sec[i].id == emp[indice].sector && emp[indice].ocupado==1)
            {

                printf("%10s %10s %10s %7.02d/%02d/%4d \n", emp[indice].nombre,emp[indice].apellido, auxComida, emp[indice].fechaing.dia,emp[indice].fechaing.mes,emp[indice].fechaing.anio);
            }

            }
        }

    }

}

int almuerzosPorFemenino(eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado emp[], int tam, eComida comidas[], int tamComida, eSector sec[], int tamsec)
{
    char auxComida[25];
    int indice;

    for(int i = 0 ; i < tamComida ; i ++)
    {
        strcpy(auxComida,comidas[i].descripcion);
        printf("\nComida : %s\n\n", auxComida);

        for(int j = 0 ; j < tamAlmuerzo; j++)
        {
            indice=obtenerEmpleado(emp,tamAlmuerzo,almuerzo[j].idEmpleado);
            if(almuerzo[j].idComida==comidas[i].id && emp[indice].sexo=='f')
            {
                printf("Empleado > %10s %10s > Sexo :  %c\n", emp[indice].nombre,emp[indice].apellido, emp[indice].sexo);

            }

        }
    }

}

int comidaFavPorSec(eAlmuerzo almuerzo[], int tamAlmuerzo, eEmpleado emp[], int tam, eComida comidas[], int tamComida, eSector sec[], int tamsec)
{
    char auxSector[25];
    char auxComida[25];
    int mayor;
    int flag =0;
    int indice;

    for(int i = 0 ; i < tamsec ; i ++)
    {
        strcpy(auxSector,sec[i].descripcion);
        printf("\nSector: : %s\n\n", auxSector);

        for(int k = 0; k<tamComida;k++)
        {
            calcularComidaMasPopular(comidas,tamComida,almuerzo,tamAlmuerzo,auxComida);

            printf("La comida mas popular por sector es : %s", auxComida);
        }

    }

}

int calcularComidaMasPopular(eComida* com, int lenC, eAlmuerzo* almuerzo, int lenAlmuerzo, char* aux, eSector* sec, int tamsec)
{
    int flag = 0;
    int mayor[tamsec];
    int todoOk = -1;

    for(int i = 0 ; i < tamsec ; i ++)
    {
        mayor[i]=0;

        for(int j = 0 ; j < lenAlmuerzo ; j++)
        {
            if(almuerzo[j].idComida == com[i].id)
            {
                mayor[i]++;
            }

        }

    }


    for(int i = 0 ; i < lenC ; i++)
    {
        if(flag == 0 || mayor[i] > mayor[i+1])
        {
            strcpy(*aux,com[i].descripcion);
            flag=1;
            todoOk=0;
        }
    }

    return todoOk;

}


