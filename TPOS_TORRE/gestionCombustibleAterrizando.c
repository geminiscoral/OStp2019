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

/********************************************!
*@fn  gestionarCombustibleAterrizando
*@param c1 ST_TODASLASLISTAS *todasLasListas
********************************************/
void gestionarCombustibleAterrizando(ST_TODASLASLISTAS *todasLasListas){
    while(1){
        while(todasLasListas->listaAterrizaje!=NULL){
            ST_LISTAAVIONES *aux=todasLasListas->listaAterrizaje;
            if(1){
                //funcion resta combustible;
                restarCombustible(todasLasListas);

            }
            aux=aux->ste;//Pregunttar
            sleep(5);
        }
    }
    return;
}
