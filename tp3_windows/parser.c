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
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char tipoPasajeros[50];
	char codigoVuelo[50];
	int header = 1;
	int cantidad = 0;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] ,%[^,] , %[^\n]\n",id,nombre,apellido,precio,tipoPasajeros,codigoVuelo);

			if((cantidad==3) && (header!=1))
			{
				auxiliar = Passenger_newParametros(id,nombre,apellido,precio,tipoPasajeros,codigoVuelo);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPassenger, auxiliar);
					isOk=0;
				}
				else
				{
					Passenger_delete(auxiliar);
				}
			}
			else
			{
				header=0;//evita el titulo
			}
		}
		while(!feof(pFile));
	}

	return isOk;
}
int parser_IdFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* id)
{
	int isOk = -1;
	char idTxt[50];
	int idInt;
	int cantidad = 0;
	int header=1;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idTxt);

			if((cantidad==1) && (header!=1))
			{
				isOk = 0;
				idInt = atoi(idTxt);

				if(idInt>*id)
				{
					*id=idInt;
				}
			}
			else
			{
				header=0;
			}
		}
		while(!feof(pFile));
	}

	return isOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int isOk = -1;
	Passenger* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			auxiliar = Passenger_new();

			if(auxiliar!=NULL)
			{
				if(fread(auxiliar,sizeof(Passenger),1,pFile))
				{
					ll_add(pArrayListPassenger,auxiliar);
					isOk=0;
				}
				else
				{
					Passenger_delete(auxiliar);
				}
			}
		}while(!feof(pFile));
	}

	return isOk;
}
