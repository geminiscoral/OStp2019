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

void gestionarCombustibleAterrizando(ST_TODASLASLISTAS *todasLasListas){
    while(1){
        while(todasLasListas->listaAterrizaje!=NULL){
            ST_LISTAAVIONES *aux=todasLasListas->listaAterrizaje;
            if(1){
                restarCombustible(todasLasListas->listaAterrizaje);
            }
            aux=aux->ste;//Pregunttar
            sleep(5);
        }
    }
    return;
}
