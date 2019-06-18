#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "aviones.h"
#include "listaAviones.h"
#include "gestionCombustibleAterrizando.h"


/******************************************//**
*@fn  gestionarCombustibleAterrizando
**Esta fn recorre la lista de aviones que solicitaron uso
**de la pista para aterrizar(utiliza la lista de aterrizando)
**y llama a la fn restaCombustible, en intervalos de 5 segundos
*@param c1 ST_TODASLASLISTAS *todasLasListas
********************************************/

void gestionarCombustibleAterrizando(ST_TODASLASLISTAS *todasLasListas){
    while(1){
        while(todasLasListas->listaAterrizaje!=NULL){
            ST_LISTAAVIONES *aux=todasLasListas->listaAterrizaje;
            if(1){
                restarCombustible(todasLasListas->listaAterrizaje);
            }
            aux=aux->ste;
            sleep(5);
        }
    }
    return;
}
