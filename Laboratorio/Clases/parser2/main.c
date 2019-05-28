#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[30];
    char lastName[30];
    float salary;

}eEmpleado;
int main()
{
    FILE* f;
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado));
    eEmpleado* auxEmp;
    int cont=0;
   /* char nombre[30];
    char lastName[30];
    char auxChar[30];
    char auxChar2[30];
    */

    char buffer[4][30];
    int cant;

    f = fopen("./empleados.csv","r");

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }else{
        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]", buffer[0],buffer[1],buffer[2],buffer[3]);
        printf("%s %10s %10s %8s \n", buffer[0] , buffer[1] , buffer[2] , buffer[3]);

        while(!feof(f)){
            cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]", buffer[0],buffer[1],buffer[2],buffer[3]);


           /// printf("%d %s %s %.2f \n", atoi(buffer[0]) , buffer[1] , buffer[2] , atof(buffer[3]));
            if(cant<4){
                if(feof(f)){
                    break;
                }else{
                    printf("Problema al leer el archivo bro :D\n");
                    break;
                }
            }
            (lista+cont)->id = atoi(buffer[0]);
            strcpy((lista+cont)->name,buffer[1]);
            strcpy((lista+cont)->lastName,buffer[2]);
            (lista+cont)->id = atof(buffer[3]);
            cont++;
            auxEmp=(eEmpleado*)realloc(lista,sizeof(eEmpleado)*(cont+1));
            if(auxEmp!=NULL)
            {
                lista=auxEmp;
            }
            /// printf("%d %10s %10s %8.2f \n", atoi(buffer[0]) , buffer[1] , buffer[2] , atof(buffer[3]));
        }
        printf("\n\n");
    }
    for(int i = 0; i<cont ; i++)
    {
        printf("%d %10s %10s %8.2f \n", (lista+i)->id , (lista+i)->name , (lista+i)->lastName , (lista+i)->salary);
    }
    fclose(f);
    return 0;
}
