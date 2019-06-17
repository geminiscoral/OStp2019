#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include "gestionPista.h"
#define longBufferAyD 2
#define longID 9
#define tamanioBufferMensaje 100


/********************************************!
*@fn  recibirMensajeAterrizajeYDespegue
**
*@param int cliente
********************************************/
void recibirMensajeAterrizajeYDespegue (int cliente){
            ST_AVION * avion = (ST_AVION*)malloc(sizeof(ST_AVION));
            char * bufferMensaje = (char*)malloc(tamanioBufferMensaje);
            int bytesRecibidos = recv(cliente, bufferMensaje, tamanioBufferMensaje, 0);
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
                case 3:
                free(avion);
                printf ("\n Se recibiò la orden para despegar\n");
                break;
                case 4:
                free(avion);
                printf ("\n Se recibiò la orden para aterrizar\n");
                break;
            }
        }


/********************************************!
*@fn  aunarListas
*@param c1 {ST_TODASLASLISTAS} * todasLasListas
*@param c2 {int} * cliente
*@param c3 {int} * IDReservaPista
*@param c4 {ST_LISTAAVIONES} * avionesRegistrados
*@param c5 {ST_LISTAAVIONES} * listaAterrizaje
*@param c6 {ST_COLA} * colaDespegue
********************************************/
void aunarListas (ST_TODASLASLISTAS * todasLasListas, int * cliente, int * IDReservaPista, ST_LISTAAVIONES * avionesRegistrados, ST_LISTAAVIONES * listaAterrizaje, ST_COLA * colaDespegue){
        todasLasListas->avionesRegistrados = avionesRegistrados;
        todasLasListas->listaAterrizaje = listaAterrizaje;
        todasLasListas->colaDespegue = colaDespegue;
        todasLasListas->cliente = *cliente;
        todasLasListas->reservapista = *IDReservaPista;
}


/********************************************!
*@fn  despegueAvion
**utilizando la fn sleep, dormiremos el proceso 25 segundos, simulando
**el despegue del avion, una vez finalizado, mandaremos un mensaje al usuario
** indicandole que el avion quedo en vuelo.
*@param c1 int ID
********************************************/
void despegueAvion (int ID){
        printf("Avion %i despegando ..↑↑↑..\n", ID);
        sleep(25);
        printf("Avion %i en vuelo ✈ \n", ID);
}


/********************************************!
*@fn  aterrizajeAvion
**utilizando la funcion sleep, dormiremos el proceso 25 segundos, simulando
**el proceso de aterrizaje del avion, una vez finalizado, mandaremos un mensaje al usuario
** indicandole que el avion aterrizo.
*@param c1 int ID
********************************************/
void aterrizajeAvion (int ID){
        printf("Avion %i aterrizando ..↑↑↑..\n", ID);
        sleep(25);
        printf("Avion %i en hangar ✈ \n", ID);
}


/********************************************!
*@fn gestionarPista
**Los aviones pueden solicitar pista para aterrizar.
**Ademas gestinara el avance de la cola de espera de los aviones que esteen por despegar.
*@param c1 ST_TODASLASLISTAS * todasLasListas
********************************************/
void gestionarPista (ST_TODASLASLISTAS * todasLasListas){
    while (1){
        while (todasLasListas->listaAterrizaje!=NULL){
            ST_LISTAAVIONES * aux = todasLasListas->listaAterrizaje;
            enviarMensaje(aux->avion.cliente, 1);

            //todasLasListas->reservapista = aux->avion.id;
            while (todasLasListas->reservapista != aux->avion.id){
                sleep (1);
            }
            aterrizajeAvion(aux->avion.id);
            enviarMensaje(aux->avion.cliente, 4);
            ST_LISTAAVIONES * avion = buscarIDEnLista(aux->avion.id, &todasLasListas->avionesRegistrados);
            avion->avion.estado = 'g';
            todasLasListas->reservapista = 0;

            recibirMensajeAterrizajeYDespegue(aux->avion.cliente);
            aterrizajeAvion(aux->avion.id);
            enviarMensaje(aux->avion.cliente, 4);

            todasLasListas->listaAterrizaje = todasLasListas->listaAterrizaje->ste;
            free(aux);
        }
        if (todasLasListas->colaDespegue->cabecera!=NULL){
            ST_LISTAAVIONES *aux = todasLasListas->colaDespegue->cabecera;
            enviarMensaje(aux->avion.cliente, 1);

            //todasLasListas->reservapista = aux->avion.id;
            while (todasLasListas->reservapista != aux->avion.id){
                sleep (1);
            }
            despegueAvion(aux->avion.id);
            enviarMensaje(aux->avion.cliente, 3);
            ST_LISTAAVIONES * avion = buscarIDEnLista(aux->avion.id, &todasLasListas->avionesRegistrados);
            avion->avion.estado = 'v';
            todasLasListas->reservapista = 0;

            recibirMensajeAterrizajeYDespegue(aux->avion.cliente);
            despegueAvion(aux->avion.id);
            enviarMensaje(aux->avion.cliente, 3);

            todasLasListas->colaDespegue->cabecera = todasLasListas->colaDespegue->cabecera->ste;
            free(aux);
        }
    }
}

