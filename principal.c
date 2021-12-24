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
	int *n;  
	//i nombre archivo entrada
	//o nombre archivo salida
	const char* i=0;
	const char* o=0;
    printf("Laboratorio III Sistemas Operativos \n");
	
	recibirArgumentos(argc, argv, &c, &i, &o, &flag);
	
	printf("%s\n",i);
	printf("%s\n",o);
		
	//Leer archivo
	//n = readFile(i, &numeroPaginas, arrValores);
	/*for(int i=0;i<22;i++){  
        printf("%d\n", n[i]);  
    }*/ 
	int tamanio = 1024;
	float *visibilidades    = (float*)malloc(sizeof(float)*tamanio);
	float *visibilidadesOut = (float*)malloc(sizeof(float)*tamanio);
	leerArchivo(i, visibilidades, tamanio);
	visibilidadesOut = obtenerDatos(visibilidades, tamanio);

	escribirArchivo(o, visibilidadesOut, tamanio);

	//printf("%d\n",numeroPaginas);
		
	//Algoritmo LRU	
	LRUAlgoritmo(c);

	if(flag==1){
		printf("Se utilizo flag -b\n");
		return 0;
	}

}
