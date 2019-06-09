#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include "aviones.h"
#include "listaAviones.h"
#define tamanioBufferMensaje 100


int main(void) {

    struct sockaddr_in direccionServidor;
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = INADDR_ANY;
    direccionServidor.sin_port = htons(8080);

    int servidor = socket(AF_INET, SOCK_STREAM, 0);

    int activado = 1;
    setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

    if (bind(servidor, (void*) &direccionServidor, sizeof(direccionServidor)) != 0) {
        perror("Falló el bind");
        return 1;
    }

    printf("Estoy escuchando\n");
    listen(servidor, 100);

    struct sockaddr_in direccionCliente;
    unsigned int tamanioDireccion = sizeof(struct sockaddr_in);
    int cliente = accept(servidor, (void*) &direccionCliente, &tamanioDireccion);

    printf("Recibí una conexión en %d!!\n", cliente);

    //------------------------------

	ST_AVION avion;
	ST_LISTAAVIONES * listaAvion;
	crearLista(&listaAvion);
    ST_LISTAAVIONES * colaAterrizar;
    crearLista(&colaAterrizar);
    ST_COLA colaDespegar;
    crearCola(&colaDespegar);

    int IDReservaPista = 0;

    while (1){

        char * bufferMensaje = (char*)malloc(tamanioBufferMensaje);

        recibirMensaje(&IDReservaPista, &listaAvion, &colaAterrizar, &colaDespegar , &avion, cliente, bufferMensaje);
        /*printf("ID: %i", avion.id);
        printf("Modelo: %s", avion.modelo);
        printf("Estado: %c", avion.estado);
        printf("Cantidad max de combustible: %i", avion.capMax);
        printf("Cantidad de combustible: %i", avion.cantCombustible);
        */
        //close (servidor);
        free(bufferMensaje);
    }

	return 0;
}
