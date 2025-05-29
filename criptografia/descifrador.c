////////////////////////////////////////////////////////////////////
/***+**********************************************************+***/
/***+                                                          +***/
/***+                 /////////////////////                    +***/
/***+             ////////////////////////////                 +***/
/***+          /////////////////////////////////               +***/
/***+        ////////                     ////////             +***/
/***+       ///////                                            +***/
/***+      //////      Ing(c) Alejandro Vergara Álavrez        +***/
/***+      //////                 1076352780                   +***/
/***+      //////                  9-11-2020                   +***/
/***+      //////        IS284_Programacion_II_Gr._4           +***/
/***+      //////         PhD Ricardo Moreno Laverde           +***/
/***+      //////     Universidad_Tecnologica_de_Pereira       +***/
/***+      ////// descifrado desplazamiento y palabra clave    +***/
/***+      ///////                                             +***/
/***+       ///////                    ////////                +***/
/***+        ////////////////////////////////                  +***/
/***+          ////////////////////////////                    +***/
/***+              ////////////////////                        +***/
/***+                                                          +***/
/***+**********************************************************+***/
////////////////////////////////////////////////////////////////////
// #include <stdio.h>// inclusion de la libreria Standar Input Output
// #include <stdlib.h>// inclusion de la libreria standard library
// #include <string.h>// inclusion de la libreria para manejo de string
#include "cifrador.c"
//prototipo de funciones a utilizar
int encontrarPosisionDesplazada(char nombreArchivo[256]);
void copiarArchivo(char nombreArchivo[256]);
void descifradoDesplaza(); 
void descifradoPalabra();
void mostrarTodo(); 
int menu();
void clear();
/**
 * Definicion de la funcion principal
 * **/
int main()
{
    int salir = 1;
    do
    {
        clear();
        salir = menu();
    } while (salir != 0);
    return 0;
} // fin función principal

/**
 * Esta función genera un menu de control para ingresar
 * a las opciones del programa
 * **/
int menu()
{
    int opcion=0; //opcion = variable para escoger opciones del menú
    printf("|========================================|\n");
    printf("| MENU GENERAL                           |\n");
    printf("|========================================|\n");
    printf("| 0. Salir del programa                  |\n");
    printf("| 1. Visualizar archivo                  |\n");
    printf("| 2. Descifrado por desplazamiento       |\n");
    printf("| 3. Descifrado por palabra Clave        |\n");
    printf("| 4. Menu encriptar                      |\n");
    printf("|========================================|\n");
    printf("Selecione la opcion que desea ejecutar: ");
    scanf("%i", &opcion);
    while(opcion < 0 || opcion > 4)
    {
        printf("\n Recuerda que solo se aceptan opciones numericas entre 0 y 3\n");
        printf("Selecione la opcion que desea ejecutar: ");
        scanf("%i", &opcion);
    } //fin while(opcion < 0  ||  opcion > 3)
    switch(opcion)
          {
           case 1:
                  mostrarTodo();
                  break;
           case 2:
                  descifradoDesplaza();
                  break;
           case 3:
                  descifradoPalabra();
                  break;
           case 4:
                  encriptar();
                  break;
           } // Fin del SWITCH
    return opcion; //Si la opcion=0 saldrá del programa
} // Fin funcion menu()

/**
 * Esta función limpia la consola
 * **/
void clear()
{
   if(system("cls"))
     system("clear");
} // fin función clear()

/**
 * Esta función imprime todos los carcateres de un archivo
 * la ruta o el nombre del archivo debe ingrsesarse por consola
 * **/
