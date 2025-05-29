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
/***+      //////             ft_find_next_prime               +***/
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
int ft_find_next_prime(int nb);
/**
 * función que devuelve el siguiente número primo mayor o igual al número dado como argumento.
 * 
 * **/
int ft_find_next_prime(int nb){
	//Si se ingresa un 0 o un 1, se inicializa el numero en 2, si no el programa tomaria a 1 como el primo siguiente
	if((nb == 0)||(nb == 1)){
		nb = 2;
	}
	//Se ejecuta hasta encontrar el numero primo
	while(1){
		//iniciamos el indice en 2 ya que 1 divide cualquier numero
		int i = 2;
		//primo es 1 si el numero aun no ha sido comprobado como compuesto
		int primo = 1;
		//Probamos todos los numeros menores a el numero o hasta comprobar que el numero no es primo
		for(i;i<nb&&primo==1;i++){
			//Si algun i es divisor del numero, este no es primo
			if(nb%i==0){
				primo = 0;
			}
		}
		//Si el ciclo termino y el numero era un numero primo, se retorna
		if(primo){
			return i;
		}
		//Si el numero no era primo, sumamos 1 al numero y ejecutamos nuevamente el ciclo
		nb++;
	}	
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int numero = 104724;
	printf("%i",ft_find_next_prime(numero));
	return 0;
}
