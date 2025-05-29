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
/***+      //////                 27-11-2020                   +***/
/***+      //////                 Versión 3                    +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////            Resonancia magnética              +***/
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
//////                    Tercer parcial                      //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
/**
 * Este programa permite detectar aspectos sospechosos en una imagen
 * que pueden ser indicadores de una enfermedad.
 * genera una matriz de prueba 100X100X100 y muestra un menu
 * el cual tiene como opciones:
 * [1-]. Identificar punto sospechoso
 * [2-]. Identificar lineas sospechosas
 * [3-]. Identificar imagen, (muestra el plano con más lineas sospechosas)
 * Contexto:
 * La resonancia magnética es una técnica de diagnostico por imagen en la que se obtiene
 * información de las características de diferentes puntos del cuerpo a partir de su respuesta 
 * a un campo magnético variable. Supongamos que tenemos una matriz tridimensional de puntos que
 * representa una imagen adquirida por este método, en el que cada punto tiene un valor entre 0 y
 * 255, correspondiente a un distinto nivel de gris. La imagen será como la de un cuaderno de 100
 * hojas, donde cada hoja tendrá una cuadricula de 100 x 100 puntos.
 * Se consideran sospechosos aquellos puntos para los que TODOS los puntos adyacentes tengan un
 * valor entre 20 y 40.
 * **/
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <stdlib.h>// inclusion de la libreria standard library 
//prototipos de funciones a utilizar
int puntoSospechoso(int img[100][100][100], int x, int y, int z);
int lineasSospechosas(int img[100][100][100], int z);
void identificarImagen(int img[100][100][100]);
void imprimirMatriz(int img[100][100][100], int z);
void mostrarPlanosDePunto(int img[100][100][100], int x, int y, int z);
int menu();
// void cargarPunto(int img[100][100][100], int x, int y, int z);
void clear();
/**
 * Declaracion de la funcion principal
 * **/
int main() 
{
    int salir = 1;// controla la salida (0 = salir)
    do
    {
        clear();
        salir = menu();
    } while (salir != 0);
    return 0;
}

void cargarPunto(int img[100][100][100], int x, int y, int z) 
{
    int pAdyacentes = 0;// almacena la cantidad de puntos adyacentes dentro del rango
    // if anidado que pregunta si todos los puntos adyacentes
    // tienen un valor entre 20 y 40, en tal caso devuelve un 
    // 1, de lo contrario devuelve un cero.
    for (size_t i = 0; i < 3 ; i++)
    {
        for (size_t iZ = z-1; iZ <= (z+1); iZ++)
        {
            for (size_t iY = y-1; iY <= (y+1); iY++)
            {
                for (size_t iX = x-1; iX <= (x+1); iX++)
                {
                    img[iX][iY][iZ] = 24;
                }
            }
        }x++;
        
    }
}
/**
 * Esta funcion muestra tres planos de una matriz 100x100x100 que hacen referencia
 * a todos los puntos adyacentes de una coordenada que es ingresada por pararmetro
 * **/
void mostrarPlanosDePunto(int img[100][100][100], int x, int y, int z)
{
    char *p[] = {"anterior.","actual.", "posterior."};// palabras de identificacion de plano
    int i = 0;// indice para imprimir la palabra de identificacion de plano
    for (size_t iZ = z-1; iZ <= (z+1); iZ++)
    {
        printf("\n\r\tPlano %s\n\r",p[i]);
        i += 1;// incrementa el iterador de palabra de identificación
        for (size_t iY = 0; iY < 100; iY++)
        {
            for (size_t iX = 0; iX < 100; iX++)
            {
                if (((iX >= x-1) && (iX <= x+1)) && ((iY >= y-1) && (iY <=y+1)))
                {
                    printf("%i,",img[iX][iY][iZ]);// imprime los valores de los puntos identificados
                } else {
                    printf("  ,");
                }
                
            }
            printf("\n");
            
        }
        
    }
    
}
/**
 * Esta funcion genera un menu
 * el cual tiene como opciones:
 * [1-]. Identificar punto sospechoso
 * [2-]. Identificar lineas sospechosas
 * [3-]. Identificar imagen, (muestra el plano con más lineas sospechosas)
 * tiene como parametro una matriz 100x100x100 la cual analiza mediante 
 * la ejecucion de alguna de las opciones
 * **/