void mostrarTodo()
{
    char nombreArchivo[256];
    printf("\n\tIngrese el nombre o ruta del archivo  -> ");
    scanf("%s", nombreArchivo);
    char valor=0;
    char espera=0;
    FILE *archivo=NULL; //crea un puntero de archivo que recibirá la direccion física donde inicia el archivo ingresado
    archivo=fopen(nombreArchivo, "r"); // se pasa la ruta del archivo y el modo de apertura "r" indica lectura - (r)ead
    if(archivo==NULL) //Por si hay problema con la apertura del archivo o no existe en la carpeta donde se esta ejecutando el programa
    {
        printf("\nError en la apertura del archivo...\n");
        printf("\n\n\n\tPresione enter para regresar al menu principal...\n");
        espera=getchar(); //Para detener el programa mientras lee mensaje
    }
    else
    {
        printf("\n\tContenido visual del archivo %s \n",nombreArchivo);
        printf("---------------------------------------------------------------------------------------------------------------\n");
        while(!feof(archivo))
        {
            valor=fgetc(archivo);
            printf("%c",valor);
        }//fin while
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();
       }//fin if
    fclose(archivo);
    espera=getchar();// espera, se debe presionar enter para seguir ejecutando el programa
    return; // Un solo return - una sola salida de la función
} // fin funcion mostrarTodo()


/**
 * Esta función Descifra un archivo encriptado por desplazamiento
 * pide por teclado el nombre del archivo a descifrar y el 
 * valor a desplazar
 * **/
void descifradoDesplaza()
{
    char nombreArchivo[256];
    printf("\n\tIngrese el nombre o ruta del archivo  -> ");
    scanf("%s", nombreArchivo);
    int vd = encontrarPosisionDesplazada(nombreArchivo); //vd=valor a desplazar
    char valor=0; //guarda el caracter leido del archivo 
    FILE *archivo=fopen(nombreArchivo,"r");
    FILE *desplazado=fopen("F_descifrado","w"); //lo crea nuevo aunque ya exista
    if(archivo==NULL||desplazado==NULL) //evalua si el archivo existe y/o no tiene problemas
    {
        printf("\n Al abrir el archivo se presentaron problemas ");
        getchar(); //detiene el programa esperando que se presione cualquier tecla. Usado para dar tiempo de leer
    }
    else
    {
        //printf("\nEntre valor a desplazar: ");
        //scanf("%i",&vd);
        while(!feof(archivo))
        {
            valor=fgetc(archivo);
            printf("%c",valor);
            valor=valor-vd;
            printf("%c",valor);
            fputc(valor,desplazado);
        }//fin while
    } //fin if
    fclose(archivo);
    fclose(desplazado);
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\n\tPresione enter para regresar al menu principal...\n");
    getchar();
    return; //Un solo return - una sola salida de la función
} //fin funcion descifradoDesplaza()


/**
 * Esta función Descifra un archivo encriptado por palabra clave
 * pide por teclado el nombre del archivo a descifrar y la
 * palabra clave con la que fue encriptada
 * **/
void descifradoPalabra()
{
    // nombre del archivo a descifrar
    char nombreArchivo[256];
    printf("\n\tIngrese el nombre o ruta del archivo --> ");
    scanf("%s", nombreArchivo);
    // palabra clave
    //char p_clave[256];
    //printf("\n\tIngrese la palabra clave --> ");
    //scanf("%s", p_clave);
    char p_clave[256]="MmUuRrCcIiEeLlAaGgOo";//Entro directamente la palabra clave
    char valor=0; //guarda el caracter leido del criptograma
    char clave=0; //guarda el caracter leido del criptograma
    FILE *encriptado=NULL; //puntero a archivo encriptado
    encriptado=fopen(nombreArchivo,"r"); //lo abre en modo lectura
    FILE *apc=NULL; //crea un puntero de archivo archivo F_descifrado
    apc=fopen("F_descifrado2", "w"); //Genera un nuevo archivo aunque exista
    if(apc==NULL||encriptado==NULL) //evalua si los archivos existen y/o no tiene problemas de apertura
    {
        printf("\n Al abrir algun archivo se presentaron problemas ");
        getchar(); //detiene el programa esperando que se presione cualquier tecla. Usado para dar tiempo de leer
    }
    else
    {
        while(!feof(encriptado))
        {
            valor = fgetc(encriptado); //leo un caracter del archivo encriptado
            if(valor < 20)
            {
                clave = p_clave[valor];
                fputc(clave,apc);
            }
        }//fin while (!feof(cifrado)
        printf("\nTamaño archivo descifrado x PC %li bytes",ftell(apc));
        fclose(apc); fclose(encriptado);
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
    }//fin if(apc==NULL||cifrado==NULL)
    printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();
    
    return; //Un solo return - una sola salida de la función
}//fin funcion descifradoPalabra()

