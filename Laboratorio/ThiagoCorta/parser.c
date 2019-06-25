#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eDominio.h"
#include "utn.h"
#include "parser.h"


int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer[3][30];
    int cant,todoOk=0;
    eDominio* pAux;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);
        while(!feof(pFile)){
            cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);
           // printf("%s %s %s\n",buffer[0],buffer[1],buffer[2]);
            pAux=eDominio_newParametros(buffer[0],buffer[1],buffer[2]);
            if(pAux!=NULL){
                ll_add(pArrayList,pAux);
                todoOk=1;
            }
            if(cant < 3){
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

int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int todoOk=0,cant=0;
    eDominio* new;
    if(pFile!=NULL && pArrayList!= NULL){
        while(!feof(pFile)){
            new=eDominio_new();
           cant = fread(new,sizeof(eDominio),1,pFile);
            if(new!=NULL){
                if(eDominio_isValid(new)==1){
                    ll_add(pArrayList,new);
                    todoOk=1;
                }else{
                    eDominio_delete(new);
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
