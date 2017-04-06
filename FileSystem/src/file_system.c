#include <stdio.h>
#include "file_system.h"
#include <commons/string.h>

int main() {

	struct addrinfo hints;
	struct addrinfo *serverInfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo(IP, PUERTO, &hints, &serverInfo);

	int serverSocket;
	serverSocket = socket(serverInfo->ai_family, serverInfo->ai_socktype,
			serverInfo->ai_protocol);

	connect(serverSocket, serverInfo->ai_addr, serverInfo->ai_addrlen);
	freeaddrinfo(serverInfo);

	int enviar = 1;



	while(enviar){
		printf("Conectado al servidor. Ingrese exit para salir\n");
		//tamaño de cadena
		char* message[100];

		scanf("%s", message);
		if(string_starts_with(message, "exit")) break;
		//acá deberían serializar
		send(serverSocket, message, strlen(message), 0);

	}

	printf("Desconectado\n");




	close(serverSocket);


	return 0;
}