int encontrarPosisionDesplazada(char nombreArchivo[256])
{
    //
    int numIguales = 0;// los valores que se repitieron el mismo numero de veces del valor conseguido
    int cont = 0;
    int contMayor = 0;
    char valor = 0;
    char valorRepetido = 0;
    char valorCopy = 0;
    copiarArchivo(nombreArchivo); // genera una copia del archivo, el archivo generado es: copy
    FILE *encriptado=NULL; //puntero a archivo encriptado
    encriptado=fopen(nombreArchivo,"r"); //lo abre en modo lectura
    if(encriptado==NULL) //evalua si los archivos existen y/o no tiene problemas de apertura
    {
        printf("\n Al abrir algun archivo se presentaron problemas ");
        getchar(); //detiene el programa esperando que se presione cualquier tecla. Usado para dar tiempo de leer
    }
    else
    {
        while(!feof(encriptado))
        {
            valor = fgetc(encriptado); //leo un caracter del archivo encriptado
            
            FILE *copyEncriptado=NULL; //puntero a archivo encriptado
            copyEncriptado=fopen("copy","r"); //lo abre en modo lectura
            if(copyEncriptado==NULL) //evalua si los archivos existen y/o no tiene problemas de apertura
            {
                printf("\n Al abrir algun archivo se presentaron problemas ");
                getchar(); //detiene el programa esperando que se presione cualquier tecla. Usado para dar tiempo de leer
            }
            else
            {
                while (!feof(copyEncriptado))
                {
                    
                    valorCopy = fgetc(copyEncriptado); //leo un caracter del archivo encriptado
                    if (valor == valorCopy)
                    {
                        cont += 1;
                    }

                }
            }
            fclose(copyEncriptado);
            if(cont >= contMayor)
            {
                if ( cont == contMayor)
                {
                    numIguales += 1;
                }
                else
                {
                    numIguales = 0;
                }
                contMayor = cont;
                valorRepetido = valor;
            }
            cont = 0;
        }//fin while (!feof(cifrado)
        fclose(encriptado);
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
    }
    if (numIguales != 0)
    {
        printf("\n\t[Error] Se repitieron la misma cantidad de veces %i valores\n\tPresione Enter para continuar.",numIguales);getchar();
    }
    return valorRepetido - 32;
}

void copiarArchivo(char nombreArchivo[256])
{
    //
    char valor = 0;
    FILE *encriptado=NULL; //puntero a archivo encriptado
    encriptado=fopen(nombreArchivo,"r"); //lo abre en modo lectura
    FILE *apc=NULL; //crea un puntero de archivo archivo F_descifrado
    apc=fopen("copy", "w"); //Genera un nuevo archivo aunque exista
    if(apc==NULL||encriptado==NULL) //evalua si los archivos existen y/o no tiene problemas de apertura
    {
        printf("\n Al abrir algun archivo se presentaron problemas ");
        getchar(); //detiene el programa esperando que se presione cualquier tecla. Usado para dar tiempo de leer
    }
    else
    {
        while(!feof(encriptado))
        {
            valor = fgetc(encriptado); //leo un caracter del archivo encriptado
            fputc(valor,apc);
        }//fin while (!feof(cifrado)
        printf("\nTamaño archivo descifrado x PC %li bytes",ftell(apc));
        fclose(apc); fclose(encriptado);
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
    }//fin if(apc==NULL||cifrado==NULL)
    printf("\n\n\n\tPresione enter para regresar al menu principal...\n");getchar();
    
    return; //Un solo return - una sola salida de la función
}
