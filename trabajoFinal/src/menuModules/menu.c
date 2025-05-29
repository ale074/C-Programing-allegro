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
/***+      //////                 04-12-2020                   +***/
/***+      //////                 Versión  1                   +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////               Graficador UTP                 +***/
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
//////                    Trabajo Final                       //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
#include <stdio.h>  // inclusion de la libreria Standar Input Output
#include <stdlib.h> // inclusion de la libreria standard library
#include <time.h>
#include <conio.h>
#include "../encriptation/cifrador.c"
#define ROJO "\x1b[31m"
#define VERDE "\033[0;32m"
#define DEFAULTCOLOR "\x1b[0m"

// prototipos de funciones a utilizar
int menuRoot();
int menu(char username[]);
int UsuariosVacio();
void imprimirCadena(char cadena[]);
int passwordIgual(char pass1[], char pass2[]);
int compararCredenciales(char username[], char password[]);
int registrarUsuario(char username[], char password[]);
void clear();
long usuarioExiste(char username[]);
void CrearNuevoUsuario();
void borrarUsuarioListadoAccesos(char username[]);
void borrarUsuario();
void listarAccesosUsuario();
void listarAccesosUser(char username[]);
void listarAccesosUsers();
void cambiarPassRoot();
void cambiarPassUser();
void asignarCodGrafico(char cod[]);
void mostrarPantallaPrincipal(char funcion[], long *rInicial, long *rFinal, long *incremento);
void registrarDatosListaAccesos(char cod[],char user[], char fecha[], char fx[], long rI, long rF, int i);
void borrarGraficoExistente(char user[]);
void imprimirGraficoReferencia(char user[]);

//ESTRUCTURAS
struct
{
    char username[30];
    char password[30];
} registro;
struct
{
    char codGrafico[4];
    char username[30];
    char fecha[128];
    char fx[50];
    long rInicial;
    long rFinal;
    int incremento;
} registroListaAccesos;

