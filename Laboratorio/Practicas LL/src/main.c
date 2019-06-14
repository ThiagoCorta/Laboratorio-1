/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "employee.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"



int main(void)
{
//        startTesting(1);  // ll_newLinkedList
//        startTesting(2);  // ll_len
//        startTesting(3);  // getNode - test_getNode
//        startTesting(4);  // addNode - test_addNode
//        startTesting(5);  // ll_add
//        startTesting(6);  // ll_get
//        startTesting(7);  // ll_set
//        startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//        startTesting(14); // ll_pop
//        startTesting(15); // ll_contains
//        startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort


     char seguir= 's';
     int auxInt;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2;
    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\nLos datos fueron cargados correctamente.\n");
                }else{
                printf("\nError al cargar archivos.\n");
                }
                system("pause");
                break;
            case 2:
               if(controller_loadFromBinary("data.bin",listaEmpleados)==1){
                   printf("\nLos datos fueron cargados correctamente.\n");
               }else{
               printf("Error al cargar archivos.\n");
               }
               system("pause");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)==1){
                    printf("\nEmpleado agregado exitosamente!!\n");
                }else{
                    printf("\nError al ingresar el empleado.\n");
                }
                system("pause");
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados)==1){
                    printf("\nEmpleado modificado exitosamente!!\n");
                }
                system("pause");
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_removeEmployee(listaEmpleados)==1){
                    printf("\nEl empleado fue dado de baja de forma exitosa!!\n");
                    }else{
                    printf("\nNo se dio de baja al empleado.\n");
                    }
                }else{
                    printf("\nNo hay empleados en el sistema.\n");
                }
                system("pause");
                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_ListEmployee(listaEmpleados);
                }else{
                    printf("\nNo hay empleados cargados que mostrar, agregue o bien cargue desde el archivo\n");
                }
                system("pause");
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_sortEmployee(listaEmpleados)==1){
                        printf("\nSe ordeno la lista de empleados!\n");
                    }else{
                        printf("\nNo se pudo ordenar la lista de empleados.\n");
                    }
                }else{
                    printf("\nNo hay empleados cargados que ordenar, agregue o bien cargue desde el archivo\n");
                }
                system("pause");
                break;
            case 8:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsText("data.csv",listaEmpleados)==1){
                        printf("\nDatos de empleados guardados en el archivo TXT con exito!\n");
                    }else{
                        printf("\nNo se pudo guardar los datos en el archivo.\n");
                    }
                }else{
                    printf("\nNo hay nada que guardar.\n");
                }
                system("pause");
                break;
            case 9:
                if(!ll_isEmpty(listaEmpleados)){
                    if(controller_saveAsBinary("data.bin",listaEmpleados)==1){
                        printf("\nDatos de empleados guardados en el archivo BIN con exito!\n");
                    }else{
                        printf("\nNo se pudo guardar los datos en el archivo.\n");
                    }
                }else{
                    printf("\nNo hay nada que guardar.\n");
                }

                system("pause");
                break;
            case 10:
                if(!ll_isEmpty(listaEmpleados)){
                listaEmpleados2 = ll_clone(listaEmpleados);
                    if(listaEmpleados2!=NULL){
                        printf("Se clono correctamente!!\n");
                    }
                }else{
                    printf("\nNo hay nada que clonar, ingrese empleados..\n");
                }
                    system("pause");
                    break;
            case 11:
                    break;
            case 12:
                if(listaEmpleados2!=NULL){
                     if(ll_containsAll(listaEmpleados,listaEmpleados2)==1){
                    printf("El linkedlist1 esta incluido en el linkedlist2.\n\n");
                    }else{
                    printf("El linkedlist1 no esta incluido en el linkedlist2.\n\n");
                    }
                }else{
                    printf("No existe el linkedlist.");
                }
                system("pause");
                    break;
            case 13:
                if(listaEmpleados2!=NULL){
                    if(ll_deleteLinkedList(listaEmpleados2)==0){
                        printf("Se borro la linkedlist\n");
                        exit(1);
                    }
                }
                seguir='n';
                    break;
            case 14:
                if(!ll_isEmpty(listaEmpleados2)){
                    controller_ListEmployee(listaEmpleados2);
                }else{
                    printf("\nNo hay empleados cargados que mostrar, primero clone la LL\n");
                }
                system("pause");
                seguir='n';
                    break;
            case 15:
                seguir='n';
                    break;
            default:
                printf("Ing opcion valida.\n");
                system("pause");
                break;
        }
    }while(seguir=='s');
    free(listaEmpleados);

    return 0;

}

































