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
/***+      //////                 ft_is_prime                  +***/
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
int ft_is_prime(int nb);
/**
 * función que devuelve 1 si el número dado como parámetro es un número primo y 0 si no lo es.
 * 
 * **/
int ft_is_prime(int nb){
	//Si se ingresa 0 o 1, se retorna 0, ya que no se consideran primos
	if((nb == 0)||(nb == 1)){
		return 0;
	}
	//Se inicia el indice en 2 ya que el 1 divide cualquier numero
	int i = 2;
	//Se comprueban los numeros desde i hasta el numero ingresado
	for(i;i<nb;i++){
		//Si i es divisor del numero ingresado, este no es primo, y se retorna 0
		if(nb%i==0){
			return 0;
		}
	}
	//Si se termina el ciclo, es que el numero es primo, se retorna 1
	return 1;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 5;
	printf("%i",ft_is_prime(numero));
	return 0;
}
