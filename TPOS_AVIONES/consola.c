#include "consola.h"
#include "avion.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define tamanioBufferMensaje 100

<<<<<<< HEAD
=======



/********************************************!
*@fn conectar
**se realiza coneccion del avión con el aeropuerto
*@param int cliente
*@param struct sockaddr_in direccionServidor
*@return 1
********************************************/
>>>>>>> rama_geminis
int conectar (int cliente, struct sockaddr_in direccionServidor){
        if (connect(cliente, (void*) &direccionServidor, sizeof(direccionServidor)) != 0) {
                perror("No se pudo conectar");
                return 1;
            }
}


<<<<<<< HEAD
=======


/********************************************!
*@fn abrirConsola
**abre un menú de opciones, muestra las característica del avión actual
*@param struct sockaddr_in direccionServidor
*@param int cliente
*@param char * IP
*@param char*puerto
*@param ST_AVION *avion
*@param int * pistaAsignada
********************************************/
>>>>>>> rama_geminis
void abrirConsola(struct sockaddr_in direccionServidor, int cliente, char * IP, char*puerto, ST_AVION *avion, int * pistaAsignada){
    printf("\n Bienvenido al sistema de control del avion\n");
    printf ("\nEl ID del avion es %s", avion->id);
    printf ("\nEl modelo del avion es %s", avion->modelo);
    printf ("\nLa capacidad maxima de combustible del avion es %i", avion->capMax);
    printf ("\nEl estado del avion es %c", avion->estado);
    printf ("\nLa cantidad de combustible del avion es %i", avion->cantCombustible);
    printf ("\n El estado de la asignaciòn de pista es %i", *pistaAsignada);
    printf("\n[1] - Registrar avion");
    printf("\n[2] - Solicitar pista");
    printf("\n[3] - Despegar");
    printf("\n[4] - Aterrizar");
    printf("\n[5] - Mostrar estado");
    printf("\n[6] - Salir\n");
    int N=0;
    scanf("%d",&N);
        //char letra = strtoi(N);
		//send(cliente, &letra, sizeof(letra), 0);
    switch (N){
        case 1:
        system("clear");
        conectar(cliente, direccionServidor);
        char* msj1 = armarMensaje(cliente,IP,puerto, avion, 1);
        send(cliente, msj1, tamanioBufferMensaje, 0);
        recibirMensaje(cliente, 1, avion, pistaAsignada);
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);
        break;
        case 2:
        system("clear");
        char* msj2 = armarMensaje(cliente,IP,puerto, avion, 2);
        send(cliente, msj2, tamanioBufferMensaje, 0);
<<<<<<< HEAD
        while (*pistaAsignada!=1){
            recibirMensaje(cliente, 2, avion, pistaAsignada);
            }
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);

=======
        recibirMensaje(cliente, 2, avion, pistaAsignada);
        //recibirMensaje(cliente, 2, avion, pistaAsignada);
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);
>>>>>>> rama_geminis
        break;
        case 3:
        system("clear");
        char* msj3 = armarMensaje(cliente,IP,puerto, avion, 3);
        send(cliente, msj3, tamanioBufferMensaje, 0);
<<<<<<< HEAD
        while(avion->estado!='v'){
            recibirMensaje(cliente, 3, avion, pistaAsignada);
            }
=======
        recibirMensaje(cliente, 3, avion, pistaAsignada);

>>>>>>> rama_geminis
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);
        break;
        case 4:
        system("clear");

        char* msj4 = armarMensaje(cliente,IP,puerto, avion, 4);
        send(cliente, msj4, tamanioBufferMensaje, 0);
<<<<<<< HEAD
        while(avion->estado!='g'){
            recibirMensaje(cliente, 3, avion, pistaAsignada);
            }
=======
        recibirMensaje(cliente, 3, avion, pistaAsignada);

>>>>>>> rama_geminis
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);
        break;
        case 5:
        system("clear");
        mostrarEstadoAvion(avion);
        abrirConsola(direccionServidor, cliente, IP, puerto, avion, pistaAsignada);
        break;
    }
}


<<<<<<< HEAD
=======

>>>>>>> rama_geminis
