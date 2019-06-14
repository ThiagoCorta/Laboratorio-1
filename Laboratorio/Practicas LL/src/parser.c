#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "utn.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char buffer[4][30];
    int cant,todoOk=0;
    Employee* employee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile)){
            cant =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            employee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(employee!=NULL && employee_isValidEmp(employee)){
                ll_add(pArrayListEmployee,employee);
                todoOk=1;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }
    return todoOk;
}
    /** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
     *
     * \param path char*
     * \param pArrayListEmployee LinkedList*
     * \return int
     *
     */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=0,cant=0;
    Employee* new;
    if(pFile!=NULL && pArrayListEmployee!= NULL){
        while(!feof(pFile)){
            new=employee_new();
           cant = fread(new,sizeof(Employee),1,pFile);
            if(new!=NULL){
                if(employee_isValidEmp(new)==1){
                    ll_add(pArrayListEmployee,new);
                    todoOk=1;
                }else{
                    employee_delete(new);
                }
            }
            if(cant<1){
                if(feof(pFile)){
                break;
                }else{
                    todoOk=0;
                    break;
                }
            }
        }
    }

    return todoOk;
}
