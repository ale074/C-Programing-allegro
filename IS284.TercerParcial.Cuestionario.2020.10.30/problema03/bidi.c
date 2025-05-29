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
/***+      //////                 Code BIDI                    +***/
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
 * Este programa gestiona códigos BIDI de una empresa de acuerdo con los siguientes pasos:
 * Declara un arreglo de 30 x 30 y lo llena con números unos(1) y ceros(0) en forma aleatoria, 
 * donde el uno(1) represente un pixel negro y el cero(0) un pixel blanco. En todo caso los pixeles
 * de la periferia estarán siempre en blanco. (0,0 hasta 0,29); (0,29 hasta 29,29) (29,29 hasta 29,0);
 * (29,0 hasta 0,0). Debe imprimir este arreglo con los códigos ASCII = 219 = █ que representa el pixel
 * negro y el ASCII=32 (espacio en blanco = sp = space) para el pixel blanco.
 * Comprueba si el código BIDI tiene las características de los códigos BIDI asignados por la empresa,
 * y en caso contrario, calcula el número de errores detectados.
 * Información adicional: Los códigos BIDI asignados por la empresa cumplen los siguientes requisitos:
 * a) Los píxeles de la periferia están siempre en blanco.
 * b) El código tiene reservados un cuadrado de 7x7 píxeles encajado en la parte más externa superior
 *    derecha, que debe estar formado por al menos 25 píxeles negros, con cualquier disposición.
 * c) En la séptima fila, las columnas 2, 4, y 25 del array son píxeles de color negro.
 * Cualquier producto que no cumpla los tres requisitos anteriores se considera falsificado. 
 * El número de errores se calculará teniendo en cuenta solo el último requisito (c),
 * asignando un punto por cada píxel de los citados que no sea negro
 * (Tomado y adaptado de los requisitos en el documento)**/
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <stdlib.h>// inclusion de la libreria standard library
#include <unistd.h>// inclusion de la libreria unistd(POXI "Portable Operating System Interface")
//prototipos de funciones a utilizar
void definirCodigoBidi(int codigo[30][30]);
void imprimirMatriz(int matriz[30][30]);
int pixelesPeriferia(int codigo[30][30]);
int cuadradoReservado(int codigo[30][30]);
int septimaFilaNumErorr(int codigo[30][30]);
void comprobarCodigoBidi(int codigo[30][30]);
/**
 * Declaracion de la funcion principal
 * **/
