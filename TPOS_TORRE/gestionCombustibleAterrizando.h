#ifndef GESTIONCOMBUSTIBLEATERRIZANDO_H_INCLUDED
#define GESTIONCOMBUSTIBLEATERRIZANDO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include "aviones.h"
#include "listaAviones.h"

/********************************************!
** TAD: gestionarCombustibleAterrizando
**En este TAD gestionaremos el uso de combustible de
**todos los aviones que se encuentra en la lista
**de aterrizaje.

**CONJUNTOS DE DATOS:
**----------Estructuras-----------:
ST_TODASLASLISTAS
**----------Punteros--------------:
*todasLasListas

**OPERACIONES:
<void gestionarCombustibleAterrizando> <(ST_TODASLASLISTAS *todasLasListas)>
<void restarCombustible> <(ST_TODASLASLISTAS *todasLasListas)>

*******************************************/

void gestionarCombustibleAterrizando(ST_TODASLASLISTAS *todasLasListas);

void restarCombustible(ST_TODASLASLISTAS *todasLasListas);

#endif // GESTIONCOMBUSTIBLEATERRIZANDO_H_INCLUDED
