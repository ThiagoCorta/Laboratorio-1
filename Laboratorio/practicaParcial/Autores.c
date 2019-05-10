#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include <conio.h>
#include "Autores.h"
#include "libros.h"
#include "socios.h"
#include <ctype.h>
#include "prestamos.h"

int findEmptySlotAutor(eAutor* list, int len)
{
    int todoOk=-1;

        for(int i = 0 ; i < len ; i++)
        {
            if(list[i].isEmpty==0)
            {
                todoOk=i;
                break;
            }
        }

    return todoOk;
}

void initAutor(eAutor* list, int len)
{

    for(int i = 0 ; i < len ;i++)
    {
        list[i].isEmpty=0;
    }

}


int idAutor()
{
    static int id = 9;

    id++;

    return id;

}


int altaAutor(eAutor* list, int len)
{
    int indice ;
    int todoOk=-1;
    char nombre[31];
    char apellido[31];

    indice=findEmptySlotAutor(list,len);

    if(indice != -1)
    {
        list[indice].idAutor=idAutor();
        utn_getCadena(nombre,31,20,"Ingresar nombre del autor : \n", "Error ingresar nombre valido : \n");
        strcpy(list[indice].nombreAutor,nombre);
        utn_getCadena(apellido,31,20,"Ingresar apellido del autor : \n", "Error ingresar apellido valido : \n");
        strcpy(list[indice].apellidoAutor,apellido);
        list[indice].isEmpty=1;

        printf("\n\nAutor cargado con exito \n\n.");
        todoOk=0;
    }
    else
    {
        printf("\n\nNo hay mas espacio para nuevos autores. \n\n");
    }

    return todoOk;
}

void printAutor(eAutor list)
{
    printf("%5d %12s %12s \n", list.idAutor, list.nombreAutor,list.apellidoAutor);
}


void printAutores(eAutor* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s  \n", "ID", "Nombre", "Apellido");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printAutor(list[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay autores que mostrar.\n");

    }

}

int findAutorById(eAutor* list, int len, int id)
{
    int esta=-1;

    for(int i = 0 ; i < len ; i ++)
    {
        if(list[i].idAutor==id)
        {
            esta=i;
        }
    }
    return esta;
}
char preguntarSiEstaSeguro(char* msg, char* msgerror)
{
    char confirma;

    printf("%s", msg);
    fflush(stdin);
    confirma = tolower(getche());

    while(confirma!='s' && confirma!='n')
    {
        printf("%s", msgerror);
        fflush(stdin);
        confirma = tolower(getche());
    }

    return confirma;
}

int removeAutor(eAutor* list, int len, int id)
{
    int todoOk = -1;
    int esta;

    esta = findAutorById(list,len,id);

    if(esta!=-1)
    {
        if(preguntarSiEstaSeguro("Desea dar de baja el Autor s/n : ", "Error ingresar s/n : ")=='s')
        {
            list[esta].isEmpty=0;
            todoOk=1;
            printf("\nAutor dado de baja.\n\n");
        }
        else
        {
            printf("\nEl Autor NO fude dado de baja.\n");
        }

    }
    else
    {
        printf("\nEl Autor no se encuentra en nuestros registos.\n");
    }

    return todoOk;

}
int menuAutores()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU AUTORES**************|\n");
    printf("\n 1- Alta Autor:\n");
    printf(" 2- Baja Autor:\n");
    printf(" 3- Modificar Autor:\n");
    printf(" 4- Mostrar Autores: \n");
    printf(" 5- Salir:");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}

int menuModificarAutores()
{
    int opcion;

    system("cls");
    fflush(stdin);
    printf("1- Modificar nombre.\n2- Modificar apellido. \n3-Volver al menu principal\n\n Ingresar opcion :  ");
    scanf("%d", &opcion);

    return opcion;

}


int modifyAutor(eAutor* list, int len)
{

    int id;
    int esta;
    char auxChar[51];
    char seguir='s';
    int todoOk=-1;


    printAutores(list,len);

    printf("\n\nIngrese el ID del Autor que desea modificar:\n ");
    scanf("%d", &id);

    esta = findAutorById(list, len, id);

    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", id);
    }
    else
    {
        do
        {
            switch(menuModificarAutores())
        {
        case 1 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del Autor s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo nombre : \n", "\nError ingresar nombre valido : \n");
                strcpy(list[esta].nombreAutor,auxChar);
                printf("Autor modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }

            break;
        case 2 :
            if(preguntarSiEstaSeguro("Desea cambiar el apellido del Autor s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo apellido : \n", "\nError ingresar apellido valido : \n");
                strcpy(list[esta].apellidoAutor,auxChar);
                printf("Autor modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }
            break;

        case 3:
            seguir='n';
            break;

        default:
            printf("Ingresar opcion valida\n");
            system("pause");
            break;


        }

        }while(seguir=='s');
    }

    return todoOk;
}
int sortAutores(eAutor* list, int len)
{
    int todoOk=-1;
     eAutor auxAutor;

    for(int i = 0 ; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(stricmp(list[i].apellidoAutor, list[j].apellidoAutor)==1&& (list[i].isEmpty==1 && list[j].isEmpty==1))
                {
                    auxAutor=list[i];
                    list[i]=list[j];
                    list[j]=auxAutor;
                }
            }
            if(i==len)
            {
            todoOk=0;
            }
        }
    return todoOk;
}


void hardCodearAutores(eAutor* list, int len)
{
    eAutor autoress [21]= {
    {1,10, "juan", "perez"},
    {1,11, "cristina", "ferrera"},
    {1,12,"thiago", "corta"},
    {1,13,"diego", "fernandez"},
    {1,14, "camila", "celano"},
    {1,15, "federico", "callejeros"},
    {1,16, "nerea", "pereyra"},
    {1,17, "matias", "hamie"},
    {1,18, "dani", "class"},
    {1,19, "sabrina", "nosee"},
    {1,20, "victoria", "sanchez"},
    {11,21, "noseqponer", "bastaaa"}};
    for(int i=0;i<len;i++)
    {
        list[i] = autoress[i];
    }

}

void funcAutores(eAutor* list, int len)
{
    int seguir='s';
    int auxInt;

    do
    {
        switch(menuAutores())
        {
            case 1:
                altaAutor(list,len);
                system("pause");
                break;
            case 2:
                printAutores(list,len);
                utn_getEntero(&auxInt,20,"\n Ingresar id de autor que desea dar de baja : \n\n", "\n Error ingresar id VALIDO\n :", 0 , len);
                removeAutor(list,len,auxInt);
                system("pause");
                break;
            case 3:
                modifyAutor(list,len);
                system("pause");
                break;
            case 4:
                sortAutores(list,len);
                printAutores(list,len);
                system("pause");
                break;
            case 5:
                seguir='n';
                break;

            default:
                printf("Ingresar opc valida \n");
                break;
        }

    }while(seguir=='s');
}

