#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "listaAviones.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#define longID 9
#define tamanioBufferMensaje 100
#define longCantComb 10


/**
*@fn crearLista
*Crea una lista apuntando la cabecera a NULL
*@param c1 ST_LISTAAVIONES**cabecera
*/
void crearLista (ST_LISTAAVIONES**cabecera){
        *cabecera = NULL;
}


/**
*@fn ST_LISTAAVIONES *crearNodo
**Crea un nodo.
*@param ST_AVION *avion
*@return nodo
*/
ST_LISTAAVIONES * crearNodo (ST_AVION * avion) {
        ST_LISTAAVIONES * nodo = (ST_LISTAAVIONES*)malloc(sizeof(ST_LISTAAVIONES));
        nodo->avion = *avion;
        nodo->ste = NULL;
        return nodo;
}


/**
*@fn crearCola
*Crea una cola apuntando tanto la cabecera como el fin a NULL
*@param ST_COLA *cola
*/
void crearCola(ST_COLA * cola){
    cola->cabecera = NULL;
    cola->fin = NULL;
}


/**
*@fn agregarACola
*Agregar a la cola
*@param ST_COLA *cola
*@param ST_AVION *avion
*/
void agregarACola (ST_COLA * cola, ST_AVION * avion){
    ST_LISTAAVIONES * nodo = crearNodo(avion);

    if(cola->cabecera==NULL){
        cola->cabecera = nodo;
    }
    else{
        cola->fin->ste = nodo;
    }
    cola->fin = nodo;
}


/**
*@fn ST_AVION eliminarDeCola
*Elimina un nodo (avion) de la cola devolviendo los datos que contenia
*@param ST_COLA *cola
*@return avion
*/
ST_AVION eliminarDeCola (ST_COLA * cola){
    ST_LISTAAVIONES * aux = cola->cabecera;
    ST_AVION avion = cola->cabecera->avion;

    cola->cabecera = cola->cabecera->ste;
    free(aux);

    return avion;
}


/**
*@fn insertarOrdenado
*inserta ordenado un nuevo nodo (avion) a la lista de aviones
*@param c1 ST_LISTAAVIONES**cabecera
*@param c2 ST_AVION avion
*/
void insertarOrdenado (ST_LISTAAVIONES ** cabecera, ST_AVION avion){
    //ST_LISTAAVIONES * busqueda = buscarIDEnLista(avion.id, cabecera);
    /*if (busqueda!=NULL){
        perror("Elemento existente");
        return;
    }*/

    ST_LISTAAVIONES * nodo = crearNodo(&avion);

    ST_LISTAAVIONES * aux = *cabecera;
    ST_LISTAAVIONES * nodoAnt = NULL;

    while ((aux!=NULL)&&(avion.id>aux->avion.id)){
            nodoAnt = aux;
            aux = aux->ste;
    }
    if(nodoAnt==NULL){
            *cabecera = nodo;
            nodo->ste = aux;
    }
    else {
            nodo->ste = aux;
            nodoAnt->ste = nodo;
    }
}


/**
*@fn mostrarLista
*Muestra las caracteristicas del avion por pantalla
*@param ST_LISTAAVIONES**cabecera
*/
void mostrarLista (ST_LISTAAVIONES**cabecera){
    ST_LISTAAVIONES * aux = *cabecera;
    if (aux!=NULL){
        printf("\nAVION:\n");
        printf("ID: %i\n",aux->avion.id);
        printf("Modelo: %s\n",aux->avion.modelo);
        printf("Estado: %c\n",aux->avion.estado);
        printf("Cantidad de combustible: %i\n",aux->avion.cantCombustible);
    }
    while((aux!=NULL)&&(aux->ste!=NULL)){
        printf("\nAVION:\n");
        printf("ID: %i\n",aux->ste->avion.id);
        printf("Modelo: %s\n",aux->ste->avion.modelo);
        printf("Estado: %c\n",aux->ste->avion.estado);
        printf("Cantidad de combustible: %i\n",aux->ste->avion.cantCombustible);
        aux = aux->ste;
    }
}


/**
*@fn ST_LISTAAVIONES * buscarIDEnLista
*Busca un avion de la lista de aviones
por numero de identificacion.
*@param c1 int ID
*@param c2 ST_LISTAAVIONES ** cabecera
*@return Null si el avion no fue encontrado
*@return aux con la estructura del avion encontrado
*/
ST_LISTAAVIONES * buscarIDEnLista (int ID, ST_LISTAAVIONES ** cabecera){
    ST_LISTAAVIONES * aux = *cabecera;
    ST_LISTAAVIONES * ant = NULL;

    while ((*cabecera!=NULL) && (aux->ste!=NULL) && (ID>aux->avion.id)){
        ant = aux;
        aux = aux->ste;
    }
    if ((ID!=aux->avion.id)||(*cabecera==NULL)){
        perror("\nElemento no encontrado\n");
        return NULL;
    }
    return aux;
}


