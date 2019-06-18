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

/******************************************//**
*@fn  gestionarCombustibleRegistrados
**Esta fn recorre la lista de aviones registrados, si hay un avion con su estado
**en 'v'(en vuelo) llama a la fn restarCombustible, en intervalos de 5 segundos.
*@param c1 ST_TODASLASLISTAS *todasLasListas
********************************************/
void gestionarCombustibleRegistrados(ST_TODASLASLISTAS *todasLasListas){
    while(1){
        while(todasLasListas->avionesRegistrados!=NULL){
            ST_LISTAAVIONES *aux=todasLasListas->avionesRegistrados;
            if(aux->avion.estado=='v'){
                //funcion resta combustible;

                restarCombustible(todasLasListas->avionesRegistrados);
            }
            aux=aux->ste;
            sleep(5);
        }
    }
    return;
}
