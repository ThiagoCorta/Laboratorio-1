#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10
typedef struct {
int id;
char name[20];
char lastName[20];
float salary;
int status;
}eEmpleado;

void initEmployees(eEmpleado* list, int len);
eEmpleado* newEmpleadoParam(int id,char*nombre,char*lastName,float salary);
eEmpleado* new_Employee();
int findEmptySlot(eEmpleado* list, int len);
void printEmployee(eEmpleado* list);
void printEmployees(eEmpleado* list, int len);
int mainMenu();
void addEmployee(eEmpleado* list, int len);
void imprimirEmployees(eEmpleado* list, int len);
void printEmployeesAsBin(eEmpleado* list, int len);
void cargarEmployee(eEmpleado* list, int len);



int main()
{
    char seguir='s';
    eEmpleado* list = (eEmpleado*)malloc(sizeof(eEmpleado)*LEN);

    if(list == NULL)
    {
        printf("\nNo se consiguio memoria bro...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    initEmployees(list,LEN);

    printf("Empleados inicializados..\n\n");


        do
        {
            switch(mainMenu())
            {

            case 1:
                cargarEmployee(list,LEN);
                system("pause");
                break;

            case 2:
                addEmployee(list,LEN);
                system("pause");
                break;

            case 3:
                printEmployees(list,LEN);
                system("pause");
                break;

            case 4:
                printEmployeesAsBin(list,LEN);
                system("pause");
                break;

            case 5:
                imprimirEmployees(list,LEN);
                system("pause");
                break;

            case 6:
                seguir='n';
                break;

            }

        }while(seguir=='s');

    free(list);

    return 0;
}

int mainMenu()
{
    int opc;

    system("cls");
    printf("1- CARGAR EMPLEADO \n2- ALTA EMPLEADO \n3- LISTAR EMPLEADOS\n4-GURDAR EMPLEADOS ARCHIVO \n5- IMPRIMIR EMPLEADOS \n6- SALIR\n\nIngresar opcion : ");
    scanf("%d", &opc);
    return opc;
}

void initEmployees(eEmpleado* list, int len)
{

    if(list!=NULL)
    {
      for(int i = 0 ; i<len;i++)
        {
        /// (*(list+i)).status=0;
            (list+i)->status=0;

        }
    }

}
eEmpleado* newEmpleadoParam(int id,char*nombre,char*lastName,float salary)
{
    eEmpleado* new = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(new!=NULL)
    {
        new->id=id;
        strcpy(new->name,nombre);
        strcpy(new->lastName,lastName);
        new->salary=salary;
        new->status=1;

    }

     return new;
}
eEmpleado* new_Employee()
{
    eEmpleado* new = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(new!=NULL)
    {
        new->id=0;
        strcpy(new->name,"");
        strcpy(new->lastName,"");
        new->salary=0;
        new->status=0;

    }
    return new;
}

int findEmptySlot(eEmpleado* list, int len)
{
    int indice =-1;
    if(list!=NULL && len > 0)
    {
        for(int i = 0 ; i<len ; i++)
        {
            if((list+i)->status==0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;

}

void printEmployee(eEmpleado* list)
{
    if(list!=NULL)
    {
        printf("%d %s %s %.2f\n", list->id, list->name, list->lastName, list->salary);
    }


}

void printEmployees(eEmpleado* list, int len)
{

    if(list!=NULL && len >0)
        {
            for(int i = 0 ; i<len ; i++)
            {
                if((list+i)->status==1)
                {
                    printEmployee(list+i);
                }
            }
        }

}

void addEmployee(eEmpleado* list, int len)
{
    int i ;
    int auxInt;
    char auxString[20];
    char auxString1[20];
    float auxFloat;


    i = findEmptySlot(list, len);

    if(i==-1)
    {
        printf("\nNo hay mas espacio bro!");
    }
    else
    {
        printf("Ingresar ID");
        fflush(stdin);
        scanf("%d", &auxInt);

        printf("\nIng nombre : \n");
        fflush(stdin);
        gets(auxString);

        printf("\nIng apellido : \n");
        fflush(stdin);
        gets(auxString1);

        printf("\nIngresar Sueldo\n");
        fflush(stdin);
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt,auxString,auxString1,auxFloat);

        if(nuevoEmpleado!=NULL)
        {
            ///Pega todos los datos de nuevo empleado, a la lista, osea q pega cada dato en la otra estructura.
            (*(list+i))=*nuevoEmpleado;
            free(nuevoEmpleado);
        }


    }




}

void imprimirEmployees(eEmpleado* list, int len)
{
    FILE* f;
    if(list!=NULL && len >0)
        {
            f=fopen("./listaEmpleados.txt","w");

            if(f!=NULL)
            {
                fprintf(f,"%10s %10s %10s %10s\n", "ID", "NOMBRE","APELLIDO","SUELDO");
                for(int i = 0 ; i<len ; i++)
                {
                    if((list+i)->status==1)
                    {
                        fprintf(f,"%10d %10s %10s %10.2f\n", (list+i)->id, (list+i)->name, (list+i)->lastName, (list+i)->salary);
                    }
                }

                fprintf(f,"\n\n");
            }

            fclose(f);

        }

}

void printEmployeesAsBin(eEmpleado* list, int len)
{
     FILE* f;
    if(list!=NULL && len >0)
        {
            f=fopen("./Empleados.bin","wb");

            if(f!=NULL)
            {
                for(int i = 0 ; i<len ; i++)
                {
                    if((list+i)->status==1)
                    {
                        fwrite((list+i),sizeof(eEmpleado),1,f);
                    }
                }

            }

            fclose(f);

        }
}

void cargarEmployee(eEmpleado* list, int len)
{
    int i ;
    FILE* f;


    f = fopen("./Empleados.bin","rb");
    if (f!=NULL)
    {
        while(!feof(f))
        {
            i = findEmptySlot(list,len);

            fread((list+i),sizeof(eEmpleado),1,f);

           if(feof(f))/// siempre lee de mas, con esto hace que no se pase !!!
           {
               break;
           }

        }

        fclose(f);
    }


}
