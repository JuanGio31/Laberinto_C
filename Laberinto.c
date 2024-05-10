#include "stdio.h"
#include "stdlib.h"
struct Bot
{
    /* data */
};

void getMenu()
{
    int opcion = 0;
    while (opcion != 4)
    {
        printf("\n\tMENU.\n");
        printf("1. Jugar\n");
        printf("2. Editor de Laberintos.\n");
        printf("3. Reportes.\n");
        printf("4. Salir.\n");

        printf("Selecciona una opcion > ");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            printf("\nOPCION: JUGAR\n");
        }
        else if (opcion == 2)
        {
            printf("\nOPCION: EDITOR DE LABERINTOS\n");
        }
        else if (opcion == 4)
        {
            printf("\nOPCION: REPORTES\n");
        }
        else if (opcion == 5)
        {
            printf("\nADIOS\n");
        }
        else
        {
            printf("\nOPCION NO VALIDA!\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    getMenu();
    return 0;
}
