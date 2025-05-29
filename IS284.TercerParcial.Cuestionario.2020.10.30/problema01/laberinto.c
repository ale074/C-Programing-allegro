////////////////////////////////////////////////////////////////////
/***+**********************************************************+***/
/***+                                                          +***/
/***+                 /////////////////////                    +***/
/***+             ////////////////////////////                 +***/
/***+          /////////////////////////////////               +***/
/***+        ////////                    ////////              +***/
/***+       ///////                                            +***/
/***+      //////  Autor. Ing(c): Alejandro Vergara Álvarez    +***/
/***+      //////               CC:1076352780                  +***/
/***+      //////                 27-11-2020                   +***/
/***+      //////                 Versión 2                    +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////                 Laberinto                    +***/
/***+      ///////                                             +***/
/***+       ///////                    /////////               +***/
/***+        //////////////////////////////////                +***/
/***+          //////////////////////////////                  +***/
/***+              //////////////////////                      +***/
/***+                                                          +***/
/***+**********************************************************+***/
////////////////////////////////////////////////////////////////////
//////                                                        //////
//////      Presentado a: PhD Ricardo Moreno Laverde          //////
//////         Universidad_Tecnologica_de_Pereira             //////
//////   Programa de Ingeniería de Sistemas y Computación     //////
//////              IS284_Programacion_II_Gr._4               //////
//////                    Tercer parcial                      //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
/**
 * Este programa permite simular un laberinto con una matriz de dimensiones 30*30 , donde los
 * pasos libres estarán representados por el carácter ASCII=32 (espacio en blanco = sp = space)
 * y los muros por el carácter ASCII = 219 = █. Se generará aleatoriamente el laberinto y en todo
 * caso la periferia estará siempre con el carácter ASCII = 219 = █. (0,2 hasta 0,29); (0,29 hasta
 * 29,29) (29,29 hasta 29,0); (29,0 hasta 2,0), las coordenadas de entrada será la fila 0 y columna
 * 0, y la salida se generara en forma aleatoria sobre la columna mas a la derecha del arreglo 
 * (columna 29), sin tocar el muro de la periferia.
 * elprograma tambien encontrara una salida del laberinto la cual será indicada sobre la misma matriz
 * con el carácter ASCII = 169 = ©, de no encontrar salida se ejecutara denuevo el algoritmo hasta 
 * generar un laberinto con salida.
 * **/
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <stdlib.h>// inclusion de la libreria standard library 
#include <unistd.h>// inclusion de la libreria unistd(POXI "Portable Operating System Interface")
//prototipos de funciones a utilizar
void definirLaberintoMatriz(char matriz[30][30]);
void imprimirMatriz(char matriz[30][30]);
void encontrarSalida(char matriz[30][30], char original[30][30], short x, short y, int ng);
int salidaAleatoria(int *semilla);
void moverBuscadorSalida(char matriz[30][30], int x, int y);
void duplicarMatriz(char destino[30][30], char origen[30][30]) ;
void laberinto(int n);
/**
 * Declaración de la funcion principal
 * **/
int main() 
{
    int n = 1;
    laberinto(n);// ejecución del algoritmo
    return 0;
}
/**
 * Esta función ejecuta el algoritmo que genera un laberinto de forma aleatoria
 * busca una posible salida, si la encuentra imprime el laberinto generado y 
 * imprime otra vez el laberinto con la salida remarcada con el caracter 169 = ©.
 * **/
void laberinto(int n)
{
    char matriz[30][30]; // se declara la matriz de 30X30(laberinto)
    char matriz1[30][30]; // se declara la matriz de 30X30(laberinto)
    definirLaberintoMatriz(matriz); // define los valores de cada posisión
    duplicarMatriz(matriz1, matriz);
    imprimirMatriz(matriz);
    printf("\n\r---------nuevo laberinto -----------------\n\r");
    encontrarSalida(matriz, matriz1, 0, 0, n); // busca una posible salida del laberinto
}
/**
 * Esta funcion define los valores de un laberinto (matriz 30X30)
 * define los valores del contorno, entrada y salida por defecto
 * en los valores internos al laberinto los asigna aleatoriamente
 * parametros de entrada:
 * tipo caracter: matriz 30X30
 * **/
