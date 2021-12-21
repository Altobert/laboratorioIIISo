

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//En este archivo.c se encuentran las implementacion de las 
//funciones para el laboratorio III de SO.

void LRUAlgoritmo(){

    int frames[10], temp[10], pages[10];
    int total_pages, m, n, position, k, l, total_frames;
    int a = 0, b = 0, page_fault = 0;
    printf("\nIngrese numero total de ventanas:\t");
    scanf("%d", &total_frames);
    for(m = 0; m < total_frames; m++){
        frames[m] = -1;
    }
    printf("Ingrese numero total de paginas:\t");
    scanf("%d", &total_pages);
    printf("Enter Values for Reference String:\n");
    for(m = 0; m < total_pages; m++){
        printf("Value No.[%d]:\t", m + 1);
        scanf("%d", &pages[m]);
    }
    for(n = 0; n < total_pages; n++){

        a = 0, b = 0;
        for(m = 0; m < total_frames; m++)
        {
                if(frames[m] == pages[n])
                {
                    a = 1;
                    b = 1;
                    break;
                }
        }
        if(a == 0)
        {
                for(m = 0; m < total_frames; m++)
                {
                    if(frames[m] == -1)
                    {
                            frames[m] = pages[n];
                            b = 1;
                            break;
                    }
                }
        }
        if(b == 0)
        {
                for(m = 0; m < total_frames; m++)
                {
                    temp[m] = 0;
                }
                for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                {
                    for(m = 0; m < total_frames; m++)
                    {
                            if(frames[m] == pages[k])
                            {
                                temp[m] = 1;
                            }
                    }
                }
                for(m = 0; m < total_frames; m++)
                {
                    if(temp[m] == 0)
                    position = m;
                }
                frames[position] = pages[n];
                page_fault++;
        }
        printf("\n");
        for(m = 0; m < total_frames; m++)
        {
                printf("%d\t", frames[m]);
        }
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
    //return 0;    
}

void recibirArgumentos(int argc, char *argv[], int *h,int *c,int *u, int *n, int *flag){

	int flags, opt;
	char *aux3=NULL;
	char *auxC=NULL;
	char *auxH=NULL;
	char *auxU=NULL;
	char *auxN=NULL;

	/*
		Se crea espacio de memoria para cada variable recibida por consola.
		Tambien es casteada a tipo de dato entero.
	*/
	aux3 = malloc(10*sizeof(char));
	auxC = malloc(10*sizeof(char));
	auxH = malloc(10*sizeof(char));
	auxU = malloc(10*sizeof(char));
	auxN = malloc(10*sizeof(char));

	if(argc <3){//si se ingresa un numero de argumentos menor a 3, se finaliza la ejecucion del programa
		//Debe ser 3, porque el nombre del programa se considera como un argumento, siendo -h y el valor que acompañe a -h los dos argumentos faltantes. No se considera -m (que seria el cuarto argumento) porque es un flag que puede ser especificado por el usuario o no
		printf("Se ingreso un numero incorrecto de argumentos\n");
		fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n",
				   argv[0]);
		   exit(EXIT_FAILURE);
	}

	//Se inicializan variables con el fin de no tener fallos por punteros en malas condiciones.	
	int H = -1, C = -1, U = -1, N = -1;
	flags = 0;

	//Se inicia un ciclo while hasta que se verifiquen todos los argumentos ingresados como entradas, 
	//los cuales se reciben con getopt()
	//int getopt (int argc, char *const *argv, const char *options): Siempre se le debe entregar argc y argv. 
	//El tercer argumento consiste en el formato de las entradas, ya sea
	//el caracter correspondiente a la opcion/entrada que se quiere recibir 
	//y además se debe indicar si dicha entrada estará acompañada de algún valor
	//Esto se indica con ":". Por lo tanto, "h:" quiere decir que se espera recibir la opcion -h 
	//y esta si o si debe estar acompañada de un valor
	//En cambio, la opcion "-b" no necesita estar acompañada de un valor
	while((opt = getopt(argc, argv, "bc:h:u:n:")) != -1) { 
	   //opt recibe el argumento leido (se hace de forma secuencial) y se ingresa a un switch
	   //En caso de que opt sea -1, se dejaran de buscar entradas y por lo tanto se podrá salir del while
	   switch(opt) {
	   
	   case 'b'://se busca la entrada -m, en caso de ser encontrado se setea el valor flags = 1, no se considera lo que se ingrese despues del flag -m
		   flags = 1;
		   break;
       
	   case 'c'://se busca la entrada -c	   		
	   		C = strtol(optarg, &auxC, 10);//se parsea el argumento ingresado junto al flag -h a entero
			if(optarg!=0 && C==0){//si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
				fprintf(stderr, "Uso correcto: %s [-c numero entero]\n", argv[0]); 
				exit(EXIT_FAILURE);
		    }	   		
		   break;		   

	   case 'h': //se busca la entrada -h
		   H = strtol(optarg, &auxH, 10);//se parsea el argumento ingresado junto al flag -h a entero
		   if(optarg!=0 && H==0){//si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
				fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]); 
				exit(EXIT_FAILURE);
		   }
		   break;

		case 'u': //se busca la entrada -u
		   U = strtol(optarg, &auxU, 10);//se parsea el argumento ingresado junto al flag -h a entero
		   if(optarg!=0 && U==0){//si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
				fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]); 
				exit(EXIT_FAILURE);
		   }
		   break;

		case 'n': //se busca la entrada -n
		   N = strtol(optarg, &auxN, 10);//se parsea el argumento ingresado junto al flag -h a entero
		   if(optarg!=0 && N==0){//si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
				fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]); 
				exit(EXIT_FAILURE);
		   }
		   break;
		

	   default: /* '?' */
		   fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n",
				   argv[0]);
		   exit(EXIT_FAILURE);
	   }
	}

	if(flags==1){//si se encontro un flag -m, se setea la variable global flag = 1, respecto al scope del proceso principal
		(*flag) = 1;
	}

	(*h) = H; //se iguala la variable n a N, para poder acceder al valor en el main
	(*c) = C; //se iguala la variable c a C, para poder acceder al valor en el main
	(*u) = U; //se iguala la variable u a U, para poder acceder al valor en el main
	(*n) = N; //se iguala la variable n a N, para poder acceder al valor en el main

	if(N<=0){
		printf("El valor que acompaña a -h debe ser mayor a 0\n");
		fprintf(stderr, "Uso correcto: %s [-h nchild] [-m]\n", argv[0]); //si el valor que acompaña a -h es negativo, se retorna un error
		exit(EXIT_FAILURE);
	}


}


