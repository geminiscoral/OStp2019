#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include "listaAviones.h"
#include "gestionCombustibleAterrizando.h"

void restarCombustible(ST_LISTAAVIONES *subLista){
    int combustibleActual= subLista->avion.cantCombustible;
    combustibleActual=(combustibleActual-2);
    subLista->avion.cantCombustible=combustibleActual;
    return;
}
