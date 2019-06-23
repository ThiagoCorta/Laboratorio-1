#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Productos.h"
#include "utn.h"
#include "Parser.h"



int parser_eProductoFromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer[5][30];
    int cant,todoOk=0;
    eProducto* pAux=NULL;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        while(!feof(pFile)){
            cant =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
            pAux=eProducto_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(pAux!=NULL && eProducto_isValidProd(pAux)){
                ll_add(pArrayList,pAux);
                todoOk=1;
            }else{
                eProducto_delete(pAux);
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

int parser_eProductoFromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk=0,cant=0;
    eProducto* new;
    if(pFile!=NULL && pArrayList!= NULL){
        while(!feof(pFile)){
            new=eProducto_new();
           cant = fread(new,sizeof(eProducto),1,pFile);
            if(new!=NULL){
                if(eProducto_isValidProd(new)==1){
                    ll_add(pArrayList,new);
                    todoOk=1;
                }else{
                    eProducto_delete(new);
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
