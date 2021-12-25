
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//Funcion encargada de leer archivo txt
void leerArchivo(const char *fileName, float *out, int len, int *numeroPaginas){
        
    //Abrir el archivo en modo lectura, no binario.
    FILE *fid = fopen(fileName, "r");
    int numbers[100];
    int i = 0;
    if (fid == NULL)
    {
        printf("Error en funcion leerArchivo() no pudo leer archivo %s \n", fileName);
        exit(0);
    }
    else
    {

        while (fscanf(fid, "%d", &numbers[i]) != EOF){
            i++;
            if (i == 99) { 
                break;
            } /* Validacion de numero de paginas como limite. */
        }
        fclose(fid);
    }    
    (*numeroPaginas)=i;        
    //Se lee el archivo, y se asigna a la variable out.
    //Automaticamente queda en nuestro arreglo la informacion correspondiente.
    fread(out, sizeof(float), len, fid);
    //Se cierra el archivo
    fclose(fid);

}

float *obtenerDatos(float* visible, int largo){

    //Se crea un puntero float y se asigna memoria de forma dinamica.   
    float *realVector = (float*) malloc(largo * sizeof(float));
    
    //Se recorre solo las posiciones pares de *visible.
    for(int i=0, j=0 ; i<2*largo ;j++, i+=2 ){
        //Se asigna a arreglo dinamico solo los indices
        //pares, por ende sus valores.
        realVector[j]=visible[i];
    }

    return realVector;
}

void escribirArchivo(const char *fileName, float *out, int len)
{
    FILE *fid = fopen(fileName, "w");
    if (fid == NULL)
        return;
    fwrite(out, sizeof(float), len, fid);
    fclose(fid);
}


