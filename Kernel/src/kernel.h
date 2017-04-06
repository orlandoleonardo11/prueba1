/*
 * kernel.h
 *
 *  Created on: 6/4/2017
 *      Author: utnso
 */

#ifndef SRC_KERNEL_H_
#define SRC_KERNEL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdint.h>


#define PUERTO "5003"
#define BACKLOG 5			// Define cuantas conexiones vamos a mantener pendientes al mismo tiempo

/*
 * 	Definicion de estructuras
 *SRC_
 * 	Es importante destacar que utilizamos el tipo uint_32, incluida en el header <stdint.h> para mantener un estandar en la cantidad
 * 	de bytes del paquete.
 */
typedef struct _t_Package {
	uint32_t Operando1;
	uint32_t Operando2;
} t_Package;

/*
 * 	Definicion de funciones
 */

void deserializarOperandos(t_Package* , char**);

#endif /* SRC_KERNEL_H_ */
