#include <stdio.h>
void alfabeto (void);
int main ()
{
    alfabeto();
    return 0;
}

void alfabeto (void) 
{
    char *letra;
    *letra = 'a';
    printf("%c",*letra);
    if (*letra < 122)
    {
        *letra = *letra+1;
        alfabeto();
    }
}