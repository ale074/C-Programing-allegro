#include <stdio.h>
#include <math.h>
void escalera(int n, int array[]);
void imprimir(int n, int array[]);
int main () {
    int array[4];
    escalera(0,array);
    imprimir(0,array);
    return 0;
}
void escalera(int n, int array[]){
    int resultado = 0;
    int a = 0;
    int b = 0;
    scanf("%i",&a);
    scanf("%i",&b);
    if((a >= 1) && (b <= 1000)){
        array[n] = (int) ceil(sqrte((double) (a*a+b*b)));
        escalera(n+1,array);
    }
}
float sqrte(float m)
{
    float i=0;
    float x1,x2;
    while( (i*i) <= m )
            i+=0.1;
    x1=i;
    for(int j=0;j<10;j++)
    {
        x2=m;
        x2/=x1;
        x2+=x1;
        x2/=2;
        x1=x2;
    }
    return x2;
}
void imprimir(int n, int array[]){
    if (n<=4)
    {
        printf("Caso #%i: %i\n",(n+1),array[n]);
        imprimir(n+1,array);
    }
    
}