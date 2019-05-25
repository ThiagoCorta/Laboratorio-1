#include <stdio.h>
#include <stdlib.h>

int main()
{
    // puntero a FILE que es la direccion d memoria de donde esta el archivo
    FILE* f ;
    FILE* f1;
    char c;


    //Abro el archivo W crea uno nuevo A lo abre y concatena cosas R lo lee, lo igualo a f para tener la dir de memoria.
    f =  fopen("./file.txt","w");

    if (f == NULL)
    {
        printf("No se pudo conseguir el archivo!!\n");
        system("pause");
        exit(1);

    }

    fprintf(f,"Mi primer archivo creado por thiago el t h i a g o y matias es alto gato");


    fclose(f);

        f1 =  fopen("./file.txt","r");

    if (f1 == NULL)
    {
        printf("No se pudo conseguir el archivo!!\n");
        system("pause");
        exit(1);

    }
    while(!feof(f))
    {

        c = fgetc(f);
        printf("%c",c);

    }

    fclose(f);
    return 0;
}
