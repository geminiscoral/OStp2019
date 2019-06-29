#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

/**
                    *DESCRIPCION
*TAD: avion
*En este TAD, nos encargaremos de la recepción y envío de mensajes de los aviones
a la torre de control. Además de la creación de un avión.

                    *CONJUNTOS DE DATOS:
*Estructuras
ST_AVION,
*Variables
charOpcion, cliente, N.

*Punteros
* argv1, * IP, * strPuerto, * ID, * modelo, * cantMaxComb, *avion, * puerto, * avion,

                        *OPERACIONES:

*Funcion: void parsearTextoParametro
*Parametros: const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb

*Funcion: void crearAvion
*ParametrosST_AVION * avion

*Funcion: void mostrarEstadoAvion
*Parametros:ST_AVION *avion

*Funcion: char * armarMensaje
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion

*Funcion: int recibirMensaje
*Parametros: int cliente, int opcion, ST_AVION * avion, int * pistaAsignada

*Funcion: char strtoi
*Parametros; int N

*Funcion: void registracion
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion

*Funcion: void solicitarPista
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion

*Funcion: void despegar
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion

*Funcion: void aterrizar
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion

*Funcion: void restarCombustible
*Parametros: ST_AVION * avion

*Funcion: void enviarCombustible
*Parametros: int cliente, char * IP, char * puerto, ST_AVION * avion

*/


typedef struct {
    char id [9];
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;

void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb );

void crearAvion (ST_AVION * avion);

void mostrarEstadoAvion (ST_AVION *avion);

char * armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion);

int recibirMensaje (int cliente, int opcion, ST_AVION * avion);

char strtoi (int N);

void registracion (int cliente, char * IP, char * puerto, ST_AVION * avion);

void solicitarPista (int cliente, char * IP, char * puerto, ST_AVION * avion);

void despegar (int cliente, char * IP, char * puerto, ST_AVION * avion);

void aterrizar (int cliente, char * IP, char * puerto, ST_AVION * avion);

void restarCombustible (ST_AVION * avion);

void enviarCombustible (int cliente, char * IP, char * puerto, ST_AVION * avion);

#endif // AVION_H_INCLUDED
