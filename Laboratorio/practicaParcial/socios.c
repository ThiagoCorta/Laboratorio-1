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

void initSocios(eSocios* list, int len)
{

    for(int i = 0 ; i < len ; i++)
    {
        list[i].isEmpty=0;
    }


}

int findEmptySlot(eSocios* list, int len)
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

int getIdSocios()
{

    static int id= 999;

    id++;

    return id;

}

int addSocio(eSocios* list, int len)
{
    int indice;
    int todoOk=-1;
    int dia;
    int mes;
    int anio;
    char sexo;
    char auxChar[31];
    char auxLastName[31];
    char auxEmail[31];
    float telefono;


    indice=findEmptySlot(list,len);

    if(indice!=-1)
    {
        list[indice].idSocio = getIdSocios();
        utn_getCadena(auxChar,31,20,"Ingresar nombre del socio: \n","Error ingresar nombre valido\n");
        strcpy(list[indice].nombreSocio,auxChar);
        utn_getCadena(auxLastName,31,20,"Ingresar apellido del socio: \n","Error ingresar apellido valido\n");
        strcpy(list[indice].apellidoSocio,auxLastName);

        printf("\n Ingresar sexo del socio m/f\n\n");
        sexo=tolower(getche());
        while(sexo!='f'&&sexo!='m')
        {
            printf("\n Error , ingresar sexo del socio valido m/f\n");
            sexo=tolower(getche());
        }
        list[indice].sexoSocio=sexo;

        utn_getEmail(auxEmail,31,20,"\nIngresar EMAIL del socio : \n", "Error, ingresar EMAIL valido\n");
        strcpy(list[indice].emailSocio,auxEmail);

        utn_getFlotante(&telefono,20,"Ingresar telefono del socio: \n", "Error ingresar telefono valido",1000000000,9999999999999999);

        pedirFecha(&dia,&mes,&anio);

        list[indice].fechaIng.dia=dia;
        list[indice].fechaIng.mes=mes;
        list[indice].fechaIng.anio=anio;

        list[indice].isEmpty=1;

        printf("\nSocio ingresado con Exito!!.\n");
        todoOk=0;
    }
    else
    {
        printf("\nNo hay mas espacio para nuevos Socios.\n");
    }

    return todoOk;
}

int findSocioById(eSocios* list, int len,int id)
{
    int esta = -1;

    for(int i = 0; i<len;i++)
    {
        if(list[i].isEmpty==1 && list[i].idSocio==id)
        {
            esta=i;
        }
    }

    return esta;


}

int removeSocio(eSocios* list, int len, int id)
{
    int todoOk = -1;
    int esta;

    esta = findSocioById(list,len,id);

    if(esta!=-1)
    {
        if(preguntarSiEstaSeguro("Desea dar de baja el socio s/n : ", "Error ingresar s/n : ")=='s')
        {
            list[esta].isEmpty=0;
            todoOk=1;
            printf("Socio dado de baja.\n\n");
        }
        else
        {
            printf("\nEl Socio NO fude dado de baja.\n");
        }

    }
    else
    {
        printf("\nEl Socio no se encuentra en nuestros registos.\n");
    }

    return todoOk;

}

int sortSocios(eSocios* list, int len)
{
   int todoOk=-1;
     eSocios socios;

    for(int i = 0 ; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(stricmp(list[i].nombreSocio, list[j].nombreSocio)==1&& (list[i].isEmpty==1 && list[j].isEmpty==1))
                {
                    socios=list[i];
                    list[i]=list[j];
                    list[j]=socios;
                }
            }
            if(i==len)
            {
            todoOk=0;
            }
        }
    return todoOk;

}


void printSocio(eSocios list)
{
    printf("%5d %12s %12s %10c %16.0f %25s %7.02d/%02d/%4d\n", list.idSocio, list.nombreSocio,list.apellidoSocio,list.sexoSocio, list.telefono, list.emailSocio,list.fechaIng.dia,list.fechaIng.mes,list.fechaIng.anio);
}


void printSocios(eSocios* list, int len)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %10s %16s %20s %120s \n", "ID", "Nombre", "Apellido", "Sexo", "Telefono","Email socio", "Fecha ing");

    for(int i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty==1)
        {
            printSocio(list[i]);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay socios que mostrar.\n");

}

}

