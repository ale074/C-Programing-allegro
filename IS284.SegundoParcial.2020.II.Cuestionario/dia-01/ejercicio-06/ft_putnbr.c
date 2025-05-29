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
/***+      //////                  ft_putnbr                   +***/
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
void ft_putnbr (int nb);
/**
 * Esta función imprime como un string, el número ingresado como parámetro. La función 
 * muestrar todos los valores posibles dentro de una variable de tipo int
 * 
 * **/
void ft_putnbr (int nb)
{
	// Se define una cadena de 6 espacios ya que los enteros signados tienen valores desde -32768 a 32767 (4 bytes)
    char digitos[] = "      ";
    // se inicializa un iterador en i que recorrera el arreglo.
    int i = 1;
    // se establese el signo dado el caso sea el numero negativo
    char charSigno = 45;
    // numero que indica si debe ir signo negativo o no. si = 1 y no = 0
    short signo = 0;
    // condicion si el numero es positivo
    if (!(nb >= 0))
    {
		signo = 1;// signo negativo 
		nb = nb * -1;
    }
    // ciclo donde se saca digito a digito y se asigna a digitos
    while (nb)
    {
        digitos[6-i] = ((nb%10) + 48);// el digito se suma con 48 para representar su equivalente en la tabla ascii
        i += 1;// aumento del itrador segun sean los digitos
        nb = nb/10;
    }
    if (signo)// si el signo  fue negativo se asigna a la cadena al final
    {
        digitos[6-i] = charSigno;
    }
    else// de lo contrario se disminuye el iterador
    {
        i -= 1;
    }
    char cadena[i];// se declara una cadena de caracteres para asignarle los digitos optenidos anteriormente
    int j = i;
    while (i > 0)
    {
        cadena[j-i] = digitos[6-i];// asignacion de los digitos a la cadena con la longitud adecuada
        i -= 1;
    }
	printf("%s",cadena);
}
/**
 * Declaración de la función main.
 * 
 * **/
int main ()
{
    ft_putnbr(42);
    return 0;
}