#include <stdio.h>
double esPar (int n);
double esImpar (int n);
int main ()
{
    double si = esPar(4);
    if (si)
    {
        printf("Es par\n");
    }
    else
    {
        printf("Es impar\n");
    }
    return 0;
}

double esPar (int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return esImpar(n-1);
    }
}

double esImpar (int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        return esPar(n-1);
    }
}