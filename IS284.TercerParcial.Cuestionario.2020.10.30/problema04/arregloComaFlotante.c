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
/***+      //////                 14-11-2020                   +***/
/***+      //////                 Versión 2                    +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////                Coma Flotante                 +***/
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
 * Este programa genera un arreglo de tipo float bidimensional de 8 x 8
 * con números aleatorios entre 0.0 y 15.0 con un(1) decimal y lo imprime
 * en pantalla de forma ordenada.
 * Luego presenta cada caso en pantalla.
 * b.- Moda: El valor que mas se repite en el arreglo e indica cuantas veces esta.
 * c.- El promedio(a un decimal) de cada fila y de cada columna
 * d.- La (suma de la diagonal superior menos (-) la suma de la inferior) / promedio(a un decimal) del arreglo.
 * e.- Calcula e imprime, un arreglo que contenga los factoriales de la parte entera de todos los valores generados en el enciso a.
 * f.- Indica cuantas veces se encuentra el promedio.
 * g.- El promedio de los valores mas altos de cada fila y cada columna**/
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <stdlib.h>// inclusion de la libreria standard library
#include <unistd.h>// inclusion de la libreria unistd(POXI "Portable Operating System Interface")
#include <math.h>// archivo de cabecera de la biblioteca estándar del lenguaje de programación C
//prototipo de funciones a utilizar
void llenarRandomArray(float array[8][8], float a, float b);// llena un array tipo float 8X8 de numeros aleatorios entre a y b.
void generarRandomArray(float array[8][8]);// genera un array tipo float 8X8 con numeros aleatorios entre 0.0 y 15.0 y lo imprime de forma ordenada.
void imprimirArray(float array[8][8]);// imprime un array de forma ordenada.
void moda(float array[8][8]);// determina la moda de una colleció de un array bidimencional.
void promediarCadaFilaYCadaColumna(float array[8][8]);//saca  el promedio de cada fila y cada columna y muestra los resultados.
void llenarPromedioColumnas(float arrayPromedioColumnas[8], float array[8][8]);// llena un array con el promedio de cada una de las columnas.
void llenarPromedioFilas(float arrayPromedioFilas[8], float array[8][8]);// llena un array con el promedio de cada una de las filas.
void mostrarEsquemaPromedioColumnasYFilas(float arrayPromedioColumnas[8], float arrayPromedioFilas[8], float array[8][8]);//muestra un esquema con los promedios de las filas y columnas.
float restarSumaDiagonalInferiorASuperior(float array[8][8]);// retorna la resta de la suma de la diagonal inferior a la suma de la diagonal superior.
float promediarElementosArray(float array[8][8]);// retorna el promedio de todos los elementos de una array tipo float 8X8.
float encisoD(float array[8][8]);// resuelve el encisoD.
unsigned long long factorial(int n);// calcula y retorna el factorial de un numero entero.
void arrayFactoriales(float array[8][8]);// genera e imprime, un arreglo que contiene los factoriales de la parte entera de todos los valores generados en el array.
void encontrarVecesPromedio(float array[8][8]);// evalua e imprime las veces en las que esta presente el promedio en la collección de valores del array.
void promediarValoresAltosFilasYColumnas(float array[8][8]);// calcula e imprime, el promedio de los valores mas altos de cada fila y cada columna.
/**
 * Declaracion de la funcion principal
 * **/
int main()
{
    float array[8][8];// array que almacenara los numeros aleatorios
    generarRandomArray(array); // enciso a 
    moda(array); // enciso b
    promediarCadaFilaYCadaColumna(array); // enciso c
    printf("\n(Enciso d) : %.1f\n", encisoD(array)); // enciso d
    arrayFactoriales(array); // enciso e
    encontrarVecesPromedio(array); // enciso f
    promediarValoresAltosFilasYColumnas(array); // enciso g

    return 0;
}// fin función main
/**
 * Esta funcion calcula e imprime el promedio de los valores mas altos de cada fila y cada columna.
 * parametros de entrada:
 * tipo int: numero
 * **/
