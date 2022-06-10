#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoDeVuelo[30];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr);
void Passenger_delete(Passenger* this);
//busqueda e impresion
int Passenger_findID(LinkedList* listaPasajeros, int id);
int Passenger_printOnePassenger(Passenger* this);
int Passenger_printList(LinkedList* listaPasajeros);
//ID
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
//nombre
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);
//apellido
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);
//codigoVuelo
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
//tipoPasajero
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
//precio
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);


#endif /* PASSENGER_H_ */