int menu()
{
    int x=0, y=0, z=0;// almacenan las coordenadas ingresadas por teclado
    int img[100][100][100];// matriz que guarda la imagen
    cargarPunto(img,12,21,5);
    int opcion=0; //opcion = variable para escoger opciones del menú
    printf("|========================================|\n");
    printf("| MENU GENERAL                           |\n");
    printf("|========================================|\n");
    printf("| 0. Salir del programa                  |\n");
    printf("| 1. Identificar punto sospechoso        |\n");
    printf("| 2. Identificar lineas sospechosas      |\n");
    printf("| 3. Identificar imagen                  |\n");
    printf("|========================================|\n");
    printf("Selecione la opcion que desea ejecutar: ");
    scanf("%i", &opcion);
    while(opcion < 0 || opcion > 3)// itera hasta el usuario ingresar una opcion permitida
    {
        printf("\n Recuerda que solo se aceptan opciones numericas entre 0 y 3\n");
        printf("Selecione la opcion que desea ejecutar: ");
        scanf("%i", &opcion);
    } //fin while(opcion < 0  ||  opcion > 3)
    switch(opcion)
    {
        case 1:
                printf("\nIngrese el coordenada X: ");// pide las coordenadas del punto a verificar
                scanf("%i",&x);
                printf("\nIngrese el coordenada Y: ");
                scanf("%i",&y);
                printf("\nIngrese el coordenada Z: ");
                scanf("%i",&z);
                int sospechoso = 0;// guarda un 0 o 1 dependiendo si el punto es sospechoso
                sospechoso = puntoSospechoso(img, x, y, z);// retorna 1 si es sospechoso, en caso contrario un 0
                if (sospechoso)// determina si el punto es sospechoso o no y muestra el plano anterior, el actual y el posterior
                {
                    printf("\n\r\tEl punto indicado es sospechoso.\n");
                    mostrarPlanosDePunto(img, x, y, z);
                } else {
                    printf("\n\r\tEl punto indicado no es sospechoso.\n");
                    mostrarPlanosDePunto(img, x, y, z);
                }
                
                printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();getchar();
                break;
        case 2:
                //
                printf("\nIngrese el coordenada Z: ");
                scanf("%i",&z);
                int numLineas = 0;// almacena el numero de lineas sospechosas encontradas
                numLineas = lineasSospechosas(img,z);
                if (numLineas)// Determina si tiene lineas sospechosas 
                {
                    printf("\nSe encontraron %i lineas sospechosas\n", numLineas);
                    imprimirMatriz(img, z);
                    printf("\nplano anterior\n");
                    imprimirMatriz(img, z-1);
                    printf("\nplano posterior\n");
                    imprimirMatriz(img, z+1);
                } else {
                    printf("\nSe encontraron %i lineas sospechosas\n", numLineas);
                    imprimirMatriz(img, z);
                    printf("\nplano anterior\n");
                    imprimirMatriz(img, z-1);
                    printf("\nplano posterior\n");
                    imprimirMatriz(img, z+1);
                }
                printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();getchar();
                break;
        case 3:
                identificarImagen(img);
                printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();getchar();
                break;
    } // Fin del SWITCH
    return opcion; //Si la opcion=0 saldrá del programa
} // Fin funcion menu()
/**
 * Esta funcion determina si una posision especifica x, y, z
 * representa un "punto sospechoso"
 * Se consideran sospechosos aquellos puntos para los que TODOS 
 * los puntos adyacentes tengan un valor entre 20 y 40
 * parametros de entrada:
 * tipo entero: imagen 100X100X100 (array tridimencional)
 * tipo entero x, y, z, coordenadas de la posision
 * **/
