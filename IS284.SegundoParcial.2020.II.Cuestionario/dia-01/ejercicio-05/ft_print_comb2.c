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
/***+      //////               ft_print_comb2                 +***/
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
void ft_print_comb2 (void);
/**
 * función que muestra todas las combinaciones diferentes de dos dígitos entre 00 y 99, enumerados en orden
 * ascendente.
 * Este es el resultado : 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99
 * 
 * **/
void ft_print_comb2 ()
{
    // cada iterador del for es un digito a imprimir
    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            for (short l = 0; l < 10; l++)
            {
                for (short m = 0; m < 10; m++)
                {
                    if (((i*10)+j)<((l*10)+m))
                    {
						printf("%i",i);
						printf("%i",j);
						printf(" ");
						printf("%i",l);
						printf("%i",m);
						printf(",\n");
                    }
                    
                }
                
            }
            
        }
        
    }
}
/**
 * Declaración de la función main.
 * 
 * **/
int main ()
{
    ft_print_comb2();
    return 0;
}