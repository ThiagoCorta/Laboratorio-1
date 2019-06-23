#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Productos.h"
#include "utn.h"
#include "Parser.h"
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        f=fopen(path,"r");
        if(f!=NULL){
            parser_eProductoFromText(f,pArrayList);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }
    }
    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;

    if(path!=NULL && pArrayList!=NULL){
        f=fopen(path,"rb");
        if(f!=NULL){
            parser_eProductoFromBinary(f,pArrayList);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }

    }


    return todoOk;
}


int controller_addProducto(LinkedList* pArrayList)
{
    int todoOk=0;

    if(addProducto(pArrayList)){
        todoOk=1;
    }
    return todoOk;
}


int controller_editProducto(LinkedList* pArrayList)
{
   int todoOk=0;

    if(editProducto(pArrayList)){
        todoOk=1;
    }
    return todoOk;
}


int controller_removeProductFisica(LinkedList* pArrayList)
{
    int todoOk=0,len,auxCodIng,i,auxCod;
    eProducto* this;

    if(pArrayList!=NULL){
        len = ll_len(pArrayList);
        utn_getEntero(&auxCodIng,20,"\nIngresar CODIGO del producto que desea dar de baja : ", "\nError ingresar un numero CODIGO valido: ",0,9999);
        for(i = 0;i<len;i++){
            this = (eProducto*)ll_get(pArrayList,i);
            eProducto_getCod(this,&auxCod);
            if(auxCod==auxCodIng){
            if(preguntarSiEstaSeguro("\nSeguro que desea dar de baja a este producto ?: ", "Error ing s/n")=='s'){
                ll_remove(pArrayList,i);
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

int controller_removeProductLogica(LinkedList* pArrayList)
{
    int todoOk=0,len,auxCodIng,i,auxCod;
    eProducto* this;

    if(pArrayList!=NULL){
        len = ll_len(pArrayList);
        utn_getEntero(&auxCodIng,20,"\nIngresar CODIGO del producto que desea dar de baja : ", "\nError ingresar un numero CODIGO valido: ",0,9999);
        for(i = 0;i<len;i++){
            this = (eProducto*)ll_get(pArrayList,i);
            eProducto_getCod(this,&auxCod);
            if(auxCod==auxCodIng){
            if(preguntarSiEstaSeguro("\nSeguro que desea dar de baja a este producto ?: ", "Error ing s/n")=='s'){
                if(eProducto_setStatus(this,0)){
                     todoOk=1;
                    break;
                }else{
                    todoOk=0;
                }
            }else{
                break;
                }
            }
        }
    }
    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayList)
{
    eProducto* aux;
    int todoOk=0;
    int len;

    if(pArrayList!=NULL){
        len=ll_len(pArrayList);
        for(int i=0;i<len;i++){
        aux=(eProducto*)ll_get(pArrayList,i);
        if(printProduct(aux))
            todoOk=1;
        }
    }

    return todoOk;
}



int controller_sortProd(LinkedList* pArrayList)
{
    int todoOk=0;
    if(pArrayList!=NULL){
        ll_sort(pArrayList,compareByDesc,1);
        todoOk=1;
    }

    return todoOk;
}