void promediarValoresAltosFilasYColumnas(float array[8][8])
{
    //
    int cont = 0;//contador de los valores altos a evaluar
    float valorAlto = 0;// valor más alto de la colección que se esta evaluando
    float valor = 0;// valor de la colección que se esta evaluando
    float sumaValoresAltos;// suma de numeros altos de cada fila y cada columna
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x < 8; x++)// recorre cada fila
        {
            valor = array[x][y];// valor que se esta evaluando
            if (valor >= valorAlto)// mayor igual al mayor
            {
                valorAlto = valor;// se asigna como mayor
            }
        }
        cont += 1;// se incrementa el numero de valores altos
        sumaValoresAltos += valorAlto;// se suma un valor alto
    }
    valorAlto = 0;// se reinicia el valor más alto
    for (size_t x = 0; x < 8; x++)
    {
        for (size_t y = 0; y < 8; y++)// recorre cada columna
        {
            valor = array[x][y];// valor que se esta evaluando
            if (valor >= valorAlto)// mayor igual al mayor
            {
                valorAlto = valor;// se asigna como mayor
            }
        }
        cont += 1;// se incrementa el numero de valores altos
        sumaValoresAltos += valorAlto;// se suma un valor alto
    }
    printf("\n(PROMEDIO) El promedio de los valores mas altos de cada fila y cada columna es: %.1f.\n",(sumaValoresAltos/cont));// imprime el resultado encontrado
    
}

/**
 * Esta funcion evalua cuantas veces esta presente el promedio dentro de un array 8X8
 * el promedio es correspondiente a el promedio de los elementos del array.
 * parametros de entrada:
 * tipo int: numero
 * **/
void encontrarVecesPromedio(float array[8][8])
{
    int repeticiones = 0;//veces que esta el promedio
    float promedio = (promediarElementosArray(array)*10);// pormedio de elementos
    promedio = floor(promedio)/10;
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x < 8; x++)
        {
            if (promedio == array[x][y])// cuando el promedio este presente
            {
                repeticiones += 1;// incrementa el numero de veces que lo ha encontrado
            }
            
        }
        
    }
    printf("\n(PROMEDIO) El promedio es %.1f y esta presente %i veces.\n",promedio,repeticiones);// imprime el resultado encontrado
}// fin función encontrarVecesPromedio

/**
 * Esta funcion Calcula y imprime, un arreglo que contiene los factoriales de la parte
 * entera de todos los valores generados en un array que recibe como parametro..
 * parametros de entrada:
 * tipo int: numero
 * **/
void arrayFactoriales(float array[8][8])
{
    printf("\n(FACTORIALES) los factoriales de la parte entera de todos los 'Elementos aleatorios(generados)'.\n\n");
    unsigned long long valor = 0;// valor del factorial de la parte entera de elemento en array
    int arrayFactoriales[8][8];// array que almacena los valores factoriales
    for (size_t y = 0; y < 8; y++)
    {
        printf("  (Fila #%i):   ",(y+1));// imprime el numero de la fila para facilitar la ientificación
        for (size_t x = 0; x < 8; x++)
        {
            valor = factorial((int)(array[x][y]));// asigna el factorial de la parte entera de los valores de array
            arrayFactoriales[x][y] = valor;// asigna al array de factoriales el valor
            printf("%llu  ",valor);// imprime los valores factoriales
        }
        printf("\n\n");
    }
    
}// fin función arrayFactoriales

/**
 * Esta funcion calcula el factorial de un número entero
 * y devuelve el resultado como parametro.
 * parametros de entrada:
 * tipo int: numero
 * **/
unsigned long long factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    return (n * factorial(n-1));
}// fin función factorial

