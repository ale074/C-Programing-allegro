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
/***+      //////                  ft_strrev                   +***/
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
char* ft_strrev(char* str);
/**
 * Esta función invierte el orden de los caracteres de una cadena.
 * 
 * **/
char* ft_strrev(char* str){
	//Se inicializa la cadena al revez
	char* str_rev;
	//Se inicializa un iterador para contar el largo de la cadena
	int size = 0;
	//Mientras no se llegue al final de la cadena, se suma 1 al tama�o
	while(str[size]!=0){
		size++;
	}
	//Se inicia el contador en 0
	int cont = 0;
	int i;
	//Se le resta 1 a size ya que la cadena empieza en 0, se itera mientras sea mayor o igual a 0 y se va decrementando
	for(size= size-1;size>=0;size--){
		//En la cadena al revez en la posicion del contador, se pone el caracter del iterador
		str_rev[cont] = str[size];
		//Se incrementa 1 al contador
		cont++;
	}
	//Se retorna la cadena invertida
	return str_rev;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	char* palabra = "Hola";
	char* palabra_rev;
	palabra_rev = ft_strrev(palabra);
	printf("%s",palabra_rev);
	return 0;
}