/**
*@fn eliminarDeLista
*Elimina un avion de la lista de aviones
buscandolo por identificacion.
*@param c1 int ID
*@param c2 ST_LISTAAVIONES ** cabecera
*/
void  eliminarDeLista (int ID, ST_LISTAAVIONES ** cabecera){
    ST_LISTAAVIONES * aux = *cabecera;
    ST_LISTAAVIONES * ant = NULL;

    while ((*cabecera!=NULL) && (aux->ste!=NULL) && (ID>aux->avion.id)){
        ant = aux;
        aux = aux->ste;
    }
    if ((ID!=aux->avion.id)||(*cabecera==NULL)){
        perror("\nElemento no encontrado\n");
        return NULL;
    }

        ant->ste = aux->ste;
        free(aux);
}


/**
*@fn ordenarPorCombustible
*Ordena la lista de aviones por cantidad de combustible
*@param c1 ST_LISTAAVIONES ** cabecera
*@param c2 ST_AVION avion
*/
void ordenarPorCombustible (ST_LISTAAVIONES ** cabecera, ST_AVION avion){
    //ST_LISTAAVIONES * busqueda = buscarIDEnLista(avion.id, cabecera);
    /*if (busqueda!=NULL){
        perror("Elemento existente");
        return;
    }*/

    ST_LISTAAVIONES * nodo = crearNodo(&avion);

    ST_LISTAAVIONES * aux = *cabecera;
    ST_LISTAAVIONES * nodoAnt = NULL;

    while ((aux!=NULL)&&(avion.cantCombustible>aux->avion.cantCombustible)){
            nodoAnt = aux;
            aux = aux->ste;
    }
    if(nodoAnt==NULL){
            *cabecera = nodo;
            nodo->ste = aux;
    }
    else {
            nodo->ste = aux;
            nodoAnt->ste = nodo;
    }
}


/**
*@fn solicitarPista
*la funcion recibe los datos del avion que socilita utilizar la pista,
y lo coloca en la cola de despegar o en la lista de aterrizar segun el caso
*@param c1 ST_LISTAAVIONES ** listaAterrizar
*@param c2 ST_COLA * colaDespegar
*@param c3 ST_AVION * avion
*/
void solicitarPista (ST_LISTAAVIONES ** listaAterrizar, ST_COLA * colaDespegar, ST_AVION * avion){
        if (avion->estado == 'v'){
            ordenarPorCombustible(listaAterrizar, *avion);
            mostrarLista(listaAterrizar);
        }
        else if (avion->estado == 'g'){
            agregarACola(colaDespegar, avion);
            mostrarLista(&colaDespegar->cabecera);
        }
        else {
            printf("\n Estado del avion invalido para efectuar la operacion \n");
        }
}

void aterrizar (int * IDReservaPista, int * cliente, ST_AVION * avion){
        if (avion->id == *IDReservaPista){

        }
}


/**
*@fn recibirMensaje
**recibe los datos del cliente (avion) y sigue la opcion recibida
*@param c1 ST_TODASLASLISTAS * todasLasListas
*/
void recibirMensaje (ST_TODASLASLISTAS * todasLasListas){
        while (1){
            ST_AVION * avion = (ST_AVION*)malloc(sizeof(ST_AVION));
            char * bufferMensaje = (char*)malloc(tamanioBufferMensaje);
            int bytesRecibidos = recv(todasLasListas->cliente, bufferMensaje, tamanioBufferMensaje, 0);
            if (bytesRecibidos <= 0) {
                perror("El chabón se desconectó o bla.");
                }
            printf("Mensaje: %s \n", bufferMensaje);
            strtok(bufferMensaje, ";");
            strtok(NULL, ";");
            strtok(NULL, ";");
            char id [longID];
            strcpy(id,strtok(NULL,";"));
            avion->id = atoi(id);
            char opcion;
            strcpy(&opcion,strtok(NULL, ";"));
            int Opcion = atoi (&opcion);
            switch (Opcion){
                case 1:
                avion->cliente = todasLasListas->cliente;
                strcpy(avion->modelo,strtok(NULL, ";"));
                strcpy(&avion->estado,strtok(NULL, ";"));
                char cantMaxComb [longCantComb];
                strcpy(cantMaxComb,strtok(NULL, ";"));
                avion->capMax = atoi (cantMaxComb);
                char cantComb [longCantComb];
                strcpy(cantComb,strtok(NULL, ";"));
                avion->cantCombustible = atoi (cantComb);
                registrarAvion(avion);
                insertarOrdenado(&todasLasListas->avionesRegistrados,*avion);
                mostrarLista(&todasLasListas->avionesRegistrados);
                enviarMensaje(avion->cliente, 0);
                free(bufferMensaje);
                break;
                case 2:
                system ("clear");
                ST_LISTAAVIONES * pAux = buscarIDEnLista(avion->id,&todasLasListas->avionesRegistrados);
                *avion = pAux->avion;
                solicitarPista(&todasLasListas->listaAterrizaje, todasLasListas->colaDespegue, avion);
                enviarMensaje(avion->cliente, 0);
                printf("\n Se copia el aviòn en una cola de espera para aterrizar u otra para despegar \n");
                free(bufferMensaje);
                free(avion);
                /*case 3:

                printf ("\n Se envìa la orden para despegar\n");
                break;
                case 4:

                break;*/
            }
        }
    }
