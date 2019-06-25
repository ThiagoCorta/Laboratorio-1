#include <stdio.h>
#include <stdlib.h>
#include "eDominio.h"
#include "Linkedlist.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

int saveAsText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    eDominio* this;
    int len,auxId,auxAnio,todoOk=0,i;
    char auxDominio[50];

    if(path!=NULL && pArrayList!=NULL){
        len=ll_len(pArrayList);
       if(fopen(path,"r")!=NULL){
             f=fopen(path,"w");
       }else{
           f=fopen(path,"w");
        }
        if(f!=NULL){
            for(i=0;i<len;i++){
                this=(eDominio*)ll_get(pArrayList,i);
                if(this!=NULL){
                    eDominio_getId(this,&auxId);
                    eDominio_getDominio(this,auxDominio);
                    eDominio_getAnio(this,&auxAnio);
                    fprintf(f,"%d,%s,%d\n",auxId,auxDominio,auxAnio);
                }
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


int saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    int i;
    int len= ll_len(pArrayList);
    eDominio* this;
    if(path != NULL && pArrayList!= NULL){
       if(fopen(path,"rb")!=NULL){
             f=fopen(path,"wb");
        }else{
            f=fopen(path,"wb");
        }
        if(f!=NULL){
                for(i=0;i<len;i++){
                    this=ll_get(pArrayList,i);
                    if(this!= NULL)
                        fwrite(this,sizeof(eDominio),1,f);
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
