#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "menus.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
#include "ABM.H"


Passenger* Passenger_new()
{
	Passenger* pPassenger = NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];

	id=0;
	strcpy(nombre,"\0");
	strcpy(apellido,"\0");
	precio=0;
	tipoPasajero=0;
	strcpy(codigoVuelo,"\0");
	pPassenger = (Passenger*) malloc(sizeof(Passenger));

	if(pPassenger!=NULL)
	{
		Passenger_setVerifyInt(pPassenger,id,nombre,apellido,precio,tipoPasajero,codigoVuelo);
	}

	return pPassenger;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr)
{
	Passenger* pPassengerParam = NULL;

		if(idStr!=NULL && nombreStr!=NULL && tipoPasajeroStr!=NULL && apellidoStr!=NULL&& precioStr!=NULL&& codigoVueloStr!=NULL)
		{
			pPassengerParam = Passenger_new();

			if(pPassengerParam!=NULL)
			{
				if((Passenger_setVerifyChar(pPassengerParam,idStr,nombreStr,apellidoStr,precioStr,tipoPasajeroStr,codigoVueloStr))!=0)
				{
					Passenger_delete(pPassengerParam);
				}
			}
		}

		return pPassengerParam;
}
void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
		{
			free(this);
			this=NULL;
		}
}

///////////////////////////SETTERS/////////////////////////////////////////////////
int Passenger_setId(Passenger* this,int id)
{
	int todoOK = -1;

		if(this!=NULL && id>0)
		{
			this->id = id;
			todoOK=0;
		}

		return todoOK;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOK = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		todoOK=0;
	}

	return todoOK;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOK = -1;

			if(this!=NULL && apellido!=NULL)
			{
				strcpy(this->apellido,apellido);
				todoOK=0;
			}

			return todoOK;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOK = -1;

				if(this!=NULL && codigoVuelo!=NULL)
				{
					strcpy(this->codigoVuelo,codigoVuelo);
					todoOK=0;
				}

				return todoOK;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int todoOK = -1;

			if(this!=NULL && tipoPasajero>0)
			{
				this->tipoPasajero = tipoPasajero;
				todoOK=0;
			}

			return todoOK;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOK = -1;

				if(this!=NULL && precio>0)
				{
					this->precio = precio;
					todoOK=0;
				}

				return todoOK;
}


//////////////////////////GETTERS////////////////////////////////////////////////


int Passenger_getId(Passenger* this,int* id)
{
	int todoOK = -1;

		if(this!=NULL && id!=NULL)
		{
			*id = this->id;
			todoOK=0;
		}

		return todoOK;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOK = -1;

		if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			todoOK=0;
		}

		return todoOK;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOK = -1;

		if(this!=NULL && apellido!=NULL)
		{
			strcpy(apellido,this->apellido);
			todoOK=0;
		}

		return todoOK;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOK = -1;

			if(this!=NULL && codigoVuelo!=NULL)
			{
				strcpy(codigoVuelo,this->codigoVuelo);
				todoOK=0;
			}

			return todoOK;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int todoOK = -1;

		if(this!=NULL && tipoPasajero!=NULL)
		{
			*tipoPasajero = this->tipoPasajero;
			todoOK=0;
		}

		return todoOK;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOK = -1;

			if(this!=NULL && precio!=NULL)
			{
				*precio = this->precio;
				todoOK=0;
			}

			return todoOK;
}
////////////////////////BUSQUEDA Y MOSTRAR////////////////////////////////////////////////////////////////
int Passenger_findID(LinkedList* listaPasajeros, int id)
{
	int i;
		int len;
		int index;
		Passenger* auxiliar;

		if(listaPasajeros!=NULL)
		{
			len = ll_len(listaPasajeros);

			if(len>0)
			{
				for(i=0; i<len ;i++)
				{
					auxiliar = (Passenger*)ll_get(listaPasajeros,i);
					if(auxiliar->id==id)
					{
						index=i;
						break;
					}
				}
			}
		}

		return index;
}
int Passenger_printOnePassenger(Passenger* this)
{
	int todoOK = -1;
		int auxID;
		char auxNombre[50];
		char auxApellido[50];
		char auxCodigoVuelo[10];
		int auxTipoPasajero;
		float auxPrecio;

		if(this!=NULL)
		{
			if(!Passenger_getVerify(this,&auxID,auxNombre,auxApellido,&auxTipoPasajero,&auxPrecio,auxCodigoVuelo))
			{
				printf("%d\t%-10s\t%-10s\t%d\t%f\t%-10s \n",auxID
											,auxNombre
											,auxApellido
											,auxTipoPasajero
											,auxPrecio
											,auxCodigoVuelo);
				todoOK=0;
			}
			else
			{
				printf("Error para mostrar el Pasajero");
			}
		}

		return todoOK;
}
int Passenger_printList(LinkedList* listaPasajeros)
{
	int todoOK = -1;
		int len;
		int i;
		Passenger* aux = NULL;

		if(listaPasajeros!=NULL)
		{
			len = ll_len(listaPasajeros);

			if(len>0)
			{
				printf("ID\tNOMBRE\t\ttipo\tSUELDO\n");

				for(i=0; i<len ;i++)
				{
					aux = (Passenger*) ll_get(listaPasajeros,i);

					if(aux != NULL)
					{
						Passenger_printOnePassenger(aux);
						todoOK=0;
					}
				}
			}
		}

		return todoOK;
}
