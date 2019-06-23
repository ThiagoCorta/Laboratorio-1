#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Productos.h"
#include "utn.h"


#define OCUPADO 1
#define LIBRE 0



void eProducto_delete(eProducto* this){
    if(this!=NULL){
        free(this);
    }

}
int eProducto_setCod(eProducto* this,int auxCod)
{
    int todoOk=0;
    if(this!=NULL && auxCod>0)
    {
       this->cod=auxCod;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_getCod(eProducto* this,int* auxCod)
{
    int todoOk=0;
    if(this!=NULL && auxCod!=NULL)
    {
        *auxCod=this->cod;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_setDesc(eProducto* this,char* auxDesc)
{
    int todoOk=0;
    if(this!=NULL && auxDesc!=NULL && strlen(auxDesc)>1)
    {
        strcpy(this->desc,auxDesc);
        todoOk=1;
    }
    return todoOk;
}

int eProducto_getDesc(eProducto* this,char* auxDesc)
{
    int todoOk=0;
    if(this!=NULL && auxDesc!=NULL)
    {
        strcpy(auxDesc,this->desc);
        todoOk=1;
    }
    return todoOk;
}

int eProducto_setImporte(eProducto* this,int auxImporte)
{
    int todoOk=0;
    if(this!=NULL && auxImporte>0)
    {
        this->importe=auxImporte;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_getImporte(eProducto* this,int* auxImporte)
{
    int todoOk=0;
    if(this!=NULL && auxImporte!=NULL)
    {
        *auxImporte=this->importe;
        todoOk=1;
    }
    return todoOk;
}


int eProducto_setCant(eProducto* this,int auxCant)
{
    int todoOk=0;
    if(this!=NULL && auxCant>0)
    {
        this->cant=auxCant;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_getCant(eProducto* this,int* auxCant)
{
    int todoOk=0;
    if(this!=NULL && auxCant!=NULL)
    {
        *auxCant=this->cant;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_setStatus(eProducto* this,int auxStatus)
{
    int todoOk=0;
    if(this!=NULL && (auxStatus==1 || auxStatus==0))
    {
        this->activo=auxStatus;
        todoOk=1;
    }
    return todoOk;
}

int eProducto_getStatus(eProducto* this,int* auxStatus)
{
    int todoOk=0;
    if(this!=NULL && auxStatus!=NULL)
    {
        *auxStatus=this->activo;
        todoOk=1;
    }
    return todoOk;
}


eProducto* eProducto_new()
{
    eProducto* new;
    new = (eProducto*) malloc(sizeof(eProducto));
    if(new != NULL){
        new->cod = 0;
        strcpy(new->desc," ");
        new->importe=0;
        new->cant=0;
        new->activo=0;
    }else{
        eProducto_delete(new);
        new=NULL;
    }
    return new;

}


eProducto* eProducto_newParametros(char* auxCod,char* auxDesc,char* auxImporte, char* auxCant, char* auxStatus)
{
    eProducto* new;
    new=eProducto_new();
    if(auxCod!=NULL && auxDesc!=NULL && auxImporte!=NULL && auxCant!=NULL && new!=NULL){
        if(!eProducto_setCod(new,atoi(auxCod))||
        !eProducto_setDesc(new,auxDesc)||
        !eProducto_setCant(new,atoi(auxCant))||
        !eProducto_setImporte(new,atoi(auxImporte))||
        !eProducto_setStatus(new,atoi(auxStatus))){
            eProducto_delete(new);
            new=NULL;
        }
    }
    return new;
}

int eProducto_isValidProd(eProducto* this){
    int todoOk=0,auxCod,auxImp,auxCant,auxStatus;
    char auxDesc[50];

    if(this!=NULL){
        eProducto_getCod(this,&auxCod);
        eProducto_getImporte(this,&auxImp);
        eProducto_getCant(this,&auxCant);
        eProducto_getDesc(this,auxDesc);
        eProducto_getStatus(this,&auxStatus);

        if(auxCod>0 && auxImp >0 && auxCant >0 && auxDesc !=NULL && auxStatus==OCUPADO){
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
    printf("1. Cargar los datos de los productos desde el archivo datos.dat.\n");
    printf("2. Cargar los datos de los productos desde el archivo temporal.dat\n");
    printf("3. Alta\n");
    printf("4. Modificar\n");
    printf("5. Baja LOGICA\n");
    printf("6. Baja FISICA\n");
    printf("7. Listar productos\n");
    printf("8. Guardar los datos de los productos en el archivo datos.dat\n");
    printf("9. Guardar los datos de los productos en el archivo temporal.dat\n");
    printf("10. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,10);

    return opc;

}

int menuModify()
{
    int opc;
    system("cls");
    printf("Menu:\n\n");
    printf("1. Editar descripcion: \n");
    printf("2. Editar importe : \n");
    printf("3. Editar cantidad : \n");
    printf("4. Salir\n");

    fflush(stdin);
    utn_getEntero(&opc,20,"\nIngresar opcion : ","\nError ingresar opcion valida.",1,4);

    return opc;

}

int printProduct(eProducto* this)
{
    int todoOk=0;

    if(this!=NULL){
        if(this->activo==1){
            printf("%5d %12s %12d %10d\n", this->cod,this->desc,this->importe,this->cant);
            todoOk=1;
        }
    }

    return todoOk;
}

int compareByDesc(void* emp1, void* emp2){
    int todoOk=0;
    eProducto* p1;
    eProducto* p2;

    if(emp1!=NULL && emp2!=NULL){
         p1 = (eProducto*)emp1;
         p2 = (eProducto*)emp2;

         if(strcmp(p1->desc,p2->desc)>0){
            todoOk=1;
         }else if(strcmp(p1->desc,p2->desc)<0){
            todoOk=-1;
         }else if(strcmp(p1->desc,p2->desc)==0){
            todoOk=0;
        }
    }

    return todoOk;
}

int addProducto(LinkedList* pArrayList){
    int todoOk=0,auxCant,auxCod,auxImp;
    char auxDesc[50];
    eProducto* new=NULL;

    if(pArrayList!=NULL)
    {
        utn_getEntero(&auxCod,20,"\nIngresar codigo de producto : ","\nError ingresar ID valido : ",1,1000);
        utn_getCadena(auxDesc,50,20,"\nIngresar descripcion del producto : ","\nError ingresar descripcion valida : \n");
        utn_getEntero(&auxImp,20,"\nIngresar importe : ", "\nError ingresar importe: \n",1,100000);
        utn_getEntero(&auxCant,20,"\nIngresar cantidad : ", "\nError ingresar cantidad valida \n",1,1000);
        new=eProducto_new();
        if(new!=NULL)
        {
            if(eProducto_setCod(new,auxCod)&&
            eProducto_setDesc(new,auxDesc)&&
            eProducto_setImporte(new,auxImp)&&
            eProducto_setCant(new,auxCant)&&
            eProducto_setStatus(new,1)){
                ll_add(pArrayList,new);
                todoOk=1;
            }

        }
    }
    return todoOk;
}

int editProducto(LinkedList* pArrayList){

    eProducto* new;
    int todoOk=0,auxInt,auxId,len;
    char auxChar[50];
    char seguir='s';

    if(pArrayList!=NULL){
        len = ll_len(pArrayList);
        utn_getEntero(&auxId,20,"\nIngresar CODIGO del producto que desea modificar : ", "\nError ingresar codigo valido\n",1,1000);
        for(int i=0;i<len;i++){
            new=(eProducto*)ll_get(pArrayList,i);
            eProducto_getCod(new,&auxInt);
            if(auxId==auxInt){
                do{
                    switch(menuModify()){
                        case 1:
                            utn_getCadena(auxChar,50,20,"\nIngresar nueva descripcion del producto : ", "\nError ingresar descripcion valida\n");
                           if(eProducto_setDesc(new,auxChar)){
                            todoOk=1;
                           }
                            break;
                        case 2:
                            utn_getEntero(&auxInt,20,"\nIngresar nuevo importe  :","\nError ingresar importe valido \n",1,99999);
                            if(eProducto_setImporte(new,auxInt)){
                                todoOk=1;
                            }
                            break;
                        case 3:
                            utn_getEntero(&auxInt,20,"\nIngresar nueva cantidad :","\nError ingresar cantidad valida\n",1,100000);
                            if(eProducto_setCant(new,auxInt)){
                                 todoOk=1;
                            }
                            break;
                        case 4:
                            seguir='n';
                            break;
                        default:
                            printf("Error ingresar opcion valida o salir si desea salir!\n");
                            break;
                    }

                }while(seguir=='s');
            }
        }

    }

    return todoOk;
}
