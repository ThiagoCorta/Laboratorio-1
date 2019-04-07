#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero;

   printf("Ingresar un numero: ");
   scanf("%d", &numero);

   if(numero>0)
   {
       printf("El numero %d es positivo.", numero);
   }
   else
   {
       printf("El numero %d es negativo.", numero);
   }
    return 0;
}
