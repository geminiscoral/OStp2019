#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED


typedef struct {
    int id;
    char modelo [20];
    int capMax;
    int cantCombustible;
    char estado;
}ST_AVION;

char strtoi (int N);

char * enteroACadena (int valor, char * cadena);

#endif // AVIONES_H_INCLUDED
