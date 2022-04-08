#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float pedirNumero(char mensaje [])
{
	float numeroIngresado;
	printf("%s",mensaje);
	scanf("%f",&numeroIngresado);
	while(numeroIngresado < 1)
	{
		printf("ingrese una cantidad de km valida");
		scanf("%f",&numeroIngresado);
	}
	return numeroIngresado;
}

float valorTarjetaDebito (float precio)
{
	float descuento;
	descuento=precio-(precio*10/100);

	return descuento;
}

float valorTarjetaCredito(float precio)
{
	float aumento;
	aumento=precio+(precio*25/100);

	return aumento;
}

float valorEnBitcoin(float precio)
{
	float valor;
	valor=precio/4606954.55;
	return valor;
}
float valorPrecioUnitario(float precio, float km)
{
	float unitario;
	unitario= precio / km;
	return unitario;
}

float valorDiferencia(float y,float z)
{
	float diferencia;
	if(y > z)
	{
		diferencia=y-z;
	}
	else
	{
		diferencia=z-y;
	}

	return diferencia;
}
void cargaForzada (void)
{
	float km;
	float y;//aerolineas
	float z;//latam
	/////////////////////
	//VARIABLES AEROLINEAS
	float debitoY;
	float creditoY;
	float bitcoinY;
	float unitarioY;
	//VARIABLES LATAM
	float debitoZ;
	float creditoZ;
	float bitcoinZ;
	float unitarioZ;
	float diferencia;

		km=7090;
		y=162965;
		z=159339;

		debitoY=valorTarjetaDebito(y);
		creditoY=valorTarjetaCredito(y);
		bitcoinY=valorEnBitcoin(y);
		unitarioY=valorPrecioUnitario(y,km);
		debitoZ=valorTarjetaDebito(z);
		creditoZ=valorTarjetaCredito(z);
		bitcoinZ=valorEnBitcoin(z);
		unitarioZ=valorPrecioUnitario(z,km);
		diferencia=valorDiferencia(y,z);

	printf("los precios de aerolineas son:\n");
	printf("en debito: %.2f \n",debitoY);
	printf("en credito: %.2f \n",creditoY);
	printf("en bitcoin: %.2f \n",bitcoinY);
	printf("el precio unitario es %.2f \n",unitarioY);
	printf("los precios de Latam son: \n");
	printf("en debito: %.2f \n",debitoZ);
	printf("en credito: %.2f \n",creditoZ);
	printf("en bitcoin: %.2f \n",bitcoinZ);
	printf("el precio unitario es %.2f \n\n",unitarioZ);
	printf("la diferencia de precios entre aerolineas y latam es: %.2f \n",diferencia);
}