int main() 
{
    int codigoBidi[30][30];// inicializa el codigo BIDI 30X30
    definirCodigoBidi(codigoBidi); // define los valores de las posisiones del codigo
    imprimirMatriz(codigoBidi); // imprime el codigo(BIDI)
    comprobarCodigoBidi(codigoBidi); // comprueba si el codigo es correcto o esta falso
    //
    return 0;
}
/**
 * Esta funcion define un codigo(BIDI)30X30 
 * la periferia en 0 el interior aleatorio 
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
void definirCodigoBidi(int codigo[30][30]) 
{
    
    int semilla = getpid(), n; // se establece una semilla para el aleatorio
    // se rrecorre el codigo
    for (size_t y = 0; y < 30; y++)
    {
        for (size_t x = 0; x < 30; x++)
        {
            //
            if ((y > 0 && y < 29) && (x > 0 && x < 29)) // para el interiror los asigna aleatoriamente
            {
                n = rand () % semilla;
                if (n > (semilla/2)) { // se asigna un caracter 1 o 0  de forma aleatorio a la matriz
                    codigo[x][y] = 1;
                } else {
                    codigo[x][y] = 0;
                }
            }
            else
            {
                codigo[x][y] = 0;
            }
        }
        
        
    }
    
}

/**
 * Esta funcion imprime un arreglo 30X30 imprimiendo caracter a caracter
 * dependiendo si es cero o uno, si es 0 imprime c1 sino imprime c2
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
void imprimirMatriz(int matriz[30][30]) 
{
    int c1 = 32, c2 = 219;// caracteres blancos=espacio, negro=219=█
    for (size_t y = 0; y < 30; y++) {
        for (size_t x = 0; x < 30; x++) {
            if (matriz[x][y] == 0)// si el caracter es 0 imprime c1
            {
                printf("%c", c1);
            }
            else// sino c2
            {
                printf("%c", c2);
            }
        }
        printf("\n");
    }
}

/**
 * Esta funcion evalua si los los pixeles de la periferia 
 * estarán siempre en blanco. 
 * es decir (0,0 hasta 0,29); (0,29 hasta 29,29) 
 * (29,29 hasta 29,0); (29,0 hasta 0,0).
 * retorna 0 si no es correcto y 1 en caso contrario.
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
int pixelesPeriferia(int codigo[30][30])
{
    int correcto = 1;// almacen  0 o 1 dependiendo  si cumple este requisito
    for (size_t y = 0; y < 30; y++)
    {
        for (size_t x = 0; x < 30; x++)
        {
            if (!((y > 0 && y < 29) && (x > 0 && x < 29)))// zona externa(periferia)
            {
                if (codigo[x][y] != 0)// si algun pixel no esta en blanco, no es correcto
                {
                    correcto = 0;
                }
                
            }
            
        }
        
    }
    return correcto;
    
}

/**
 * Esta funcion evalua si existe un cuadrado 7X7 reservado,
 * con 25 píxeles negros, negro=1
 * devuelve 1 si esta correcto 0 si es incorrecto
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
int cuadradoReservado(int codigo[30][30])
{
    // cantidad de pixeles negros
    int pixelesNegros = 0;// almacena la cantidad de pixeles negros encontrados en esa zona
    for (size_t y = 1; y < 8; y++)
    {
        for (size_t x = 22; x < 29; x++)
        {
            if (codigo[x][y] == 1) // el pixel es negro?
            {
                pixelesNegros += 1;// incrementa la cantidad de los que encuentre
            }
        }
    }
    if (pixelesNegros >= 25)// si los pixeles son almenos 25, devolvera correcto = 1
    {
        return 1;
    }
    else
    {
        return 0;// sino 0 = incorrecto
    }
    
}

/**
 * Esta funcion evalua si en la septima fila de la matriz
 * en las columnas 2, 4, 25 estan los pixeles negros
 * si es el caso devuelve 0 dado que tuvo 0 errore
 * sino devuelve el numero de pixeles que no estuvieran
 * negros.
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
int septimaFilaNumErorr(int codigo[30][30])
{
    // evalua cada posision si alguna no tiene 1, 
    // incrementa los errores segun la cantidad
    int errores = 0;// almacena el numero de errores encontrados
    if (codigo[6][2] != 1)// evalua cada posision las posisiones
    {
        errores += 1;
    }
    if (codigo[6][4] != 1)
    {
        errores += 1;
    }
    if (codigo[6][25] != 1)
    {
        errores += 1;
    }
    return errores; // retorna la cantidad de errores que haya tenido 
}


/**
 * Esta funcion evalua todas las validaciones al codigo(BIDI)
 * si esta falsificado alerta al usuario, sino le indica que 
 * es un codigo verificado.
 * parametros de entrada:
 * tipo entero: codigo 30X30 
 * **/
void comprobarCodigoBidi(int codigo[30][30])
{
    int falsificado = 1;// almacena 1 o 0 dependiendo si elcodigo es falsificado o no
    int numError = septimaFilaNumErorr(codigo);// guarda el numero de errores al verificar la septima fila
    if (pixelesPeriferia(codigo)) // devuelve uno si es correcto
    {
        if (cuadradoReservado(codigo)) // devuelve uno si es correcto
        {
            if (numError == 0) // si es igual a cero significa que no hubo error
            {
                falsificado = 0;
            }
            
        }
        
    }
    if (falsificado) // si esta falsificado alerta, sino solo dice que ha sido verificado
    {
        printf("\n\t(Peligro): Codigo Falsificado.\n\t(Numero de Errores): %i", numError);
    }
    else
    {
        printf("\n\t(Informacion): Codigo Verificado.");
    }
    
    
    
}