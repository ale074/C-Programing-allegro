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
/***+      //////              The Eight Queens                +***/
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
int ft_eight_queens_puzzle();
int ft_eight_queens(int tablero[],int columna);
/**
 * El objetivo de este juego es colocar ocho reinas en un tablero de ajedrez, sin que se puedan encontrar de un solo
 * golpe.
 * Refresque sus recuerdos sobre las reglas del ajedrez.
 * Evidentemente, se requiere recurrencia para resolver este problema.
 * Crea una función que devuelva la cantidad de posibilidades para colocar esas ocho reinas en el tablero de ajedrez
 * sin que se puedan alcanzar entre sí.
 * 
 * 
 * Para este problema se toma un arreglo de la forma x = {a,b,c,d,e,f,g,h}
 * Cada posicion i del arreglo x es una columna
 * Cada valor del arreglo x[i] corresponde a la fila en la que debe ubicarse la reina de la columna i.
 * 
 * **/
int ft_eight_queens(int tablero[],int columna){
	//Definimos el iterador
	int i = 0;
	//Si la columna es 8 quiere decir que ya se ha llenado todo el tablero, por ende hay que comprobar si la solucion el valida
	if(columna==8){
		//Arreglo donde se almacena la ubicacion en filas de las reinas por cada columna
		int filas[8] = {0,0,0,0,0,0,0,0};
		//Arreglo donde se almacena la diagonal principal en la que se ubica cada reina
		int diagonalesPrincipales[8] = {0,0,0,0,0,0,0,0};
		//Arreglo donde se almacena la diagonal secundaria en la que se ubica cada reina
		int diagonalesSecundarias[8] = {0,0,0,0,0,0,0,0};
		//LLenamos los 3 arreglos 
		for(i;i<8;i++){
			//Al arreglo en i se le asigna el valor del tablero que se esta comprobando en el mismo indice
			filas[i] = tablero[i];
			//Para dos reinas que esten en la misma dianogal principal, vease como una funcion lineal con pendiente negativa, la resta entre la columna y la fila deben ser iguales
			diagonalesPrincipales[i] = i - tablero[i];
			//Para dos reinas que esten en la misma dianogal secundaria, vease como una funcion lineal con pendiente positiva, la suma entre la columna y la fila deben ser iguales
			diagonalesSecundarias[i] = i + tablero[i];
			//definimos un segundo iterador
			int j = 0;
			/*
			-Se recorre el tablero desde el inicio hasta la columna que se desea insertar en el arreglo
			-Si se quiere ingresar un numero en la columna 3 (i=2), se recorre el arreglo unicamente hasta i=1
			*/
			for(j;j<i;j++){
				//Se comprueba si las reinas estan en la misma fila,diagonal principal, o diagonal secundaria, lo que quiere decir que se atacan
				if((filas[j]==filas[i])||(diagonalesPrincipales[j]==diagonalesPrincipales[i])||(diagonalesSecundarias[j]==diagonalesSecundarias[i])){
					//Si se atacan, retornamos 0
					return 0;
				}
			}
		}
		//Si se llega a este punto quiere decir que las reinas no se atacaron, por ende la solucion es valida, se retorna un 1
		return 1;
	}
	/*
	-Si aun no se han resuelto las 8 columnas, hay que proponer soluciones
	*/
	
	//Se crean 8 tableros vacios
	int tablero1[8] = {0,0,0,0,0,0,0,0};
	int tablero2[8] = {0,0,0,0,0,0,0,0};
	int tablero3[8] = {0,0,0,0,0,0,0,0};
	int tablero4[8] = {0,0,0,0,0,0,0,0};
	int tablero5[8] = {0,0,0,0,0,0,0,0};
	int tablero6[8] = {0,0,0,0,0,0,0,0};
	int tablero7[8] = {0,0,0,0,0,0,0,0};
	int tablero8[8] = {0,0,0,0,0,0,0,0};
	//Se copia el tablero ingresado por parametro a los 8 tableros creados
	for(i;i<8;i++){
		tablero1[i]=tablero[i];
		tablero2[i]=tablero[i];
		tablero3[i]=tablero[i];
		tablero4[i]=tablero[i];
		tablero5[i]=tablero[i];
		tablero6[i]=tablero[i];
		tablero7[i]=tablero[i];
		tablero8[i]=tablero[i];
	}
	//Se proponen las 8 posibles posiciones para una reina en la columna
	tablero1[columna] = 0;
	tablero2[columna] = 1;
	tablero3[columna] = 2;
	tablero4[columna] = 3;
	tablero5[columna] = 4;
	tablero6[columna] = 5;
	tablero7[columna] = 6;
	tablero8[columna] = 7;
	/*
	-Recursivamente se retorna la suma que se obtiene de la solucion de los 8 tableros propuestos
	-Los tableros de el llamado recursivo daran solucion a la columna columna+1
	*/
	return ft_eight_queens(tablero1,columna+1) + ft_eight_queens(tablero2,columna+1) + ft_eight_queens(tablero3,columna+1) + 
	ft_eight_queens(tablero4,columna+1) + ft_eight_queens(tablero5,columna+1) + ft_eight_queens(tablero6,columna+1) + 
	ft_eight_queens(tablero7,columna+1) + ft_eight_queens(tablero8,columna+1);
}
/**
 * Declaración de la función ft_eight_queens_puzzle.
 * 
 * **/
int ft_eight_queens_puzzle(){
	//Se crea un tablero vacio
	int tablero[8] = {0,0,0,0,0,0,0,0};
	//Se retorna el resultado de la funcion que resuelve el puzzle
	return ft_eight_queens(tablero,0);
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	printf("%i",ft_eight_queens_puzzle());
	return 0;
}
