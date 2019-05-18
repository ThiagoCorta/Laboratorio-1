#include <stdio.h>
#include <stdlib.h>
typedef struct{
int dia;
int mes;
int anio;
}eFecha;
typedef struct{
int legajo;
char nombre[20];
float sueldo;
char sexo;
eFecha fechaing;
}eEmpleado;

int main()
{

    eEmpleado lista[]=
    {{1234,"Juan",24000,'m',{11,8,2000}},
    {1554,"pepe",24000,'f',{15,1,2017}},
    {5914,"tomas",24000,'m',{21,11,1999}}};
    eFecha fecha = {11,8,1999};
    eEmpleado* pEmp;
    eFecha* pFec;

    printEmployees(lista,3);

/*
    pEmp = &emp1;

    printf("%s\n",emp1.nombre);

    printf("%s\n", pEmp->nombre);


    printf("%d %d %d\n",fecha.dia,fecha.mes,fecha.anio);

    printf("%d %d %d\n",pEmp->fechaIng.dia,pEmp->fechaIng.mes,pEmp->fechaIng.anio);

  //  printf("Ing nombre;");

   // scanf("%s", pEmp->nombre);

    // printf("%s\n", pEmp->nombre);

     printf("Ing nombre;");

     gets(pEmp->nombre);

     printf("%s\n", pEmp->nombre);

     printf("ing nuevo sueldo");

     scanf("%f",&pEmp->sueldo);

     printf("%f\n", pEmp->sueldo);

    int x=5;
    int asd;



    printf("%p\n",&x);
    printf("%d\n\n", x);

   asd= modificarAlgo(&x);

   if(asd==1)
   {
      printf("%d\n",x);
        printf("%d",asd);
   }


   conseguirDirMemoria(&x);

   printf("%p",&x);

*//*
    int vec[]={3,9,4,4,5};

    f1(vec,5);
    f2(vec,5);
    f3(vec,5);
    f4(vec,5);
*/
/*
    char cadena [20]="Esto es una cadena";

    char* p=

    p = cadena;

    while(*p!='\0')
    {
        printf("%c",*p);
        p++;
    }
*/



    return 0;
}

int modificarAlgo(int* pAux)
{
    int auxint;
    int todoOk=-1;
    printf("ingentero\n");
    scanf("%d",&auxint);
    *pAux=auxint;

    if(*pAux==auxint)
    {
        todoOk=1;
    }

    return todoOk;

}

int conseguirDirMemoria(int* pAux)
{
    int* memoria;

    memoria=pAux;

    printf("\n%p\n",memoria);

    return memoria;
}

void f1(int array[], int tam)
{
    for(int i=0; i<tam;i++)
    {
        printf(" %d ",array[i]);
    }
     printf("\n");

}

void f2(int array[], int tam)
{
    for(int i=0; i<tam;i++)
    {
        printf(" %d ",*(array+i));
    }
     printf("\n");

}

void f3(int* array, int tam)
{
   for(int i=0; i<tam;i++)
    {
        printf(" %d ",array[i]);
    }
     printf("\n");
}

void f4(int* array, int tam)
{
    for(int i=0; i<tam;i++)
    {
        printf(" %d ",*(array+i));
    }
     printf("\n");

}

void printEmployee(eEmpleado* list)
{
 printf("%5d %10s %10c %10.2f %7.02d/%02d/%4d\n", list->legajo, list->nombre,list->sexo,list->sueldo, list->fechaing.dia,list->fechaing.mes,list->fechaing.anio);
}

void printEmployees(eEmpleado* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %10s %10s %10s %15s \n", "Legajo", "Nombre", "Sexo", "Salario", "Fecha");

    for(int i = 0 ; i < len ; i++)
    {
        printEmployee(list+i);
        cont++;

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.\n");

}

}
