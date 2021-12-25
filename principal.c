#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funciones.h"

/*
	Funcion principal de programa en lenguaje c
*/
int main(int argc, char *argv[]){

	//Variables que ingresaran por consola
	int c = 0, flag = 0, numeroPaginas=0;
	int arrValores[]={};
	//int *n;  
	//i nombre archivo entrada
	//o nombre archivo salida
	const char* i=0;
	const char* o=0;
    printf("Laboratorio III Sistemas Operativos \n");
	
	recibirArgumentos(argc, argv, &c, &i, &o, &flag);
	
	printf("%d\n",c);
	printf("%s\n",i);
	printf("%s\n",o);	

			
	int tamanio = 1024;
	int *visibilidades    = (float*)malloc(sizeof(float)*tamanio);
	int *visibilidadesOut = (float*)malloc(sizeof(float)*tamanio);
	
	leerArchivo(i, visibilidades, tamanio, &numeroPaginas);
		
	visibilidadesOut = obtenerDatos(visibilidades, tamanio);

	printf("paginas desde main: %d\n",numeroPaginas);

	escribirArchivo(o, visibilidadesOut, tamanio);

	LRUAlgoritmo(c,numeroPaginas);

	if(flag==1){
		printf("Se utilizo flag -b\n");
		
	}

	/*

	if(flag==1){
		printf("Se utilizo flag -b\n");
		
	}
	*/
	return 0;

}
