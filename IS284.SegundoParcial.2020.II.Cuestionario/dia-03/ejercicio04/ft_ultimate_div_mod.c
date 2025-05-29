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
/***+      //////            ft_ultimate_div_mod               +***/
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
void ft_div_mod(int* a,int* b);
/**
 * Esta función divide los parámetros a por b. El resultado de esta división se almacena en el int apuntado por a. El
 * resto de la división se almacena en el int apuntado por b.
 * 
 * **/
void ft_div_mod(int* a,int* b){
	//Guarda en una variable temporal el valor de la division entre el valor de la direccion a la que apunta a, y el valor de la direccion a la que apunta b
	int div = *a/ *b;
	//Guarda en una variable temporal el valor del modulo entre el valor de la direccion a la que apunta a, y el valor de la direccion a la que apunta b
	int mod = *a%*b;
	//Guarda en la direccion a la que apunta a el valor de la division
	*a = div;
	//Guarda en la direccion a la que apunta b el valor del modulo
	*b = mod;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int a = 26;
	int b = 5;
	ft_div_mod(&a,&b);
	printf("%i --- %i",a,b);
	return 0;
}
