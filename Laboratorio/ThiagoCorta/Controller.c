#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "eDominio.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        strcat(path,".csv");
        f=fopen(path,"r");
        if(f!=NULL){
            parser_FromText(f,pArrayList);
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
            parser_FromBinary(f,pArrayList);
            fclose(f);
            todoOk=1;
        }else{
            todoOk=0;
        }

    }


    return todoOk;
}

int controller_sort(LinkedList* pArrayList)
{
    int todoOk=0;
    if(pArrayList!=NULL){
        ll_sort(pArrayList,compareByName,1);
        todoOk=1;
    }

    return todoOk;
}
int controller_List(LinkedList* pArrayList)
{
    eDominio* aux;
    int todoOk=0;
    int len;

    if(pArrayList!=NULL){
        len=ll_len(pArrayList);
        for(int i=0;i<len;i++){
            aux=(eDominio*)ll_get(pArrayList,i);
            printDominio(aux);
            todoOk=1;
        }
    }

    return todoOk;
}
