#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED

/**
** TAD: aviones
*este TAD se encargara del envio de mensajes de los aviones
ademas de las registraciones de los mismos.

**CONJUNTOS DE DATOS:
*----------Estructuras-----------:
ST_AVION
*----------Variables-------------:
N, valor, opcion, cliente
*----------Punteros--------------:
* avion, * cadena

*OPERACIONES:

*Funcion: char strtoi
*Parametros:int N

*Funcion: char * enteroACadena
*Parametros: int valor, char * cadena

*Funcion: void enviarMensaje
*Parametro: int cliente, int opcion)>

*Funcion: void registrarAvion
*Parametro: ST_AVION * avion
*/


/**
*@struct ST_AVION
*Esta estructura define las caracteristicas de un avion
*/
typedef struct {
    int cliente;
    int id;
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;

char strtoi (int N);

char * enteroACadena (int valor, char * cadena);

void enviarMensaje (int cliente, int opcion);

void registrarAvion (ST_AVION * avion);

#endif // AVIONES_H_INCLUDED
