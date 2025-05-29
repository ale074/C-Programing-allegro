////////////////////////////////////////////////////////////////////
/***+**********************************************************+***/
/***+                                                          +***/
/***+                 /////////////////////                    +***/
/***+             ////////////////////////////                 +***/
/***+          /////////////////////////////////               +***/
/***+        ////////                     ////////             +***/
/***+       ///////                                            +***/
/***+      //////  Ing(c) Alejandro Vergara Álavrez            +***/
/***+      //////           CC:1076352780                      +***/
/***+      //////            15-11-2020                        +***/
/***+      ////// Universidad_Tecnologica_de_Pereira           +***/
/***+      //////    IS284_Programacion_II_Gr._4               +***/
/***+      //////    PhD Ricardo Moreno Laverde                +***/
/***+      //////        Tercer parcial III                    +***/
/***+      ///////                                             +***/
/***+       ///////                    ////////                +***/
/***+        ////////////////////////////////                  +***/
/***+          ////////////////////////////                    +***/
/***+              ////////////////////                        +***/
/***+                                                          +***/
/***+**********************************************************+***/
////////////////////////////////////////////////////////////////////
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <string.h>// inclusion de la libreria String para manejo de cadenas
#include <math.h>// inclusion de la libreria String para manejo de cadenas


long resolverCadenaPolinomica(char cadena[], long x);
long leerNumero(char cadena[], int *pos, long num);
/**
 * Declaracion de la funcion principal
 * **/
int main()
{
    char cadena[255];
    int rinicial = 0;
    int rfinal = 0;
    int incremento = 0;
    printf("\nCalcular Funci%cn Polin%cmica\nSe pide ingresar una funci%cn del tipo:",162,162,162);
    printf("\n\n\t%c(x)= A1X%cn + A2X%c(n-1) + ...AnX%c + b\n",159,94,94,251);
    printf("\nDonde: A1, A2...An son los coeficientes y b el termino independiente.");
    printf("\n\n\tEjemplo: %c(x) = 348X5-784X2+6 .\n");
    printf("\n\nIngresar Funci%cn Polin%cmica -> ",162,162);
    scanf("%s",cadena);
    printf("\n\nIngresar Rango Inicial -> ");
    scanf("%i",&rinicial);
    printf("\n\nIngresar Rango Final -> ");
    scanf("%i",&rfinal);
    printf("\n\nIngresar incremento -> ");
    scanf("%i",&incremento);
    analizarCadenaPolinomica(cadena, 2);
    return 0;
}
/**
 * Esta función analiza y resuelve una cadena de caracteres que representa una función 
 * polinomica del tipo:
 *                        ƒ(x)= A1X^n + A2X^(n-1) + ...AnX¹ + b
 * 
 * Donde: A1, A2...An son los coeficientes y b el termino independiente.
 * 
 *                        Ejemplo: ƒ(x) = 348X5-784X2+6 .
 * Parametros de entrada:
 * char cadena[], contiene la funcion polinomica en formato string
 * int x, contiene el valor por el se remplaza X en la funcion
 * **/
long resolverCadenaPolinomica(char cadena[], long x)
{
    //
    int resultado = 0;// guarda el resultado de la funcion
    int i = 0;// es el indice con el que se recorre la cadena
    while (cadena[i] != 0)
    {
        int coeficiente = 1;// guarda el coeficiente que se esta evaluando
        int expt = 1;// guarda el exponente de la X
        int signo = 1;// se multiplica por el termino al final, si es 1 es positivo, -1 negativo
        if (cadena[i] == 45)// Si el primer caracter es un signo menos, al final el termino se multiplica por -1
        {
            signo = -1;
            i += 1;
        }if (cadena[i] == 43)// Si el primer caracter es un signo más, se pasa a la siguiente posision
        {
            i += 1;
        }
        if ((cadena[i] > 47) && (58 > cadena[i]))// evalua si es un digito numerico
        {
            coeficiente = leerNumero(cadena, &i, 0);// determina que numero equivale la colleccion de digitos numericos seguidos
        }
        if ((cadena[i] == 88) || (cadena[i] == 120))// evalua la presencia de la X
        {
            i+=1;
            if ((cadena[i] > 47) && (58 > cadena[i]))//evalua si la X tiene exponente
            {
                expt = leerNumero(cadena, &i, 0);// determina equivalente numerico del exponente
            }
            coeficiente *= pow(x,expt);// termina de resolver el termino que se esta evaluando con la presencia de la X
        }
        resultado += coeficiente*signo;// resuelve el signo de el termino, si al inicio no se agrego signo por defecto es positivo
    }
    printf("\nResultado : %i",resultado);// imprime el resultado de la función
    
}
/**
 * Esta función lee el valor numerico de una cadena de caracteres numericos,
 * evalua digito por digito para determinar el valor entero de esa colección
 * de digitos numericos y luego retorna dicho valor entero.
 * la funcion evaluara recursivamente digito por digito hasta encontrar un valor 
 * diferente a el de un digito numerico, el valor del indice apuntador será el de 
 * esta ultima posisión.
 * Parametros de entrada:
 * char cadena[] cadena que almacena la colección de digitos
 * int *pos apuntador que apunta a la dirteccion de memoria del inindice con el que se esta recorriendo la cadena 
 * int num valor entero equivalente a la coleción de digitos numericos de la cadena, obligatorio que inicie con 0**/
long leerNumero(char cadena[], int *pos, long num)
{
    if ((cadena[*pos] > 47) && (58 > cadena[*pos]))// evalua si es digito numerico
    {
        num += cadena[*pos] - 48;// guarda el digito en su equivalente entero
        if (cadena[(*pos)+1] > 47 && 58 > cadena[(*pos)+1])// evalua si hay más numeros
        {
            num = num*10;// si hay mas numeros, multiplica el numero por 10 para subrilo una decena
        }
        *pos += 1;// avanza la posicion
        leerNumero(cadena, pos, num);// llamada recursiva de la función
    }
    else
    {
        return num;// cuando en la posisión actual no hay digitos numericos retorna el valor conseguido hasta ese momento
    }
}
