#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define limit 2000
#define tamHardcodeo 5
#define Empty 0
#define Full 1
typedef struct{
		int id;
		char name [51];
		char lastname[51];
		float price;
		char flycode[10];
		int typePassenger;
		int statusflight;
		int isEmpty;
	}Passenger;
// funciones obligatorias
int initPassengers( Passenger list[], int len);
int addPassengers( Passenger list[], int len, int id, char name[],char lastname[],float price,int typePassenger, char flycode [],int statusflight);
int findPassengersById( Passenger list[], int len ,int id);
int removePassenger( Passenger list[], int len ,int id);
int sortPassengers( Passenger list[], int len ,int order);
int printPassengers( Passenger list[], int len);
int sortPassengerByCode( Passenger list[], int len ,int order);


//funciones propias
int agregarPasajero(Passenger list[], int size); //pido los datos y se los paso a add passengers para cargarlos, tambien marco una validacion en caso de que uno de los datos sea erroneo.
int buscarlibre(Passenger list[], int size);//busca un espacio libre en el array y lo manda a completar en addPassengers
int modificar(Passenger list[], int len);//se pide una id y si esta coincide con la de un pasajero encontrado en findPassengersById se llama a la funcion modificar pasajero.
void modificarPasajero( Passenger list[], int len ,int id);// se piden los datos a modificar y los sobreescribe.
int eliminarPasajero(Passenger list[], int len);//se pide una id y si esta coincide con la de un pasajero en removePassenger se elimina.
void mostrar(Passenger* pasajero);//en caso de que haya un dato cargado esta funcion lo muestra, se llama a esta funcion en printPassengers.
int hardcodeo(Passenger list[],int len);//pongo los datos hardcodeados de 5 pasajeros para mostrar en el alta forzada.
int ordenarPorApellido(Passenger list[],int len);//ordena por apellido el listado
int ordenarPorcodigo(Passenger list[],int len);//ordena por codigo el listado
int totalPrecio(Passenger list[],int len);// devuelve el total de precio
int promedioPrecios(Passenger list[],int len);//devuelve el promedio de precios
int cantPasajeros(Passenger list[],int len);//devuelve la cantidad de pasajeros que superan el promedio de precio
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max); //valida el ingreso de una cadena
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);//valida el ingreso de un flotante (float)
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);//valida el ingreso de un numero entero
