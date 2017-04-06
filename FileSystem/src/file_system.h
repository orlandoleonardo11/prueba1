/*
 * file_system.h
 *
 *  Created on: 6/4/2017
 *      Author: utnso
 */

#ifndef SRC_FILE_SYSTEM_H_
#define SRC_FILE_SYSTEM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdint.h>

#define IP "127.0.0.1"
#define PUERTO "5003"

/*
 * 	Definicion de estructuras
 *
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

void serializarOperandos(t_Package, char**);


#endif /* SRC_FILE_SYSTEM_H_ */
