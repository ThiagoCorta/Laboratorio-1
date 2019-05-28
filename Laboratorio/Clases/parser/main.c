#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero[]= {3,2,4,5,2,6,5,4,7,1,9,3};
    FILE* f;

    f = fopen("./numeros.txt","w");

    if(f!=NULL)
    {
       for(int i = 0 ; i<12;i++)
       {
           if((i+1)%4!=0)
           {
               fprintf(f,"%d,",numero[i]);
           }
           else{
            fprintf(f,"%d\n",numero[i]);
           }

       }
    }
    else{

        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);

    }


    return 0;
}
