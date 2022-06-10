#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funciones.h"
#include "Menus.h"
#include "Controller.h"
#include "ABM.H"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOK = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				todoOK=1;
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

    return todoOK;
}

int controller_loadFromTextID(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int todoOK = -1;
		FILE* pArchivo;

		if(path!=NULL && pArrayListPassenger!=NULL)
		{
			pArchivo = fopen(path,"r");

			if(pArchivo!= NULL)
			{
				if(!parser_IdFromText(pArchivo,pArrayListPassenger,id))
				{
					todoOK = 0;
				}
			}
			fclose(pArchivo);
		}

	    return todoOK;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOK = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo!= NULL)
		{
			if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger))
			{
				printf("Se cargo con exito\n");
				todoOK=1;
			}
			fclose(pArchivo);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}

	return todoOK;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* id)
{
	int todoOK = -1;
	int opcion;
	int auxId;
	int i=0;

	if(pArrayListPassenger!=NULL && id!=NULL)
	{

		controller_loadFromTextID("id.csv", pArrayListPassenger, id);

		auxId=*id;

		printf("ALTA DE PASAJEROS\n");
		utn_getInt("\n¿Cuantos pasajeros desea dar de alta?: ","\nError, reingrese: ",1,1000,3,&opcion);
		do
		{
			if(!Passenger_add(pArrayListPassenger,&auxId))
			{
				*id=auxId;
				todoOK=0;
			}
			i++;
		}while(opcion!=i);

		if(!todoOK)
		{
			printf("Se ha dado de alta correctamente");
		}
		else
		{
			printf("No se ha dado de alta un nuevo empleado");
		}
	}
	return todoOK;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOK = -1;

		if(pArrayListPassenger!=NULL)
		{
			printf("MODIFICACION DE PASAJEROS\n");
			if(!Passenger_modificar(pArrayListPassenger))
			{
				printf("Se ha modificado con exito");
			}
			else
			{
				printf("No se han podido actualizar los datos");
			}
		}
		return todoOK;
}

/*
  \brief Baja de pasajero

  \param path char*
  \param pArrayListPassenger LinkedList*
  \return int

 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOK = -1;
	int opcion;
	int i=0;

	if(pArrayListPassenger!=NULL)
	{
		printf("BAJA DE PASAJEROS\n");
		utn_getInt("\n¿Cuantos pasajeros desea dar de baja?: ","\nError, reingrese: ",1,1000,3,&opcion);

		do
		{
			if(!Passenger_remove(pArrayListPassenger))
			{
				todoOK=1;
			}
			i++;
		}while(opcion!=i);
	}

	return todoOK;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOK = -1;

	if(pArrayListPassenger!=NULL)
	{
		printf("LISTA DE PASAJEROS\n");
		if(Passenger_printList(pArrayListPassenger)!=0)
		{
			printf("No hay pasajeros para mostrar");
			todoOK=1;
		}
	}

	return todoOK;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOK = -1;
	int criterio;
	int opcion;
	char confirmar[4];
	strcpy(confirmar,"no");
	LinkedList* clon;
	if(pArrayListPassenger!=NULL)
	{
		clon = ll_clone(pArrayListPassenger);

		if(clon!=NULL)
		{
			do
			{
				opcion = Passenger_menuOrden();
				if(opcion!=0 && opcion!=5)
				{
					criterio = Passenger_subMenuOrden();
				}
				switch(opcion)
				{
					case 0:
						utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
						ll_deleteLinkedList(clon);
						break;
					case 1:
						if(!ll_sort(clon,Passenger_comparaPorId,criterio))
						{
							if(criterio)
							{
								printf("Se ha ordenado la lista por id ascendente");
							}
							else
							{
								if(!criterio)
								{
									printf("Se ha ordenado la lista por id descendente");
								}
							}
						}
						break;
					case 2:
						ll_sort(clon,Passenger_comparaPorNombre,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por nombre de A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por nombre de Z-A");
							}
						}
						break;
					case 3:
						ll_sort(clon,Passenger_comparaPorApellido,criterio);
						if(criterio)
						{

							printf("Se ha ordenado la lista por apellido A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por apellido Z-A");
							}
						}
						break;
					case 4:
						ll_sort(clon,Passenger_comparaPorPrecio,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por precio ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por precio descendente");
							}

						}
						break;
					case 5:
						ll_sort(clon,Passenger_comparaPorTipoPasajero,criterio);
						if(criterio)
						{
							printf("Se ha ordenado la lista por tipo de pasajero ascendente");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por tipo de pasajero descendente");
							}

						}
						break;
					case 6:
						ll_sort(clon,Passenger_comparaPorCodigoVuelo,criterio);
						if(criterio)
						{

							printf("Se ha ordenado la lista por codigo A-Z");
						}
						else
						{
							if(!criterio)
							{
								printf("Se ha ordenado la lista por codigo Z-A");
							}
						}
						break;
					case 7:
						controller_ListPassenger(clon);
						break;
				}
			}while(stricmp(confirmar,"si"));
		}
	}

	return todoOK;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOK = -1;
	int i;
	int len;
	int auxID;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[10];
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListPassenger);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,nombre,apellido,precio,tipoPasajero,codigoVuelo\n");
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);
				if(aux!=NULL)
				{
					if(!Passenger_getVerify(aux,&auxID,auxNombre,auxApellido,&auxTipoPasajero,&auxPrecio,auxCodigoVuelo))
					{
						fprintf(pArchivo,"%d,%s,%s,%f,%d,%s\n",auxID,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo);
						todoOK=0;
					}
					else
					{
						Passenger_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!todoOK)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return todoOK;
}
int controller_saveAsTextID(char* path , LinkedList* pArrayListEmployee, int id)
{
	int todoOK = -1;
	int idMayor = 0;
	FILE* pArchivo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(id==2000)
		{
			idMayor = id;
			todoOK=0;
		}
		else
		{
			idMayor = ObtenerMayorId(pArrayListEmployee);
		}

		pArchivo = fopen(path,"w");

		if(pArchivo!= NULL)
		{
			fprintf(pArchivo,"Siguiente ID:\n");
			fprintf(pArchivo,"%d\n",idMayor);
			todoOK=0;
		}

		fclose(pArchivo);
	}

	return todoOK;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOK = -1;
	int i;
	int len;
	FILE* pArchivo;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);

		pArchivo = fopen(path,"wb");

		if(pArchivo!= NULL && len>0)
		{
			for(i=0; i<len ;i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger,i);

				if(aux!=NULL)
				{
					fwrite(aux,sizeof(Passenger),1,pArchivo);
					todoOK=0;
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
		if(!todoOK)
		{
			printf("Se guardo con exito\n");
		}
	}

	return todoOK;
}

