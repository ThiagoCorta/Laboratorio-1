#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Save.h"
#include "Productos.h"
#include "utn.h"


int saveAsText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    eProducto* this;
    int len,auxCod,auxCant,auxImporte,todoOk=0,i, auxStatus;
    char auxDesc[50];

    if(path!=NULL && pArrayList!=NULL){
        len=ll_len(pArrayList);
       if(fopen(path,"r")!=NULL){
             f=fopen(path,"w");
       }else{
           f=fopen(path,"w");
        }
        if(f!=NULL){
            for(i=0;i<len;i++){
                this=(eProducto*)ll_get(pArrayList,i);
                if(this!=NULL){
                    eProducto_getCod(this,&auxCod);
                    eProducto_getDesc(this,auxDesc);
                    eProducto_getImporte(this,&auxImporte);
                    eProducto_getCant(this,&auxCant);
                    eProducto_getStatus(this,&auxStatus);
                    fprintf(f,"%d,%s,%d,%d,%d\n",auxCod,auxDesc,auxImporte,auxCant,auxStatus);
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1 todoOk - 0 todoMal
 *
 */
int saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    int i;
    int len= ll_len(pArrayList);
    eProducto* this;
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
                        fwrite(this,sizeof(eProducto),1,f);
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
