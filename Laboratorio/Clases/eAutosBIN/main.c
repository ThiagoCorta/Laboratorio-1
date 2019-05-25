#include <stdio.h>
#include <stdlib.h>


typedef struct{
int id;
char marca[50];
float cilindrada;

}eAuto;
int main()
{
    eAuto auto1 = {1234,"ford",1.6};
    eAuto auto2 = {9999,"renault",1.8};
    eAuto auto3 = {4567,"peugeot",1.2};

    eAuto* lista = (eAuto*) malloc (sizeof(eAuto)*3);

    if (lista == NULL)
    {
        printf("No se pudo conseguir el archivo!!\n");
        system("pause");
        exit(1);

    }

    *lista = auto1;
    *(lista+1) = auto2;
    *(lista+2) = auto3;

  //  mostrarAutos(lista,3);


    FILE* f;

    f  = fopen("./autos.dat", "ab");

    if (f == NULL)
    {
        printf("No se pudo conseguir el archivo!!\n");
        system("pause");
        exit(1);

    }

   // fwrite(lista,sizeof(eAuto),3,f);
    for(int i = 0 ; i < 3 ; i++)
    {
        fwrite(lista+i,sizeof(eAuto),1,f);

    }

    fclose(f);

    FILE* f1;
    char asd;

     f  = fopen("./autos.dat", "rb");



}

void mostrarAuto(eAuto* unAuto)
{
    if(unAuto!=NULL)
    {
        printf("%10d%10s%15.2f\n", unAuto->id, unAuto->marca, unAuto->cilindrada);

    }

}


void mostrarAutos(eAuto* lista, int tam)
{
    if(lista!=NULL && tam > 0)
    {
        printf("%10s %10s %15s\n", "ID", "MARCAS", "CILINDRADAS");
       for(int i = 0 ; i < tam ; i++)
        {
        mostrarAuto(lista+i);
        }

    }


}
