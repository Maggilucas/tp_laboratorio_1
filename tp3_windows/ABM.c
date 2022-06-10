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

int ObtenerMayorId (LinkedList* listaPasajeros)
{
	int mayorId=0;
		int id;
		int len;
		int i;
		Passenger* aux;

		if(listaPasajeros!=NULL)
		{
			len = ll_len(listaPasajeros);

			if(len>0)
			{
				for(i=0;i<len;i++)
				{
					aux = (Passenger*)ll_get(listaPasajeros,i);
					Passenger_getId(aux,&id);

					if(i==0 || (mayorId<id))
					{
						mayorId=id;
					}
				}
			}
		}

		return mayorId;
}
////////////////////////////COMPARADORES//////////////////////////////////////////
int Passenger_comparaPorId(void* Pasajero1, void* Pasajero2)//compara para ordenar
{
	int resultado = 0;//si son iguales
		Passenger* pasa1 = NULL;
		Passenger* pasa2 = NULL;
		int id1;
		int id2;

		if(Pasajero1!=NULL && Pasajero2!=NULL)
		{
			pasa1 = (Passenger*) Pasajero1;
			pasa2 = (Passenger*) Pasajero2;

			if((!Passenger_getId(pasa1,&id1)) && (!Passenger_getId(pasa2,&id2)))
			{
				if(id1 > id2)//mayores
				{
					resultado = 1;
				}
				else
				{
					if(id1 < id2)//menores
					{
						resultado = -1;
					}
				}
			}
		}

		return resultado;
}
int Passenger_comparaPorNombre(void* Pasajero1, void* Pasajero2)
{
	int resultado = -1;
		Passenger* pasa1 = NULL;
		Passenger* pasa2 = NULL;
		char nombre1[50];
		char nombre2[50];

		if(Pasajero1!=NULL && Pasajero2!=NULL)
		{
			pasa1 = (Passenger*) Pasajero1;
			pasa2 = (Passenger*) Pasajero2;

			if((!Passenger_getNombre(pasa1,nombre1)) && (!Passenger_getNombre(pasa2,nombre2)))
			{
				resultado = strcmp(nombre1,nombre2);
			}
		}

		return resultado;
}
int Passenger_comparaPorApellido(void* Pasajero1, void* Pasajero2)
{
	int resultado = -1;
			Passenger* pasa1 = NULL;
			Passenger* pasa2 = NULL;
			char apellido1[50];
			char apellido2[50];

			if(Pasajero1!=NULL && Pasajero2!=NULL)
			{
				pasa1 = (Passenger*) Pasajero1;
				pasa2 = (Passenger*) Pasajero2;

				if((!Passenger_getApellido(pasa1,apellido1)) && (!Passenger_getApellido(pasa2,apellido2)))
				{
					resultado = strcmp(apellido1,apellido2);
				}
			}

			return resultado;
}
int Passenger_comparaPorCodigoVuelo(void* Pasajero1, void* Pasajero2)
{
	int resultado = -1;
	Passenger* pasa1 = NULL;
	Passenger* pasa2 = NULL;
	char codigo1[10];
	char codigo2[10];

	if(Pasajero1!=NULL && Pasajero2!=NULL)
	{
		pasa1 = (Passenger*) Pasajero1;
		pasa2 = (Passenger*) Pasajero2;

		if((!Passenger_getCodigoVuelo(pasa1,codigo1)) && (!Passenger_getCodigoVuelo(pasa2,codigo2)))
		{
			resultado = strcmp(codigo1,codigo2);
		}
	}

	return resultado;
}
int Passenger_comparaPorTipoPasajero(void* Pasajero1, void* Pasajero2)
{
	int resultado = 0;//si son iguales
	Passenger* pasa1;
	Passenger* pasa2;
	int tipo1;
	int tipo2;

	if(Pasajero1!=NULL && Pasajero2!=NULL)
	{
		pasa1 = (Passenger*) Pasajero1;
		pasa2 = (Passenger*) Pasajero2;

		if((!Passenger_getTipoPasajero(pasa1,&tipo1)) && (!Passenger_getTipoPasajero(pasa2,&tipo2)))
		{
			if(tipo1 > tipo2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(tipo1 < tipo2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
int Passenger_comparaPorPrecio(void* Pasajero1, void* Pasajero2)
{
	int resultado = 0;//si son iguales
	Passenger* pasa1;
	Passenger* pasa2;
	float precio1;
	float precio2;

	if(Pasajero1!=NULL && Pasajero2!=NULL)
	{
		pasa1 = (Passenger*) Pasajero1;
		pasa2 = (Passenger*) Pasajero2;

		if((!Passenger_getPrecio(pasa1,&precio1)) && (!Passenger_getPrecio(pasa2,&precio2)))
		{
			if(precio1 > precio2)//mayores
			{
				resultado = 1;
			}
			else
			{
				if(precio1 < precio2)//menores
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}
////////////////////////////VERIFICADORES//////////////////////////////////////////
int Passenger_setVerifyInt(Passenger* this,int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo)
{
	int todoOK = -1;

		if(this!=NULL && id>0 && nombre!=NULL && apellido!=NULL && precio>0 && tipoPasajero>0 && codigoVuelo != NULL)
		{
			if((!(Passenger_setId(this,id)) &&
			!(Passenger_setNombre(this,nombre)) &&
			!(Passenger_setApellido(this, apellido)) &&
			!(Passenger_setPrecio(this,precio)) &&
			!(Passenger_setCodigoVuelo(this,codigoVuelo)) &&
			!(Passenger_setTipoPasajero(this,tipoPasajero))))
			{
				todoOK=0;
			}
		}

		return todoOK;
}
int Passenger_setVerifyChar(Passenger* this,char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr)
{
	int todoOK = -1;

			if(this!=NULL && idStr !=NULL && nombreStr!=NULL && tipoPasajeroStr!=NULL)
			{
				if((!(Passenger_setId(this,atoi(idStr))) &&
				!(Passenger_setNombre(this,nombreStr)) &&
				!(Passenger_setApellido(this,apellidoStr)) &&
				!(Passenger_setPrecio(this,atof(precioStr))) &&
				!(Passenger_setTipoPasajero(this,atoi(tipoPasajeroStr))) &&
				!(Passenger_setCodigoVuelo(this,codigoVueloStr))))
				{
					todoOK=0;
				}
			}

			return todoOK;
}
int Passenger_getVerify(Passenger* this, int* id, char* nombre,char* apellido, int* tipoPasajero, float* precio,char* codigoVuelo)
{
	int todoOK = -1;

			if(this!=NULL && id>0 && nombre!=NULL && apellido!=NULL && precio>0 && tipoPasajero>0 && codigoVuelo != NULL)
			{
				if((!(Passenger_getId(this,id)) &&
				!(Passenger_getNombre(this,nombre)) &&
				!(Passenger_getApellido(this,apellido)) &&
				!(Passenger_getPrecio(this,precio)) &&
				!(Passenger_getCodigoVuelo(this,codigoVuelo)) &&
				!(Passenger_getTipoPasajero(this,tipoPasajero))))
				{
					todoOK=0;
				}
			}

			return todoOK;
}
/////////////////////////////////////////////////////////////////////////////
int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int todoOK = -1;
	int auxPrecio;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR PRECIO****\t\n");
		utn_getInt("Ingrese el nuevo precio \n","Error, cantidad invalida\n",1000,100000,3,&auxPrecio);
		auxiliar.precio=auxPrecio;
		Passenger_printOnePassenger(&auxiliar);
		utn_getFloat("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",1000,100000,3,opciones);
		if(opciones)
		{
			Passenger_modificaPrecio(listaPasajeros,index,auxPrecio);
			todoOK=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return todoOK;
}
int Passenger_caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int todoOK = -1;
	int auxTipo;
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR TIPO PASAJERO****\t\n");
		utn_getInt("Ingrese el nuevo tipo \n","Error, cantidad invalida\n",1,100000,3,&auxTipo);
		auxiliar.tipoPasajero=auxTipo;
		Passenger_printOnePassenger(&auxiliar);
		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modificaTipoPasajero(listaPasajeros,index,auxTipo);
			todoOK=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}
	return todoOK;
}
int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int todoOK = -1;
	char auxNombre[50];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR NOMBRE****\t\n");
		utn_getString("Ingrese el nuevo nombre\n","Error, nombre invalido\n",50,3,auxNombre);
		SizeString(auxNombre);

		strcpy(auxiliar.nombre,auxNombre);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modificaNombre(listaPasajeros,index,auxNombre);
			todoOK=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return todoOK;
}
int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int todoOK = -1;
	char auxApellido[50];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR APELLIDO****\t\n");
		utn_getString("Ingrese el nuevo apellido\n","Error, apellido invalido\n",50,3,auxApellido);
		SizeString(auxApellido);

		strcpy(auxiliar.apellido,auxApellido);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modificaApellido(listaPasajeros,index,auxApellido);
			todoOK=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return todoOK;
}
int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int todoOK = -1;
	char auxCodigo[10];
	int opciones;

	if(listaPasajeros!=NULL && index!=-1)
	{
		printf("\t****MODIFICAR CODIGO****\t\n");
		utn_getString("Ingrese el nuevo apellido\n","Error, apellido invalido\n",10,3,auxCodigo);
		SizeString(auxCodigo);

		strcpy(auxiliar.codigoVuelo,auxCodigo);
		Passenger_printOnePassenger(&auxiliar);

		utn_getInt("\n¿Esta seguro que desea modificarlo? [1/0]\n","\nRespuesta invalida, ingrese [1/0]\n",0,1,3,&opciones);
		if(opciones)
		{
			Passenger_modificaCodigoVuelo(listaPasajeros,index,auxCodigo);
			todoOK=0;
		}
		else
		{
			printf("Modificacion cancelada");
		}
	}

	return todoOK;
}
///////////////////////////////MODIFICADORES////////////////////////////////////

int Passenger_modificaPrecio(LinkedList* listaPasajeros, int index, float auxPrecio)
{
	int todoOK = -1;
		Passenger* aux;

		if(listaPasajeros!=NULL && index>=0 && auxPrecio>=1000)
		{

			aux = (Passenger*) ll_get(listaPasajeros,index);

			if(aux!=NULL)
			{
				if(!Passenger_setPrecio(aux,auxPrecio))
				{
					printf("Se cargo correctamente el nuevo precio\n");
				}
				else
				{
					printf("No se pudo modificar el precio\n");
				}
				todoOK=0;
			}
		}
	    return todoOK;
}
int Passenger_modificaTipoPasajero(LinkedList* listaPasajeros, int index, int auxTipo)
{
	int todoOK = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxTipo>=1)
	{

		aux = (Passenger*) ll_get(listaPasajeros,index);

		if(aux!=NULL)
		{
			if(!Passenger_setTipoPasajero(aux,auxTipo))
			{
				printf("Se cargo correctamente el nuevo tipo de pasajero\n");
			}
			else
			{
				printf("No se pudo modificar el tipo de pasajero\n");
			}
			todoOK=0;
		}
	}
	return todoOK;
}
int Passenger_modificaNombre(LinkedList* listaPasajeros, int index, char* auxNombre)
{
	int todoOK = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxNombre!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxNombre);

		if(aux!=NULL)
		{
			if(!Passenger_setNombre(aux,auxNombre))
			{
				printf("Se cargo correctamente el nuevo nombre\n");
			}
			else
			{
				printf("No se pudo modificar el nombre\n");
			}
			todoOK=0;
		}
	}

	return todoOK;
}
int Passenger_modificaApellido(LinkedList* listaPasajeros, int index, char* auxApellido)
{
	int todoOK = -1;
	Passenger* aux;

	if(listaPasajeros!=NULL && index>=0 && auxApellido!=NULL)
	{
		aux = (Passenger*) ll_get(listaPasajeros,index);
		SizeString(auxApellido);

		if(aux!=NULL)
		{
			if(!Passenger_setApellido(aux,auxApellido))
			{
				printf("Se cargo correctamente el nuevo apellido\n");
			}
			else
			{
				printf("No se pudo modificar el apellido\n");
			}
			todoOK=0;
		}
	}

	return todoOK;
}
int Passenger_modificaCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigo)
{
	int todoOK = -1;
		Passenger* aux;

		if(listaPasajeros!=NULL && index>=0 && auxCodigo!=NULL)
		{
			aux = (Passenger*) ll_get(listaPasajeros,index);
			SizeString(auxCodigo);

			if(aux!=NULL)
			{
				if(!Passenger_setCodigoVuelo(aux,auxCodigo))
				{
					printf("Se cargo correctamente el nuevo codigo\n");
				}
				else
				{
					printf("No se pudo modificar el codigo\n");
				}
				todoOK=0;
			}
		}

		return todoOK;
}
//////////////////////////////////// ABM  /////////////////////////////////
int Passenger_add(LinkedList* listaPasajeros, int* id)
{
	int todoOK = -1;
	char respuesta[4];
	int auxID;
	char auxNombre[50];
	char auxApellido[50];
	char auxCodigoVuelo[10];
	int auxTipoPasajero;
	float auxPrecio;
	Passenger* auxPasajero = NULL;

	if(listaPasajeros!=NULL && id!=NULL)
	{
		auxPasajero = Passenger_new();

		if(auxPasajero!=NULL)
		{
			if((!(utn_getString("\nIngrese el nombre: ","\nError, reingrese: ",50,3,auxNombre)) &&
				!(utn_getString("\nIngrese el Apellido: ","\nError, reingrese: ",50,3,auxApellido)) &&
				!(utn_getInt("\nIngrese el tipo de pasajero: ","\nError, reingrese: ",1,4,3,&auxTipoPasajero)) &&
				!(utn_getFloat("\nIngrese precio: ","\nError, reingrese: ",1,10000,3,&auxPrecio)) &&
				!(utn_getString("\nIngrese el codigo de vuelo: ","\nError, reingrese: ",10,3,auxCodigoVuelo))))
			{
				SizeString(auxNombre);
				SizeString(auxApellido);
				SizeString(auxCodigoVuelo);
				auxID = *id;
				auxID+=1;

				if(!Passenger_setVerifyInt(auxPasajero,auxID,auxNombre,auxApellido,auxPrecio,auxTipoPasajero,auxCodigoVuelo))
				{
					Passenger_printOnePassenger(auxPasajero);
					utn_getString("\n¿Esta seguro que desea guardar este Pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

					if(!(stricmp(respuesta,"si")))
					{
						ll_add(listaPasajeros, auxPasajero);
						*id=auxID;
						todoOK=0;
					}
					else
					{
						Passenger_delete(auxPasajero);
					}
				}
			}
			else
			{
				printf("\nReintente nuevamente");
			}
		}
		else
		{
			printf("No hay espacio para un nuevo Pasajero");
		}
	}

	return todoOK;
}
int Passenger_remove(LinkedList* listaPasajeros)
{
	int todoOK = -1;
		int id;
		int index = -1;
		char respuesta[4];
		Passenger* aux = NULL;

		if(listaPasajeros!=NULL)
		{
			Passenger_printList(listaPasajeros);
			utn_getInt("Ingrese el ID para dar de baja: \n","Error, ID invalido\n",1,2000,3,&id);
			index = Passenger_findID(listaPasajeros,id);

			if(index!=-1)
			{
				aux = ll_get(listaPasajeros,index);
				Passenger_printOnePassenger(aux);
				utn_getString("\n¿Esta seguro que desea eliminar este pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

				if(!(stricmp(respuesta,"si")))
				{
					ll_remove(listaPasajeros,index);
					printf("Baja realizada con exito\n");
				}
				else
				{
					printf("Baja cancelada\n");
				}
			}
			else
			{
				printf("No se pudo encontrar el ID\n");
			}
		}

		return todoOK;
}
int Passenger_modificar(LinkedList* listaPasajeros)
{
	int todoOK = -1;
		int id;
		int index = -1;
		char respuesta[4];
		char confirmar[4];
		Passenger* aux;
		Passenger auxiliar;
		strcpy(confirmar,"no");

		if(listaPasajeros!=NULL)
		{
			Passenger_printList(listaPasajeros);
			utn_getInt("Ingrese el ID para modificar\n","Error, ID invalido\n",1,2000,3,&id);
			index = Passenger_findID(listaPasajeros,id);

			if(index!=-1)
			{
				aux = (Passenger*) ll_get(listaPasajeros,index);
				auxiliar=*aux;
				Passenger_printOnePassenger(&auxiliar);
				utn_getString("\n¿Esta seguro que desea editar este pasajero?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

				if(!(stricmp(respuesta,"si")))
				{
					do
					{
						switch(Passenger_menuModificar())
						{
							case 0:
								utn_getString("\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
								break;
							case 1:
								Passenger_caseNombre(listaPasajeros,index,auxiliar);
								break;
							case 2:
								Passenger_caseApellido(listaPasajeros,index,auxiliar);
								break;
							case 3:
								Passenger_casePrecio(listaPasajeros,index,auxiliar);
								break;
							case 4:
								Passenger_caseTipoPasajero(listaPasajeros, index, auxiliar);
								break;
							case 5:
								Passenger_caseCodigoVuelo(listaPasajeros, index, auxiliar);
								break;

						}
					}while(stricmp(confirmar,"si"));
					printf("Modificacion realizada con exito\n");
				}
				else
				{
					printf("Modificacion cancelada\n");
				}
			}
			else
			{
				printf("No se pudo encontrar el ID\n");
			}
		}
		else
		{
			printf("Error. Imposible realizar una modificacion\n");
		}

		return todoOK;
}

