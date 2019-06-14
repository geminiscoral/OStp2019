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
** esta funcion resta en dos unidades el conbusible actual de un avion y lo actualiza.
*@param ST_TODASLASLISTAS *ListasAviones
********************************/
void restarCombustible(ST_TODASLASLISTAS *ListasAviones){
    int combustibleActual= ListasAviones->listaAterrizaje->avion.cantCombustible;
    combustibleActual=(combustibleActual-2);
    ListasAviones->listaAterrizaje->avion.cantCombustible=combustibleActual;
    return;
}