// declaracion de funciones
void imprimirGraficoReferencia(char user[])
{
    int num = 0;
    int numCod = 0;
    // se imprime el mensaje que indique al usuario para ingresar el numero de referencia
    printf("\nAplicativo - Graficador - UTP");
    printf("\nImprimir gráfico por referencia");
    printf("\ningrese el numero de referencia del grafico -> ");
    scanf("%i",&num);
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo lectura y escritura
    // se comprueba que no halla errores
    if ((fichero = fopen("files/accessList.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        fread(&registroListaAccesos, sizeof(registroListaAccesos)+1, 1, fichero);
        while (feof(fichero))
        {
            /* code */
            // numero de referencia en su valor entero
            numCod = atoi(registroListaAccesos.codGrafico);
        }
        
    }
}
/**
 * Esta función borra el registro perteneciente al codigo de referencia 
 * ingresado por teclado, recibe como parametro el nombre de usuario
 * para verificar si el usuario tiene acceso al registro de la grafica**/
void borrarGraficoExistente(char user[])
{
    // almacena la posision del puntero despues de leer el archivo
    long posision = 0;
    // almacena el codigo de grafico ingresado por el usuario
    int cod = 0;
    // almacena el codigo del registro a analizar
    int numCod = 0;
    // detiene el ciclo cuando ya se ha encontrado el registro con el codigo y el mismo usuario
    int ya = 1;
    // se imprime el mensaje que indique al usuario para ingresar el numero de referencia
    printf("\nAplicativo - Graficador - UTP");
    printf("\nBorrar un gráfico existente");
    printf("\ningrese el numero de referencia del grafico -> ");
    scanf("%i",&cod);
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo lectura y escritura
    // se comprueba que no halla errores
    if ((fichero = fopen("files/accessList.txt", "r+")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // while que recorre cada registro hasta encontrar al que pertenece la referencia
        while (!feof(fichero) && ya)
        {
            // se lee el registro para comparar los numeros de referencia
            fread(&registroListaAccesos, sizeof(registroListaAccesos)+1, 1, fichero);
            // numero de referencia en su valor entero
            numCod = atoi(registroListaAccesos.codGrafico);
            // se compara para verificar que sean el mismo registro y que pertenesca
            // al mismo usuario
            if (numCod == cod && (strcmp(registroListaAccesos.username, user)==0))
            {
                // se limpia el registro
                strcpy(registroListaAccesos.codGrafico,"");
                strcpy(registroListaAccesos.username,"");
                strcpy(registroListaAccesos.fecha,"");
                strcpy(registroListaAccesos.fx,"");
                registroListaAccesos.rInicial = 0;
                registroListaAccesos.rFinal = 0;
                registroListaAccesos.incremento = 0;
                // se asigna la posision actual para reposisionar
                posision = ftell(fichero);
                // se posisiona el puntero en la posision del registro
                fseek(fichero, (posision-sizeof(registroListaAccesos)-1), SEEK_SET);
                // se asigna el registro vacio en la posion del registro anterior
                fwrite(&registroListaAccesos, sizeof(registroListaAccesos)+1, 1, fichero);
                // se asigna cero para detener la iteracion 
                ya = 0;
            }// fin if (numCod == cod && (strcmp(registroListaAccesos.username, user)==0))
        }// fin while(!feof(fichero))
        // pregunta si encontro el registro y era del mismo usuario de lo contrario mensaje de erro
        if (ya == 0)
        {
            printf(VERDE"\nEl Grafico borrado con exito.\n"DEFAULTCOLOR);getchar();
        }// fin if(ya == 0)
        else
        {
            printf(ROJO"\nLa referencia indicada no existe o el usuario no tiene acceso.\n"DEFAULTCOLOR);getchar();
        }// fin else
    }// else
}// fin función void borrarGraficoExistente(char user[])
/**
 * Esta funcion toma todos los datos necesarios para generar
 * un nuevo registro de función y lo agrega a el archivo de
 * listado de accesos, posterior mente abre una ventana para 
 * graficar la función del tipo polinomica.
 * recibe como parametro el nombre de usuario, para asignarlo al registro
 * **/
void CrearNuevoGrafico(char user[])
{
    // se captura la fecha actual
    time_t tiempo = time(0);
    // se asigna la fecha local
    struct tm *tlocal = localtime(&tiempo);
    // cadena qe almacena la fecha
    char output[128];// fecha actual
    // asigna la fecha actual en la cadena
    strftime(output, 128, "%d/%m/%y", tlocal);
    // almacena el codigo de la grafica
    char codGrafico[4];
    // asigna el codigo de la grafica para el nuevo registro
    asignarCodGrafico(codGrafico);
    // cadena que guarda la funcion ingresada por parametro
    char funcion[50];
    // rango inicial del segmento a graficar
    long rInicial = 0;
    // rango final del segmento a graficar
    long rFinal = 0;
    // incremento para la posision de cada punto
    long incremento = 0;
    // se muestra una pantalla con información para que el usuario
    // ingrese los valores correspondientes
    mostrarPantallaPrincipal(funcion, rInicial, rFinal, incremento);
    // se registran los datos en el archivo de listado de accesos de usuarios
    registrarDatosListaAccesos(codGrafico, user, output, funcion, rInicial, rFinal, incremento);
    //graficar funcion
}
/**
 * Esta función guardav el un nuevo registro con los datos que recibe como parametros**/
void registrarDatosListaAccesos(char cod[],char user[], char fecha[], char fx[], long rI, long rF, int i)
{
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo 
    // de operaciones de escritura
    // se comprueba que no halla errores
    if ((fichero = fopen("files/accessList.txt", "a")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se asignan los datos a el registro a guardar
        strcpy(registroListaAccesos.codGrafico,cod);
        strcpy(registroListaAccesos.username,user);
        strcpy(registroListaAccesos.fecha,fecha);
        strcpy(registroListaAccesos.fx,fx);
        registroListaAccesos.rInicial = rI;
        registroListaAccesos.rFinal = rF;
        registroListaAccesos.incremento = i;
        // se guarda el registro en el archivo
        fwrite(&registroListaAccesos,sizeof(registroListaAccesos)+1, 1, fichero);
    }
    fclose(fichero);
}// fin función registrarDatosListaAccesos(char cod[],char user[], char fecha[], char fx[], long rI, long rF, int i)
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
void mostrarPantallaPrincipal(char funcion[], long *rInicial, long *rFinal, long *incremento)
{
    clear();
    printf("\nAplicativo - Graficador - UTP");
    printf("\nGraficar Funci%cn Polin%cmica\nSe pide ingresar una funci%cn del tipo:",162,162,162);
    printf("\n\n\t%c(x)= A1X%cn + A2X%c(n-1) + ...AnX%c + b\n",159,94,94,251);
    printf("\nDonde: A1, A2...An son los coeficientes y b el termino independiente.");
    printf("\n\n\tEjemplo: %c(x) = 348X5-784X2+6 .\n");
    printf("\n\nIngresar Funci%cn Polin%cmica -> ",162,162);
    scanf("%s",funcion);
    printf("\n\nIngresar Rango Inicial -> ");
    scanf("%li",rInicial);
    printf("\n\nIngresar Rango Final -> ");
    scanf("%li",rFinal);
    printf("\n\nIngresar incremento -> ");
    scanf("%li",incremento);
}// fin función mostrarPantallaPrincipal(char funcion[], long *rInicial, long *rFinal, long *incremento)
/**
 * Esta función asigna a una cadena de caracteres recibida por parametros
 * el codigo para guardar el proximo registro de el archivo de accesos de 
 * usuarios
 * recibe comoparametro 
 * char cod[] alq ue se asigna el nuevo codigo de registro de grafica**/
void asignarCodGrafico(char cod[])
{
    //almacena el valor entero en formato string del codigo de grafico
    char num[4];
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de lectura
    // se comprueba que no halla errores
    if ((fichero = fopen("files/accessList.txt", "r")) == NULL)
    {
        FILE *nuevo = fopen("files/accessList.txt", "w");
        fclose(nuevo);
        strcpy(cod, "0000");
        // salida de la funcion en caso tal que el archivo no exista se crea el primer codigo
        return;
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se posisiona el puntero en la posision del ultimo registro
        fseek(fichero, (1+sizeof(registroListaAccesos)), SEEK_END);
        // se lee el ultimo registro
        fread(&registroListaAccesos, sizeof(registroListaAccesos)+1, 1, fichero);
        // se convierte a entero y se suma una unidad
        int x = atoi(registroListaAccesos.codGrafico)+1;
        // se asigna los digitos del nuevo codigo a num
        itoa(x, num, 10);
        // se rellena de ceros segun se requiera
        if(strlen(num) == 1)
        {
            strcpy(cod,"000");
            strcad(cod, num);
        }
        else if(strlen(num)==2)
        {
            strcpy(cod,"00");
            strcad(cod, num);
        }
        else if(strlen(num)==3)
        {
            strcpy(cod,"0");
            strcad(cod, num);
        }
        else
        {
            printf(ROJO"\nEl archivo tiene el maximo de registros permitidos"DEFAULTCOLOR);getchar();
        }
        
    }
    fclose(fichero);
}// fin función asignarCodGrafico(char cod[])
/**
 * Esta función cabia el password de un usuario
 * cuyo username es entrado por teclado**/
void cambiarPassUser()
{
    clear();
    // almacena la posision en la que se encuentra el registro o 0 si no lo encontro
    long posision = 0;
    // se declara un array que guardan el usuario ingresado por teclado
    char username[30];
    // se declara un array que guardan la contraseña ingresada por teclado
    char password[30];
    // imprime el mensaje de la pantalla de inicio de sesion.
    printf("\nAplicativo - Graficador - UTP\n");
    printf("\nUsername:");
    fflush(stdin);
    // asigna el valor ingresado por teclado a el array username
    scanf("%[^\n]%*c", username);
    fflush(stdin);
    // se asigna la posision en la que encuentra el registro de ser asi de lo contrario
    // retorna un 0, indicando que no encontro ningun registro usuario con ese username
    posision = usuarioExiste(username);
    // verifica que le usuario no exista
    if (posision == 0)
    {
        // si existe imprime un mensaje de error
        printf(ROJO "\n(Error 203): El usuario ingresado no existe.\n" DEFAULTCOLOR);
        getchar();
        return; // sale de la funcion indicando que el proceso no se pudo realizar
    }           // fin if (usuarioExiste(username))
    printf("\nIngrese el nuevo password: ");
    // asigna el valor ingresado por teclado a el array password
    // imprime el caracter * por cada caracter ingresado
    int p = 0;
    do
    {
        password[p] = getch();
        if (password[p] != '\r')
        {
            printf("*");
        } // fin if (password[p]!='\r')
        p++;
    } while (password[p - 1] != '\r'); // fin do-while
    password[p - 1] = '\0';
    printf("\nIngrese el nuevo password: ");
    // asigna el valor ingresado por teclado a el array password
    // imprime el caracter * por cada caracter ingresado
    p = 0;
    do
    {
        registro.password[p] = getch();
        if (registro.password[p] != '\r')
        {
            printf("*");
        } // fin if (password[p]!='\r')
        p++;
    } while (registro.password[p - 1] != '\r'); // fin do-while
    registro.password[p - 1] = '\0';
    if (strcmp(password, registro.password) != 0)
    {
        //control de error cuando el password no coincide
        printf(ROJO "\n(Error 204): El nuevo password ingresado no coincidió." DEFAULTCOLOR);
        getchar();
        return;
    }
    else
    {
        // se declara un apuntador de tipo archivo
        FILE *fichero;
        // se inicializa el apuntador, se abre el archivo usuarios en un modo de escritura
        // se comprueba que no halla errores
        if ((fichero = fopen("files/Usuarios.txt", "a")) == NULL)
        {
            // control de errores para abrir el archivo
            printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
        } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
        else
        {
            // asigna los valores del usuario
            strcpy(registro.username, username);
            // encripta la contraseña
            encriptar(password);
            // la asigna al registro
            strcpy(registro.password, password);
            // actualiza la contraseña del usario
            fseek(fichero, posision, SEEK_SET);
            fwrite(&registro, sizeof(registro) + 1, 1, fichero);
        } // fin else
    }     // fin else
} // fin función cambiarPassUser()
/**
 * Esta función cambia ejecuta la opcion para cambiar el password
 * del usuario root, pide la contraseña anterior, y pide confirmar 2 veces
 * la nueva contraseña, si todo no hay errores registra la nueva contraseña 
 * de el usuario root, si hay algun error lo indica y vuelve al menu principal de root**/
void cambiarPassRoot()
{
    // limpia la pantalla de la consola
    clear();
    // se declara un array que guardan la contraseña ingresada por teclado
    char password[30];
    // se imrime la pantalla para la opcion Cambiar Password del usuario root
    printf("\nAplicativo - Graficador - UTP");
    printf("\nCambiar Password del usuario root");
    // pide que ingrese el password anterior por teclado
    printf("\nPassword anterior:");
    // asigna el valor ingresado por teclado a el array password
    // imprime el caracter * por cada caracter ingresado
    int p = 0;
    do
    {
        password[p] = getch();
        if (password[p] != '\r')
        {
            printf("*");
        } // fin if (password[p]!='\r')
        p++;
    } while (password[p - 1] != '\r'); // fin do-while
    password[p - 1] = '\0';
    if (compararCredenciales("root", password))
    {
        //control de error cuando el password no coincide
        printf(ROJO "\n(Error 204): El password ingresado es incorrecto." DEFAULTCOLOR);
        getchar();
        return;
    }
    else
    {
        printf("\nIngrese el nuevo password: ");
        // asigna el valor ingresado por teclado a el array password
        // imprime el caracter * por cada caracter ingresado
        p = 0;
        do
        {
            password[p] = getch();
            if (password[p] != '\r')
            {
                printf("*");
            } // fin if (password[p]!='\r')
            p++;
        } while (password[p - 1] != '\r'); // fin do-while
        password[p - 1] = '\0';
        printf("\nIngrese el nuevo password: ");
        // asigna el valor ingresado por teclado a el array password
        // imprime el caracter * por cada caracter ingresado
        p = 0;
        do
        {
            registro.password[p] = getch();
            if (registro.password[p] != '\r')
            {
                printf("*");
            } // fin if (password[p]!='\r')
            p++;
        } while (registro.password[p - 1] != '\r'); // fin do-while
        registro.password[p - 1] = '\0';
        if (strcmp(password, registro.password) != 0)
        {
            //control de error cuando el password no coincide
            printf(ROJO "\n(Error 204): El nuevo password ingresado no coincidio." DEFAULTCOLOR);
            getchar();
            return;
        }
        else
        {
            // se declara un apuntador de tipo archivo
            FILE *fichero;
            // se inicializa el apuntador, se abre el archivo usuarios en un modo de escritura
            // se comprueba que no halla errores
            if ((fichero = fopen("files/Usuarios.txt", "r+")) == NULL)
            {
                // control de errores para abrir el archivo
                printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
            } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
            else
            {
                // asigna los valores de root
                strcpy(registro.username, "root");
                // encripta la contraseña
                encriptar(password);
                // la asigna al registro
                strcpy(registro.password, password);
                // actualiza la contraseña del usario root
                fwrite(&registro, sizeof(registro) + 1, 1, fichero);
            } // fin else
        }     // fin else
    }         // fin else
} // fin función void  cambiarPassRoot()
/**
 * Esta función imprime una lista de todas las listas
 * de accesos de los usuarios**/
void listarAccesosUsers()
{
    // almacena el numero de registros por usuario
    long numRegistros = 0;
    //posision del apuntador
    long posision = 0;
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de
    // actualización de lectura , se comprueba que no halla errores
    if ((fichero = fopen("../files/Usuarios.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // ubica la posision del apuntador para leer el registro siguiente
        // a el usuario root
        fseek(fichero, (ftell(fichero) + sizeof(registro)), SEEK_SET);
        // se imprime la pantalla de la opcion listar accesos todos los usuario
        printf("\nAplicativo - Graficador - UTP");
        printf("\nListado de accesos todos los usuario");
        // se recorre el archivo para imprimir los listados usuario por usuario
        while (!feof(fichero))
        {
            // asigna la posision del puntero en la que se encuentra el archivo
            posision = ftell(fichero);
            // lee el registro para verificar que pertenece al usuario a borrar
            fread(&registro, sizeof(registro), 1, fichero);
            listarAccesosUser(registro.username);
        } // fin while (!feof(fichero))
    }     // fin else
    // se sierra el archivo
    fclose(fichero);

} // fin función listarAccesosUsers()
/**
 * Esta función imprime datos de los registros de accesos
 * de un usuario incgresado por teclado**/
void listarAccesosUser(char username[])
{
    // posision del registro
    long posision = 0;
    // almacena el numero de registros del usuario
    long numRegistros = 0;
    //posision del apuntador
    posision = 0;
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de
    // actualización de lectura y escritura, se comprueba que no halla errores
    if ((fichero = fopen("../files/accessList.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se imprime las celdas de cabecera
        printf("\nUsername: %s", username);
        printf("\nFecha        Nro gr%cfico   Polinomio F(x)", 160);
        printf("\n__________________________________________");
        // se recorre el archivo para encontrar los registros pertenecientes
        // al usuario
        while (!feof(fichero))
        {
            // asigna la posision del puntero en la que se encuentra el archivo
            posision = ftell(fichero);
            // lee el registro para verificar que pertenece al usuario
            fread(&registroListaAccesos, sizeof(registroListaAccesos), 1, fichero);
            // se verifica que el nombre de usuario sea el mismo
            if (strcmp(registroListaAccesos.username, username) == 0)
            {
                // se imprimen los datos del registro
                printf("\n%s      %s       &s", registroListaAccesos.fecha,
                       registroListaAccesos.codGrafico,
                       registroListaAccesos.fx);
            }
        } // fin while (!feof(fichero))
        printf("\n___________________________");
        printf("\n%li registros", numRegistros);
        getchar();
    } // fin else
    // se sierra el archivo
    fclose(fichero);
} // fin función listarAccesosUser()
/**
 * Esta función imprime datos de los registros de accesos
 * de un usuario incgresado por teclado**/
void listarAccesosUsuario()
{
    // limpia la pantalla de la consola
    clear();
    // posision del registro
    long posision = 0;
    // se declara un array que guardan el usuario ingresado por teclado
    char username[30];
    // se imprime la pantalla de la opcion crear nuevo usuario
    printf("\nAplicativo - Graficador - UTP");
    printf("\nListado de accesos por usuario");
    printf("\nEntre el usuario:");
    printf("\nUsername: ");
    fflush(stdin);
    // asigna el valor ingresado por teclado a el array username
    scanf("%[^\n]%*c", username);
    fflush(stdin);
    // se asigna la posision en la que encuentra el registro de ser asi de lo contrario
    // retorna un 0, indicando que no encontro ningun registro usuario con ese username
    posision = usuarioExiste(username);
    // verifica que le usuario no exista
    if (posision == 0)
    {
        // si existe imprime un mensaje de error
        printf(ROJO "\n(Error 203): El usuario ingresado no existe.\n" DEFAULTCOLOR);
        getchar();
        return; // sale de la funcion indicando que el proceso no se pudo realizar
    }           // fin if (usuarioExiste(username))
    // almacena el numero de registros del usuario
    long numRegistros = 0;
    //posision del apuntador
    posision = 0;
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de
    // actualización de lectura y escritura, se comprueba que no halla errores
    if ((fichero = fopen("../files/accessList.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se imprime las celdas de cabecera
        printf("\nFecha        Nro gr%cfico   Polinomio F(x)", 160);
        printf("\n__________________________________________");
        // se recorre el archivo para encontrar los registros pertenecientes
        // al usuario
        while (!feof(fichero))
        {
            // asigna la posision del puntero en la que se encuentra el archivo
            posision = ftell(fichero);
            // lee el registro para verificar que pertenece al usuario
            fread(&registroListaAccesos, sizeof(registroListaAccesos), 1, fichero);
            // se verifica que el nombre de usuario sea el mismo
            if (strcmp(registroListaAccesos.username, username) == 0)
            {
                // se imprimen los datos del registro
                printf("\n%s      %s       &s", registroListaAccesos.fecha,
                       registroListaAccesos.codGrafico,
                       registroListaAccesos.fx);
            }
        } // fin while (!feof(fichero))
        printf("\n___________________________");
        printf("\n%li registros", numRegistros);
        getchar();
    } // fin else
    // se sierra el archivo
    fclose(fichero);
} // fin función listarAccesosUsuario()
/**
 * Esta función borra todos los datos de un usuario ingresado 
 * por teclado, elimina tambien los valores de la lista de accesos
 * **/
void borrarUsuario()
{
    // limpia la pantalla de la consola
    clear();
    // posision del registro
    long posision = 0;
    // se declara un array que guardan el usuario ingresado por teclado
    char username[30];
    // se imprime la pantalla de la opcion crear nuevo usuario
    printf("\nAplicativo - Graficador - UTP");
    printf("\nMenú para usuario: root Borrar usuario");
    printf("\nEntre el usuario:");
    printf("\nUsername: ");
    fflush(stdin);
    // asigna el valor ingresado por teclado a el array username
    scanf("%[^\n]%*c", username);
    fflush(stdin);
    // se asigna la posision en la que encuentra el registro de ser asi de lo contrario
    // retorna un 0, indicando que no encontro ningun registro usuario con ese username
    posision = usuarioExiste(username);
    // verifica que le usuario no exista
    if (posision == 0)
    {
        // si existe imprime un mensaje de error
        printf(ROJO "\n(Error 203): El usuario ingresado no existe.\n" DEFAULTCOLOR);
        getchar();
        return; // sale de la funcion indicando que el proceso no se pudo realizar
    }           // fin if (usuarioExiste(username))
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de lectura
    // se comprueba que no halla errores
    if ((fichero = fopen("./files/Usuarios.txt", "r+")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
        getchar();
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // situa el puntero del archivo en la posision en la que se encuentra el registro
        fseek(fichero, posision, SEEK_SET);
        // se lee el registro para comparar si efectivamente son los datos del usuario
        fread(&registro, sizeof(registro) + 1, 1, fichero);
        // verifica que sea el mismo
        if (strcmp(registro.username, username) == 0)
        {
            // se borran los datos del usuario en el registro
            strcpy(registro.username, "");
            strcpy(registro.password, "");
            // situa el puntero del archivo en la posision en la que se encuentra el registro
            fseek(fichero, posision, SEEK_SET);
            // se asigna ese registro vacio al registro del usuario
            fwrite(&registro, sizeof(registro) + 1, 1, fichero);
        } // fin if (strcmp(registro.username,username) == 0)
    }     // else
    fclose(fichero);
    //borrarUsuarioListadoAccesos(username);
} // fin función borrarUsuario()
/**
 * Esta función borra todos los datos correspondientes
 * a usuario, unca cadena de caracteres recibida por parametro
 * **/
void borrarUsuarioListadoAccesos(char username[])
{
    // almacena el numero de registros borrados
    long numRegistros = 0;
    //posision del apuntador
    long posision = 0;
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de
    // actualización de lectura y escritura, se comprueba que no halla errores
    if ((fichero = fopen("../files/listaAccesos.txt", "r+")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se recorre el archivo para encontrar los registros pertenecientes
        // al usuario
        while (!feof(fichero))
        {
            // asigna la posision del puntero en la que se encuentra el archivo
            posision = ftell(fichero);
            // lee el registro para verificar que pertenece al usuario a borrar
            fread(&registroListaAccesos, sizeof(registroListaAccesos), 1, fichero);
            // se verifica que el nombre de usuario sea el mismo
            if (strcmp(registroListaAccesos.username, username) == 0)
            {
                // borra los datos del usuario en el registro
                strcpy(registroListaAccesos.fecha, "");
                strcpy(registroListaAccesos.codGrafico, "");
                strcpy(registroListaAccesos.fx, "");
                strcpy(registroListaAccesos.username, "");
                // ubica el apuntador en la posision donde esta el registro a borrar
                fseek(fichero, posision, SEEK_SET);
                // asigna el registro vacio al registro de la lista de accesos
                fwrite(&registroListaAccesos, sizeof(registroListaAccesos), 1, fichero);
                // se incrementa el numero de registros borrados
                numRegistros += 1;
            } // fin if (strcmp(registroListaAccesos.username, username)==0)
        }     // fin while (!feof(fichero))
        //printf("Se eliminaron %li registros",numRegistros);getchar();
    } // fin else
    // se sierra el archivo
    fclose(fichero);
} // fin función borrarUsuarioListadoAccesos(char username)
/**
 * Esta función optiene dos credenciales por teclado
 * userna y password, se valida que el usuario no este
 * registrado previamente, si lo esta, se le imprime
 * un mensaje de error y se regresa al menu principal
 * de root, si el usuario no existe se toma el password
 * y se registra**/
void CrearNuevoUsuario()
{
    // limpia la pantalla de la consola
    clear();
    // se declara un array que guardan el usuario ingresado por teclado
    char username[30];
    // se declara un array que guardan la contraseña ingresada por teclado
    char password[30];
    // se imprime la pantalla de la opcion crear nuevo usuario
    printf("\nAplicativo - Graficador - UTP");
    printf("\nMen%c para usuario: root Crear nuevo usuario", 163);
    printf("\nEntre el nuevo usuario:");
    printf("\nUsername: ");
    fflush(stdin);
    // asigna el valor ingresado por teclado a el array username
    scanf("%[^\n]%*c", username);
    fflush(stdin);
    // verifica que le usuario no exista
    if (usuarioExiste(username))
    {
        // si existe imprime un mensaje de error
        printf(ROJO "\n(Error 202): El usuario ingresado ya existe.\n" DEFAULTCOLOR);
        return; // sale de la funcion indicando que el proceso no se pudo realizar
    }           // fin if (usuarioExiste(username))
    printf("\nPassword:");
    // asigna el valor ingresado por teclado a el array password
    // imprime el caracter * por cada caracter ingresado
    int p = 0;
    do
    {
        password[p] = getch();
        if (password[p] != '\r')
        {
            printf("*");
        } // fin if (password[p]!='\r')
        p++;
    } while (password[p - 1] != '\r'); // fin do-while
    password[p - 1] = '\0';
    // control de errores para el registro de un usuario
    if (registrarUsuario(username, password))
    {
        // se imprime un mensaje de error si no se pudo registrar el usuario
        printf(ROJO "\n(Error 200): no se pudo registrar el usuario %s.\n", username);
        printf("Por favor intente nuevamente.\n" DEFAULTCOLOR);
        getchar();
    } // fin if (registrarUsuario(username, password))
} // fin función CrearNuevoUsuario()
/**
 * Esta función verifica si el username recibido por parametro
 * existe dentro del registro de usuarios, de ser así se retorna
 * la posision en la que se encontro el registro, de lo contrario
 * retorna 0 indicando que el usuario no existe dentro del registro**/
long usuarioExiste(char username[])
{
    // almacena la posision del primer registro en el que el username es identico
    long posision = 0;
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de lectura
    // se comprueba que no halla errores
    if ((fichero = fopen("./files/Usuarios.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
        getchar();
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // recorre el archivo hasta llegar al final del mismo
        // o encontrar un registro en el que el username sea identico
        while ((!feof(fichero)))
        {
            // se lee el registro para proceder a compararlo
            fread(&registro, sizeof(registro) + 1, 1, fichero);
            // se valida si el username son identicos
            if (strcmp(username, registro.username) == 0)
            {
                // asigna la posision del archivo en el que encontro el registro
                posision = (ftell(fichero) - (sizeof(registro) + 1));
            }
        }
    } //fin else
    fclose(fichero);
    return posision;
}
/**
 * Esta funcion gestiona el menu del usuario root
 * **/
int menuRoot()
{
    int opcion = 0; //opcion=variable para escoger opciones del menú
    //imprime la pantalla del menu del usuario root
    printf("\nAplicativo - Graficador - UTP");
    printf("\nMen%c principal para usuario: root\n", 163);
    printf("\n0. Salir del aplicativo");
    printf("\n1. Crear un nuevo usuario");
    printf("\n2. Borrar usuario");
    printf("\n3. Listar accesos por usuario");
    printf("\n4. Listar accesos todos los usuarios");
    printf("\n5. Imprimir gr%cfico por referencia", 160);
    printf("\n6. Cambiar password del usuario root");
    printf("\n7. Cambiar password de un usuario");
    printf("\nSelecione la opcion que desea ejecutar: ");
    // recibe por teclado la opción indicada
    scanf("%i", &opcion);
    // en caso de no haber ingresado una opcion dentro del rango
    // el programa iterará hasta que el usuario ingrese una opcion
    // dentro del rango de opciones
    while (opcion < 0 || opcion > 7)
    {
        printf("\n Recuerda que solo se aceptan opciones numericas entre 0 y 7\n");
        printf("Selecione la opcion que desea ejecutar: ");
        scanf("%i", &opcion);
    } //fin while(opcion<0||opcion>7)
    // determina que accion ejecutar segun la opcion escogida
    switch (opcion)
    {
    case 1:
        CrearNuevoUsuario();
        break;
    case 2:
        borrarUsuario();
        break;
    case 3:
        listarAccesosUsuario();
        break;
    case 4:
        listarAccesosUsers();
        break;
    case 5:
        //
        break;
    case 6:
        cambiarPassRoot();
        break;
    case 7:
        cambiarPassUser();
        break;
    }              // Fin del SWITCH
    return opcion; //Si la opcion=0 saldrá del programa
} // fin función menuRoot()
/**
 * Esta funcion gestiona el menu del usuario root
 * **/
int menuUsers(char username[])
{
    int opcion = 0; //opcion=variable para escoger opciones del menú
    //imprime la pantalla del menu del usuario root
    printf("\nAplicativo - Graficador - UTP");
    printf("\nMen%c principal para usuario: %s\n", 163, username);
    printf("\n0. Salir del aplicativo");
    printf("\n1. Crear un nuevo gráfico");
    printf("\n2. Borrar un gráfico existente");
    printf("\n3. Listar accesos");
    printf("\n4. Imprimir gráfico por referencia");
    printf("\n5. Cambiar password del usuario %s", 160, username);
    printf("\nSelecione la opcion que desea ejecutar: ");
    // recibe por teclado la opción indicada
    scanf("%i", &opcion);
    // en caso de no haber ingresado una opcion dentro del rango
    // el programa iterará hasta que el usuario ingrese una opcion
    // dentro del rango de opciones
    while (opcion < 0 || opcion > 5)
    {
        printf("\n Recuerda que solo se aceptan opciones numericas entre 0 y 5\n");
        printf("Selecione la opcion que desea ejecutar: ");
        scanf("%i", &opcion);
    } //fin while(opcion<0||opcion>7)
    // determina que accion ejecutar segun la opcion escogida
    switch (opcion)
    {
    case 1:
        CrearNuevoGrafico(username);
        break;
    case 2:
        borrarGraficoExistente(username);
        break;
    case 3:
        clear();
        // se imprime la pantalla de la opcion listar accesos todos los usuario
        printf("\nAplicativo - Graficador - UTP");
        printf("\nModulo listar accesos - Usuario: %s", username);
        // manejar funcion de orden ascendente y descendente
        listarAccesosUser(username);
        break;
    case 4:
        imprimirGraficoReferencia(username);
        break;
    case 5:
        //
        break;
    }              // Fin del SWITCH
    return opcion; //Si la opcion=0 saldrá del programa
} // fin función menuUsers()
/**
 * Esta función valida las credenciales nombre de usuario y contraseña
 * si el usuario esta registrado y las credenciales son correctas retorna un 0
 * en caso contrario retorna 1 para ser manejado por un control de error
 * **/
int compararCredenciales(char username[], char password[])
{
    // se declara y se incializa en 1, se refiere a que las credenciales aun no son validas
    int credencialesCorrectas = 1;
    // se trae la posision del registro
    long existeUsuario = usuarioExiste(username);
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de lectura
    // se comprueba que no halla errores
    if ((fichero = fopen("./files/Usuarios.txt", "r")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // iterará siempre y cuando no llegue al final del archivo
        // y tampoco halla evaluado que las credenciales sean correctas correctas
        if ((existeUsuario != 0) || (strcmp(username, "root") == 0))
        {
            // se limpia el registro
            strcpy(registro.password, "");
            strcpy(registro.username, "");
            // se ubica el puntero en la posision donde se ubica el registro
            fseek(fichero, existeUsuario, SEEK_SET);
            // se lee el registro a comparar
            fread(&registro, sizeof(registro) + 1, 1, fichero);
            printf("[1]%s - %s", registro.username, registro.password);
            getchar();
            printf("[2]%s - %s", username, password);
            getchar();
            // determina si los nombres de usuario son identicos
            if (strcmp(registro.username, username) == 0)
            {
                // encripta la contraseña para proceder a compararla
                encriptar(password);
                printf("[3]%s - %s - %i", username, password, strcmp(registro.password, password));
                getchar();
                // determina si las contraseñas son identicas
                if (strcmp(registro.password, password) == 0)
                {
                    // si las credenciales son correctas se asigna un cero y sera el valor que retorne
                    // de lo contrario retornará 1, significando que las credenciales no son correctas
                    credencialesCorrectas = 0;
                } // fin if (strcmp(registro.password,password))
            }     // fin if (strcmp(registro.username,username) == 0)
        }         // fin if (existeUsuario)
    }             //fin else
    // sierre del archivo
    fclose(fichero);
    // retorna el resultado
    return credencialesCorrectas;
} // fin función compararCredenciales(char username[], char password[])
/**
 * Esta función crea un registro a partir de un username 
 * y un password ingresados por parametros, ambos cadenas 
 * de caracteres, que posterior mente es encriptado el password
 * por ultimo el registro es agregado al archivo de usuarios.txt
 * **/
int registrarUsuario(char username[], char password[])
{
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de escritura
    // se comprueba que no halla errores
    if ((fichero = fopen("./files/Usuarios.txt", "a")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    } // fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        // se limpia el registro
        strcpy(registro.password, "");
        strcpy(registro.username, "");
        // se copia el usuario en el registro del usuario
        strcpy(registro.username, username);
        // se encripta la contraseña por desplazamiento y por palabra clave
        encriptar(password);
        // se copia la contraseña en el registro del usuario
        strcpy(registro.password, password);
        // se agrega el registro de usuario al archivo de usuarios
        fwrite(&registro, sizeof(registro) + 1, 1, fichero);
    } //fin else
    // sierre del archivo
    fclose(fichero);
    // se verifica que no hayan surgido errores
    if ((strcmp(registro.username, username) + strcmp(registro.password, password)) != 0)
    {
        // retorna 1 si sucedio algun error
        return 1;
    } // fin if ((strcmp(registro.username,username) + strcmp(registro.password,password))!=0)
    else
    {
        // retorna 0 si todo se ejecuto correctamente
        return 0;
    } // fin else
} // fin función (char username[], char password[])
/**
 * Esta función evalua si el archivo 'Usuarios.text' esta vacio o no.
 * retorna 1 si esta vacio.
 * retorna 0 en caso contrario.
 * **/
int UsuariosVacio()
{
    // guarda el indicador si el archivo esta vacio o no
    int vacio = 0;
    // se inializa el puntero y se abre el archivo
    FILE *fichero;
    if ((fichero = fopen("files/Usuarios.txt", "a")) == NULL)
    {
        // control de errores para abrir el archivo
        printf(ROJO "\n(Error 100): No se puede abrir el fichero.\n" DEFAULTCOLOR);
    }
    else
    {
        // situa el puntero del archivo en la posision final del archivo
        fseek(fichero, 0L, SEEK_END);
        // si la posision del puntero actual es igual a 0, entonces esta vacio
        if (ftell(fichero) == 0)
        {
            vacio = 1;
        } //fin if
    }     //fin else
    fclose(fichero);
    return vacio;
} // fin función UsuariosVacio()
/**
 * Esta función administra la asignacion de menus de los susuarios
 * recibe por parametro el nombre de usuario al cual le asignara menu
 * **/
int menu(char username[])
{
    int salir = 1; // controla la salida (0 = salir)
    do
    {
        clear();
        if (strcmp(username, "root") == 0)
        {
            salir = menuRoot();
        }
        else
        {
            salir = menuUsers(username);
        }
    } while (salir != 0);
    return 0;
} // fin función menu (char username[])
/**
 * esta funcion limpia la pantalla de la consola**/
void clear()
{
    if (system("cls"))
        system("clear");
} // fin función clear()
/**
 * Esta funcion compara dos cadenas de caracteres 
 * y verifica que sean exactamente iguales, de ser
 * así retorna 1 de lo contrario retorna 0**/
int passwordIgual(char pass1[], char pass2[])
{
    int igual = 0;
    int cont = 0;
    int in1 = 0;
    int in2 = 0;
    // for que recorre la cadena a comparar
    for (size_t i = 0; pass1[i] = '\0'; i++)
    {
        cont += 1;
        in1 = (int)pass1[i];
        in2 = (int)pass2[i];
        if (in1 == in2)
        {
            igual += 1;
        }
    }
    if (igual == cont)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // fin función passwordIgual(char pass1[], char pass2[])
/**
 * Esta funcion compara dos cadenas de caracteres 
 * y verifica que sean exactamente iguales, de ser
 * así retorna 1 de lo contrario retorna 0**/
void imprimirCadena(char cadena[])
{
    // for que recorre la cadena a comparar
    for (size_t i = 0; cadena[i] = '\0'; i++)
    {
        printf("%i,", cadena[i]);
    }
} // fin función passwordIgual(char pass1[], char pass2[])