int puntoSospechoso(int img[100][100][100], int x, int y, int z) 
{
    int pAdyacentes = 0;// almacena la cantidad de puntos adyacentes dentro del rango
    // if anidado que pregunta si todos los puntos adyacentes
    // tienen un valor entre 20 y 40, en tal caso devuelve un 
    // 1, de lo contrario devuelve un cero.
    for (size_t iZ = z-1; iZ <= (z+1); iZ++)
    {
        for (size_t iY = y-1; iY <= (y+1); iY++)
        {
            for (size_t iX = x-1; iX <= (x+1); iX++)
            {
                if ((img[iX][iY][iZ] >= 20) && (img[iX][iY][iZ] <= 40))
                {
                    pAdyacentes += 1;
                }/* else if (iZ == z && iY == y && iX == x)// en el documento no se especifica que la coordenada tenga que ser verificada, solo los adyacentes
                {
                    pAdyacentes += 1;
                }*/
            }
        }
    }
    if (pAdyacentes == 27)// determina si todos los puntos adyacentes estaban en el rango 
    {
        return 1;
    } else {
        return 0;
    }
}
/**
 * Esta funcion determina cuantas lineas sospechosas hay en 
 * un plano y retorna la cantidad mencionada
 * parametros de entrada:
 * tipo entero: imagen 100X100X100 (array tridimencional)
 * tipo entero z coordenada del plano
 * **/
int lineasSospechosas(int img[100][100][100], int z) 
{
    int nLineas = 0; // numero de lineas
    int nPuntos = 0; // numero de puntos
    for (size_t y = 1; y < 99; y++)
    {
        for (size_t x = 1; x < 99; x++)
        {
            if (puntoSospechoso(img, x, y, z))// busca si hay un punto sospechoso en esa posision
            {
                nPuntos += 1;// aumenta el numero de de puntos sospechosos seguidos
            }
            else // termina linea
            {
                if (nPuntos >= 3)// si el numero de puntos es mayor igual a 3 es linea
                {
                    nLineas += 1;
                }
                nPuntos = 0;// reinicia para buscar otra linea
            }
        }
        nPuntos = 0; // cambio de posision inicia una nueva fila
    }
    return nLineas; // retorna el numero de lineas encontradas
}
/**
 * Esta funcion recorre los planos para encontrar cual es el que tiene
 * más lineas sospechosas y lo imprime
 * parametros de entrada:
 * tipo entero: imagen 100X100X100 (array tridimencional)
 * **/
void identificarImagen(int img[100][100][100]) 
{
    //
    int mayor = 0;// almacena el mayor numero de lineas encontradas en un plano
    int lineasPlano = 0;// almacena el numero de lineas encontradas en un plano actual
    int zmayor = 0;// guarda el plano con mayor numero de lineas sospechosas encontradas
    for (size_t z = 1; z < 99; z++)// esta dentro del rango
    {
        lineasPlano = lineasSospechosas(img, z);
        if (lineasPlano >= mayor)
        {
            mayor = lineasPlano; // se asigna el mayor numero de lineas encontradas hasta ese momento
            zmayor = z;// se asigna el z con mayor numero de lineas sospechosas encontradas hasta ese momento
        }
    }
    imprimirMatriz(img, zmayor);
}
/**
 * Esta funcion imprime el plano de una matriz tridimencional
 * parametros de entrada:
 * tipo entero: imagen 100X100X100 (array tridimencional)
 * tipo entero z coordenada del plano
 * **/
void imprimirMatriz(int img[100][100][100], int z) 
{
    for (size_t y = 0; y < 100; y++) {
        for (size_t x = 0; x < 100; x++) {
            printf("%i", img[x][y][z]);
        }
        printf("\n");
    }
}
/**
 * esta funcion limpia la pantalla de la consola**/
void clear()
{
   if(system("cls"))
     system("clear");
} // fin función clear()
