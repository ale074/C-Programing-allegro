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
/***+      //////            ft_sort_integer_table             +***/
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
void ft_sort_integer_table(int* tab,int size);
/**
 * función que clasifiqua una matriz (tabla) de números enteros en orden ascendente.
 * Los argumentos son un puntero a int y el número de ints en la matriz.
 * 
 * **/
void ft_sort_integer_table(int* tab,int size){
	//define los iteradores
	int i,j,x,y;
	/* i y j inician en 0, se incrementan de 1 en 1 hasta size, 
	 * para comparar cada valor(i,j) con todos los valores de la misma matriz */
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			/* x e y inician en 0, se incrementan de 1 en 1 hasta size, 
	 		 * para recorrer la matriz y comparar sus valores con cada posision (i,j) */
			for(x=0;x<size;x++){
				for(y=0;y<size;y++){
					/* La idea es intercambiar los valores iniciales por los menores valores que
					 * encuentra, despues de encontrar el menor valor de toda la matriz, pasa a la siguiente
					 * posision y ubica ahi el 2 menor valor encontrado en toda la matriz, avanza a la siguiente  
					 * y los va ubicando de la misma manera.
					 * por eso se comprueba que x sea menor a i e y menor a j, para respetar los valores menores ya ubicados*/
					if((x>=i)&&(y>=j)){
						/* tab es la posicion inical del arreglo
						 * i y x son el numero de la fila, por eso debe multiplicarse por size
						 * j e y son el indice en la fila, debe siempre ser mayor la posision(x,y) que la posision(i,j)
						 * La posicion de memoria para tab[i][j] con punteros es tab + (i*size) + j
						 * Se comprueba que el valor tab[i][j] sea mayor a tab[x][y], si lo son, se intercambian*/
						if((*(tab+(i*size)+j))>(*(tab+(x*size)+y))){
							//Se crea una variable temporal para hacer el intercambio de valores, y se le da el valor de la primera direccion
							int aux = *(tab+(x*size)+y);
							//Se asigna a la segunda direccion el valor de la primera
							*(tab+(x*size)+y) = *(tab+(i*size)+j);
							//Se asigna el valor de la variable temporal a la primera direccion
							*(tab+(i*size)+j) = aux;
						}
					}
				}
			}
		}
	}
	//Se imprime la matriz resuelta
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%i ",*(tab+(i*size)+j));
		}
		printf("\n");
	}
}
/**
 * Declaración de la función main.
 * 
 * **/
int main(){
	int size = 2;
	int matriz[2][2] = {{4,3},{2,1}};
	ft_sort_integer_table(matriz,2);
	return 0;
}
