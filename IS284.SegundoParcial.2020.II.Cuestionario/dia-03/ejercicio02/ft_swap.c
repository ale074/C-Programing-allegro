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
/***+      //////                  ft_swap                     +***/
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
void ft_swap(int* a,int* b);
/**
 * Esta función intercambia el valor de dos enteros cuyas direcciones se ingresan como parámetros.
 * entero a
 * entero b
 * **/
void ft_swap(int* a,int* b){
	//Se inicializa una variable de paso para almacenar el valor que tiene la direccion a la que apunta b
	int c = *b;
	//Se le asigna a la dirreccion a la que apunta b, el valor de la direccion a la que apunta a
	*b = *a;
	//Se le asigna a la dirreccion a la que apunta a, el valor de c
	*a = c;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int a = 1;
	int b = 2;
	ft_swap(&a,&b);
	printf("%i -- %i",a,b);
	return 0;
}
