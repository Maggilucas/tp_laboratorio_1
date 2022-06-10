#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Menus.h"
#include "funciones.h"
#include "ABM.H"
#define REALIZADO 1
#define NO_REALIZADO 0
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	char confirmar[4];
	int opcion = 0;
	int flagTxt = NO_REALIZADO;
	int flagBin = NO_REALIZADO;
	int flagSaveTxt = NO_REALIZADO;
	int flagSaveBin = NO_REALIZADO;
	int id=1;
	strcpy(confirmar,"no");
	LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	Menu();
    	scanf("%d",&opcion);
        switch(opcion)
        {
		case 1:
		if(ll_isEmpty(listaPasajeros) || (flagTxt==NO_REALIZADO && flagBin==NO_REALIZADO))
		{
			printf("\nElegir el archivo a cargar: \n");
			utn_getInt("\n1. Cargar lista original. \n2. Cargar lo ultimo guardado. \n","\nRespuesta invalida, ingrese [1/2]\n",1,2,3,&opcion);
			if(opcion==1)
			{
				if(!controller_loadFromText("data.csv", listaPasajeros))
				{
					flagTxt=REALIZADO;
				}
				else
				{
					flagTxt=NO_REALIZADO;
				}
			}
			else
			{
				if(!controller_loadFromText("data2.csv", listaPasajeros))
				{
					flagTxt=REALIZADO;
				}
				else
				{
					flagTxt=NO_REALIZADO;
				}
			}

		}
		else
		{
			printf("No puedes cargar el archivo dos veces");
		}
		break;
		case 2:
		if(ll_isEmpty(listaPasajeros) || (flagBin==NO_REALIZADO && flagTxt==NO_REALIZADO))
		{
			if(!controller_loadFromBinary("data.bin",listaPasajeros))
			{
				flagBin=REALIZADO;
			}
			else
			{
				flagBin=NO_REALIZADO;
			}
		}
		else
		{
			printf("No puedes cargar el archivo dos veces");
		}
		break;
		case 3:
		if(!controller_addPassenger(listaPasajeros,&id))
		{
			controller_saveAsTextID("id.csv",listaPasajeros,id);
		}
		break;
		case 4:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_editPassenger(listaPasajeros);
		}
		else
		{
			printf("No hay Pasajeros para modificar");
		}
		break;
		case 5:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_removePassenger(listaPasajeros);
		}
		else
		{
			printf("No hay Pasajeros para dar de baja");
		}
		break;
		case 6:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_ListPassenger(listaPasajeros);
		}
		else
		{
			printf("No hay Pasajeros para mostrar");
		}
		break;
		case 7:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_sortPassenger(listaPasajeros);
		}
		else
		{
			printf("No hay Pasajeros para mostrar");
		}
		break;
		case 8:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_saveAsText("data2.csv",listaPasajeros);
			controller_saveAsTextID("id.csv",listaPasajeros,id);
			flagSaveTxt=REALIZADO;
		}
		else
		{
			printf("No hay Pasajeros para guardar");
		}
		break;
		case 9:
		if(!ll_isEmpty(listaPasajeros))
		{
			controller_saveAsBinary("data.bin",listaPasajeros);
			controller_saveAsTextID("id.csv",listaPasajeros,id);
			flagSaveBin=REALIZADO;
		}
		else
		{
			printf("No hay Pasajeros para guardar");
		}
		break;
		case 10:
		if((flagSaveTxt==NO_REALIZADO) && (flagSaveBin==NO_REALIZADO))
		{
			utn_getString("\n¿Esta seguro que desea salir sin guardar?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,confirmar);
			if(stricmp(confirmar,"si"))
			{
				utn_getInt("\n1. Guardar modo texto\n2. Guardar modo binario\n","\nRespuesta invalida, ingrese [1/2]\n",1,2,3,&opcion);
				if(opcion==1)
				{
					controller_saveAsText("data2.csv",listaPasajeros);
					strcpy(confirmar,"si");
				}
				else
				{
					controller_saveAsBinary("data.bin",listaPasajeros);
					strcpy(confirmar,"si");
				}
			}
		}
		else
		{
			strcpy(confirmar,"si");
		}

		break;
        }
    }while(stricmp(confirmar,"si"));
    printf("Gracias por utilizar nuestro servicio");
    return 0;
}

