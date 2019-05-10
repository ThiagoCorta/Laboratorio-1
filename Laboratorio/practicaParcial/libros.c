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

int findEmptySlotLibro(eLibros* list, int len)
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

void initLibro(eLibros* list, int len)
{

    for(int i = 0 ; i < len ;i++)
    {
        list[i].isEmpty=0;
    }

}


int idLibro()
{
    static int id = 99;

    id++;

    return id;

}


int altaLibro(eLibros* list, int len, eAutor* autores, int lenAut)
{
    int indice ;
    int todoOk=-1;
    char titulo[51];
    int idAutor;

    indice=findEmptySlotLibro(list,len);

    if(indice != -1)
    {
        list[indice].idLibro=idLibro();
        utn_getCadena(titulo,31,20,"Ingresar titulo del libro : \n", "Error ingresar titulo valido : \n");
        strcpy(list[indice].titulo,titulo);

        printAutores(autores,lenAut);
        utn_getEntero(&idAutor,20,"\n Ingresar ID del autor de este libro. : \n\n ", "\nError, ingresar ID autor valido",0,lenAut);

        while(findAutorById(autores,lenAut,idAutor)==-1)
        {
            utn_getEntero(&idAutor,20,"\n Ingresar ID del autor de este libro. : \n\n ", "\nError, ingresar ID autor valido",0,lenAut);
        }

        list[indice].idAutor=idAutor;

        list[indice].isEmpty=1;

        printf("\nLibro cargado con exito \n\n.");

        todoOk=0;
    }
    else
    {
        printf("\n\nNo hay mas espacio para nuevos libros. \n\n");
    }

    return todoOk;
}

void printLibro(eLibros list)
{
    printf("%5d %40s %10d \n", list.idLibro, list.titulo,list.idAutor);
}


void printLibros(eLibros* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %30s %25s  \n", "ID", "Titulo", "Codigo autor");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printLibro(list[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay libros que mostrar.\n");

    }

}

int findLibroById(eLibros* list, int len, int id)
{
    int esta=-1;

    for(int i = 0 ; i < len ; i ++)
    {
        if(list[i].idLibro==id)
        {
            esta=i;
        }
    }
    return esta;
}

int removeLibro(eLibros* list, int len, int id)
{
    int todoOk = -1;
    int esta;

    esta = findLibroById(list,len,id);

    if(esta!=-1)
    {
        if(preguntarSiEstaSeguro("Desea dar de baja el libro s/n : ", "Error ingresar s/n : ")=='s')
        {
            list[esta].isEmpty=0;
            todoOk=1;
            printf("\nibro dado de baja.\n\n");
        }
        else
        {
            printf("\nEl libro NO fude dado de baja.\n");
        }

    }
    else
    {
        printf("\nEl Libro no se encuentra en nuestros registos.\n");
    }

    return todoOk;

}
int menuLibros()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU AUTORES**************|\n");
    printf("\n 1- Alta libro:\n");
    printf(" 2- Baja libro:\n");
    printf(" 3- Modificar libro:\n");
    printf(" 4- Mostrar libros: \n");
    printf(" 5- Salir:");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}

int menuModificarLibros()
{
    int opcion;

    system("cls");
    fflush(stdin);
    printf("1- Modificar titulo.\n2- Modificar codigo de autor. \n3-Volver al menu principal\n\n Ingresar opcion :  ");
    scanf("%d", &opcion);

    return opcion;

}


int modifyLibro(eLibros* list, int len, eAutor* autores, int lenAu)
{

    int id;
    int esta;
    int auxInt;
    char auxChar[51];
    char seguir='s';
    int todoOk=-1;


    printAutores(autores,lenAu);

    printf("\n\nIngrese el ID del Libro que desea modificar:\n ");
    scanf("%d", &id);

    esta = findLibroById(list, len, id);

    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", id);
    }
    else
    {
        do
        {
            switch(menuModificarLibros())
        {
        case 1 :
            if(preguntarSiEstaSeguro("Desea cambiar el titulo del Libro s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo titulo : \n", "\nError ingresar titulo valido : \n");
                strcpy(list[esta].titulo,auxChar);
                printf("Libro modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }

            break;
        case 2 :
            if(preguntarSiEstaSeguro("Desea cambiar el id autor del Libro s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getEntero(&auxInt,20,"\n Ingresar el nuevo id de autor : \n\n","Error ingresar id valido. : \n",0,len);
                while(findAutorById(autores,lenAu,auxInt)==-1)
                {
                    utn_getEntero(&auxInt,20,"\n Ingresar el nuevo id de autor : \n\n","Error ingresar id valido. : \n",0,len);
                }

                list[esta].idAutor=auxInt;
                printf("Libro modificado con exito!..\n\n");
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
int sortLibros(eLibros* list, int len)
{
    int todoOk=-1;
     eLibros auxAutor;

    for(int i = 0 ; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(stricmp(list[i].titulo, list[j].titulo)==1&& (list[i].isEmpty==1 && list[j].isEmpty==1))
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


void hardCodearLibros(eLibros* list, int len)
{
    eLibros libross [21]= {
    {1,100,10, "juan y las hadas"},
    {1,101,11 ,"cristina y los perros "},
    {1,102,12,"thiago juega al lol y malgasta su vida"},
    {1,103,13,"diego no se q hace"},
    {1,104,14 ,"camila no se un titulo"},
    {1,105,15,"federico juega al lol tmnb"},
    {1,106,16 ,"nerea nose man"},
    {1,107,17 ,"matias este es alto gato"},
    {1,108, 18,"dani EL dani."},
    {1,109,19, "sabrina le gusta harry potter"},
    {1,110,20, "victoria yo q se "},
    {11,111,21, "noseqponer ya fue"}};
    for(int i=0;i<len;i++)
    {
        list[i] = libross[i];
    }

}

void funcLibros(eLibros* list, int len, eAutor* autores, int lenAu)
{
    int seguir='s';
    int auxInt;

    do
    {
        switch(menuAutores())
        {
            case 1:
                altaLibro(list,len,autores,lenAu);
                system("pause");
                break;
            case 2:
                printLibros(list,len);
                utn_getEntero(&auxInt,20,"\n Ingresar id del libro que desea dar de baja : \n\n", "\n Error ingresar id VALIDO\n :", 0 , len);
                removeLibro(list,len,auxInt);
                system("pause");
                break;
            case 3:
                modifyLibro(list,len,autores,lenAu);
                system("pause");
                break;
            case 4:
                sortLibros(list,len);
                printLibros(list,len);
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
