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



//1
/********************************************!
*@fn crearLista
**Pone la cabecera de una lista en NULL
*@param c1 ST_LISTAAVIONES**cabecera
*******************************************/

void crearLista (ST_LISTAAVIONES**cabecera){
        *cabecera = NULL;
}


//2
/********************************************!
*@fn ST_LISTAAVIONES *crearNodo
**crea nodo
*@param ST_AVION *avion
*@return nodo
********************************************/
ST_LISTAAVIONES * crearNodo (ST_AVION * avion) {
        ST_LISTAAVIONES * nodo = (ST_LISTAAVIONES*)malloc(sizeof(ST_LISTAAVIONES));
        nodo->avion = *avion;
        nodo->ste = NULL;
        return nodo;
}


//3
/********************************************!
*@fn crearCola
** crea cola
*@param ST_COLA *cola
********************************************/
void crearCola(ST_COLA * cola){
    cola->cabecera = NULL;
    cola->fin = NULL;
}


//4
/********************************************!
*@fn agregarACola
**agrega a la cola
*@param ST_COLA *cola
*@param ST_AVION *avion
********************************************/
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

//5
/********************************************!
*@fn ST_AVION eliminarDeCola
*@param ST_COLA *cola
*@return avion
********************************************/
ST_AVION eliminarDeCola (ST_COLA * cola){
    ST_LISTAAVIONES * aux = cola->cabecera;
    ST_AVION avion = cola->cabecera->avion;

    cola->cabecera = cola->cabecera->ste;
    free(aux);

    return avion;
}

//6
/********************************************!
*@fn insertarOrdenado
**inserta ordenado un nuevo avion a la lista de aviones
*@param c1 ST_LISTAAVIONES**cabecera
*@param c2 ST_AVION avion
********************************************/
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

//7
/********************************************!
*@fn mostrarLista
**Muestra las caracteristicas del avion por pantalla
*@param ST_LISTAAVIONES**cabecera
********************************************/
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

//8
/********************************************!
*@fn ST_LISTAAVIONES * buscarIDEnLista
**Busca un avion de la lista de aviones
**por numero de identificacion.
*@param c1 int ID
*@param c2 ST_LISTAAVIONES ** cabecera
*@return Null si el avion no fue encontrado
*@return axu la estructura del avion encontrado
********************************************/
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


//9
/********************************************!
*@fn eliminarDeLista
**Elimina un avion de la lista de aviones
**Buscandolo por identificacion.
*@param c1 int ID
*@param c2 ST_LISTAAVIONES ** cabecera
********************************************/
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

//10
/********************************************!
*@fn ordenarPorCombustible
**Ordena la lista de aviones por cantidad de combustible
*@param c1 ST_LISTAAVIONES ** cabecera
*@param c2 ST_AVION avion
********************************************/
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

//11
/********************************************!
*@fn solicitarPista
**los aviones en estado 'en vuelo' seran ordenados por combustible,
**y los que esteen en listos esperando en hangar seran agregados a la cola de despegar
*@param c1 ST_LISTAAVIONES ** listaAterrizar
*@param c2 ST_COLA * colaDespegar
*@param c3 ST_AVION * avion
********************************************/
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

//12
/********************************************!
*@fn aterrizar
**
*@param c1 int * IDReservaPista
*@param c2 int * cliente
*@param c3 ST_AVION * avion
********************************************/
void aterrizar (int * IDReservaPista, int * cliente, ST_AVION * avion){
        if (avion->id == *IDReservaPista){

        }
}

//13
/********************************************!
*@fn recibirMensaje
*@param c1 ST_TODASLASLISTAS * todasLasListas
********************************************/
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
                break;
                case 3:
                todasLasListas->reservapista = avion->id;
                printf ("\n Se recibiò la orden para despegar\n");
                printf ("\n La pista està siendo utilizada por el avion ID: %i\n", avion->id);
                free(bufferMensaje);
                free(avion);
                break;
                case 4:
                todasLasListas->reservapista = avion->id;
                printf ("\n Se recibiò la orden para aterrizar\n");
                printf ("\n La pista està siendo utilizada por el avion ID: %i\n", avion->id);
                free(bufferMensaje);
                free(avion);
                break;
                /*case 3:

                printf ("\n Se envìa la orden para despegar\n");
                break;
                case 4:

                break;*/
            }
        }
    }
