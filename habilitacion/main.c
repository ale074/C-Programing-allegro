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
/***+      //////                 16-12-2020                   +***/
/***+      //////                 Versión  1                   +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////                  ORDENAR                     +***/
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
//////                     HABILITACION                       //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
/**
 * Este programa crea un archivo de prueba con registros para realizar
 * la prueba de la función ordenar, que lee los registros y los imprime 
 * organizando los apellidos de forma ascendente de la A-Z.
 * 
 * **/
#include <stdio.h> // inclusion de la libreria Standar Input Output
// macros para definir colores de impresion para la función printf()
#define ROJO "\x1b[31m"
#define DEFAULTCOLOR "\x1b[0m"
// prototipo de funciones a utilizar
void ordena(FILE *);
void imprimirRegistro(FILE * fichero, long nRegistro);
int contardigitos(long n);
void llenarEspacio(int n, int m);
void prueba();
// declaracion de funciones
/**
 * declaración de lña función principal**/
int main()
{
    prueba();// se ejecuta la prueba de la función
    return 0;
}
/**
 * Esta funcion crea un archivo y lo carga con registros para realizar 
 * la prueba de ejecución de la función ordenar
 * **/
void prueba()
{
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se crea el archivo en un modo lectura y escritura
    // se comprueba que no halla errores
    if ((fichero = fopen("prueba.txt", "w+")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se cargan los datos 
        char *cedulas[] = {"1075894572","215487954","215465464","215487787","215786688","6465416896","2154898854"};
        char *nombres[] = {"EDGAR","RUBEN EMILIO","CARLOS","ALBA","EMILIO","MARIA ELENA","HERNAN DARIO"};
        char *apellidos[] = {"ZULUAGA ARCE","ZAPATA GOMEZ","LAGOS ORTEGA","GARCIA BUSTAMANTE","ARCINIEGAS CALLE","AMORTEGUI RUIZ","LOPEZ QUIJANO"};
        char *direcciones[] = {"DIAGONAL 12 TR 15-12","CR15 3-12","CALLE 15 N.6-20","TR115 11A43","CALLE 105 3-12","CALLE 15 9-12","CRA 21 #18B-52"};
        double salarios[] = {4678986.0,1200900.0,1200000.5,6345876.5,1400000.0,5234987.5,2822557.0,};
        for (size_t i = 0; i < 7; i++)
        {
            fputs(cedulas[i], fichero);
            fputc(64, fichero);
            fputs(nombres[i], fichero);
            fputc(64, fichero);
            fputs(apellidos[i], fichero);
            fputc(64, fichero);
            fputs(direcciones[i], fichero);
            fputc(64, fichero);
            fwrite(&salarios[i], 8, 1, fichero);
            fputc(64, fichero);
        }// fin for (size_t i = 0; i < 7; i++)
        // se ejecuta la función ordenar
        ordena(fichero);
    }// fin else
    // ordena(fichero);
    fclose(fichero);
}// fin función prueba()
/**
 * esta función imprime de forma ordenada los registros de un archivo,
 * el apuntador es ingresado por parametro, la funcion recorre el alfabeto
 * y lee los registros imprimiendo secuencialmente los registros en los que
 * la primera letra del primer apellido coincida con la letra del alfabeto
 * que se esta evaluando de la 'A' a 'Z', enumerando los registros que se imprimen.
 * parametros de entrada
 * FILE *fichero; trae el apuntador del archivo a ordenar e imprimir
 * **/
void ordena(FILE *fichero)
{
    // se imprime el mensaje de cabecera(INFO)
    printf("\nLISTADO DE USUARIOS ORDENADO POR APELLIDOS EN FORMA ASCENDENTE (A-Z)\n\r");
    printf("\nNro     CEDULA                   NOMBRES                 APELLIDOS                 DIRECCION                SUELDO");
    printf("\n------  ----------------------   ---------------------   -----------------------   ----------------------   ---------\n");
    // almacena el numero de registro a imprimir
    long nRegistro = 0;
    // almacena el numero de bytes con los que cuenta el registro o los dos primeros campos
    int nBytesRegistro = 0;
    // almacena la cantidad de caracter 64 encontrados hasta llegar a 5
    int registro = 0;
    // almacena el caracter leido del archivo que se esta verificando
    char letra = 32;
    // almacena la letra del alfabeto que esta evaluando en el archivo
    char l = 65;
    // recorre las letras del alfabeto para imprimir con apellidos en forma ascendente
    while (l <= 90)
    {
        // posisiona el apuntador al inicio del archivo para leerlo
        fseek(fichero, 0, SEEK_SET);
        // recorre el archivo para imprimir los registros con el apellido que corresponda
        // a la letra del alfabeto que se este evaluando
        while (!feof(fichero))
        {
            // se asigna el caracter leido del archivo
            letra = fgetc(fichero);
            // aumenta el numero de caracteres leidos
            nBytesRegistro += 1;
            // evalua si el catacter es igual al caracter 64
            // y aumenta el numero de campos de registro hasta
            // llegar al campo apellido
            if ((letra == 64) && (registro < 5))
            {
                // aumenta los campos leidos del registro
                registro += 1;
                // si esta en el campo apellido
                if (registro == 2)
                {
                    letra = fgetc(fichero);
                    // si la letra del apellido es igual a la que se esta evaluando
                    if (letra == l)
                    {
                        // se posisiona el apuntador al inicio del registro a imprimir
                        fseek(fichero, (nBytesRegistro * -1), SEEK_CUR);//cuando es el primer registro
                        
                        // imprime el registro enviando el fichero y el numerador del registro
                        imprimirRegistro(fichero, nRegistro += 1);
                        // se inicializan los datos para evaluar nuevos registros
                        nBytesRegistro = 0;
                        registro = 0;
                    }// fin if (letra == l)
                }// fin if (registro == 2)
            }/*fin if ((letra == 64) && (registro < 5))*/
            // si ya recorrio todos los campos del registro
            if (registro == 5)
            {
                // se inicializan los datos para un nuevo registro
                registro = 0;
                nBytesRegistro = 0;
            }// fin if (registro == 5)
        }// fin while (!feof(fichero))
        l += 1;
    }// fin while (l < 91)
    // se imprime el pie de pantalla
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    printf("***FIN DE IMPRESI%cN****",224);
}// fin función  ordena(FILE *fichero)
/**
 * Esta función imprime un registro de tamaño variable de un archivo
 * cuyos campos estan separados por el caracter ascii 64, 
 * tambien se imprime un numerador de registro y imprime el registro 
 * en orden por apellido de forma ascendente.
 * parametros de entrada:
 * FILE * fichero; archivo del que se leen los registros
 * long nRegistro; enumerador del registro
 * **/
void imprimirRegistro(FILE * fichero, long nRegistro)
{
    // almacena el valor del campo salario del registro que se esta imprimiendo
    double salario = 0;
    // guarda el numero de caracteres impresos del campo que se imprime
    int tamCampo = 0;
    // numero de caracteres que se debe imprimir para cada campo (char *)
    int tamDefault = 25;
    // almacena el caracter que se lee del archivo
    char letra = 32;
    // cantidad de caracter 64 encontrados
    int n = 0;
    // imprime la enumeracion del registro
    printf("%li",nRegistro);
    // almacena la cantidad de caracteres que se imprimieron como numero de resgistro
    int digitos = contardigitos(nRegistro);
    // llena el resto de espacios definidos para mostrar la enumeracion (millones de registros)
    llenarEspacio(digitos, 8);
    // recorre los caracteres para imprimir los campos
    while (n < 4)
    {
        // recibe la letra del archivo
        letra = fgetc(fichero);
        // pregunta si es caracter 64
        if (letra == 64)
        {
            // llena los espacios restantes definidos para el registro
            llenarEspacio(tamCampo, tamDefault);
            // aumenta en uno indicando que pasa a un nuevo campo
            n += 1;
            // tamaño vuelve a ser cero para contar un nuevo campo
            tamCampo = 0;
        }/*fin if (letra == 64)*/ else// sino es, imprime el caracter que sea
        {
            // el tamaño del campo sigue aumentando hasta que finalize
            tamCampo += 1;
            printf("%c",letra);
        }// fin else
    }// fin while (n < 4)
    // se lee el campo salario
    fread(&salario, 8, 1, fichero);
    // se imprime el campo salario
    printf("%.1lf\n",salario);
    // se posisiona al inicio de otro registro
    fseek(fichero, 1, SEEK_CUR);
}// fin función imprimirRegistro(FILE * fichero, long nRegistro)
/**
 * esta función cuenta la cantidad de caracteres que tiene un
 * valor entero largo ingresado por parametro
 * parametros de entrada:
 * long n;**/
int contardigitos(long n)
{
    // almacena la cantidad de digitos que tiene el numero
    int cont = 0;
    do
    {
        n = n/10;
        cont += 1;
    } while (n != 0);
    return cont;
}// fin función contardigitos(long n)
/**
 * Esta función recibe dos valores enteros por parametros
 * y imprime los espacios que falta para que n llegue a m
 * int n; cantidad de espacios impresos
 * int m; cantidad de espacios que se deben imprimir**/
void llenarEspacio(int n, int m)
{
    //imprime espacios hasta que n y m sean iguales
    if (n < m)
    {
        printf(" ");
        llenarEspacio(n+1, m);
    }// fin if (n < m)
}// fin función llenarEspacio(int n, int m)