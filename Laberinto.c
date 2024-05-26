#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include <ctype.h>
#include "constantes.h"

// var Globales
int turno = 0;
int numeroDeRegistro = 0;
int botPosX = 0;
int botPosY = 0;

// declaracion de la funcion
void limpiar_pantalla();
void limpiar_buffer();
int obtenerTurno();

struct Personaje
{
    char nombre[15];
    int puntaje;
    char estado[10];
};

struct Bot
{
    int posX;
    int posY;
    int movimientos;
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
    return rand() % limSup + limInf;
}

void ubicarBot(char matrix[FILAS][COLUMAS])
{
    // inicializar el generador de números aleatorios con una semilla
    // que cambia con el tiempo
    do
    {
        srand(time(NULL));
        botPosX = aleatorio(28, 1);
        botPosY = aleatorio(28, 1);
    } while (matrix[botPosY][botPosX] != 'O');
}

void posicionRandom(int *posX, int *posY, char matrix[FILAS][COLUMAS])
{
    // inicializar el generador de números aleatorios con una semilla
    // que cambia con el tiempo
    do
    {
        srand(time(NULL));
        *posX = aleatorio(28, 1);
        *posY = aleatorio(28, 1);
    } while (matrix[*posY][*posX] != 'O');
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

void verMapa(int posX, int posY, char arr[FILAS][COLUMAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMAS; j++)
        {
            if (i == posY && j == posX)
            {
                printf("\033[1;31mA \033[0m");
            }
            else if (i == botPosY && j == botPosX)
            {
                printf("\033[1;34mB \033[0m");
            }
            else
            {

                if (arr[i][j] == 'O')
                {
                    printf("  ");
                }
                else if (arr[i][j] == 'G')
                {
                    printf("\033[1;33mG \033[0m");
                }
                else if (arr[i][j] == 'S')
                {
                    printf("\033[1;35mS \033[0m");
                }
                else
                {
                    printf("\033[1;36m%c \033[0m", arr[i][j]);
                    // printf("%c ", arr[i][j]);
                }
            }
        }
        printf("\n");
    }
}

void obtenerMovimiento(int *posX, int *posY, char arr[FILAS][COLUMAS], struct Personaje *personaje)
{
    char op;
    do
    {
        limpiar_buffer();
        // printMatrix(*posX, *posY, arr);
        verMapa(*posX, *posY, arr);
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

        if (op == 'f')
        {
            if (arr[*posY][*posX] == 'G')
            {
                printf("Recogio oro +10\n");
                arr[*posY][*posX] = 'O';
                personaje->puntaje += 10;
            }
        }

        if (op == 'e')
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

int obtenerNumero(char entrada)
{
    int numero;
    scanf("%c", &entrada);

    if (isdigit(entrada))
    {                           // Verifica si el caracter ingresado es un dígito
        numero = entrada - '0'; // Convierte el caracter a su valor numérico
        return numero;
    }
    else
    {
        return 0;
    }
}

void obtenerMenu(int *posX, int *posY, char matrix[FILAS][COLUMAS])
{
    struct Personaje reportes[REGISTROS];
    int opcion = 0;
    char input;
    while (opcion != 3)
    {
        printf("\n\tMENU.\n");
        printf("1. Jugar\n");
        printf("2. Reportes.\n");
        printf("3. Salir.\n");

        printf("Selecciona una opcion > ");
        opcion = obtenerNumero(input);
        switch (opcion)
        {
        case 1:
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
            posicionRandom(posX, posY, matrix);
            obtenerMovimiento(posX, posY, matrix, &reportes[numeroDeRegistro]);
            numeroDeRegistro++;
            break;
        case 2:
            printf("\nOPCION: REPORTES\n");
            verRegistro(reportes);
            break;
        case 3:
            printf("\nADIOS\n\n");
            break;
        default:
            printf("\nOPCION NO VALIDA!\n");
            break;
        }
        limpiar_buffer();
    }
}

int main(int argc, char const *argv[])
{
    struct Bot bot;
    bot.movimientos = 3; // definir cuantos movimientos tendra el bot

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

    int x, y;
    // obtener poscion aleatoria del bot
    // ubicarBot(matrix);
    // bot.posX = botPosX, bot.posY = botPosY;
    // printf("posicion bot [%d][%d]\n", bot.posX, bot.posY);
    obtenerMenu(&x, &y, matrix);
    return 0;
}

void limpiar_buffer(void)
{
    while (getchar() != '\n')
        ;
}

int obtenerTurno()
{
    if (turno % 2 == 0)
    {
        return TURNO_USUARIO;
    }
    return TURNO_BOT;
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