int menuModificarSocio()
{
    int opcion;

    system("cls");
    fflush(stdin);
    printf("1- Modificar nombre.\n2- Modificar apellido. \n3- Modificar sexo. \n4- Modificar telefono\n5-Modificar Email.\n6-Volver al menu principal\n\n Ingresar opcion :  ");
    scanf("%d", &opcion);

    return opcion;

}


int modifySocio(eSocios* list, int len)
{

    int id;
    int esta;
    float auxFloat;
    char sexo;
    char auxChar[51];
    char seguir='s';
    int todoOk=-1;


    printSocios(list,len);

    printf("\n\nIngrese el ID del socio que desea modificar:\n ");
    scanf("%d", &id);

    esta = findSocioById(list, len, id);

    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", id);
    }
    else
    {
        do
        {
            switch(menuModificarSocio())
        {
        case 1 :
            if(preguntarSiEstaSeguro("Desea cambiar el nombre del socio s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo nombre : \n", "\nError ingresar nombre valido : \n");
                strcpy(list[esta].nombreSocio,auxChar);
                printf("Socio modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }

            break;
        case 2 :
            if(preguntarSiEstaSeguro("Desea cambiar el apellido del socio s/n : ", "Error ingresar s/n : ")=='s')
            {
                utn_getCadena(auxChar,50,3,"\nIngresar nuevo apellido : \n", "\nError ingresar apellido valido : \n");
                strcpy(list[esta].apellidoSocio,auxChar);
                printf("Socio modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }
            break;
        case 3 :
            if(preguntarSiEstaSeguro("Desea cambiar el sexo del socio s/n : ", "Error ingresar s/n \n")=='s')
            {
                printf("\n Ingresar nuevo sexo :  \n");
                sexo=tolower(getche());

                while(sexo!='f' && sexo!='m')
                {
                    printf("\n Error, Ingresar nuevo sexo :  \n");
                    sexo=tolower(getche());

                }
                list[esta].sexoSocio=sexo;
                printf("Socio modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }

            break;
        case 4 :
            if(preguntarSiEstaSeguro("Desea cambiar el telefono del socio s/n : " , "Error ingresar s/n : ")=='s')
            {
                 utn_getFlotante(&auxFloat,20,"\nIngresar nuevo telefono : \n", "Error ingresar telefono : \n",1000000000,9999999999999);
                list[esta].telefono=auxFloat;
                printf("Socio modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }


            break;
        case 5:
            if(preguntarSiEstaSeguro("Desea cambiar el Email del socio s/n : " , "Error ingresar s/n : ")=='s')
            {
                utn_getEmail(auxChar,31,20,"Ingresar nuevo mail del empleado: \n\n", "Error ing email valido \n");
                strcpy(list[esta].emailSocio,auxChar);
                printf("Socio modificado con exito!..\n\n");
                todoOk=0;
                system("pause");
            }

            break;
        case 6:
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

int menuSocios()
{
    int opcion;
    system("cls");
    fflush(stdin);

    printf("|**************MENU AUTORES**************|\n");
    printf("\n 1- Alta socio:\n");
    printf(" 2- Baja socio:\n");
    printf(" 3- Modificar socio:\n");
    printf(" 4- Mostrar socios: \n");
    printf(" 5- Salir:");
    printf("\n\n Ingresar opcion : ");

    scanf("%d", &opcion);

return opcion;
}

void funcSocios(eSocios* list, int len)
{
    int seguir='s';
    int auxInt;

    do
    {
        switch(menuSocios())
        {
            case 1:
                addSocio(list,len);
                system("pause");
                break;
            case 2:
                printSocios(list,len);
                utn_getEntero(&auxInt,20,"\n Ingresar id de autor que desea dar de baja : \n\n", "\n Error ingresar id VALIDO\n :", 0 , len);
                removeSocio(list,len,auxInt);
                system("pause");
                break;
            case 3:
                modifySocio(list,len);
                system("pause");
                break;
            case 4:
                sortSocios(list,len);
                printSocios(list,len);
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

