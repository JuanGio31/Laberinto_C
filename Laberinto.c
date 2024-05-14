#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define FILAS 30
#define COLUMAS 30
#define limiteInf 1
#define liminteSup 28
#define errorMov 0
#define aceptarMov 1

// var Globales
char matrix[FILAS][COLUMAS] =
    {{'#', '#', '#', '#', '#', '#', '#', '#', 'S', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
     {'#', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'S'},
     {'#', '#', '#', '#', '#', '#', 'O', 'O', '#', '#', '#', 'O', '#', '#', '#', 'O', '#', 'O', 'O', '#', '#', '#', '#', '#', '#', 'O', 'O', '#', 'O', '#'},
     {'#', 'O', 'O', 'G', 'O', '#', 'O', '#', 'G', 'G', '#', 'O', '#', 'G', '#', 'O', '#', 'G', '#', 'O', '#', 'O', 'O', 'O', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', '#', '#', 'O', '#', 'O', 'O', 'O', 'O', '#', 'G', '#', 'O', '#', 'O', '#', '#', 'O', 'O', '#', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', '#'},
     {'#', 'G', '#', 'O', 'O', '#', 'O', '#', '#', '#', '#', '#', '#', 'O', '#', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', '#', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', '#', '#', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', '#', '#', '#'},
     {'#', '#', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', 'O', 'O', '#', '#', 'O', '#', '#', 'O', '#', '#', '#', '#', '#', 'O', '#', 'O', '#', '#', 'G', '#'},
     {'#', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', '#', 'G', '#'},
     {'#', 'O', '#', '#', 'O', '#', '#', '#', 'O', '#', 'O', '#', 'O', '#', '#', 'O', '#', 'O', '#', '#', '#', 'O', '#', '#', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', 'O', '#', 'O', '#', 'O', 'O', '#', 'O', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', '#', 'O', '#'},
     {'#', '#', '#', 'G', '#', 'O', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', '#', 'O', '#', '#', '#', '#', '#', 'O', '#', 'O', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', 'O', '#', 'O', 'O', '#', '#', '#', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', '#'},
     {'#', '#', 'O', '#', '#', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', '#', 'O', '#', '#', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', '#', 'O', '#'},
     {'#', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', '#', 'O', '#', 'O', '#', 'O', '#', '#', 'O', 'O', '#', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', '#'},
     {'#', '#', 'O', '#', '#', 'O', 'O', 'O', 'O', '#', 'O', '#', '#', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', '#', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', '#', '#', '#', '#', 'O', '#', 'O', '#', 'O', '#', 'O', '#'},
     {'#', '#', 'O', 'O', 'O', '#', '#', '#', 'O', '#', 'O', '#', 'O', '#', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', '#', 'O', '#'},
     {'S', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', '#', 'O', 'O', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'O', 'O', 'O', 'O', '#'},
     {'#', 'O', '#', 'O', 'O', 'O', '#', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', '#', '#', '#', '#', '#', 'O', 'O', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'O', 'O', '#', 'O', '#', '#', '#'},
     {'#', 'O', '#', 'O', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'S'},
     {'#', 'O', 'O', 'O', '#', 'O', '#', 'O', 'O', '#', 'O', '#', '#', '#', '#', '#', '#', 'O', '#', '#', '#', 'O', 'O', 'O', 'O', '#', 'O', '#', '#', '#'},
     {'#', '#', '#', '#', '#', 'O', '#', 'O', '#', 'O', 'O', '#', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', '#', 'O', '#', '#', '#', '#', 'O', '#', 'O', '#'},
     {'#', 'O', '#', 'O', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', '#', '#', '#', '#', '#', '#', 'O', '#', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', '#'},
     {'#', 'O', '#', '#', '#', 'O', '#', '#', '#', '#', 'O', '#', 'O', 'O', 'O', 'O', '#', 'O', '#', 'O', '#', '#', '#', 'O', '#', 'O', '#', '#', 'O', '#'},
     {'#', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', '#', 'O', '#', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', '#'},
     {'#', 'O', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'O', '#', 'O', 'O', '#', '#', 'O', '#', 'O', '#', '#', '#', '#', '#', '#', 'O', 'O', 'O', '#'},
     {'#', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', '#', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', '#', 'O', 'O', '#'},
     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'S', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

// declaracion de la funcion
void limpiar_pantalla();

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
        else if (opcion == 3)
        {
            printf("\nOPCION: REPORTES\n");
        }
        else if (opcion == 4)
        {
            printf("\nADIOS\n\n");
        }
        else
        {
            printf("\nOPCION NO VALIDA!\n");
        }
    }
}

int rd(int limSup, int limInf)
{
    // srand(time(NULL));
    return rand() % limSup + limInf;
}

void posicionRandom(int *posX, int *posY)
{
    while (matrix[*posY][*posX] != 'O')
    {
        // inicializar el generador de números aleatorios con una semilla
        // que cambia con el tiempo
        srand(time(NULL));
        int nX = rd(28, 1);
        int nY = rd(28, 1);
        if (matrix[nY][nX] == 'O')
        {
            *posX = nX;
            *posY = nY;
        }
    }
}

void pintar(int x, int y)
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMAS; j++)
        {
            if (i == x && j == y)
            {
                printf("@ ");
            }
            else
            {
                if (matrix[i][j] == 'O')
                {
                    printf("  ");
                }
                else
                {
                    printf("%c ", matrix[i][j]);
                }
            }
        }
        printf("\n");
    }
}
void game(int *posX, int *posY)
{
    char op;
    limpiar_pantalla();
    while (1)
    {

        if (op == 'q')
        {
            break;
        }
        else
        {
            pintar(*posY, *posX);

            printf("Press key > ");
            scanf("%c", &op);
            if (op == 'a')
            {
                if (*posX > limiteInf)
                {
                    *posX--;
                }
            }
            else if (op == 's')
            {
                if (*posY < liminteSup)
                {
                    *posY++;
                }
            }
            else if (op == 'd')
            {
                if (*posX < liminteSup)
                {
                    *posX++;
                }
            }
            else if (op == 'w')
            {
                if (*posY > limiteInf)
                {
                    *posY--;
                }
            }
            printf("\n");
            limpiar_pantalla();
        }
    }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    posicionRandom(&x, &y);
    game(&x, &y);

    // getMenu();
    return 0;
}

// Codigo para limpiar pantalla
// Primero detecta el OS, luego aplicar metodo
#ifdef _WIN32
#include <windows.h>
#endif

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}