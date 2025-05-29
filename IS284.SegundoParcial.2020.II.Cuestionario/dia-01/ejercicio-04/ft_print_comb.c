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
/***+      //////               ft_print_comb                  +***/
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
void ft_print_comb (void);
/**
 * función que muestra todas las combinaciones diferentes de tres dígitos diferentes en orden ascendente,
 * listado por orden ascendente.
 * Este es el resultado previsto: 012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789
 * 987 no está ahí porque 789 ya lo está.
 * 999 no está allí porque el dígito 9 está presente más de una vez
 * 
 * **/
void ft_print_comb ()
{
    // cada iterador del for es un digito a imprimir
    for (short i = 0; i < 8; i++)
    {
        for (short j = i+1; j < 9; j++)
        {
            for (short l = j+1; l < 10; l++)
            {
                printf("%hi",i);
                printf("%hi",j);
                printf("%hi",l);
                printf(",");
                printf(" ");
                
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
    ft_print_comb();
    return 0;
}