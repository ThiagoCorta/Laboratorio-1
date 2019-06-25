#include <stdio.h>
#include <stdlib.h>
#include "eDominio.h"
#include "Linkedlist.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
#include "Save.h"

int main()
{
    LinkedList* pList = ll_newLinkedList();
    LinkedList* pMotos=NULL;
    LinkedList* pAutos=NULL;
    char seguir='s', path[20];

    if(pList!=NULL){
        do{
            switch(menu()){
                case 1:
                    utn_getCadena(path,20,20,"Ingresar nombre del archivo\n","Error, ingresar un path correcto\n");
                    if(controller_loadFromText(path,pList)){
                        puts("\nSistema cargado correctamente!");
                    }else{
                        puts("Error al cargar los datos");
                    }
                    getchar();
                    break;
                case 2:
                    if(!ll_isEmpty(pList)){
                        if(controller_sort(pList)){
                            controller_List(pList);
                        }else{
                            puts("Error al ordenar");
                        }
                    }else{
                        puts("Para mostrar los datos primero hay que cargarlos");
                    }
                    getchar();
                break;
                case 3:
                    if(!ll_isEmpty(pList)){
                        pAutos = ll_filter(pList,eDominio_filterAuto);
                           if(pAutos!=NULL){
                             controller_List(pAutos);
                           }
                    }else{
                        puts("Primero cargar los datos.");
                    }

                   getchar();
                break;
                case 4:
                    if(!ll_isEmpty(pList)){
                        pAutos=ll_map(pList,eDominio_llAutos);
                        if(pAutos!=NULL){
                            if(saveAsText("autos.csv",pAutos)){
                                puts("Se cargo de forma correcta!");
                             }else{
                                puts("Error");
                             }
                        }
                    }else{
                        puts("Primero cargue los datos");
                    }
                    getchar();
                    break;
                case 5:
                    if(pAutos!=NULL && !ll_isEmpty(pAutos)){
                        if(controller_sort(pAutos)){
                            controller_List(pAutos);
                        }else{
                            puts("Error al ordenar");
                        }
                    }else{
                        puts("Primero hacer el Map");
                    }
                    getchar();
                break;
                case 6:
                     if(!ll_isEmpty(pList)){
                        pMotos = ll_filter(pList,eDominio_filterMoto);
                           if(pMotos!=NULL){
                            controller_loadFromText("autos.csv",pAutos);
                             controller_List(pMotos);
                           }
                    }else{
                        puts("Primero cargar los datos");
                    }
                   getchar();
                case 7:
                    if(!ll_isEmpty(pList)){
                        pMotos=ll_map(pList,eDominio_llMotos);
                        if(pMotos!=NULL){
                             if(saveAsText("motos.csv",pMotos)){
                                puts("Se cargo de forma correcta!");
                             }else{
                                puts("Error");
                             }
                        }
                    }else{
                        puts("Primero cargue los datos");
                    }
                    getchar();
                    break;
                 case 8:
                   if(pMotos!=NULL && !ll_isEmpty(pMotos)){
                        if(controller_sort(pMotos)){
                            controller_loadFromText("motos.csv",pMotos);
                            controller_List(pMotos);
                        }else{
                            puts("Error al ordenar");
                        }
                    }else{
                        puts("Primero hacer el map");
                    }
                    getchar();
                    break;
                 case 9:
                    seguir='n';
                    break;
            }

        }while(seguir=='s');

    }
    return 0;
}
