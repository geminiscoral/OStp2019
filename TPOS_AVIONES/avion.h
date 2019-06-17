#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

<<<<<<< HEAD
=======

/********************************************!
** TAD: avion
**En este TAD, nos encargaremos de la recepción y envío de mensajes de los aviones
a la torre de control. Además de la creación de un avión.

**CONJUNTOS DE DATOS:
**----------Estructuras-----------:
ST_AVION,
**----------Variables-------------:
charOpcion, cliente, N,
**----------Punteros--------------:
* argv1, * IP, * strPuerto, * ID, * modelo, * cantMaxComb, *avion, * puerto, * avion,
**OPERACIONES:
**1--<void parsearTextoParametro>  <(const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb )>
**2--<void crearAvion>  <(ST_AVION * avion)>
**3--<void mostrarEstadoAvion>  <(ST_AVION *avion)>
**4<char * armarMensaje>  <(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion)>
**5<int recibirMensaje>  <(int cliente, int opcion, ST_AVION * avion, int * pistaAsignada)>
**6<char strtoi>  <(int N)>;
*******************************************/



/*******************************!
*@struct ST_AVION
**En esta estructura definiremos las características del avión
********************************/
>>>>>>> rama_geminis
typedef struct {
    char id [9];
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;

<<<<<<< HEAD
void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb );

void crearAvion (ST_AVION * avion);

void mostrarEstadoAvion (ST_AVION *avion);

char * armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion);

int recibirMensaje (int cliente, int opcion, ST_AVION * avion, int * pistaAsignada);

char strtoi (int N);

#endif // AVION_H_INCLUDED
=======
//1
void parsearTextoParametro (const char * argv1, char * IP, char* strPuerto, int * puerto, char * ID, char * modelo, int * cantMaxComb );

//2
void crearAvion (ST_AVION * avion);

//3
void mostrarEstadoAvion (ST_AVION *avion);

//4
char * armarMensaje(int cliente, char * IP, char * puerto, ST_AVION * avion, int charOpcion);

//5
int recibirMensaje (int cliente, int opcion, ST_AVION * avion, int * pistaAsignada);

//6
char strtoi (int N);

#endif // AVION_H_INCLUDED


>>>>>>> rama_geminis
