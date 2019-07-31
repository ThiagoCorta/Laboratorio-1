#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eDominio.h"
#include "utn.h"


void eDominio_delete(eDominio* this){
    if(this!=NULL){
        free(this);
    }

}
int eDominio_setId(eDominio* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
       this->id=id;
        todoOk=1;
    }
    return todoOk;
}

int eDominio_getId(eDominio* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int eDominio_setTipo(eDominio* this,char auxTipo)
{
    int todoOk=0;
    if(this!=NULL && (auxTipo!='A' || auxTipo!='M'))
    {
        this->tipo=auxTipo;
        todoOk=1;
    }
    return todoOk;
}

int eDominio_getTipo(eDominio* this,char* auxTipo)
{
    int todoOk=0;
    if(this!=NULL && auxTipo!=NULL)
    {
        *auxTipo=this->tipo;
        todoOk=1;
    }
    return todoOk;
}

int eDominio_setDominio(eDominio* this,char* auxDom)
{
    int todoOk=0;
    if(this!=NULL && auxDom!=NULL)
    {
        strcpy(this->dominio,auxDom);
        todoOk=1;
    }
    return todoOk;
}

int eDominio_getDominio(eDominio* this,char* auxDom)
{
    int todoOk=0;
    if(this!=NULL && auxDom!=NULL)
    {
        strcpy(auxDom, this->dominio);
        todoOk=1;
    }
    return todoOk;
}


int eDominio_setAnio(eDominio* this,int auxAnio)
{
    int todoOk=0;
    if(this!=NULL && auxAnio>0)
    {
        this->anio=auxAnio;
        todoOk=1;
    }
    return todoOk;
}

int eDominio_getAnio(eDominio* this,int* auxAnio)
{
    int todoOk=0;
    if(this!=NULL && auxAnio!=NULL)
    {
        *auxAnio=this->anio;
        todoOk=1;
    }
    return todoOk;
}



eDominio* eDominio_new()
{
    eDominio* new;
    new = (eDominio*) malloc(sizeof(eDominio));
    if(new != NULL){
        new->id = 0;
        new->tipo='X';
        new->anio=0;
        strcpy(new->dominio," ");
    }else{
        eDominio_delete(new);
        new=NULL;
    }
    return new;

}


eDominio* eDominio_newParametros(char* idStr,/*char* tipoStr,*/char* dominioStr, char* anioStr)
{
    eDominio* new;
    new=eDominio_new();
    if(idStr!=NULL && /*tipoStr!=NULL &&*/ dominioStr!=NULL && anioStr!=NULL && new!=NULL){
        if(!eDominio_setId(new,atoi(idStr))||
        /*!eDominio_setTipo(new,tipoStr)||*/
        !eDominio_setAnio(new,atoi(anioStr))||
        !eDominio_setDominio(new,dominioStr)){
            eDominio_delete(new);
            new=NULL;
        }
    }
    return new;
}

int eDominio_isValid(eDominio* pAux){
    int todoOk=0,id,anio;
   // char tipo[50];
    char dominio[50];

    if(pAux!=NULL){
        eDominio_getId(pAux,&id);
        eDominio_getDominio(pAux,dominio);
        eDominio_getAnio(pAux,&anio);
        //eDominio_getTipo(pAux,tipo);

        if(id>0 && anio >1 /*&& tipo!=NULL*/ && dominio !=NULL){
            todoOk=1;
        }
    }
    return todoOk;
}

int menu()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Cargar los datos.\n");
    printf("2. Mostrar datos.\n");
    printf("3. Map.\n");
    printf("4. Filth autos.\n");
    printf("5. Filth motos.\n");
    printf("6. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,6);

    return opc;

}

int printDominio(eDominio* this)
{
    int todoOk=0,id,anio;
    char dominio[20], tipo;



    if(this!=NULL){
        eDominio_getId(this,&id);
        eDominio_getDominio(this,dominio);
        eDominio_getAnio(this,&anio);
        eDominio_getTipo(this,&tipo);
        printf("%5d %12s %12d %5c\n",id,dominio,anio,tipo);
        todoOk=1;
    }

    return todoOk;
}

int compareByName(void* eDom1, void* eDom2){
    int todoOk=0;
    char dominioA[20];
    char dominioB[20];

    if(eDom1!=NULL && eDom2!=NULL){
        eDominio_getDominio(eDom1,dominioA);
        eDominio_getDominio(eDom2,dominioB);


         if(strcmp(dominioA,dominioB)>0){
            todoOk=1;
         }else if(strcmp(dominioA,dominioB)<0){
            todoOk=-1;
         }else if(strcmp(dominioA,dominioB)==0){
            todoOk=0;
        }
    }

    return todoOk;
}

int eDominio_filterM(void* pAux){
     int todoOk = 0;
    char aux;
    if(pAux!=NULL){
        eDominio_getTipo(pAux,&aux);
        if(aux=='M'){
            todoOk=1;
        }else{
            todoOk=-1;
        }
    }
    return todoOk;
}

int eDominio_filterAuto(void* pAux){
    int todoOk = 0;
    char auxDom[20];
    char aux[3];
    if(pAux!=NULL){
    eDominio_getDominio(pAux,auxDom);
    for(int i=3;i<strlen(auxDom);i++){
        *(auxDom+i)=0;
    }
    strcpy(aux,auxDom);
        if(isLetras(aux)){
            todoOk=1;
        }
    }
    return todoOk;
}

void* eDominio_llmap(void* pAux){
    eDominio* pDominio=eDominio_new();
    int auxId,auxAnio;
    char auxDominio[20];
    char car='A', moto='M';
    if(pAux != NULL){
        if(eDominio_filterAuto(pAux)==1){
            eDominio_getId(pAux,&auxId);
            eDominio_getDominio(pAux,auxDominio);
            eDominio_getAnio(pAux,&auxAnio);

            eDominio_setId(pDominio,auxId);
            eDominio_setDominio(pDominio,auxDominio);
            eDominio_setAnio(pDominio,auxAnio);
            eDominio_setTipo(pDominio,car);

        }else{
            eDominio_getId(pAux,&auxId);
            eDominio_getDominio(pAux,auxDominio);
            eDominio_getAnio(pAux,&auxAnio);

            eDominio_setId(pDominio,auxId);
            eDominio_setDominio(pDominio,auxDominio);
            eDominio_setAnio(pDominio,auxAnio);
            eDominio_setTipo(pDominio,moto);
        }

    }
    return (void*)pDominio;

}

int eDominio_filthA(void* pAux){
    int todoOk = 0;
    char aux;
    if(pAux!=NULL){
        eDominio_getTipo(pAux,&aux);
        if(aux=='A'){
            todoOk=1;
        }else{
            todoOk=-1;
        }
    }
    return todoOk;
}



