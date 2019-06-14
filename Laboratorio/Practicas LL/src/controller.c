#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "parser.h"
#include "employee.h"
#include "utn.h"
#include "controller.h"
#include "../testing/inc/main_test.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk=0;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL){
            parser_EmployeeFromText(f,pArrayListEmployee);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }
    }
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk=0;

    if(path!=NULL && pArrayListEmployee!=NULL){
        f=fopen(path,"rb");
        if(f!=NULL){
            parser_EmployeeFromBinary(f,pArrayListEmployee);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }

    }


    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0,auxInt,auxId,auxHoras;
    char auxChar[50];
    Employee* new;

    if(pArrayListEmployee!=NULL)
    {
        utn_getEntero(&auxId,20,"\nIngresar id del empleado : ","\nError ingresar ID valido : ",0,99999);
        utn_getCadena(auxChar,50,20,"\nIngresar nombre del empleado : ","\nError ingresar nombre valido : \n");
        /*utn_getCadena(auxLastName,50,20,"\nIngresar apellido del empleado : ","\nError ingresar apellido valido : \n");
        strcat(auxChar, " ");
        strcat(auxChar, auxLastName);*/
        utn_getEntero(&auxHoras,20,"\nIngresar horas trabajadas : ", "\nError ingresar horas validas: \n",0,350);
        utn_getEntero(&auxInt,20,"\nIngresar sueldo del empleado : ", "\nError ingresar sueldo valido \n",5000,2000000);
        new=employee_new();
        if(new!=NULL)
        {
            if(employee_setId(new,auxId)&&
            employee_setName(new,auxChar)&&
            employee_setHoursWorked(new,auxHoras)&&
            employee_setSalary(new,auxInt)){
                ll_add(pArrayListEmployee,new);
                todoOk=1;
            }

        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* new;
    int todoOk=0,auxInt,auxId,len;
    char auxChar[50];
    char seguir='s';

    if(pArrayListEmployee!=NULL){
        len = ll_len(pArrayListEmployee);
        utn_getEntero(&auxId,20,"\nIngresar ID del empleado que desea modificar : ", "\nError ingresar ID valido\n",1,99999);
        for(int i=0;i<len;i++){
            new=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(new,&auxInt);
            if(auxId==auxInt){
                do{
                    switch(menuModify()){
                        case 1:
                            utn_getCadena(auxChar,50,20,"\nIngresar nuevo nombre del empleado : ", "\nError ingresar nombre valido\n");
                           if(employee_setName(new,auxChar)){
                            todoOk=1;
                           }
                            break;
                        case 2:
                            utn_getEntero(&auxInt,20,"\nIngresar nuevas horas trabajadas :","\nError ingresar horas validas \n",0,9999);
                            if(employee_setHoursWorked(new,auxInt)){
                                todoOk=1;
                            }
                            break;
                        case 3:
                            utn_getEntero(&auxInt,20,"\nIngresar nuevo sueldo :","\nError ingresar sueldo valido\n",5000,200000);
                            if(employee_setSalary(new,auxInt)){
                                 todoOk=1;
                            }
                            break;
                        case 4:
                            seguir='n';
                            break;
                        default:
                            printf("Error ingresar opcion valida o salir si desea salir!\n");
                            break;
                    }

                }while(seguir=='s');
            }
        }

    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0,len,idIng,i,idAux;
    Employee* this;

    if(pArrayListEmployee!=NULL){
        len = ll_len(pArrayListEmployee);
        utn_getEntero(&idIng,20,"\nIngresar ID del empleado que desea dar de baja : ", "\nError ingresar un numero ID valido: ",0,9999);
        for(i = 0;i<len;i++){
            this = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(this,&idAux);
            if(idAux==idIng){
            if(preguntarSiEstaSeguro("\nSeguro que desea dar de baja a este empleado ?: ", "Error ing s/n")=='s'){
                ll_remove(pArrayListEmployee,i);
                todoOk=1;
                break;
            }else{
                break;
                }
            }
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int todoOk=0;
    int len;
   /* int id;
    int hours;
    int salary;
    char name[50];*/

    if(pArrayListEmployee!=NULL){
        len=ll_len(pArrayListEmployee);
        for(int i=0;i<len;i++){
            aux=(Employee*)ll_get(pArrayListEmployee,i);
           print_Employee(aux);
            /*employee_getId(aux,&id);
            employee_getName(aux,name);
            employee_getHoursWorked(aux,&hours);
            employee_getSalary(aux,&salary);

            printf("%5d %12s %12d %10d\n", id,name,hours,salary);*/

            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0, seguir=1;
    if(pArrayListEmployee!=NULL){
        do{
             switch(menuSort()){
                case 1:
                    ll_sort(pArrayListEmployee,compareByName,1);
                    todoOk=1;
                    break;
                case 2:
                    ll_sort(pArrayListEmployee,compareById,1);
                    todoOk=1;
                    break;
                case 3:
                    ll_sort(pArrayListEmployee,compareById,0);
                    todoOk=1;
                    break;
                case 4:
                    ll_sort(pArrayListEmployee,compareByName,0);
                    todoOk=1;
                    break;
                case 5:
                    seguir=0;
                    break;

                default:
                    printf("Error ingresar opc valida.");
                    break;
                }
        }while(seguir==1);


    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* emp;
    int len,id,salary,hours,todoOk=0,i;
    char name[50];

    if(path!=NULL && pArrayListEmployee!=NULL){
        len=ll_len(pArrayListEmployee);
      //  if(fopen(path,"r")!=NULL){
             f=fopen(path,"w");
      //  }else{
       //     f=fopen(path,"w");
       // }
        if(f!=NULL){
            for(i=0;i<len;i++){
                emp=(Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(emp,&id);
                employee_getName(emp,name);
                employee_getHoursWorked(emp,&hours);
                employee_getSalary(emp,&salary);
                fprintf(f,"%d,%s,%d,%d\n",id,name,hours,salary);
            }
            fclose(f);
            if(i==len){
                todoOk=1;
            }
        }else{
            todoOk=0;
        }

    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk=0;
    int i;
    int len= ll_len(pArrayListEmployee);
    Employee* emp;
    if(path != NULL && pArrayListEmployee!= NULL){
       //if(fopen(path,"rb")!=NULL){
             f=fopen(path,"wb");
      //  }else{
           // f=fopen(path,"wb");
      //  }
        if(f!=NULL){
                for(i=0;i<len;i++){
                    emp=ll_get(pArrayListEmployee,i);
                    if(emp!= NULL)
                        fwrite(emp,sizeof(Employee),1,f);
                        }
                if(i==len){
                    todoOk=1;
                    fclose(f);
                }else{
                    todoOk=0;
                }
            }
    }

    return todoOk;
}
