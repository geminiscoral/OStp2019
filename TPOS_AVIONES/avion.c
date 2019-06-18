#include "avion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define longComb 10
#define tamanioMaxLinea 50
#define tamanioBufferMensaje 100
#define longMensajeRecibido 2

/*****************************************//**
*@fn  strtoi
convierte una cifra entera en un char
*@param int N
*@return una variable char
********************************************/
   char strtoi (int N){
        char salida;
        salida = N + 48;
        return salida;
    }

/******************************************//**
*@fn  * enteroACadena
convierte un número en una cadena
*@param int valor
*@param char *cadena
*@return cadena
********************************************/
     char * enteroACadena (int valor, char * cadena){
        int cont = 0;
        char cad [10];
        int aux = valor;
        char numero;
        while ((aux/10)!=0){
            cont ++;
            aux = aux/10;
        }
        cad[cont+1] = '\0';
        while ((valor/10)!=0){
            numero = (valor%10) + 48;
            cad[cont] = numero;
            valor = valor/10;
            cont--;
        }
        numero = (valor%10) + 48;
        cad[cont] = numero;
        strcpy(cadena,cad);
        return cadena;
    }


/******************************************//**
*@fn  * armarMensaje
**EN esta función concatenamos (armaremos) una sola cadena con todos los datos.
*@param c1 int cliente
*@param c2 char *IP
*@param c3 char * puerto
*@param c4 ST_AVION * avion
*@param c5 int charOpcion
*@return bufferMensaje
********************************************/
    char* armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion){
        char * bufferMensaje = (char*)malloc(tamanioBufferMensaje);
        memset(bufferMensaje, '\0', tamanioBufferMensaje);
        char charCliente = strtoi(cliente);
        strncat(bufferMensaje, &charCliente, 1);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, IP);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, puerto);
        strcat(bufferMensaje, ";");
        strcat(bufferMensaje, avion->id);
        strcat(bufferMensaje, ";");
        char opcion;
        opcion = strtoi(charOpcion);
        strncat(bufferMensaje, &opcion, 1);
        strcat(bufferMensaje, ";");
        if (charOpcion == 1){
            strcat(bufferMensaje, avion ->modelo);
            strcat(bufferMensaje, ";");
            strncat(bufferMensaje, &avion ->estado, 1);
            strcat(bufferMensaje, ";");
            char * cantMaxComb = (char*)malloc (longComb);
            strcpy(cantMaxComb, enteroACadena(avion->capMax, cantMaxComb));
            strcat(bufferMensaje, cantMaxComb);
            strcat(bufferMensaje, ";");
            char * cantComb = (char*)malloc (longComb);
            strcpy(cantComb, enteroACadena(avion->cantCombustible, cantComb));
            strcat(bufferMensaje, cantComb);
            strcat(bufferMensaje, ";");
            free(cantMaxComb);
            free(cantComb);
        }
        printf("Mensaje: %s", bufferMensaje);
        return bufferMensaje;

    }

/******************************************//**
*@fn  parsearLinea
**parsear la línea
*@param c1 FILE* pArchivo
*@param c2 char * variable
********************************************/
void parsearLinea (FILE* pArchivo, char * variable){
        char lineaArchivo [tamanioMaxLinea];
        fgets(lineaArchivo, sizeof(lineaArchivo), pArchivo);
        strtok (lineaArchivo, ":");
        strcpy(variable, strtok (NULL, ";"));
    }


/******************************************//**
*@fn  parsearTextoParametro
**parsea el texto
*@param c1 const char * argv1
*@param c2 char * IP
*@param c3 char* strPuerto
*@param c4 int * puerto
*@param c5 char * ID
*@param c6 char * modelo
*@param c7 int * cantMaxComb
********************************************/
void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb ){
    FILE * pArchivo = fopen(argv1, "r+");
    parsearLinea(pArchivo, IP);
    parsearLinea(pArchivo, strPuerto);
    (*puerto)=atoi(strPuerto);
    parsearLinea(pArchivo, ID);
    parsearLinea(pArchivo, modelo);
    char cantMaxCombust [8];
    parsearLinea(pArchivo, cantMaxCombust);
    *cantMaxComb = atoi(cantMaxCombust);
    fclose (pArchivo);
}