void definirLaberintoMatriz(char matriz[30][30]) 
{
    int semilla = getpid(), n=0; // semilla para numeros aleatorios
    char c1 = 48, c2 = 49; // caracteres que se van a utilizar 32 = ' ' 219 = ''
    int salida = salidaAleatoria(&semilla); // numero aleatorio para determinar el lugar donde será la salida
    for (size_t i = 0; i < 30; i++) { // for que recorre las columnas
        for (size_t j = 0; j < 30; j++) { // for que recorre las filas
            // condicional (define la zona dentro del marco junto con la zona  de la entrada al laberinto) 
            if(((i == 0 || i == 1) && (j == 0 || j == 1)) || ((i > 0 && i < 29) && (j > 0 && j < 29))) {
                // define la zona interior del marco
                if ((i > 0 && i < 29) && (j > 0 && j < 29) && (!(i == 1 && j == 1))) {
                    n = rand () % semilla; // se genra el numero aleatorio que definira el caracter a asignar
                    if (n > (semilla/6)) { // se asigna un caracter aleatorio a la matriz
                        matriz[i][j] = c1;
                    } else {
                        matriz[i][j] = c2;
                    }
                } else {
                    matriz[i][j] = c1; // cuando i y j estan en los rangos 0 y 1 solo se asignara espacios
                }
            } else { // se asigna los caracteres del marco del laberinto
                if (salida == i && j == 29) { // se asigna el caracter (espacio vacio) donde ira la salida
                    matriz[i][j] = c1;
                } else { // se asigna los caracteres del marco del laberinto
                    matriz[i][j] = c2;
                }
            }
        }
    }
}

// esta funcion imprime un arreglo bidimencional de 30X30
void imprimirMatriz(char matriz[30][30]) 
{
    char letra = '*';// se asigna la letra de la posision
    for (size_t i = 0; i < 30; i++) {
        for (size_t j = 0; j < 30; j++) {
            letra = matriz[i][j];// para cada posision 
            printf("%c", letra);
        }
        printf("\n");
    }
}
// esta funcion imprime un arreglo bidimencional de 30X30
void duplicarMatriz(char destino[30][30], char origen[30][30]) 
{
    for (size_t i = 0; i < 30; i++) {
        for (size_t j = 0; j < 30; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}
/**
 * Esta funcion devuelve un numero aleatorio dentro del rango
 * de salida del laberinto 1 < rango < 28
 * parametros: semilla para aleatorio
 * **/
int salidaAleatoria(int *semilla) 
{
    int n = rand () % *semilla;//determina la posision de la salida de forma aleatoria
    if (n > 1 && n < 28) {
        return n;
    } else {
        salidaAleatoria(semilla);
    }
}

/**
 * Esta funcion busca una posible salida del laberinto 30X30
 * es recursiva por lo que se llamara a si misma moviendose 
 * entre posisiones hasta encontrar una salida o determinar 
 * que el laberinto no tiene salida
 * parametros de entrada:
 * tipo caracter: matriz 30X30
 * tipo short: y posision vertical
 * tipo short: x posision horizontal
 * **/
void encontrarSalida(char matriz[30][30], char original[30][30], short y, short x, int ng) 
{
    // caracteres a implementar: c1 = espaciolibre, c2 = muro, c3 = recorrido.
    char c1 = 48, c2 = 49, c3 = 169;// caaracteres espacio, muro y camino recorrido
    if ((x == 0) && (0 == y)) // control de la entrada al laberinto
    {
        int n = 0;// se usa para iniciar el camino desde la entrada
        matriz[n][n] = c3;
        matriz[n][n+1] = c3;
        matriz[n+1][n+1] = c3;
        encontrarSalida(matriz, original, n+1, (n+1), ng);
    } 
    else if ((x > 0 && x < 29) && (y > 0 && y < 28)) // control interno del laberinto
    {
        if ((matriz[y][x+1] == c1)) // si a la derecha no hay muro, entonces avanzo a la derecha
        {
            matriz[y][x+1] = c3;
            encontrarSalida(matriz, original, y, (x+1), ng);
        }
        else if ((matriz[y+1][x] == c1)) // si abajo no hay muro, entonces avanza hacia abajo
        {
            matriz[y+1][x] = c3;
            encontrarSalida(matriz, original, (y+1), x, ng);
        }
        else if ((matriz[y][x-1] != c2)) // si a la izquierda no hay muro, entonces avanza hacia la izquierda
        {
            matriz[y][x-1] = c3;
            encontrarSalida(matriz, original, y, x-1, ng);
        }
        else if ((matriz[y-1][x] != c2)) // si arriba no hay muro, entonces avanza hacia arriba
        {
            matriz[y-1][x] = c3;
            encontrarSalida(matriz, original, (y-1), x, ng);
        }
        else if ((matriz[y][x+1] != c2)) // si a la derecha no hay muro entonces avanzo a la derecha
        {
            matriz[y][x+1] = c3;
            encontrarSalida(matriz, original, y, (x+1), ng);
        }
        else if ((matriz[y+1][x] != c2)) // si abajo no hay muro, entonces avanza hacia abajo
        {
            matriz[y+1][x] = c3;
            encontrarSalida(matriz, original, (y+1), x, ng);
        }
    }
    else if (x == 29)// si se encuentra una salida
    {
        imprimirMatriz(original); // imprime la matriz con los valores definidos(aleatoriamente)
        printf("Salida Encontrada.\n"); // imprime la salida encontrada
        imprimirMatriz(matriz); // imprime la matriz con la salida marcada con el caracter 169
        printf("Laberintos generados: %i\n", ng); // imprime el numero de laberintos encontrados
    }
    else // si no se encuentra salida
    {
        laberinto(ng+1);
    }
}