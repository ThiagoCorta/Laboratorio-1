#include <stdio.h>
#include <stdlib.h>

int main()
{
    int peso;
    int contadorEmpleados=0;
    int contadorHasta80=0;
    int contadorSupera80=0;
    char seguir;

    do
    {
        printf("Ingresar el peso del empleado que desea: ");
        fflush(stdin);
        scanf("%d", &peso);
        contadorEmpleados++;

        if(peso<=80)
        {
            contadorHasta80++;
        }
        else
        {
            if(peso>80)
            {
                contadorSupera80++;
            }
        }

        printf("Ingrese s para ingresar otro empleado...");
        fflush(stdin);
        seguir=tolower(seguir);
        scanf("%c", &seguir);

    }while(seguir=='s');

    printf("La cantidad de empleados que no superan los 80KG son : %d\n", contadorHasta80);
    printf("La cantidad de empleados que superan los 80KG: %d", contadorSupera80);

    return 0;
}
