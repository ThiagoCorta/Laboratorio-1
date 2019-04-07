#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero;
   int contadorPares=0;

   for(numero=0;numero<=100;numero++)
   {
       if(numero%2==0 && numero!=0)
       {
           contadorPares++;
           printf("Numero par: %d \n", numero);
       }
   }

   printf("Cantidad de pares: %d", contadorPares);

    return 0;
}
