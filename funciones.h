#ifndef FUNCIONES_H
#define FUNCIONES_H

//Cabecera de funcion encargada de recibir argumentos ingresados por consola.
//void recibirArgumentos(int argc, char *argv[], int *n, int *flag);
void recibirArgumentos(int argc, char *argv[], int *c,const char** i,const char** o, int *flag);

//Cabecera de funcion leer archivo
void leerArchivoFloat(const char* fileName, float * out, int len);

//Algoritmo LRU
void LRUAlgoritmo(int marcos);

#endif