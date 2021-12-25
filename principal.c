#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funciones.h"

/*
	Funcion principal de programa en lenguaje c
*/
int main(int argc, char *argv[]){

	//Variables que ingresaran por consola
	//int c = 0, flag = 0, numeroPaginas=0;
	int marcos = 0, flag = 0;
	
	//i nombre archivo entrada
	//o nombre archivo salida
	const char* i=0;
	const char* o=0;

	//paginas
	int paginas[100];

    printf("Laboratorio III Sistemas Operativos \n");
	
	recibirArgumentos(argc, argv, &marcos, &i, &o, &flag);
	
	printf("%d\n",marcos);
	printf("%s\n",i);
	printf("%s\n",o);	

			
	/*
	int tamanio = 1024;	
	float *visibilidades    = (float*)malloc(sizeof(float)*tamanio);
	float *visibilidadesOut = (float*)malloc(sizeof(float)*tamanio);	
	leerArchivo(i, visibilidades, tamanio, &numeroPaginas);		
	visibilidadesOut = obtenerDatos(visibilidades, tamanio);		
	printf("paginas desde main: %d\n",numeroPaginas);
	escribirArchivo(o, visibilidadesOut, tamanio);*/
	//Lectura de archivo

	FILE *file;
	file = fopen(i, "r");
	int cantidad=0;
	while(fscanf(file,"%d",&paginas[cantidad]) != EOF) {
		cantidad++;
		if (cantidad == 99) { break; } /* 99 pagias es un limite */
	}

	//LRU
	printf("--------------------------------\n");
	printf("Algoritmo LRU\n");	
	LRUAlgoritmo(marcos,paginas,cantidad);

	printf("--------------------------------\n");
	printf("Algoritmo OPT\n");	
	OPTAlgoritmo(marcos,paginas,cantidad);

	if(flag==1){
		printf("Se utilizo flag -b\n");
		
	}
	
	return 0;

}
