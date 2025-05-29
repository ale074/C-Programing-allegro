#include <stdio.h>
#include <string.h>

//ESTRUCTURAS
struct {
    long desplazamiento;
    char p_clave[30];
} registroSeguridad;
int main()
{
    // se declara un apuntador de tipo archivo
    FILE *fichero;
    // se inicializa el apuntador, se abre el archivo usuarios en un modo de lectura
    // se comprueba que no halla errores
    if ((fichero = fopen( "./seguridad.gra", "w")) == NULL)
    {
        // control de errores para abrir el archivo
        printf("\x1b[31m""\n(Error 100): No se puede abrir el fichero.\n""\x1b[0m");
    }// fin if ((fichero = fopen( "files/Usuarios.txt", "r+")) == NULL)
    else
    {
        registroSeguridad.desplazamiento = 5;
        strcpy(registroSeguridad.p_clave,"MmUuRrCcIiEeLlAaGgOo123456789");
        fwrite(&registroSeguridad, sizeof(registroSeguridad)+1, 1, fichero);
    }
    return 0;
}