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
/***+      //////           ft_recursive_factorial             +***/
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
int ft_recursive_factorial(int nb);
/**
 * función recursiva que devuelve el factorial del número dado como parámetro.
 * Si hay un error, la función devuelve 0.
 * 
 * **/
int ft_recursive_factorial(int nb){
	//Si se recibe 1 o 0 su factorial es 1
	if((nb==1)||(nb==0)){
		return 1;
	}
	//Para otro valor, se multiplica el numero por el valor de factorial(n-1)
	return nb * ft_recursive_factorial(nb-1);
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 7;
	printf("%i",ft_recursive_factorial(numero));
	return 0;
}
