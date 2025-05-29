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
/***+      //////             The Eight Queens 2               +***/
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
int ft_eight_queens_puzzle2();
void ft_eight_queens(int tablero[],int columna);
/**
 * función que muestre todas las posibles ubicaciones de las ocho reinas en el tablero de ajedrez, sin que se
 * puedan alcanzar entre sí.
 * Se requiere recursividad para resolver este problema.
 * Así es como se debe crear un prototipo: void ft_eight_queens_puzzle_2 (void);
 * Así es como se mostrará:
 * 15863724
 * 16837425
 * 17468253
 * ...
 * La secuencia va de izquierda a derecha. El primer dígito representa la posición de la primera Reina en la primera
 * columna (el índice comienza desde 1). El enésimo dígito representa la posición de la enésima reina en la enésima
 * columna.
 * Hay un salto de línea después de la última solución
 * 
 * 
 * Para este problema se toma un arreglo de la forma x = {a,b,c,d,e,f,g,h}
 * Cada posicion i del arreglo x es una columna
 * Cada valor del arreglo x[i] corresponde a la fila en la que debe ubicarse la reina de la columna i 
*/
void ft_eight_queens(int tablero[],int columna){
	//Definimos el iterador
	int i = 0;
	//Si la columna es 8 quiere decir que ya se ha llenado todo el tablero, por ende hay que comprobar si la solucion es valida
	if(columna==8){
		//Arreglo donde se almacena la ubicacion en filas de las reinas por cada columna
		int filas[8] = {0,0,0,0,0,0,0,0};
		//Arreglo donde se almacena la diagonal principal en la que se ubica cada reina
		int diagonalesPrincipales[8] = {0,0,0,0,0,0,0,0};
		//Arreglo donde se almacena la diagonal secundaria en la que se ubica cada reina
		int diagonalesSecundarias[8] = {0,0,0,0,0,0,0,0};
		//LLenamos los 3 arreglos
		for(i;i<8==1;i++){
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
					//Si se a|tacan, se aborta la funcion con un return; ya que es void
					return;
				}
			}
		}
		//Si se llega a este punto es que la solucion es correcta, en ese caso, se imprime
		for(i=0;i<8;i++){
			printf("%i",tablero[i]);
		}
		//Se imprime un salto de linea para pasar a la siguiente solucion
		printf("\n");
	}
	/*
	-Si aun no se han resuelto las 8 columnas, hay que proponer soluciones
	*/
	else{
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
		-Recursivamente se llama a la funcion con los 8 tableros para que sigan resolviendose
		-Los tableros de el llamado recursivo daran solucion a la columna columna+1
		*/
		ft_eight_queens(tablero1,columna+1);
		ft_eight_queens(tablero2,columna+1);
		ft_eight_queens(tablero3,columna+1);
		ft_eight_queens(tablero4,columna+1);
		ft_eight_queens(tablero5,columna+1);
		ft_eight_queens(tablero6,columna+1);
		ft_eight_queens(tablero7,columna+1);
		ft_eight_queens(tablero8,columna+1);
	}
}
/**
 * Declaración de la función ft_eight_queens_puzzle2.
 * 
 * **/
int ft_eight_queens_puzzle2(){
	//Se crea un tablero vacio
	int tablero[8] = {0,0,0,0,0,0,0,0};
	//Se llama la funcion que resuelve el puzzle
	ft_eight_queens(tablero,0);
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	ft_eight_queens_puzzle2();
	return 0;
}
