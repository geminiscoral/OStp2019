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

void crearLista (ST_LISTAAVIONES**cabecera){
        *cabecera = NULL;
}

ST_LISTAAVIONES * crearNodo (ST_AVION * avion) {
        ST_LISTAAVIONES * nodo = (ST_LISTAAVIONES*)malloc(sizeof(ST_LISTAAVIONES));
        nodo->avion = *avion;
        nodo->ste = NULL;
        return nodo;
}

void crearCola(ST_COLA * cola){
    cola->cabecera = NULL;
    cola->fin = NULL;
}

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

ST_AVION eliminarDeCola (ST_COLA * cola){
    ST_LISTAAVIONES * aux = cola->cabecera;
    ST_AVION avion = cola->cabecera->avion;

    cola->cabecera = cola->cabecera->ste;
    free(aux);

    return avion;
}

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
        if (avion->id == IDReservaPista){

        }
}

void recibirMensaje (int * IDReservaPista, ST_LISTAAVIONES ** lista, ST_LISTAAVIONES ** colaAterrizar, ST_COLA * colaDespegar , ST_AVION * avion, int cliente, char * buffer){
            int bytesRecibidos = recv(cliente, buffer, tamanioBufferMensaje, 0);
            /*if (bytesRecibidos <= 0) {
                perror("El chabón se desconectó o bla.");
                }
                 return 1;*/
            printf("Mensaje: %s \n", buffer);
            strtok(buffer, ";");
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
                strcpy(avion->modelo,strtok(NULL, ";"));
                strcpy(&avion->estado,strtok(NULL, ";"));
                char cantMaxComb [longCantComb];
                strcpy(cantMaxComb,strtok(NULL, ";"));
                avion->capMax = atoi (cantMaxComb);
                char cantComb [longCantComb];
                strcpy(cantComb,strtok(NULL, ";"));
                avion->cantCombustible = atoi (cantComb);
                registrarAvion(avion);
                insertarOrdenado(lista,*avion);
                mostrarLista(lista);
                enviarMensaje(cliente, 0);
                break;
                case 2:
                system ("clear");
                ST_LISTAAVIONES * pAux = buscarIDEnLista(avion->id,lista);
                *avion = pAux->avion;
                solicitarPista(colaAterrizar, colaDespegar, avion);
                enviarMensaje(cliente, 0);
                printf("\n Se copia el aviòn en una cola de espera para aterrizar u otra para despegar \n");
                break;
                case 3:

                printf ("\n Se envìa la orden para despegar\n");
                break;
                case 4:

                break;
            }
    }
