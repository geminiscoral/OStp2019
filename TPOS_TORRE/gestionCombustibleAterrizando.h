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
//cambiosque hay que borrarrrrrrrrrrrrr

void gestionarCombustibleAterrizando(ST_TODASLASLISTAS *todasLasListas);

void restarCombustible(ST_TODASLASLISTAS *todasLasListas);

#endif // GESTIONCOMBUSTIBLEATERRIZANDO_H_INCLUDED
