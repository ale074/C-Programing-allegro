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
#include <stdlib.h>// inclusion de la libreria standard library 
#include <string.h>// inclusion de la libreria String para manejo de cadenas
#include <math.h>// inclusion de la libreria String para manejo de cadenas


struct funcionPolinomica
{
    char *funcion;
    long rInicial;
    long rFinal;
    long incremento;
}funcion[1];

typedef struct nodo
{
    char *cadena;
    char *x;
    char *y;
    struct nodo *sig;
}Fila;

long resolverCadenaPolinomica(char cadena[], int x);
int leerNumero(char cadena[], int *pos, int num);
char *generarCadenaXRemplazada(char *funcion, long x, long y);
void mostrarPantallaPrincipal();
Fila *agregarFila(Fila *tabla, char *x, char *y, char *cadena);
Fila *mostrarTablaValores(Fila *tabla);
char *espacios(int n);
Fila *llenarTabla(Fila *Tabla);
/**
 * Declaracion de la funcion principal
 * **/
int main()
{
    mostrarPantallaPrincipal();
    Fila *tabla = llenarTabla(tabla);
    mostrarTablaValores(tabla);
    return 0;
}
Fila *mostrarTablaValores(Fila *tabla)
{
    //
    printf("    X     |                    Evaluación                    |     Y    ");
    printf("------------------------------------------------------------------------");
    Fila *aux = tabla;
    while (aux->sig != NULL)
    {
        printf("%s|%s|%s",aux->x,aux->cadena,aux->y);
        printf("------------------------------------------------------------------------");
        /* code */
        aux = aux->sig;
    }
    
}
Fila *llenarTabla(Fila *tabla)
{
    long i = 0;
    //
    for (i = funcion->rInicial; i <= funcion->rFinal; i += funcion->incremento)
    {
        char *cadena;
        char *x = malloc(10 * sizeof(char));
        char *y = malloc(10 * sizeof(char));
        long iy = 0;
        /* code */
        sprintf(x, "%li", i);
        if (strlen(x) != 10)
        {
            /* code */
            char *sp = espacios(10-(strlen(x)));
            printf("%s",sp);
            strcat(x, sp);
        } else {
            printf("Error, en la conversion de la cadena x");
        }
        iy = resolverCadenaPolinomica(funcion->funcion, i);
        sprintf(y, "%li", iy);
        if (strlen(y) != 10)
        {
            /* code */
            char *sp = espacios(50-(strlen(y)));
            strcat(y, sp);
        } else {
            printf("Error, en la conversion de la cadena y");
        }
        cadena = generarCadenaXRemplazada(funcion->funcion, i, iy);
        tabla = agregarFila(tabla, x, y, cadena);
    }
    return tabla;
}
Fila *agregarFila(Fila *tabla, char *x, char *y, char *cadena)
{
    //
    Fila *nuevaFila, *aux;
    nuevaFila = (Fila*)malloc(sizeof(Fila));
    nuevaFila->cadena = cadena;
    nuevaFila->x = x;
    nuevaFila->y = y;
    nuevaFila->sig = NULL;
    if (tabla == NULL)
    {
        tabla = nuevaFila;
    } else {
        //
        aux = tabla;
        while (aux->sig != NULL)
        {
            /* code */
            aux = aux->sig;
        }
        aux->sig = nuevaFila;
    }
    return tabla;
}
char *generarCadenaXRemplazada(char funcion[], long x, long y)
{
    //
    char *cadRemplazada;
    int i = 0;
    while (funcion[i] != 0)
    {
        
        long coeficiente = 1;// guarda el coeficiente que se esta evaluando
        char *coefi = malloc(10 * sizeof(char));
        char *sx = malloc(10 * sizeof(char));
        int expt = 1;// guarda el exponente de la X
        char *exp = malloc(6 * sizeof(char));
        if (funcion[i] == 45)// Si el primer caracter es un signo menos, al final el termino se multiplica por -1
        {
            strcat(cadRemplazada, "-");
            i += 1;
        }if (funcion[i] == 43)// Si el primer caracter es un signo más, se pasa a la siguiente posision
        {
            i += 1;
        }
        if ((funcion[i] > 47) && (58 > funcion[i]))// evalua si es un digito numerico
        {
            coeficiente = leerNumero(funcion, &i, 0);// determina que numero equivale la colleccion de digitos numericos seguidos
            
            sprintf(coefi, "%li", coeficiente);
            strcat(cadRemplazada, coefi);
        }
        if ((funcion[i] == 88) || (funcion[i] == 120))// evalua la presencia de la X
        {
            strcat(cadRemplazada, "(");
            sprintf(sx, "%i", x);
            strcat(cadRemplazada, sx);
            strcat(cadRemplazada, ")");
            strcat(cadRemplazada, (char *)94);
            i+=1;
            if ((funcion[i] > 47) && (58 > funcion[i]))//evalua si la X tiene exponente
            {
                expt = leerNumero(funcion, &i, 0);// determina equivalente numerico del exponente
            }
            sprintf(exp, "%i", expt);
            strcat(cadRemplazada, exp);// coeficiente*(x^exponente)
        }
    }
    if (strlen(cadRemplazada) != 50)
    {
        /* code */
        char *sp = espacios(50-(strlen(cadRemplazada)));
        strcat(cadRemplazada, sp);
    }
    
    return cadRemplazada;
    
}
char *espacios(int n)
{
    char *p= malloc(1 * sizeof(" "));
    if (n > 1)
    {
        strcat(p,espacios(n-1));
    } else
    {
        return p;
    }
    
    
}
/**
 * Esta funcion muestra por consola la pantalla principal en la 
 * que explica lo que hace el programa, define el formato y el 
 * tipo de la funcion polinomica, pide los datos necesarios para 
 * realizar el proceso.
 * llena los datos de la estructura funcion polinomica
 * char *funcion
 * int rInicial
 * int rFinal
 * int incremento
 * **/
void mostrarPantallaPrincipal()
{
    char cadena[255];
    printf("\nCalcular Funci%cn Polin%cmica\nSe pide ingresar una funci%cn del tipo:",162,162,162);
    printf("\n\n\t%c(x)= A1X%cn + A2X%c(n-1) + ...AnX%c + b\n",159,94,94,251);
    printf("\nDonde: A1, A2...An son los coeficientes y b el termino independiente.");
    printf("\n\n\tEjemplo: %c(x) = 348X5-784X2+6 .\n");
    printf("\n\nIngresar Funci%cn Polin%cmica -> ",162,162);
    scanf("%s",cadena);
    int size = strlen(cadena);
    funcion->funcion = malloc(size * sizeof(char));
    if (funcion->funcion == NULL)
    {
        printf("Error al asignar Memoria\n");getchar();
    }
    printf("\n%s\n",funcion->funcion);
    printf("\n\nIngresar Rango Inicial -> ");
    scanf("%li",&funcion->rInicial);
    printf("\n\nIngresar Rango Final -> ");
    scanf("%li",&funcion->rFinal);
    printf("\n\nIngresar incremento -> ");
    scanf("%li",&funcion->incremento);
    
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
long resolverCadenaPolinomica(char cadena[], int x)
{
    //
    long resultado = 0;// guarda el resultado de la funcion
    int i = 0;// es el indice con el que se recorre la cadena
    while (cadena[i] != 0)
    {
        long coeficiente = 1;// guarda el coeficiente que se esta evaluando
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
    return resultado;// imprime el resultado de la función
    
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
int leerNumero(char cadena[], int *pos, int num)
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
