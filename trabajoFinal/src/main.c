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
/***+      //////                 03-12-2020                   +***/
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
/**
 * Este aplicativo administra un programa que permite primero acceso
 * con un modulo de usuarios con “username” y “password” para cada 
 * usuario, registrando el “log” de acceso a todos los usuarios y
 * luego permita manejar un modulo quepermita graficar una función
 * polinómica del tipo f(x).
 * **/
#include "./menuModules/menu.c"
#define SCANSPACIOS "%[^\n]%*c"
// prototipos de funciones a utilizar
int inicioSesion(int n);
//ESTRUCTURAS
//DECLARACION DE FUNCIONES
/**
 * Esta funcion **/
int inicioSesion(int n)
{
    // se declara un array que guardan el usuario ingresado por teclado
    char username[30];
    // se declara un array que guardan la contraseña ingresada por teclado
    char password[30];
    // imprime el mensaje de la pantalla de inicio de sesion.
    printf("\nAplicativo - Graficador - UTP\n");
    printf(VERDE"\nUsername:"DEFAULTCOLOR);
    fflush(stdin);
    // asigna el valor ingresado por teclado a el array username
    scanf(SCANSPACIOS,username);
    fflush(stdin);
    // determina si el archivo de usuarios esta vacio
    if (UsuariosVacio())
    {
        // determina si el usuario es diferente a root
        if (strcmp(username,"root") != 0)
        {
            // en tal caso termina el programa
            printf(ROJO"\n(Error): Usuario incorrecto\n"DEFAULTCOLOR);
            return 0;
        }// fin if (UsuariosVacio())
        else
        {
            // asigna el valor ingresado por teclado a el array password
            // imprime el caracter * por cada caracter ingresado
            do
            {
                printf(VERDE"\nPassword:"DEFAULTCOLOR);
                int p = 0;
                do
                {
                    password[p]=getch();
                    if (password[p]!='\r')
                    {
                        printf("*"); 
                    }// fin if (password[p]!='\r')
                    p++;
                }while(password[p-1]!='\r');// fin do-while
                password[p-1]='\0';
                printf("%c[2K%c", 27, 13);
                printf("%c[2K%c", 27, 13);
            } while (!(strlen(password)>=4));
            printf(VERDE"\nPassword:"DEFAULTCOLOR);
            // control de errores para el registro de un usuario
            if (registrarUsuario(username, password))
            {
                printf(ROJO"\n(Error 200): no se pudo registrar el usuario %s.\n", username);
                printf("Por favor intente nuevamente.\n"DEFAULTCOLOR);getchar();
                return inicioSesion(n+1);
            } else {// fin  if (registrarUsuario(username, password))
                return 0;// si el registro se realizo con exito, se sierra el aplicativo
            }// fin else
        }// fin if (strcmp(username,"root") != 0)
    }// fin if (UsuariosVacio())
    // si no debe comparar las credenciales del usuario ingresado
    else
    {
        printf(VERDE"\nPassword:"DEFAULTCOLOR);
        int p = 0;
        do
        {
            password[p]=getch();
            if (password[p]!='\r')
            {
                printf("*"); 
            }// fin if (password[p]!='\r')
            p++;
        }while(password[p-1]!='\r');// fin do-while
        password[p-1]='\0';
        // control de errores para la comparacion de credenciales
        if (compararCredenciales(username, password))
        {
            printf(ROJO"\n(Error 201): El username o password ingresados,"
                "\nno corresponden a un usuario registrado,"
                "\nPor favor intente nuevamente.\n"DEFAULTCOLOR);getchar();
            // 3 oportunidades tendra para inciar sesion
            if (n < 3)
            {
                return inicioSesion(n+1);
            } else {// fin if (n <= 3)
                return 0;
            }// fin else
        }// fin if (compararCredenciales(username, password))
        else
        {
            return menu(username);
        }// else
    }// fin else
}// fin inicioSesion()
/**Declaracion de la función Principal**/
int main()
{
    int salir = 1;// controla la salida (0 = salir)
    do
    {
        //clear();
        salir = inicioSesion(salir);
    } while (salir != 0);
    return 0;
}// fin función main()