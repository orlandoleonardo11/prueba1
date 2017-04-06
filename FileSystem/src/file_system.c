#include <stdio.h>
#include "file_system.h"

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

	char* operando; //defino operando (string)
	int enviar = 1;
	int packageSize = sizeof(operando); //tamaño de cadena
	char *message = malloc(packageSize);

	while(enviar){
		printf("Conectado al servidor. Ingrese dos numeros, para salir, ambos operandos deben ser 0:\n");
		scanf("%s", &(operando));
		if(operando == "salir") enviar = 0;		// Chequea si el usuario quiere salir.
		if(enviar) {
			//deberia serializar
			send(serverSocket, message, packageSize, 0);
		}
	}

	printf("Desconectado\n");


	free(message);

	close(serverSocket);


	return 0;
}
