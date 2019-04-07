#include <stdio.h>
#include <stdlib.h>

int main()
{

    char caracter;
    int contador;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;

    for(contador=0;contador<20;contador++)
    {
        printf("Ingresar una vocal: ");
        fflush(stdin);
        scanf("%c", &caracter);
        caracter=tolower(caracter);

        switch(caracter)
        {
            case 'a':
                contadorA++;
                break;

            case 'e':
                contadorE++;
                break;

            case 'i':
                contadorI++;
                break;

             case 'o':
                contadorO++;
                break;

            case 'u':
                contadorU++;
                break;
        }
    }

    system("cls");

    printf("La cantidad de A ingresadas: %d\n",contadorA);
     printf("La cantidad de E ingresadas: %d\n",contadorE);
      printf("La cantidad de I ingresadas: %d\n",contadorI);
       printf("La cantidad de O ingresadas: %d\n",contadorO);
        printf("La cantidad de U ingresadas: %d\n",contadorU);

    return 0;
}
