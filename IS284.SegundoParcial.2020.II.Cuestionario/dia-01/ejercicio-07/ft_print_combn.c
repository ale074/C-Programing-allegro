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
/***+      //////                 21-11-2020                   +***/
/***+      //////                 Versión 2                    +***/
/***+      //////  Compilador: gcc (MinGW.org GCC Build-2)     +***/
/***+      //////               Versión: 9.2.0                 +***/
/***+      //////               ft_print_combn                 +***/
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
//////                    Segundo parcial                     //////
//////                                                        //////
////////////////////////////////////////////////////////////////////
#include <stdio.h>// inclusion de la libreria Standar Input Output
//prototipo de función
void ft_print_combn(int n);
/**
 * Esta función que muestra todas las combinaciones diferentes de n números en orden ascendente.
 * 
 * **/
void ft_print_combn (int n)
{
    int comb[n];
	//Se definen las variables que se van a combinar
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0;
	//Se define el incio de cada variable, de esta estar presente en un int array
    for (size_t i = 0; i < n; i++)
    {
        comb[i] = i;
    }
	
	/**
	 * Se presentan los diferentes casos, dependiendo del valor de n
	 * Por cada n se requerira una variable mas en el problema, por ende otro for anidado
	 * Cada variable debe iniciar en 1 mas que la variable anterior
	 * Cada variable finaliza en su posicion inicial + (10 - n), donde n es el numero de variables
	 * **/
	switch (n){
		case 1:
			for(a=0;a<=(comb[0]+(10-n));a++){
				printf("%i,",a);
			}
			break;
		case 2:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
				printf("%i%i,",a,b);
				}
			}
			break;
		case 3:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						printf("%i%i%i,",a,b,c);
					}
				}
			}
			break;
		case 4:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							printf("%i%i%i%i,",a,b,c,d);
						}
					}
				}
			}
			break;
		case 5:	
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							for(e=d+1;e<=(comb[4]+(10-n));e++){
								printf("%i%i%i%i%i,",a,b,c,d,e);
							}
						}
					}
				}
			}
		case 6:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							for(e=d+1;e<=(comb[4]+(10-n));e++){
								for(f=e+1;f<=(comb[5]+(10-n));f++){
									printf("%i%i%i%i%i%i,",a,b,c,d,e,f);
								}
							}
						}
					}
				}
			}
		case 7:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							for(e=d+1;e<=(comb[4]+(10-n));e++){
								for(f=e+1;f<=(comb[5]+(10-n));f++){
									for(g=f+1;g<=(comb[6]+(10-n));g++){
										printf("%i%i%i%i%i%i%i,",a,b,c,d,e,f,g);
									}
								}
							}
						}
					}
				}
			}
		case 8:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							for(e=d+1;e<=(comb[4]+(10-n));e++){
								for(f=e+1;f<=(comb[5]+(10-n));f++){
									for(g=f+1;g<=(comb[6]+(10-n));g++){
										for(h=f+1;h<=(comb[7]+(10-n));h++){
											printf("%i%i%i%i%i%i%i%i,",a,b,c,d,e,f,g,h);
										}
									}
								}
							}
						}
					}
				}
			}
		case 9:
			for(a=0;a<=(comb[0]+(10-n));a++){
				for(b=a+1;b<=(comb[1]+(10-n));b++){
					for(c=b+1;c<=(comb[2]+(10-n));c++){
						for(d=c+1;d<=(comb[3]+(10-n));d++){
							for(e=d+1;e<=(comb[4]+(10-n));e++){
								for(f=e+1;f<=(comb[5]+(10-n));f++){
									for(g=f+1;g<=(comb[6]+(10-n));g++){
										for(h=g+1;h<=(comb[7]+(10-n));h++){
											for(i=h+1;i<=(comb[8]+(10-n));i++){
												printf("%i%i%i%i%i%i%i%i%i,",a,b,c,d,e,f,g,h,i);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		default:
			break;
	}   
    
}
/**
 * Declaración de la función main.
 * 
 * **/
int main ()
{
    ft_print_combn(6);
    return 0;
}