#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Save.h"
#include "Productos.h"
#include "utn.h"
#include "Parser.h"
#include "Controller.h"


int main()
{
    char seguir='s';
    LinkedList* pArrayList = ll_newLinkedList();

    if(pArrayList!=NULL){
        do{
            switch(menu()){
            case 1:
                if(controller_loadFromText("datos.dat",pArrayList)){
                    puts("\n\nProductos cargados al sistema correctamente!\n");
                }else{
                    puts("\n\nError al abrir y/o cargar el archivo.\n");
                }
                 getchar();
                break;
            case 2:
                if(controller_loadFromText("temporal.dat",pArrayList)){
                    puts("\n\nProductos cargados al sistema correctamente!\n");
                }else{
                    puts("\n\nError al abrir y/o cargar el archivo.\n");
                }
                getchar();
                break;
            case 3:
                if(controller_addProducto(pArrayList)){
                    puts("\n\nSe agrego el producto al sistema!\n");
                }else{
                    puts("\n\nError!\n");
                }
                getchar();
                break;
            case 4:
                if(!ll_isEmpty(pArrayList)){
                    if(controller_editProducto(pArrayList)){
                        puts("\n\nSe modificaron el/los productos.\n");
                    }else{
                        puts("\n\nError!\n");
                    }
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 5:
                if(!ll_isEmpty(pArrayList)){
                    if(controller_removeProductLogica(pArrayList)){
                        puts("\n\nSe realizo la baja LOGICA");
                    }else{
                        puts("\n\nError!\n");
                    }
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 6:
                if(!ll_isEmpty(pArrayList)){
                    if(controller_removeProductFisica(pArrayList)){
                        puts("\n\nSe realizo la baja FISICA");
                    }else{
                        puts("\n\nError!\n");
                    }
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 7:
                if(!ll_isEmpty(pArrayList)){
                    controller_ListEmployee(pArrayList);
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 8:
                if(!ll_isEmpty(pArrayList)){
                    if(saveAsText("datos.dat",pArrayList)){
                        puts("\n\nArchivo cargado con exito!");
                   }else{
                        puts("\n\nError\n");
                    }
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 9:
                if(!ll_isEmpty(pArrayList)){
                    if(saveAsText("temporal.dat",pArrayList)){
                        puts("\n\nArchivo cargado con exito!");
                   }else{
                        puts("\n\nError\n");
                    }
                }else{
                    puts("\n\nPrimero cargue los productos al sistema!\n");
                }
                getchar();
                break;
            case 10:
                seguir='n';
                break;
            }
        }while(seguir=='s');
    }
}
