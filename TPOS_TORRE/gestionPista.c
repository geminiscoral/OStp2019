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


void aunarListas (ST_TODASLASLISTAS * todasLasListas, int * cliente, int * IDReservaPista, ST_LISTAAVIONES * avionesRegistrados, ST_LISTAAVIONES * listaAterrizaje, ST_COLA * colaDespegue){
        todasLasListas->avionesRegistrados = avionesRegistrados;
        todasLasListas->listaAterrizaje = listaAterrizaje;
        todasLasListas->colaDespegue = colaDespegue;
        todasLasListas->cliente = *cliente;
        todasLasListas->reservapista = *IDReservaPista;
}

void despegueAvion (int ID){
        printf("Avion %i despegando ..↑↑↑..\n", ID);
        sleep(25);
        printf("Avion %i en vuelo ✈ \n", ID);
}

void aterrizajeAvion (int ID){
        printf("Avion %i aterrizando ..↑↑↑..\n", ID);
        sleep(25);
        printf("Avion %i en hangar ✈ \n", ID);
}


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
            todasLasListas->colaDespegue->cabecera = todasLasListas->colaDespegue->cabecera->ste;
            free(aux);
        }
    }
}
