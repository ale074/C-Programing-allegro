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
/***+      //////                 21-11-2020                   +***/
/***+      //////                 Versión 2                    +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////               ft_is_negative                 +***/
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
//////                    Segundo parcial                     //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
#include <stdio.h>// inclusion de la libreria Standar Input Output
//prototipo de función
void ft_is_negative (int n);
/**
 * función que muestra 'N' ó 'P' según el signo del número entero ingresado como parámetro. Si n es negativo,
 * muestra "N". Si n es positivo o nulo, muestra "P".
 * 
 * **/
void ft_is_negative (int n)
{
    if (n >= 0)// si n es mayor o igual a cero, n es positivo
    {
        printf("P");
    }
    else
    {
        printf("N");
    }
}
/**
 * Declaración de la función main.
 * 
 * **/
int main ()
{
    int num = 4;
    ft_is_negative(num);
    return 0;
}
