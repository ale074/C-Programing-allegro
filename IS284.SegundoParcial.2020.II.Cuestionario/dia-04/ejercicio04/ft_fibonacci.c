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
/***+      //////                ft_fibonacci                  +***/
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
int ft_fibonacci(int index);
/**
 * función ft_fibonacci que devuelve el n-ésimo elemento de la secuencia de Fibonacci, el primer elemento
 * está en el índice 0. Consideraremos que la secuencia de Fibonacci comienza así: 0, 1, 1, 2.
 * 
 * **/
int ft_fibonacci(int index){
	//Si se ingresa un numero negativo, se retorna un -1
	if(index < 0){
		return -1;		
	}
	//Si se ingresa un 0, se retorna un 0
	else if(index == 0){
		return 0;
	}
	//Si se ingresa un 1, se retorna un 1
	else if(index == 1){
		return 1;
	}
	//Se retorna la suma de fibonaci(n-1) + fibonacci(n-2)
	return ft_fibonacci(index-1) + ft_fibonacci(index-2);

}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int index = 11;
	printf("%i",ft_fibonacci(index));
	return 0;
}
