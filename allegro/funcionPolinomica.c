#include <math.h>
long resolverCadenaPolinomica(char cadena[], long x);
int cargarDaTam(long *max, long *min, char fun[], long i,long f, int c);
int leerNumero(char cadena[], int *pos, int num);
void graficarPolinomica(int nRef, char user[], char fecha[], char poli[], long rIni, long rFin, int incre)
{
	//
	long maxY = 0;
	long minY = 0;
	int nPuntos = cargarDaTam(&maxY, &minY, poli, rIni, rFin, incre);
	
	
}

/**
 * Esta función retorna la cantidad de puntos que se pueden graficar en el segmento de
 * una funcion de igual forma asigna a dos punteros el valor maximo que toma 'Y' y el
 * valor minimo  dentro de ese segmento de la función de tipo polinomica para determinar
 * el alto de la grafica de la función.
 * Recibe los siguientes parametros:
 * long *max; entero largo apuntador, valor maximo que toma 'Y'
 * long *min; entero largo apuntador, valor minimo que toma 'Y'
 * char []fun; función polinomica en formato String
 * long i; rango inicial del segmento de función en x
 * long f; rango final del segmento de función en x
 * int c; incremento del valor de x para cada solución
 * **/
int cargarDaTam(long *max, long *min, char fun[], long i,long f, int c)
{
	// almacena el numero de puntos que se pueden graficar en ese segmento de la función
	int cont = 0;
	// almacena el valor de la solucion de la función para el X especificado
	long y = 0;
	while(i <= f)
	{
		// asigna el valor de la solucion de la función para el X especificado
		y = resolverCadenaPolinomica(fun, i);
		if(y >= *max)
		{
			// asigna el mayor valor de 'Y' encontrado
			*max = y;
		}
		if(y <= *min)
		{
			// asigna el menor valor de 'Y' encontrado
			*min = y;
		}
		cont += 1;
		// aumenta la 'X' con el incremento para la proxima iteración
		i += c;
	}
	return cont;
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
    long resultado = 0;// guarda el resultado de la funcion
    int i = 0;// es el indice con el que se recorre la cadena
    while (cadena[i] != 0)
    {
        long coeficiente = 0;// guarda el coeficiente que se esta evaluando
        long expt = 1;// guarda el exponente de la X
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
            coeficiente = leerNumero(cadena, &i, coeficiente);// determina que numero equivale la colleccion de digitos numericos seguidos
        }
        if ((cadena[i] == 88) || (cadena[i] == 120))// evalua la presencia de la X
        {
            i+=1;
            if ((cadena[i] > 47) && (58 > cadena[i]))//evalua si la X tiene exponente
            {
                expt = leerNumero(cadena, &i, 0);// determina equivalente numerico del exponente
            }
            coeficiente *= pow( x,expt);// termina de resolver el termino que se esta evaluando con la presencia de la X
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

