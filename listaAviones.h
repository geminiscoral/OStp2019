#ifndef LISTAAVIONES_H_INCLUDED
#define LISTAAVIONES_H_INCLUDED

#include "aviones.h"

typedef struct listaAviones {
    ST_AVION avion;
    struct listaAviones * ste;
}ST_LISTAAVIONES;

typedef struct {
    ST_LISTAAVIONES *cabecera;
    ST_LISTAAVIONES *fin;
}ST_COLA;

void crearCola(ST_COLA * cola);

void agregarACola (ST_COLA * cola, ST_AVION * avion);

ST_AVION eliminarDeCola (ST_COLA * cola);

void crearLista (ST_LISTAAVIONES**cabecera);

void insertarOrdenado (ST_LISTAAVIONES ** cabecera, ST_AVION avion);

void mostrarLista (ST_LISTAAVIONES**cabecera);

ST_LISTAAVIONES * buscarIDEnLista (int ID, ST_LISTAAVIONES ** cabecera);

void  eliminarDeLista (int ID, ST_LISTAAVIONES ** cabecera);

void ordenarPorCombustible (ST_LISTAAVIONES ** cabecera, ST_AVION avion);

void solicitarPista (ST_LISTAAVIONES ** listaAterrizar, ST_COLA * colaDespegar, ST_AVION * avion);

void recibirMensaje (int * IDReservaPista, ST_LISTAAVIONES ** lista, ST_LISTAAVIONES ** colaAterrizar,ST_COLA * colaDespegar , ST_AVION * avion, int cliente, char * buffer);

#endif // LISTAAVIONES_H_INCLUDED
