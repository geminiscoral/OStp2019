#ifndef LISTAAVIONES_H_INCLUDED
#define LISTAAVIONES_H_INCLUDED

#include "aviones.h"

/**

                DESCRIPCION

*TAD: listaAviones
**En este TAD gestionaremos las listas de los aviones


            *CONJUNTOS DE DATOS:

*Estructuras
*ST_LISTAAVIONES, ST_AVION, ST_COLA
*Variables
*ID, avion
*Punteros
*cliente, cabecera, avion, cola, listaAterrizar, colaDespegar, IDReservaPista, todasLasListas.


                    *OPERACIONES

*Funcion: void crearLista
*Parametros: ST_LISTAAVIONES**cabecera

*Funcion: ST_LISTAAVIONES * crearNodo
*Parametros: ST_AVION * avion

*Funcion: void crearCola
*Parametros: ST_COLA * cola

*Funcion: void agregarACola
*Parametros: ST_COLA * cola, ST_AVION * avion

*Funcion: void insertarOrdenado
*Parametros: ST_LISTAAVIONES ** cabecera, ST_AVION avion

*Funcion: void mostrarLista
*Parametros: ST_LISTAAVIONES**cabecera

*Funcion: ST_LISTAAVIONES * buscarIDEnLista
*Parametros: int ID, ST_LISTAAVIONES ** cabecera

*Funcion: void ordenarPorCombustible
*Parametros: ST_LISTAAVIONES ** cabecera, ST_AVION avion

*Funcion: void solicitarPista
*Parametros: ST_LISTAAVIONES ** listaAterrizar, ST_COLA * colaDespegar, ST_AVION * avion

*Funcion: int parsearMensaje
*Parametros: char * bufferMensaje, ST_AVION * avion

*Funcion: void caracterizarAvion
*Parametros: ST_AVION * avion

*Funcion: void recibirMensajeEnHilo
*Parametros: ST_TODASLASLISTAS * todasLasListas

*******************************************/



/**
*@struct ST_LISTAAVIONES
*@struct struct listaAviones * ste
**Estructura para listar a los aviones
*/
typedef struct listaAviones {
    ST_AVION * avion;
    struct listaAviones * ste;
}ST_LISTAAVIONES;


/**
*@struct ST_COLA
**estructura para una cola
*/
typedef struct {
    ST_LISTAAVIONES *cabecera;
    ST_LISTAAVIONES *fin;
}ST_COLA;

/**
*@struct ST_TODASLASLISTAS
**Esta estructura reune las listas de los
aviones registrados, la lista de los aviones que
estan por Aterrizar, la cola de los aviones que estan
por despegar.
*/
typedef struct {
    ST_LISTAAVIONES * avionesRegistrados;
    ST_LISTAAVIONES * listaAterrizaje;
    ST_COLA * colaDespegue;
    int cliente;
    int reservapista;
    int pistaAsignada;
    int avionEliminado;
} ST_TODASLASLISTAS;

/**
*@fn crearCola
*@param ST_COLA * cola
*/
void crearCola(ST_COLA * cola);

/**
*@fn crearCola
*@param ST_COLA * cola
*/
void agregarACola (ST_COLA * cola, ST_AVION * avion);

/**
*@fn crearCola
*@param ST_COLA * cola
*/
void crearLista (ST_LISTAAVIONES**cabecera);

/**
*@fn insertarEnLista
*@param ST_COLA * cola
*/
void insertarEnLista (ST_LISTAAVIONES ** cabecera, ST_AVION * avion);

/**
*@fn mostrarLista
*@param ST_COLA * cola
*/
void mostrarLista (ST_LISTAAVIONES**cabecera);

/**
*@fn ST_LISTAAVIONES * buscarIDEnLista
*@param ST_COLA * cola
*/
ST_LISTAAVIONES * buscarIDEnLista (int ID, ST_LISTAAVIONES ** cabecera);

/**
*@fn ordenarPorCombustible
*@param ST_COLA * cola
*/
void ordenarPorCombustible (ST_LISTAAVIONES ** cabecera, ST_AVION * avion);

/**
*@fn solicitarPista
*@param ST_COLA * cola
*/
void solicitarPista (ST_LISTAAVIONES ** listaAterrizar, ST_COLA * colaDespegar, ST_AVION * avion);

/**
*@fn recibirMensajeEnHilo
*@param ST_COLA * cola
*/
void recibirMensajeEnHilo (ST_TODASLASLISTAS * todasLasListas);

/**
*@fn eliminarAvion
*@param ST_COLA * cola
*/
void eliminarAvion (ST_TODASLASLISTAS * todasLasListas);

#endif // LISTAAVIONES_H_INCLUDED