/**
 * Esta funcion resuelve los requerimientos el enciso d del problema 04 de este tercer parcial.
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
float encisoD(float array[8][8])
{
    float encisoD = restarSumaDiagonalInferiorASuperior(array)/promediarElementosArray(array);
    return encisoD;
}// fin función encisoD

/**
 * Esta funcion calcula el promedio de los elementos de un array 8X8.
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
float promediarElementosArray(float array[8][8])
{
    float sumaArray = 0;
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x < 8; x++)
        {
            sumaArray += array[x][y];// suma todos los elementos del array
        }
        
    }
    return (sumaArray/(8*8));// retorna el promedio de todos los elementos

}// fin función promediarElementosArray

/**
 * Esta funcion calcula la suma de la diagona superior y suma de la inferior y retorna
 * la resta de la suma de la diagonal inferior a la suma de ladiagonal superior.
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
float restarSumaDiagonalInferiorASuperior(float array[8][8])
{
    float sumaDSuperior = 0;// suma de los elementos de la diagonal superior
    float sumaDInferior = 0;// suma de los elementos de la diagonal inferior
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = y; x < 8; x++)// la columna inicia en el valor de y
        {
            sumaDSuperior += array[x][y];// suma de la diagonal superior
        }
    }
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x <= y; x++)// la columna avanza hasta el valor de y
        {
            sumaDInferior += array[x][y];// suma de la diagonal superior
        }
    }
    return sumaDSuperior-sumaDInferior;
}// fin función restarSumaDiagonalInferiorASuperior

/**
 * Esta funcion evalua cual es el promedio de cada fila y cada columna
 * y lo imprime de modo que lo muestre de una forma entendible.
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
void promediarCadaFilaYCadaColumna(float array[8][8])
{
    //
    float arrayPromedioColumnas[8];// se inicializa un array que almacene el promedio de cada columna
    float arrayPromedioFilas[8];// se inicializa un array que almacene el promedio de cada fila
    llenarPromedioColumnas(arrayPromedioColumnas,array);// se llena el arreglo con los promedios de las columnas de array
    llenarPromedioFilas(arrayPromedioFilas,array);// se llena el arreglo con los promedios de las filas de array
    mostrarEsquemaPromedioColumnasYFilas(arrayPromedioColumnas, arrayPromedioFilas, array);// muestra los promedios de cada fila y de cada columna
}// fin función promediarCadaFilaYCadaColumna

/**
 * Esta funcion muestra un esquema donde se visualiza el promedio de cada fila y de cada columna
 * de un array de tipo comaflotante.
 * parametros de entrada:
 * tipo float: arrayPromedioColumnas[8] // array que almacena el promedio de cada columna
 * tipo float: arrayPromedioFilas[8] // array que almacena el promedio de cada fila
 * tipo float: array 8X8
 * **/
void mostrarEsquemaPromedioColumnasYFilas(float arrayPromedioColumnas[8], float arrayPromedioFilas[8], float array[8][8])
{
    //Se imprime la cabecera de la nota
    printf("\n(PROMEDIO) de cada fila y de cada columna\n\n");
    printf("      ");
    for (size_t i = 0; i < 8; i++)// se imprime los promedios de las columnas
    {
        if (arrayPromedioColumnas[i] < 10)
        {
            printf("0%.1f  ",arrayPromedioColumnas[i]);
        } else {
            printf("%.1f  " ,arrayPromedioColumnas[i]);
        }
    }
    printf("\n      ");
    for (size_t i = 0; i < 8; i++)// se imprime los caracteres de especificación
    {
        printf(" ||   ");
    }
    printf("\n");
    for (size_t y = 0; y < 8; y++)// recorre cada fila
    {
        printf("      ");
        for (size_t x = 0; x < 8; x++)// recorre cada columna
        {
            if (array[x][y] < 10)
            {
                printf("0%.1f  ",array[x][y]);
            } else {
                printf("%.1f  " ,array[x][y]);
            }
        }
        if (arrayPromedioFilas[y] < 10)// imprime el promedio de cada fila al final de la misma
        {
            printf("  =  0%.1f",arrayPromedioFilas[y]);
        } else {
            printf("  =  %.1f" ,arrayPromedioFilas[y]);
        }
        printf("\n");
    }
    
    
}// fin función mostrarEsquemaPromedioColumnasYFilas

/**
 * Esta funcion calcula el promedio de cada fila de un array 8X8
 * y los almacena en un array de 8 posisiones.
 * parametros de entrada:
 * tipo float: arrayPromedioFilas[8] // array que almacena el promedio de cada fila
 * tipo float: array 8X8
 * **/
void llenarPromedioFilas(float arrayPromedioFilas[8], float array[8][8])
{
    //
    float sumaFila = 0; // almacena la suma de los elementos de la fila
    for (size_t y = 0; y < 8; y++)
    {
        sumaFila = 0;// se reinicia el valor para cada fila
        for (size_t x = 0; x < 8; x++)// evalua cada fila
        {
            sumaFila += array[x][y];
        }
        arrayPromedioFilas[y] = sumaFila/8;
    }
    
}// fin función llenarPromedioFilas

/**
 * Esta funcion calcula el promedio de cada columna de un array 8X8
 * y los almacena en un array de 8 posisiones.
 * parametros de entrada:
 * tipo float: arrayPromedioColumnas[8] // array que almacena el promedio de cada columna
 * tipo float: array 8X8
 * **/
