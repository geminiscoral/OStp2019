#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include "listaAviones.h"
#include "gestionCombustibleAterrizando.h"


/*******************************!
*@fn restarCombustible
** Esta funcion resta en dos unidades el combustible actual de un avion y lo actualiza.
*@param ST_TODASLASLISTAS *ListasAviones
********************************/

void restarCombustible(ST_LISTAAVIONES *subLista){
    int combustibleActual= subLista->avion.cantCombustible;
    combustibleActual=(combustibleActual-2);
    subLista->avion.cantCombustible=combustibleActual;
}
