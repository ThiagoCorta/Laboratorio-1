#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


void employee_delete(Employee* this){
    if(this!=NULL){
        free(this);
    }

}
int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
       this->id=id;
        todoOk=1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setName(Employee* this,char* name)
{
    int todoOk=0;
    if(this!=NULL && name!=NULL && strlen(name)>1)
    {
        strcpy(this->name,name);
        todoOk=1;
    }
    return todoOk;
}

int employee_getName(Employee* this,char* name)
{
    int todoOk=0;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHoursWorked(Employee* this,int hoursWorked)
{
    int todoOk=0;
    if(this!=NULL && hoursWorked>0)
    {
        this->hoursWorked=hoursWorked;
        todoOk=1;
    }
    return todoOk;
}

int employee_getHoursWorked(Employee* this,int* hoursWorked)
{
    int todoOk=0;
    if(this!=NULL && hoursWorked!=NULL)
    {
        *hoursWorked=this->hoursWorked;
        todoOk=1;
    }
    return todoOk;
}


int employee_setSalary(Employee* this,int salary)
{
    int todoOk=0;
    if(this!=NULL && salary>0)
    {
        this->salary=salary;
        todoOk=1;
    }
    return todoOk;
}

int employee_getSalary(Employee* this,int* salary)
{
    int todoOk=0;
    if(this!=NULL && salary!=NULL)
    {
        *salary=this->salary;
        todoOk=1;
    }
    return todoOk;
}



Employee* employee_new()
{
    Employee* new;
    new = (Employee*) malloc(sizeof(Employee));
    if(new != NULL){
        new->id = 0;
        strcpy(new->name," ");
        new->salary=0;
        new->hoursWorked=0;
    }else{
        employee_delete(new);
        new=NULL;
    }
    return new;

}


Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary)
{
    Employee* new;
    new=employee_new();
    if(idStr!=NULL && nameStr!=NULL && hoursWorkedStr!=NULL && salary!=NULL && new!=NULL){
        if(!employee_setId(new,atoi(idStr))||
        !employee_setName(new,nameStr)||
        !employee_setSalary(new,atoi(salary))||
        !employee_setHoursWorked(new,atoi(hoursWorkedStr))){
            employee_delete(new);
            new=NULL;
        }/*else{
            free(new);
            new=NULL;
        }*/
    }
    return new;
}

int menu()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Clonar\n");
    printf("11. \n");
    printf("12. Funcion containsAll\n");
    printf("13. Borrar linkedlist(Borra el clonado)\n");
    printf("14. Listar empleados del LL clonado: \n");
    printf("15. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,15);

    return opc;

}

int menuModify()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Editar nombre : \n");
    printf("2. Editar horas trabajadas : \n");
    printf("3. Editar sueldo : \n");
    printf("4. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,4);

    return opc;

}

int menuSort()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Ordenar alfabeticamnete A Z . : \n");
    printf("2. Ordenar por ID de menor a mayor. : \n");
    printf("3. Ordenar alfabeticamnete Z a. : \n");
    printf("4. Ordenar por ID de mayor a menor. : \n");
    printf("5. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,5);

    return opc;

}

int print_Employee(Employee* this)
{
    int todoOk=0;

    if(this!=NULL){
        printf("%5d %12s %12d %10d\n", this->id,this->name,this->hoursWorked,this->salary);
        todoOk=1;
    }

    return todoOk;
}

int ordenarXSueldo(void* emp1, void* emp2){
    int todoOk=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(p1->salary > p2->salary){
            todoOk=1;
         }else if(p1->salary < p2->salary){
            todoOk=-1;
         }else if(p1->salary == p2->salary){
            todoOk=0;
        }
    }

    return todoOk;
}

int compareByName(void* emp1, void* emp2){
    int todoOk=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(strcmp(p1->name,p2->name)>0){
            todoOk=1;
         }else if(strcmp(p1->name,p2->name)<0){
            todoOk=-1;
         }else if(strcmp(p1->name,p2->name)==0){
            todoOk=0;
        }
    }

    return todoOk;
}

int compareById(void* emp1, void* emp2){
    int todoOk=0;
    Employee* p1;
    Employee* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (Employee*)emp1;
         p2 = (Employee*)emp2;

         if(p1->id>p2->id){
            todoOk=1;
         }else if(p1->id<p2->id){
            todoOk=-1;
         }else if(p1->id==p2->id){
            todoOk=0;
        }
    }

    return todoOk;
}

int employee_isValidEmp(Employee* emp){
    int todoOk=0,id,hours,salary;
    char name[50];

    if(emp!=NULL){
        employee_getId(emp,&id);
        employee_getHoursWorked(emp,&hours);
        employee_getSalary(emp,&salary);
        employee_getName(emp,name);

        if(id>0 && hours >0 && salary >0 && name !=NULL){
            todoOk=1;
        }
    }
    return todoOk;
}

