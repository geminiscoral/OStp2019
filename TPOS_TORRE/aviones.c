#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "aviones.h"
#define longMensajeEnviado 2

/********************************************!
*@fn  strtoi
combierte una cifra entera en un char
*@param int N
*@return una variable char
********************************************/
   char strtoi (int N){
        char salida;
        salida = N + 48;
        return salida;
    }

/********************************************!
*@fn  * enteroACadena
combierte un valor entero en una cadena
*@param int valor
*@param char *cadena
*@return cadena
********************************************/
    char * enteroACadena (int valor, char * cadena){
        int cont = 0;
        char cad [10];
        int aux = valor;
        char numero;
        while ((aux/10)!=0){
            cont ++;
            aux = aux/10;
        }
        cad[cont+1] = '\0';
        while ((valor/10)!=0){
            numero = (valor%10) + 48;
            cad[cont] = numero;
            valor = valor/10;
            cont--;
        }
        numero = (valor%10) + 48;
        cad[cont] = numero;
        strcpy(cadena,cad);
        return cadena;
    }


/********************************************!
*@fn  registrarAvion
**registra un nuevo avion y modifica su estado,
**pasa de estado h(en hangar) a g(listo/hangar)
*@param ST_AVION *avion
********************************************/
    void registrarAvion (ST_AVION * avion){
            if (avion->estado == 'h'){
                    avion->estado = 'g';
            }
    }


/********************************************!
*@fn  enviarMensaje
**Segun la opcion ingresada por teclado, la fn envia un mensaje
**a un cliente que se pasara por parametro.
*@param int cliente
*@param int opcion
********************************************/
    void enviarMensaje (int cliente, int opcion){
            switch(opcion){
                case 0: // La solicitud se proceso exitosamente
                    send(cliente, "0", longMensajeEnviado, 0);
                break;
                case 1: // La pista fue cedida a cliente
                    send(cliente, "1", longMensajeEnviado, 0);
                break;
                case 3: // El avion despego
                    send(cliente, "3", longMensajeEnviado, 0);
                break;
                case 4: // El avion aterrizo
                    send(cliente, "4", longMensajeEnviado, 0);
                break;
            }
    }