/******************************************//**
*@fn  ingresarEstado
**función que toma el valor por teclado, y modifica el estado del avión.
*@param c1 ST_AVION* avion
********************************************/
    void ingresarEstado (ST_AVION * avion){
        scanf("%c", &avion->estado);
        if ((avion->estado!='h')&&(avion->estado!='v')){
            printf("El estado ingresado no es vàlido");
            ingresarEstado(avion);
        }
    }

/******************************************//**
*@fn  crearAvion
**función que crea un avion
*@param c1 ST_AVION * avion
********************************************/
    void crearAvion (ST_AVION * avion){
        printf("\n Ingrese el estado actual en el que se encuentra el avion ('h' para 'En Hangar' y 'v' para 'En Vuelo') \n");
        ingresarEstado(avion);
        printf("Ingrese la cantidad de combustible del avion \n");
        scanf("%i", &avion->cantCombustible);
    }


/******************************************//**
*@fn  recibirMensaje
**función que recibe la opción por consola y determina la acción siguiente.
*@param c1 int cliente
*@param c2 int opcion
*@param c3 ST_AVION * avion
*@param c4 int * pistaAsignada
********************************************/
    int recibirMensaje (int cliente, int opcion, ST_AVION * avion, int * pistaAsignada){
                char * bufferRecibido = (char*)malloc(longMensajeRecibido);
                int bytesRecibidos = recv(cliente, bufferRecibido, sizeof(bufferRecibido), 0);
                if (bytesRecibidos <= 0) {
                    perror("El chabón se desconectó o bla.");
                    return 1;
                    }
                int aux;
                aux = atoi(bufferRecibido);
                switch (opcion){
                    case 1:
                    if (aux==0){
                        printf ("\n El avion se registrò correctamente\n");
                            if (avion->estado=='h'){
                                avion->estado = 'g';
                            }
                        }
                    break;
                    case 2:
                    if (aux==0){
                        printf ("\n Se realizò correctamente la solicitud de pista\n");
                    }
                    if (aux==1){
                        printf("\n Se asignò la pista a este avion. Por favor indique al piloto la acciòn a realizar.\n");
                        *pistaAsignada = 1;
                    }
                    break;
                    case 3:
                    if (aux==0){
                        printf ("\n La operacion se relizo exitosamente\n");
                    }
                    if (aux==3){
                        printf ("\n El avion despegò satisfactoriamente\n");
                        avion->estado = 'v';
                        *pistaAsignada = 0;
                    }
                    if (aux==4){
                        printf ("\n El avion aterrizo satisfactoriamente\n");
                        avion->estado = 'g';
                        *pistaAsignada = 0;
                    }
                    break;
                }
                free(bufferRecibido);
        }


/*****************************************//**
*@fn  mostrarEstadoAvion
**muestra las caracteristicas del avion actual
**muestra, id, estado y cantidad de combustible
*@param c1 ST_AVION *avion
********************************************/
void mostrarEstadoAvion (ST_AVION *avion){
    printf("\n Estados: 'h' = 'En Hangar'; 'a' = 'Aterrizando'; 'e' = 'Espera/Aterrizar'; 'v' = 'En Vuelo'; 'd' = 'Despegando'; 'g' = 'Listo/Hangar'; 'l' = 'Listo/Despegar' \n");
    printf("\nEl ID del avion es %s\n", avion->id);
    printf("\nEl estado del avion es %c\n", avion->estado);
    printf("\nLa cantidad de combustible del avion es %i\n", avion->cantCombustible);

}

