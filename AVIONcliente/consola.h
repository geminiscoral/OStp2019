#ifndef CONSOLA_H_INCLUDED
#define CONSOLA_H_INCLUDED
#include "avion.h"

#include <arpa/inet.h>
#include <sys/socket.h>


/**
                    DESCRIPCION
* TAD: consola
**Este TAD nos permite abrir un menú de opciones, muestra las característica del avión actual


                *CONJUNTOS DE DATOS:

*Estructuras
struct sockaddr_in direccionServidor, ST_AVION

*Variables
 cliente

*Punteros
* IP, *puerto, *avion, * pistaAsignada.

                        *OPERACIONES:

*Funcion: void abrirConsola
Parametros: struct sockaddr_in direccionServidor, int cliente, char * IP, char*puerto, ST_AVION *avion


*/

void abrirConsola(struct sockaddr_in direccionServidor, int cliente, char * IP, char*puerto, ST_AVION *avion);

#endif // CONSOLA_H_INCLUDED
