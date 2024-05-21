#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include <ctype.h>
#include "constantes.h"

// var Globales
int numeroDeRegistro = 0;
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

struct Personaje
{
    char nombre[15];
    int puntaje;
    char estado[10];
};

// Función para cambiar el nombre de una persona
void setNombre(struct Personaje *personaje, char *nuevoNombre)
{
    strcpy(personaje->nombre, nuevoNombre);
}

// Función para cambiar el estado de una persona
void setEstado(struct Personaje *personaje, char *str)
{
    strcpy(personaje->estado, str);
}

void verRegistro(struct Personaje reportes[REGISTROS])
{
    int size = numeroDeRegistro;
    if (size == 0)
    {
        printf("No hay registros\n");
    }
    else
    {

        printf("Rportes: [");
        for (int i = 0; i < size; i++)
        {
            printf("nombre: %s, puntaje: %d, estado: %s", reportes[i].nombre, reportes[i].puntaje, reportes[i].estado);
            if (i < size - 1)
            {
                printf(",\n");
            }
        }
        printf("]\n");
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

void printMatrix(int posX, int posY, char arr[FILAS][COLUMAS])
{
    int inicioFila = posX - 1;
    int finFila = posX + 1;
    int inicioColumna = posY - 1;
    int finColumna = posY + 1;

    // Verificar límites
    if (inicioFila < 0)
    {
        inicioFila = 0;
    }
    if (finFila >= FILAS)
    {
        finFila = FILAS - 1;
    }
    if (inicioColumna < 0)
    {
        inicioColumna = 0;
    }
    if (finColumna >= COLUMAS)
    {
        finColumna = COLUMAS - 1;
    }

    // Imprimir celdas alrededor de [posX,posY]
    for (int i = inicioFila; i <= finFila; i++)
    {
        for (int j = inicioColumna; j <= finColumna; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void pintar(int x, int y)
{
    for (int i = y - 7; i <= y + 7; i++)
    {
        if (i >= 0 && i < FILAS)
        {
            for (int j = x - 7; j <= x + 7; j++)
            {
                if (j >= 0 && j < COLUMAS)
                {
                    if (i - 7 != x || j - 7 != y)
                    {
                        /* code */

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
                }
            }
            printf("\n");
        }
    }

    // for (int i = 0; i < FILAS; i++)
    // {
    //     for (int j = 0; j < COLUMAS; j++)
    //     {
    //         if (i - 4 > -1 && j - 4 > -1 && i + 4 < COLUMAS && j + 4 < COLUMAS)
    //         {
    //             /* code */

    //             if (i == x && j == y)
    //             {
    //                 printf("@ ");
    //             }
    //             else
    //             {
    //                 if (matrix[i][j] == 'O')
    //                 {
    //                     printf("  ");
    //                 }
    //                 else
    //                 {
    //                     printf("%c ", matrix[i][j]);
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             printf(" *");
    //         }
    //     }
    //     printf("\n");
    // }
}
void obtenerMovimiento(int *posX, int *posY, char arr[FILAS][COLUMAS], struct Personaje *personaje)
{
    char op;
    do
    {
        limpiar_buffer();
        printMatrix(*posX, *posY, arr);
        printf("Press key > ");
        scanf("%c", &op);
        int temp = 0;
        if (op == 'a')
        {
            temp = (*posX) - 1;
            if (validarMovimiento(temp, *posY, arr) == ACEPTAR_MOV)
            {
                (*posX)--;
            }
        }
        else if (op == 's')
        {
            temp = (*posY) + 1;
            if (validarMovimiento(*posX, temp, arr) == ACEPTAR_MOV)
            {
                (*posY)++;
            }
        }
        else if (op == 'd')
        {
            temp = (*posX) + 1;
            if (validarMovimiento(temp, *posY, arr) == ACEPTAR_MOV)
            {
                (*posX)++;
            }
        }
        else if (op == 'w')
        {
            temp = (*posY) - 1;
            if (validarMovimiento(*posX, temp, arr) == ACEPTAR_MOV)
            {
                (*posY)--;
            }
        }

        limpiar_pantalla();

        if (op == 'k')
        {
            if (arr[*posY][*posX] == 'G')
            {
                printf("Recogio oro +10\n");
                arr[*posY][*posX] = 'O';
                personaje->puntaje += 10;
            }
        }

        if (op == 'x')
        {
            if (arr[*posY][*posX] == 'S')
            {
                if (personaje->puntaje >= 20)
                {
                    printf("Ganaste. Puntaje: %d\n", personaje->puntaje);
                    setEstado(personaje, "Gano");
                    return;
                }
            }
        }

        if (op == 'q')
        {
            setEstado(personaje, "Abandonado");
            break;
        }
        temp = 0;
        printf("\n");
    } while (1);
}

int obtenerNumero(char input)
{
    int num;
    scanf("%c", &input);

    if (isdigit(input))
    {                      // Verifica si el caracter ingresado es un dígito
        num = input - '0'; // Convierte el caracter a su valor numérico
        return num;
    }
    else
    {
        return 0;
    }
}

void getMenu(int *posX, int *posY)
{
    struct Personaje reportes[REGISTROS];
    int opcion = 0;
    char input;
    while (opcion != 4)
    {
        printf("\n\tMENU.\n");
        printf("1. Jugar\n");
        printf("2. Editor de Laberintos.\n");
        printf("3. Reportes.\n");
        printf("4. Salir.\n");

        printf("Selecciona una opcion > ");
        opcion = obtenerNumero(input);
        if (opcion == 1)
        {
            if (numeroDeRegistro == 10)
            {
                numeroDeRegistro = 0;
            }
            char nombre[15];
            printf("Ingrese su nombre > ");
            scanf("%s", nombre);
            setNombre(&reportes[numeroDeRegistro], nombre);
            reportes[numeroDeRegistro].puntaje = 0;
            printf("\nOPCION: JUGAR\n");
            posicionRandom(posX, posY);
            obtenerMovimiento(posX, posY, matrix, &reportes[numeroDeRegistro]);
            numeroDeRegistro++;
        }
        else if (opcion == 2)
        {
            printf("\nOPCION: EDITOR DE LABERINTOS\n");
        }
        else if (opcion == 3)
        {
            printf("\nOPCION: REPORTES\n");
            verRegistro(reportes);
        }
        else if (opcion == 4)
        {
            printf("\nADIOS\n\n");
        }
        else
        {
            printf("\nOPCION NO VALIDA!\n");
        }
        limpiar_buffer();
    }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    getMenu(&x, &y);
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