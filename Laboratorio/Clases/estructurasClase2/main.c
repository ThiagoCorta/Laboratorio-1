#include <stdio.h>
#include <stdlib.h>
#define TAM 2

typedef struct{
int legajo;
char nombre[20];
char sexo;
float sueldo;
int ocupado;

}eEmpleado;


void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarVacio(eEmpleado vec [], int tam);
void mostrarEmpleados(eEmpleado empleados[], int tam);
void mostrarEmpleado(eEmpleado emp);


int main()
{

    eEmpleado empleados[TAM];
    char seguir='s';

    inicializarEmpleados(empleados,TAM);


    do
    {


        switch(menuAbm())
        {
        case 1:
            altaEmpleado(empleados,TAM);
            system("pause");
            break;

        case 2:
            bajaEmpleado(empleados,TAM);
            system("pause");

            break;

        case 3:

            break;

        case 4:


            break;

        case 5:
            mostrarEmpleados(empleados,TAM);
            system("pause");
            break;

        case 6:
            seguir='n';
            break;

        }
    }
    while(seguir=='s');


    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0;i<tam;i++)
    {
        vec[i].ocupado=0;

    }

}

int buscarVacio(eEmpleado vec [], int tam)
{
    int indice=-1;

    for(int i = 0; i<tam;i++)
    {
        if(vec[i].ocupado==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int   indice = -1;

    for(int i=0;i<tam;i++)
    {
        if(vec[i].legajo==legajo && vec[i].ocupado ==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int menuAbm(){

    int opcion;

        system("cls");
        printf("********MENU ABM********\n\n");
        printf("1- Alta empleado: \n");
        printf("2- Baja empleado: \n");
        printf("2- Modificar empleado:  \n");
        printf("4- Ordenar empleado: \n");
        printf("5- Mostrar Empleados: \n");
        printf("6- Salir: \n");

        scanf("%d", &opcion);

        return opcion;

}

int altaEmpleado(eEmpleado vec[], int tam)
{
    int legajoIng;
    int indice;
    int esta;


    indice = buscarVacio(vec,tam);
    if(indice==-1)
    {
        printf("No hay lugar para nuevos empleados. \n");
        system("pause");
    }
    else
    {
        printf("Ingresar legajo: \n");
        scanf("%d", &legajoIng);

      esta=buscarEmpleado(vec,tam,legajoIng);

        if(esta==-1)
        {
            vec[indice].legajo=legajoIng;

            printf("Ingrese nombre:\n ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingresar sexo: \n");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: \n");
            scanf("%f", &vec[indice].sueldo);

            vec[indice].ocupado=1;

            printf("\n El empleado a sido registrado!\n");

        }
        else
        {
            mostrarEmpleado(vec[esta]);
        }

    }
}

void mostrarEmpleado(eEmpleado emp)
{

    printf("Legajo : %d > Nombre : %s > Sexo : %c > Sueldo : %.2f\n", emp.legajo, emp.nombre,emp.sexo,emp.sueldo);

}

void mostrarEmpleados(eEmpleado empleados[], int tam)
{
    int cont=0;

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].ocupado==1)
        {
            mostrarEmpleado(empleados[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.");

    }

}

void bajaEmpleado (eEmpleado vec[], int tam )
{
    int legajo;
    char confirma;
    int esta;

    printf("Ingrese el legajo : \n");
    scanf("%d", &legajo);

    esta=buscarEmpleado(vec,tam,legajo);

    if(esta==-1)
    {
        printf("El legajo > %d No esta registrado en el sistema\n", legajo);
    }
    else
    {
         mostrarEmpleado(vec[esta]);

         printf("\n Quiere dar de baja al empleado? s/n\n");
         fflush(stdin);
         confirma=tolower(getche());

         if(confirma=='s')
         {
             vec[esta].ocupado=0;
         }
         else
         {
             printf("\n La eliminacion ha sido cancelada");
         }
    }
}



