#ifndef LISTAAVIONES_H_INCLUDED
#define LISTAAVIONES_H_INCLUDED

#include "aviones.h"

typedef struct listaAviones {
    ST_AVION avion;
    struct listaAviones * ste;
}ST_LISTAAVIONES;


void crearLista (ST_LISTAAVIONES**cabecera);

void insertarOrdenado (ST_LISTAAVIONES ** cabecera, ST_AVION avion);

void mostrarLista (ST_LISTAAVIONES**cabecera);

ST_LISTAAVIONES * buscarIDEnLista (int ID, ST_LISTAAVIONES ** cabecera);

void  eliminarDeLista (int ID, ST_LISTAAVIONES ** cabecera);

void recibirMensaje (ST_LISTAAVIONES ** lista, ST_AVION * avion, int cliente, char * buffer);

#endif // LISTAAVIONES_H_INCLUDED
