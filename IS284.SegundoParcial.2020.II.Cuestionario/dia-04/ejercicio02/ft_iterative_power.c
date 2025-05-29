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
/***+      //////             ft_iterative_power               +***/
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
int ft_iterative_power(int nb,int power);
/**
 * función iterada que devuelve el valor de una potencia aplicada a un número.
 * Una potencia inferior a 0 devuelve 0. 
 * "No es necesario manejar los desbordamientos".
 * 
 * **/
int ft_iterative_power(int nb,int power){
	//Se incializa el iterador en 1 y el numero sera la variable donde se almacena el resultado
	int i = 1,numero = 1;
	//Se incrementa el iterador hasta que llegue al valor del numero
	for(i;i<=power;i++){
		//Se multiplica el numero por nb y se almacena en la variable
		numero = numero * nb;
	}
	//Se retorna el resultado
	return numero;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 5, power = 4;
	printf("%i",ft_iterative_power(numero,power));
	return 0;
}
