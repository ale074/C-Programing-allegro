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
/***+      //////                 ft_div_mod                   +***/
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
void ft_div_mod(int a,int b, int* div, int* mod);
/**
 * Esta función divide los parámetros a por b y almacena el resultado en el int apuntado por div. También almacena
 * el residuo de la división entera de a por b en el int apuntado por mod.
 * 
 * **/
void ft_div_mod(int a,int b, int* div, int* mod){
	//asignamos el valor a/b a la direccion a la que apunta div
	*div = a/b;
	//asignamos el valor a%b a la direccion a la que apunta mod
	*mod = a%b;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int a = 26;
	int b = 5;
	int div,mod;
	ft_div_mod(a,b,&div,&mod);
	printf("%i --- %i",div,mod);
	return 0;
}
