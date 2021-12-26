#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

float* faults_opt;

#include "funciones.h"

/*
	Funcion principal de programa en lenguaje c
*/
int main(int argc, char *argv[]){

	printf("Laboratorio III Sistemas Operativos \n");

	//Variables que ingresaran por consola
	//int c = 0, flag = 0, numeroPaginas=0;
	int marcos = 0, flag = 0;
	
	//i nombre archivo entrada
	//o nombre archivo salida
	const char* i=0;
	const char* o=0;

	//paginas - valor por defecto inicial.
	int paginas[100];
    	
	recibirArgumentos(argc, argv, &marcos, &i, &o, &flag);
	
	printf("%d\n",marcos);
	printf("%s\n",i);
	printf("%s\n",o);	
			
	FILE *file = fopen(i, "r");
	int cantidad=0;
	if (file == NULL)
    {
        printf("Error en funcion leerArchivo() no pudo leer archivo %s \n", i);
        exit(0);
    }else{
	
		while(fscanf(file,"%d",&paginas[cantidad]) != EOF) {
			cantidad++;
			if (cantidad == 99) { break; } /* 99 pagias es un limite */
		}
		fclose(file);
	}

	
	
	printf("--------------------------------\n");
	printf("Algoritmo OPT\n");	
	OPTAlgoritmo(marcos,paginas,cantidad);

	printf("--------------------------------\n");
	printf("Algoritmo LRU\n");	
	LRUAlgoritmo(marcos,paginas,cantidad);

	printf("--------------------------------\n");
	printf("Algoritmo CLOCK\n");	
	CLOCKAlgoritmo(marcos,paginas,cantidad);

	printf("--------------------------------\n");
	printf("Algoritmo FIFO\n");	
	FIFOAlgoritmo(marcos,paginas,cantidad);

	if(flag==1){
		printf("Se utilizo flag -b\n");
	}
	
	return 0;

}
