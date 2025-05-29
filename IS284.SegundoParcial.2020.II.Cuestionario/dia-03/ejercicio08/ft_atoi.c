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
/***+      //////                  ft_atoi                     +***/
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
int ft_atoi(char* str);
/**
 * Esta función convierte una cadena a su valor numérico (entero)
 * 
 * **/
int ft_atoi(char* str){
	//variable donde se almacena el numero al que corresponde la cadena
	int numero = 0;
	//variable que se multiplica por los numeros que se obtienen de la cadena, desde la cifra menos significativa hasta la mas significativa
	int potencia = 1;
	//variable para contar el tama�o de la cadena
	int size = 0;
	//variable para determinar si la cadena corresponde a un numero negativo
	int negativo = 0;
	//final esta en 0 cuando el numero es positivo, esto quiere decir que leemos la totalidad de la cadena, en caso que sea 1 el numero es negativo y leemos hasta el indice 1
	int final = 0;
	//punto desde el que empezamos a leer la cadena, ya que debemos leerla de atras hacia adelante
	int inicial = 0;
	//Comprobamos si es un numero negativo,si lo es, lo indicamos en la variable negativo y marcamos el final como el indice 1
	if(str[0] == '-'){
		negativo = 1;
		final = 1;
	}
	//Contamos el largo de la cadena
	while(str[size]!='\0'){
		size++;
	}
	//El punto inicial para leer la cadena es el tamaño - 1, leemos la cadena hasta el indice final y vamos decrementando 1 al indice
	for(int indice = size-1;indice >= final;indice--){
		/*
		-Se obtiene el caracter en el indice y se le resta 48 ya que ese es el valor de 0 en el codigo ascii
		-Se multiplica el valor obtenido por la potencia, inicialmente la potencia es 1 que corresponde a 10^0
		-El valor obtenido se suma a la variable numero, que es lo que se ha ido sumando de cada iteracion	
		*/
		numero = numero + ((str[indice]-48)*potencia);
		//La potencia se multiplica por 10 para la siguiente iteracion, la proxima vez sera 10^(n+1)
		potencia = potencia*10;
	}
	//Si el numero es negativo, se multiplica por -1
	if(negativo){
		numero = numero * -1;
	}
	return numero;
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	char* numero = "-1508";
	int valor = ft_atoi(numero);
	printf("%i",valor);
	return 0;
}
