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
                        pList=ll_map(pList,eDominio_llmap);
                            if(pList!=NULL){
                                puts("Map correcto");
                            }else{
                                exit(EXIT_FAILURE);
                            }
                    }else{
                        puts("Primero cargue los datos");
                    }
                    getchar();
                    break;
                case 4:
                    if(!ll_isEmpty(pList)){
                        pAutos = ll_filter(pList,eDominio_filthA);
                           if(pAutos!=NULL){
                                if(saveAsText("autos.csv",pAutos)){
                                puts("Se guardo correcto");
                                }
                           }
                    }else{
                        puts("Primero cargar los datos");
                    }
                    getchar();
                    break;
                case 5:
                     if(!ll_isEmpty(pList)){
                        pMotos = ll_filter(pList,eDominio_filterM);
                           if(pMotos!=NULL){
                                if(saveAsText("motos.csv",pMotos)){
                                    puts("Correcto");
                                }
                           }
                    }else{
                        puts("Primero cargar los datos");
                    }
                   getchar();
                   break;
                 case 6:
                    seguir='n';
                    break;
            }

        }while(seguir=='s');

    }
    return 0;
}