void llenarPromedioColumnas(float arrayPromedioColumnas[8], float array[8][8])
{
    //
    float sumaColumna = 0; // almacena la suma de los elementos de la columna
    for (size_t x = 0; x < 8; x++)
    {
        sumaColumna = 0;// se reinicia el valor para cada columna
        for (size_t y = 0; y < 8; y++)// evalua cada columna
        {
            sumaColumna += array[x][y];
        }
        arrayPromedioColumnas[x] = sumaColumna/8;
    }
    
}// fin función llenarPromedioColumnas

/**
 * Esta funcion evalua cual es el valor que más se repite en el array
 * y imprime la moda con el número de veces que se repite, de no tener
 * valores que se repitan más de una vez el programa determinara que 
 * la coleccion de valores no tiene moda.
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
void moda(float array[8][8])
{
    float valorMayor = 0.0;// valor que más se repite
    int vecesMayor = 0; // veces que se repite el valor más repetido
    float valor = 0.0;// valor dinamico
    int veces = 0; // veces que se repite el valor dinamico
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x < 8; x++)
        {
            veces = 0;
            valor = array[x][y];// se asigna el valor dinamico
            for (size_t i = 0; i < 8; i++)
            {
                for (size_t j = 0; j < 8; j++)
                {
                    if (valor == array[j][i])// si el valor es igual entonces incrementa
                    {
                        veces += 1;
                    }
                    
                }// fin for x dinamico
                
            }// fin for y dimanico
            if (vecesMayor <= veces)// si es mayor igual al mayor entonces se asigna al mayor
            {
                vecesMayor = veces;// las veces repetidas pasan a ser el mayor numero de veces
                valorMayor = valor;// y el valor del mayor cambia
            }
        }// fin for x 
    }// fin for y
    if (vecesMayor <= 1)
    {
        printf("\n(MODA): No hay moda dentro de la colecci%cn de valores.\n",162);
    } else {
        printf("\n(MODA): el valor mas repetido fue : %.1f\n",valorMayor);
        printf("        Se repitio %i veces\n",vecesMayor);// imprime el resultado
    }
    
}// fin función moda

/**
 * Esta funcion a partir de un array(8X8) bacio, genera un arreglo de tipo
 * float bidimensional de 8 x 8 con números aleatorios entre 0.0 y 15.0
 * con un(1) decimal y lo imprime en pantalla de forma ordenada.
 * parametros de entrada:
 * tipo float: array 8X8 del que generara el RandomArray
 * **/
void generarRandomArray(float array[8][8])
{
    srand(getpid());
    llenarRandomArray(array, 0.0, 15.0);
    printf("\nElementos aleatorios(generados)\n");
    imprimirArray(array);
}// fin función generarRandomArray

/**
 * Esta funcion llena un array de 8X8 con numeros aleatorios 
 * entre a y b, a y b son variables de tipo entero ingresadas
 * como parametros de entrada.
 * parametros de entrada:
 * tipo float: array 8X8
 * float  a >= 0
 * float  (0 < b < a)
 * **/
void llenarRandomArray(float array[8][8], float a, float b)
{
    float aux = 0;
    if (a <= 0)// si es 0 debe cambiarse por 99 
    {
        a = 99;
    } else {// sino se multiplica por 1000 para 0.1 = 1000/1000 
        a *= 1000;
    }
    b *= 1000;
    for (size_t y = 0; y < 8; y++)// recorre cada fila
    {
        for (size_t x = 0; x < 8; x++)// recorre cada columna
        {
            aux = floor(((rand () % (int)(b-a+1) + a) / 1000.0f)*10);
            array[x][y] = aux/10;// se genera un numero entre a y b
        }
    }
}// fin función llenarRandomArray

/**
 * Esta funcion imprime un array 8X8
 * parametros de entrada:
 * tipo float: array 8X8
 * **/
void imprimirArray(float array[8][8])
{
    // 
    for (size_t y = 0; y < 8; y++)// recorre cada fila
    {
        for (size_t x = 0; x < 8; x++)// recorre cada columna
        {
            if (array[x][y] < 10)
            {
                printf("0%.1f  ",array[x][y]);
            } else {
                printf("%.1f  " ,array[x][y]);
            }
        }
        printf("\n");
    }
}// fin función imprimirArray