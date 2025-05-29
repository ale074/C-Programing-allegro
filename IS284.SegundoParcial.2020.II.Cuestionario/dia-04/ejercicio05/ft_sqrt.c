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
/***+      //////                  ft_sqrt                     +***/
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
int ft_sqrt(int nb);
/**
 * función que devuelve la raíz cuadrada entera de un número (si existe), ó 0 si la raíz cuadrada no es un
 * número entero.
 * 
 * **/
int ft_sqrt(int nb){
	//Se inicializa el iterador
	int i = 0;
	//Si se ingresa un numero negativo, no tiene raiz
	if(nb < 0){
		return -1;
	}
	//Se comprueba los iteradores hasta llegar al mismo numero
	for(i;i<nb;i++){
		//Si el iterador por si mismo da el numero, es su raiz y se retorna
		if(i*i == nb){
			return i;
		}
	}
	//Si se acaba el ciclo, es que no tiene raiz entera, se retorna 0
	return 0;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 25;
	printf("%i",ft_sqrt(numero));
	return 0;
}
