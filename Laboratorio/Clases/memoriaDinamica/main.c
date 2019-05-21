#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* int* pNum;

    //Pido memoria dinamica, se pasa en bytes y en este caso le paso un syzeof de int.
    pNum = (int*)malloc(sizeof(int));

    if(pNum!=NULL)
    {
        *pNum = 10;

        printf("%d\n", *pNum);

        //Libera la memoria.
        free(pNum);

        printf("%d\n", *pNum);
        printf("%p\n", pNum);

        printf("ing num : \n");
        scanf("%d",pNum);

        printf("%d", *pNum);*/


        int* vec;

    //Pido memoria dinamica, se pasa en bytes y en este caso le paso un syzeof de int.
    vec = (int*)malloc(sizeof(int)*5);


    if(vec == NULL)
    {
        printf("NO SE CONSIGUIO MEMORIA !!!");
        system("pause");
        exit(1);
    }


        for (int i = 0 ; i < 5 ; i++)
        {
            printf("ingresar el numero NRO %d : ", i);
            scanf("%d", vec+i);
        }

        for (int i = 0 ; i < 5 ; i++)
        {
            printf("Numeros %d : %d \n",i,*(vec+i));
        }


        free(vec);





}
