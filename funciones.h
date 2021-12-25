#ifndef FUNCIONES_H
#define FUNCIONES_H

//Cabecera de funcion encargada de recibir argumentos ingresados por consola.
//void recibirArgumentos(int argc, char *argv[], int *n, int *flag);
void recibirArgumentos(int argc, char *argv[], int *c,const char** i,const char** o, int *flag);

//Cabecera de funcion leer archivo
void leerArchivo(const char* fileName, float * out, int len);

float *obtenerDatos(float* visible, int largo);

void escribirArchivo(const char* fileName, float* out, int len);

//Cabecera de funcion encargada de leer archivo
int * readFile(const char* nombreArchivo, int *numeroPaginas, int arrValores[]);

//Algoritmo LRU
void LRUAlgoritmo(int marcos);

// Algoritmo FIFO
void FIFOAlgoritmo(int marcos);

// Algoritmo OPT
void OPTAlgoritmo(int marcos);

// Algoritmo CLOCK
void CLOCKAlgoritmo(int marcos);

#endif