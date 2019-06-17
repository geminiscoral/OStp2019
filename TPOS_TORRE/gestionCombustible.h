#ifndef GESTIONCOMBUSTIBLE_H_INCLUDED
#define GESTIONCOMBUSTIBLE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include "aviones.h"
#include "listaAviones.h"

<<<<<<< HEAD
/********************************************!
** TAD: gestionarCombustibleRegistrados
**Gestion Combustible, es este TAD gestinaremos
**el uso del combustible, utilizando una funcion secundaria
**para restar el combustible a los aviones. Ademas utilizaremos la
**funcion sleep para dormir el proceso.

**CONJUNTOS DE DATOS:
**----------Estructuras-----------:
ST_TODASLASLISTAS
**----------Punteros--------------:
*todasLasListas

**OPERACIONES:
<void gestionarCombustibleRegistrados> <(ST_TODASLASLISTAS *todasLasListas)>
<void restarCombustible> <(ST_TODASLASLISTAS *todasLasListas)>

*******************************************/


void gestionarCombustibleRegistrados(ST_TODASLASLISTAS *todasLasListas);

void restarCombustible(ST_TODASLASLISTAS *todasLasListas);
=======
void gestionarCombustibleRegistrados(ST_TODASLASLISTAS *todasLasListas);
void restarCombustible(ST_LISTAAVIONES *subLista);
>>>>>>> my_branch_psang

#endif // GESTIONCOMBUSTIBLE_H_INCLUDED
