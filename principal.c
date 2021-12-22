#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funciones.h"

/*
	Funcion principal de programa en lenguaje c
*/
int main(int argc, char *argv[]){

	//Variables que ingresaran por consola
	int c = 0, i=0, o=0, flag = 0;
    printf("Inicio Programa comparacion Algoritmos -m\n");
	//recibirArgumentos(argc, argv, &n, &flag);
	recibirArgumentos(argc, argv, &c, &i, &o, &flag);
	if(flag==1){
		printf("Se utilizo flag -b\n");
	}
	printf("%d\n",c);		
	printf("%d\n",i);		
	printf("%d\n",o);		
    return 0;

}
