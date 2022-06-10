#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funciones.h"
#include "Menus.h"
#include "Controller.h"
#include "ABM.H"

void Menu()
{

		printf("\n\t\t\t\t>-MENU-<\t\t\t\t\n");
		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de pasajeros\n");
		printf("4. Modificar de pasajeros\n");
		printf("5. Baja de pasajeros\n");
		printf("6. Listar pasajeros\n");
		printf("7. Ordenar pasajeros\n");
		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
		printf("10. Salir\n");


}

int Passenger_menuModificar()
{
	int opciones;

		printf("\n\t>-MENU MODIFICACIONES-<\t\n");
		printf("1. Modificar nombre\n");
		printf("2. Modificar apellido\n");
		printf("3. Modificar precio\n");
		printf("4. Modificar tipo de pasajero\n");
		printf("5. Modificar codigo de vuelo\n");
		printf("0. Salir\n");

		utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,5,3,&opciones);

		return opciones;
}
int Passenger_menuOrden(void)
{
	int opciones;

		printf("\n\t>-MENU ORDEN-<\t\n");
		printf("1. Ordenar por ID\n");
		printf("2. Ordenar por nombre\n");
		printf("3. Ordenar por apellido\n");
		printf("4. Ordenar por precio\n");
		printf("5. Ordenar por tipo de pasajero\n");
		printf("6. Ordenar por codigo de vuelo\n");
		printf("7. Mostrar lista ordenada\n");
		printf("0. Salir\n");

		utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,7,3,&opciones);

		return opciones;
}
int Passenger_subMenuOrden(void)
{
	int opciones;

		printf("\n\t>-CRITERIO DE ORDEN-<\t\n");
		printf("0. Descendente\n");
		printf("1. Ascendente\n");

		utn_getInt("\nIngrese una opcion: ","\nError, opcion invalida: ",0,1,3,&opciones);

		return opciones;
}
