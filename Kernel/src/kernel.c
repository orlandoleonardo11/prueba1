/*
 * kernel.c
 *
 *  Created on: 6/4/2017
 *      Author: utnso
 */
#include "kernel.h"

int main() {


struct addrinfo hints;
	struct addrinfo *serverInfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;		// No importa si uso IPv4 o IPv6
	hints.ai_flags = AI_PASSIVE;		// Asigna el address del localhost: 127.0.0.1
	hints.ai_socktype = SOCK_STREAM;	// Indica que usaremos el protocolo TCP

	getaddrinfo(NULL, PUERTO, &hints, &serverInfo); // Notar que le pasamos NULL como IP, ya que le indicamos que use localhost en AI_PASSIVE

	int listenningSocket;
		listenningSocket = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);

		bind(listenningSocket,serverInfo->ai_addr, serverInfo->ai_addrlen);
		freeaddrinfo(serverInfo);


		listen(listenningSocket, BACKLOG);		// IMPORTANTE: listen() es una syscall BLOQUEANTE.

		struct sockaddr_in addr;			// Esta estructura contendra los datos de la conexion del cliente. IP, puerto, etc.
			socklen_t addrlen = sizeof(addr);

			int socketCliente = accept(listenningSocket, (struct sockaddr *) &addr, &addrlen);

			/*
			 Cuando el cliente cierra la conexion, recv() devolvera 0.
			 */

			char *buffer = malloc(100);
			int tamanioBuffer = 100;


			int status = 1;

			printf("Cliente Conectado. ");

			while (status != 0){
				printf("Esperando valores...\n");
				status = recv(socketCliente, buffer, tamanioBuffer, 0);
				//deberian deserializar acá
				printf("recibi\n");
				buffer[status] = '\0';
				if (status != 0) printf("%s\n", buffer);

			}

			printf("Cliente Desconectado.\n");

			free(buffer);

			close(socketCliente);
			close(listenningSocket);



	return 0;
}
