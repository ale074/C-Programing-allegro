#include <stdio.h>
int main()
{
    char c = 0;
    FILE *aa = fopen("F_desplazado","r");
    for (size_t i = 0; i < 78; i++)
    {
        c = fgetc(aa);
        printf("%i-",c);
        printf("%c\n",c);
    }
    
    return  0;
}