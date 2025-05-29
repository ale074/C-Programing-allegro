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
#include <stdio.h>// inclusion de la libreria Standar Input Output
#include <string.h>


//ESTRUCTURAS
struct {
    int desplazamiento;
    char p_clave[30];
} registroSeguridad;

//prototipo de funciones a utilizar
void encriptarPorDesplazamiento(char cadena[], int n); // Toma el archivo "original.txt" y genera siempre un nuevo archivo "F_desplazado"
void encriptarPorPalabraClave(char cadena[], char p_clave[]); // Toma el archivo "F_desplazado" y genera siempre un nuevo archivo "F_palabraclave"
void encriptar(char cadena[]);
void desencriptarPorDesplazamiento(char cadena[], int n); // Toma el archivo "original.txt" y genera siempre un nuevo archivo "F_desplazado"
void desencriptarPorPalabraClave(char cadena[], char p_clave[]); // Toma el archivo "F_desplazado" y genera siempre un nuevo archivo "F_palabraclave"
void desencriptar(char cadena[]);// funcion que ejecuta el programa


void encriptarPorDesplazamiento(char cadena[], int n)
{
  for (size_t i = 0; cadena[i] != 0; i++)
  {
    cadena[i] = cadena[i]+n;
  }
} //fin funcion encriptarPorDesplazamiento(char cadena[], int n)

void encriptarPorPalabraClave(char cadena[], char p_clave[])
{
  char c = ' ';
  for (size_t i = 0; cadena[i] != '\0'; i++)
  {
    c = cadena[i];
    for (size_t j = 0; p_clave[j] != '\0'; j++)
    {
      if (c == p_clave[j])
      {
        c = i+1;
      }
    }
    cadena[i]=c;
  }
}//fin funcion encriptarPorPalabraClave(char cadena[], char p_clave[])



void encriptar(char cadena[])
{
  FILE *fichero;
  if ((fichero = fopen( "files/seguridad.gra", "r")) == NULL)
  {
      // control de errores para abrir el archivo
      printf("\x1b[31m""\n(Error 100): No se puede abrir el fichero.\n""\x1b[0m");
  }
  else
  {
    fread(&registroSeguridad, sizeof(registroSeguridad)+1, 1, fichero);
    encriptarPorDesplazamiento(cadena ,registroSeguridad.desplazamiento);
    encriptarPorPalabraClave(cadena, registroSeguridad.p_clave);
    
  }
  fclose(fichero);
} // fin encriptar

 


void desencriptarPorDesplazamiento(char cadena[], int n)
{
  for (size_t i = 0; cadena[i] != 0; i++)
  {
    cadena[i] = cadena[i]-n;
  }
} //fin funcion encriptarPorDesplazamiento(char cadena[], int n)

void desencriptarPorPalabraClave(char cadena[], char p_clave[])
{
  char c = ' ';
  for (size_t i = 0; cadena[i] != 0; i++)
  {
    c = cadena[i];
    if (c >= 0 && c < strlen(p_clave))
    {
      c = p_clave[c];
    }
    cadena[i]=c;
  }
}//fin funcion encriptarPorPalabraClave(char cadena[], char p_clave[])



void desencriptar(char cadena[])
{
  FILE *fichero;
  if ((fichero = fopen( "files/seguridad.gra", "r")) == NULL)
  {
      // control de errores para abrir el archivo
      printf("\x1b[31m""\n(Error 100): No se puede abrir el fichero.\n""\x1b[0m");
  }
  else
  {
    fread(&registroSeguridad, sizeof(registroSeguridad)+1, 1, fichero);
    desencriptarPorPalabraClave(cadena, registroSeguridad.p_clave);
    desencriptarPorDesplazamiento(cadena ,registroSeguridad.desplazamiento);
  }
  fclose(fichero);
} // fin encriptar

 
