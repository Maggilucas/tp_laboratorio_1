/*
 ============================================================================
 Name        : tp.c
 Author      : lucas maggi
 Version     :
 Copyright   : Your copyright notice
 Description : tp 1

 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.

Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void)
{
	setbuf(stdout, NULL);

	int opcion; //para el menu.
	float km;
	float y;//aerolineas
	float z;//latam
	/////////////////////
	//VARIABLES AEROLINEAS
	float debitoY;//variable para tarjeta de debito
	float creditoY;//variable para tarjeta de credito
	float bitcoinY;//variable para precio bitcoin
	float unitarioY;
	//VARIABLES LATAM
	float debitoZ;//variable para tarjeta de debito
	float creditoZ;//variable para tarjeta de credito
	float bitcoinZ;//variable para precio bitcoin
	float unitarioZ;//precio viaje /km;
	////////////////////////
	float diferencia;// diferencia de precios;
	



	do{
	printf("ingrese la opcion que quiera\n");
	printf("1 ingresar km \n");
	printf("2 ingresar Precio de Vuelos:\n");
	printf("3 calcular costos\n");
	printf("4 informe de resultados\n");
	printf("5 carga forzada de datos\n");
	printf("6 salir \n");
	scanf("%d",&opcion);


		switch(opcion)
		{
		case 1:
				km=pedirNumero("ingrese los km \n");
		break;
		case 2:
				y=pedirNumero("ingrese precio aerolineas\n");
				z=pedirNumero("ingrese precio latam\n");
		break;
		case 3:
			if(y==0 || km==0)
			{
				printf("no se a ingresado ningun dato,porfavor ingrese km y precios.\n");
			}
			else
			{
				debitoY=valorTarjetaDebito(y);
				creditoY=valorTarjetaCredito(y);
				bitcoinY=valorEnBitcoin(y);
				unitarioY=valorPrecioUnitario(y,km);
			}
			if(z == 0 || km == 0)
			{
				printf("no se a ingresado ningun dato,porfavor ingrese km y precios.\n");
			}
			else
			{
				debitoZ=valorTarjetaDebito(z);
				creditoZ=valorTarjetaCredito(z);
				bitcoinZ=valorEnBitcoin(z);
				unitarioZ=valorPrecioUnitario(z,km);
			}
			diferencia=valorDiferencia(y,z);

		break;
		case 4:
			if(y==0 || z==0 || km==0)
			{
				printf("no se ingresaron km o precios, ingreselos e intente nuevamente\n");
			}
			else
			{
				printf("los precios de aerolineas son:\n");
				printf("en debito (descuento del 10%): %.2f \n",debitoY);
				printf("en credito (interes del 25%): %.2f \n",creditoY);
				printf("en bitcoin: %.2f \n",bitcoinY);
				printf("el precio unitario es %.2f \n",unitarioY);
				printf("los precios de Latam son: \n");
				printf("en debito(descuento del 10%): %.2f \n",debitoZ);
				printf("en credito(intereses del 25%): %.2f \n",creditoZ);
				printf("en bitcoin: %.2f \n",bitcoinZ);
				printf("el precio unitario es %.2f \n\n",unitarioZ);
				printf("la diferencia de precios entre aerolineas y latam es: %.2f \n",diferencia);
			}
		break;
		case 5:
			   cargaForzada();
		break;
		case 6:
				printf("gracias por usar la app \n");
		break;
		default:
				printf("ingrese una opcion correcta\n");
		break;
			}
				}while(opcion != 6);

	return 0;
}
