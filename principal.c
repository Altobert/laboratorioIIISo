#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char *argv[]){

	//Variables que ingresaran por consola
	int h = 0, c=0, u=0, n=0, flag = 0;
    printf("Inicio Programa comparacion Algoritmos -m\n");
	//recibirArgumentos(argc, argv, &n, &flag);
	recibirArgumentos(argc, argv, &h, &c, &u, &n, &flag);
	if(flag==1){
		printf("Se utilizo flag -m\n");
	}		
    return 0;

}
