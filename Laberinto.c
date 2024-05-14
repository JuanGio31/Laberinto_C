#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define FILAS 30
#define COLUMAS 30
#define LIMITE_INF -1
#define LIMITE_SUP 30
#define ERROR_MOV 0
#define ACEPTAR_MOV 1

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
void limpiar_buffer();

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

int aleatorio(int limSup, int limInf)
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
        int nX = aleatorio(28, 1);
        int nY = aleatorio(28, 1);
        if (matrix[nY][nX] == 'O')
        {
            *posX = nX;
            *posY = nY;
        }
    }
}

int validarMovimiento(int posX, int posY, char arr[FILAS][COLUMAS])
{
    int temp;
    if (posX > LIMITE_INF && posX < LIMITE_SUP &&
        posY > LIMITE_INF && posY < LIMITE_SUP)
    {

        if (arr[posY][posX] == '#')
        {
            temp = ERROR_MOV;
        }
        else
        {
            temp = ACEPTAR_MOV;
        }
    }
    else
    {
        temp = ERROR_MOV;
    }

    return temp;
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
void mover(int *posX, int *posY)
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
            int temp = 0;
            if (op == 'a')
            {
                temp = (*posX) - 1;
                if (validarMovimiento(temp, *posY, matrix) == ACEPTAR_MOV)
                {
                    (*posX)--;
                }
            }
            else if (op == 's')
            {
                temp = (*posY) + 1;
                if (validarMovimiento(*posX, temp, matrix) == ACEPTAR_MOV)
                {
                    (*posY)++;
                }
            }
            else if (op == 'd')
            {
                temp = (*posX) + 1;
                if (validarMovimiento(temp, *posY, matrix) == ACEPTAR_MOV)
                {
                    (*posX)++;
                }
            }
            else if (op == 'w')
            {
                temp = (*posY) - 1;
                if (validarMovimiento(*posX, temp, matrix) == ACEPTAR_MOV)
                {
                    (*posY)--;
                }
            }
            temp = 0;
            printf("\n");
            limpiar_pantalla();
            limpiar_buffer();
        }
    }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    posicionRandom(&x, &y);
    mover(&x, &y);

    // prueba(&x, &y);

    // getMenu();
    return 0;
}

void limpiar_buffer(void)
{
    while (getchar() != '\n')
        ;
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