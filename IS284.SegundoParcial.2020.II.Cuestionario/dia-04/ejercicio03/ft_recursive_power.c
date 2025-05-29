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
/***+      //////             ft_recursive_power               +***/
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
int ft_recursive_power(int nb,int power);
/**
 * función recursiva que devuelve el valor de una potencia aplicada a un número.
 * Si hay un error, la función devuelve 0.
 * 
 * **/
int ft_recursive_power(int nb,int power){
	//Si se recibe 0, se retorna 1
	if(power == 0){
		return 1;
	}
	//Si se recibe 1, se retorna el mismo numero
	else if(power == 1){
		return nb;
	}
	//En caso contrario se multiplica el numero por la potencia de x^(n-1)
	return nb * ft_recursive_power(nb,power-1);
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 5, power = 4;
	printf("%i",ft_recursive_power(numero,power));
	return 0;
}
