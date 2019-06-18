#ifndef GESTIONPISTA_H_INCLUDED
#define GESTIONPISTA_H_INCLUDED

#include "listaAviones.h"

/********************************************!
** TAD: gestionPista
**En este TAD gestionaremos las colas de los aviones, y ademas
**la solicitud de pista que envien los aviones

**CONJUNTOS DE DATOS:
**----------EStructuras-----------:
ST_TODASLASLISTAS, ST_LISTAAVIONES,ST_COLA
**----------Variables-------------:
cliente, ID,
**----------Punteros--------------:
*todasLasListas, ,* cliente,* IDReservaPista,
* avionesRegistrados, * listaAterrizaje, * colaDespegue

**OPERACIONES:
*<gestionarPista> <(ST_TODASLASLISTAS * todasLasListas)>
*<void aunarListas> <(ST_TODASLASLISTAS * todasLasListas, int * cliente, int * IDReservaPista, ST_LISTAAVIONES * avionesRegistrados, ST_LISTAAVIONES * listaAterrizaje, ST_COLA * colaDespegue)>
*******************************************/



void gestionarPista (ST_TODASLASLISTAS * todasLasListas);

void aunarListas (ST_TODASLASLISTAS * todasLasListas, int * cliente, int * IDReservaPista, ST_LISTAAVIONES * avionesRegistrados, ST_LISTAAVIONES * listaAterrizaje, ST_COLA * colaDespegue);

//se realizo prueva de compilacion y no genera errores, pero las marcamos en comentario para verificar su uso.
/*void recibirMensajeAterrizajeYDespegue (int cliente);*/

/*void despegueAvion (int ID);*/

/*void aterrizajeAvion (int ID)*/

#endif // GESTIONPISTA_H_INCLUDED
