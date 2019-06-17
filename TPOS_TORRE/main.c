#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>
#include "aviones.h"
#include "listaAviones.h"
#include "gestionPista.h"
<<<<<<< HEAD

=======
>>>>>>> my_branch_psang
#include "gestionCombustibleAterrizando.h"
#include "gestionCombustible.h"
#define tamanioBufferMensaje 100

<<<<<<< HEAD

=======
>>>>>>> my_branch_psang
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

<<<<<<< HEAD


=======
>>>>>>> my_branch_psang
    //------------------------------

	ST_LISTAAVIONES * listaAvion;
	crearLista(&listaAvion);
    ST_LISTAAVIONES * colaAterrizar;
    crearLista(&colaAterrizar);
    ST_COLA colaDespegar;
    crearCola(&colaDespegar);
    ST_TODASLASLISTAS todasLasListas;

    int IDReservaPista = 0;
    int cliente = 0;

    aunarListas(&todasLasListas,&cliente, &IDReservaPista, listaAvion, colaAterrizar, &colaDespegar);

    pthread_t gestionPista;
<<<<<<< HEAD

    pthread_create(&gestionPista, NULL, (void*)gestionarPista, (void*)&todasLasListas);

    pthread_t gestionCombustible;

    pthread_create(&gestionCombustible, NULL, (void*)gestionarCombustibleRegistrados, (void*)&todasLasListas);

    pthread_t gestionCombustibleAterrizando;

    pthread_create(&gestionCombustibleAterrizando, NULL, (void*)gestionarCombustibleAterrizando, (void*)&todasLasListas);


=======
    pthread_create(&gestionPista, NULL, (void*)gestionarPista, (void*)&todasLasListas);

    pthread_t gestionCombustible;
    pthread_create(&gestionCombustible, NULL, (void*)gestionarCombustibleRegistrados, (void*)&todasLasListas);

    pthread_t gestionCombustibleAterrizando;
    pthread_create(&gestionCombustibleAterrizando, NULL, (void*)gestionarCombustibleAterrizando, (void*)&todasLasListas);

>>>>>>> my_branch_psang
    while (1){

        struct sockaddr_in direccionCliente;
        unsigned int tamanioDireccion = sizeof(struct sockaddr_in);
        cliente = accept(servidor, (void*) &direccionCliente, &tamanioDireccion);

        todasLasListas.cliente = cliente;

        pthread_t gestionClientes;

        pthread_create(&gestionClientes, NULL,(void*)recibirMensaje, (void*)&todasLasListas);

<<<<<<< HEAD

=======
>>>>>>> my_branch_psang
        printf("Recibí una conexión en %d!!\n", cliente);

        //recibirMensaje(&todasLasListas);
        /*printf("ID: %i", avion.id);
        printf("Modelo: %s", avion.modelo);
        printf("Estado: %c", avion.estado);
        printf("Cantidad max de combustible: %i", avion.capMax);
        printf("Cantidad de combustible: %i", avion.cantCombustible);
        */
        //close (servidor);
    }

	return 0;
}
