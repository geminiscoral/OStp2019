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
#include "gestionCombustible.h"

void gestionarCombustibleRegistrados(ST_TODASLASLISTAS *todasLasListas){
    while(1){
        while(todasLasListas->avionesRegistrados!=NULL){
            ST_LISTAAVIONES *aux=todasLasListas->avionesRegistrados;
            if(aux->avion.estado=='v'){
                restarCombustible(todasLasListas->avionesRegistrados);
            }
            aux=aux->ste;
            sleep(5);
        }
    }
    return;
}
