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
**Esta fn busca todos los aviones que se encuentren en estado
**aterrizando (utiliza la lista de aterrizando) para utilizar la
** la fn restaCombustible. Ademas duerme el proceso 5 seg
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