void LRUAlgoritmo(int marcos, int cantidaPaginas){

    printf("LRU %d, %d\n",marcos, cantidaPaginas);
    int frames[10], temp[10], pages[10];    
    int total_pages, m, n, position, k, l, total_marcos;
    int a = 0, b = 0, page_fault = 0;
    total_marcos  = marcos;
     

    for (m = 0; m < total_marcos; m++)
    {
        frames[m] = -1;
    }
    printf("Ingrese numero total de paginas:\t");
    scanf("%d", &total_pages);
    printf("Ingrese los valores referenciados:\n");
    for (m = 0; m < total_pages; m++)
    {
        printf("Value No.[%d]:\t", m + 1);
        scanf("%d", &pages[m]);
    }
    for (n = 0; n < total_pages; n++)
    {

        a = 0, b = 0;
        for (m = 0; m < total_marcos; m++)
        {
            if (frames[m] == pages[n])
            {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (m = 0; m < total_marcos; m++)
            {
                if (frames[m] == -1)
                {
                    frames[m] = pages[n];
                    b = 1;
                    break;
                }
            }
        }
        if (b == 0)
        {
            for (m = 0; m < total_marcos; m++)
            {
                temp[m] = 0;
            }
            for (k = n - 1, l = 1; l <= total_marcos - 1; l++, k--)
            {
                for (m = 0; m < total_marcos; m++)
                {
                    if (frames[m] == pages[k])
                    {
                        temp[m] = 1;
                    }
                }
            }
            for (m = 0; m < total_marcos; m++)
            {
                if (temp[m] == 0)
                    position = m;
            }
            frames[position] = pages[n];
            page_fault++;
        }
        printf("\n");
        for (m = 0; m < total_marcos; m++)
        {
            printf("%d\t", frames[m]);
        }
    }
    printf("\nNumero total de fallos:\t%d\n", page_fault);
    //return 0;
}

void FIFOAlgoritmo(int marcos)
{
    printf("%d", marcos);
    int reference_string[25], frames[25], interval[25];
    int pages, total_frames, page_faults = 0;
    int m, n, temp, flag, found;
    int position, maximum_interval, previous_frame = -1;
    printf("\nEnter Total Number of Pages:\t");
    scanf("%d", &pages);
    printf("\nEnter Values of Reference String\n");
    for (m = 0; m < pages; m++)
    {
        printf("Value No.[%d]:\t", m + 1);
        scanf("%d", &reference_string[m]);
    }
    printf("\nEnter Total Number of Frames:\t");
    scanf("%d", &total_frames);
    for (m = 0; m < total_frames; m++)
    {
        frames[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        flag = 0;
        for (n = 0; n < total_frames; n++)
        {
            if (frames[n] == reference_string[m])
            {
                flag = 1;
                printf("\t");
                break;
            }
        }
        if (flag == 0)
        {
            if (previous_frame == total_frames - 1)
            {
                for (n = 0; n < total_frames; n++)
                {
                    for (temp = m + 1; temp < pages; temp++)
                    {
                        interval[n] = 0;
                        if (frames[n] == reference_string[temp])
                        {
                            interval[n] = temp - m;
                            break;
                        }
                    }
                }
                found = 0;
                for (n = 0; n < total_frames; n++)
                {
                    if (interval[n] == 0)
                    {
                        position = n;
                        found = 1;
                        break;
                    }
                }
            }
            else
            {
                position = ++previous_frame;
                found = 1;
            }
            if (found == 0)
            {
                maximum_interval = interval[0];
                position = 0;
                for (n = 1; n < total_frames; n++)
                {
                    if (maximum_interval < interval[n])
                    {
                        maximum_interval = interval[n];
                        position = n;
                    }
                }
            }
            frames[position] = reference_string[m];
            printf("FAULT\t");
            page_faults++;
        }
        for (n = 0; n < total_frames; n++)
        {
            if (frames[n] != -1)
            {
                printf("%d\t", frames[n]);
            }
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_faults);
}

void OPTAlgoritmo(int marcos)
{

    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");

    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
}

void CLOCKAlgoritmo(int marcos)
{
}

void readFile(const char *nombreArchivo, int *numeroPaginas, int *arrValores)
{

    int numbers[100];
    int i = 0;

    FILE *file = fopen(nombreArchivo, "r");
    if (file == NULL)
    {
        printf("Error en funcion leerArchivo() no pudo leer archivo %s \n", nombreArchivo);
        exit(0);
    }
    else
    {

        while (fscanf(file, "%d", &numbers[i]) != EOF)
        {
            i++;
        }
        fclose(file);
    }

    (*numeroPaginas) = i; //Se asigna i al numero de paginas para que pueda ser leido desde main.
}

void recibirArgumentos(int argc, char *argv[], int *c, const char **i, const char **o, int *flag)
{

    int flags, opt;
    char *auxC = NULL;
    //char *auxI = NULL;
    //char *auxO = NULL;

    /*
		Se crea espacio de memoria para cada variable recibida por consola.
		Tambien es casteada a tipo de dato entero.
	*/
    auxC = malloc(10 * sizeof(char));
    //auxI = malloc(10 * sizeof(char));
    //auxO = malloc(10 * sizeof(char));

    if (argc < 3)
    { //si se ingresa un numero de argumentos menor a 3, se finaliza la ejecucion del programa
        //Debe ser 3, porque el nombre del programa se considera como un argumento, siendo -h y el valor que acompañe a -h los dos argumentos faltantes. No se considera -m (que seria el cuarto argumento) porque es un flag que puede ser especificado por el usuario o no
        printf("Se ingreso un numero incorrecto de argumentos\n");
        fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    //Se inicializan variables con el fin de no tener fallos por punteros en malas condiciones.
    int C = -1;
    const char *I = NULL;
    const char *O = NULL;
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
    while ((opt = getopt(argc, argv, "bo:i:c:")) != -1)
    {
        //opt recibe el argumento leido (se hace de forma secuencial) y se ingresa a un switch
        //En caso de que opt sea -1, se dejaran de buscar entradas y por lo tanto se podrá salir del while
        switch (opt)
        {
        case 'b': //se busca la entrada -m, en caso de ser encontrado se setea el valor flags = 1, no se considera lo que se ingrese despues del flag -m
            flags = 1;
            break;
        case 'c':                          //se busca la entrada -c
            C = strtol(optarg, &auxC, 10); //se parsea el argumento ingresado junto al flag -h a entero
            if (optarg != 0 && C == 0)
            { //si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
                fprintf(stderr, "Uso correcto: %s [-c numero entero]\n", argv[0]);
                exit(EXIT_FAILURE);
            }
            break;

        case 'i': //se busca la entrada -h
                  //I = strtol(optarg, &auxI, 10);//se parsea el argumento ingresado junto al flag -h a entero
            printf("Input file i: \"%s\"\n", optarg);
            I = optarg;
            if (optarg != 0 && I == 0)
            { //si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
                fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]);
                exit(EXIT_FAILURE);
            }
            break;

        case 'o': //se busca la entrada -u
                  //O = strtol(optarg, &auxO, 10);//se parsea el argumento ingresado junto al flag -h a entero
            printf("Input file o: \"%s\"\n", optarg);
            O = optarg;
            if (optarg != 0 && O == 0)
            { //si no se ingresa un argumento junto a -h o si no se logra parsear el argumento ingresado, se considera como invalido
                fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]);
                exit(EXIT_FAILURE);
            }
            break;

        default: /* '?' */
            fprintf(stderr, "Uso correcto: %s [-h numero entero] [-m]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (flags == 1)
    { //si se encontro un flag -m, se setea la variable global flag = 1, respecto al scope del proceso principal
        (*flag) = 1;
    }

    (*c) = C; //se iguala la variable c a C, para poder acceder al valor en el main
    (*i) = I; //se iguala la variable n a N, para poder acceder al valor en el main
    (*o) = O; //se iguala la variable n a N, para poder acceder al valor en el main

    if (C <= 0)
    {
        printf("El valor que acompaña a -c debe ser mayor a 0\n");
        fprintf(stderr, "Uso correcto: %s [-h nchild]\n", argv[0]); //si el valor que acompaña a -c es negativo, se retorna un error
        exit(EXIT_FAILURE);
    }
    if (I == NULL)
    {
        printf("El valor que acompaña a -i no debe ser null o vacio\n");
        fprintf(stderr, "Uso correcto: %s [-i nchild]\n", argv[1]); //si el valor que acompaña a -i es vacio o null, se retorna un error
        exit(EXIT_FAILURE);
    }
    if (O == NULL)
    {
        printf("El valor que acompaña a -o no debe ser null o vacio\n");
        fprintf(stderr, "Uso correcto: %s [-o nchild]\n", argv[2]); //si el valor que acompaña a -o es vacio o null, se retorna un error
        exit(EXIT_FAILURE);
    }
}