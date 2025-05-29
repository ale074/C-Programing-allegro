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
/***+      //////           ft_iterative_factorial             +***/
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
int ft_iterative_factorial(int nb);
/**
 * función iterada que devuelve un número. Este número es el resultado de una operación factorial basada
 * en el número dado como parámetro.
 * Si hay un error, la función devuelve 0.
 * 
 * **/
int ft_iterative_factorial(int nb){
	//Se inicializa la variable numero en 1, que es donde se almacena el resultado del factorial, tambien se inicializa el iterador
	int numero = 1,i=1;
	//Se incrementa el iterador hasta que llegue al valor del numero
	for(i;i<=nb;i++){
		//Se multiplica el numero por i y se almacena en la variable
		numero = numero * i;
	}
	//Una vez multiplicados todos los valores, se retorna
	return numero;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 7;
	printf("%i",ft_iterative_factorial(numero));
	return 0;
}
