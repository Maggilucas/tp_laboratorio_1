#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//ID
int ObtenerMayorId (LinkedList* listaPasajeros);
int Passenger_comparaPorId(void* Pasajero1, void* Pasajero2);
//verificaciones
int Passenger_setVerifyInt(Passenger* this,int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo);
int Passenger_setVerifyChar(Passenger* this,char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr);
int Passenger_getVerify(Passenger* this, int* id, char* nombre,char* apellido, int* tipoPasajero, float* precio,char* codigoVuelo);
//nombre
int Passenger_caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modificaNombre(LinkedList* listaPasajeros, int index, char* auxNombre);
int Passenger_comparaPorNombre(void* Pasajero1, void* Pasajero2);
//apellido
int Passenger_caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modificaApellido(LinkedList* listaPasajeros, int index, char* auxApellido);
int Passenger_comparaPorApellido(void* Pasajero1, void* Pasajero2);
//precio
int Passenger_casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modificaPrecio(LinkedList* listaPasajeros, int index, float auxPrecio);
int Passenger_comparaPorPrecio(void* Pasajero1, void* Pasajero2);
//tipo de pasajero
int Passenger_caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modificaTipoPasajero(LinkedList* listaPasajeros, int index, int auxTipo);
int Passenger_comparaPorTipoPasajero(void* Pasajero1, void* Pasajero2);
//codigo de vuelo
int Passenger_caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);
int Passenger_modificaCodigoVuelo(LinkedList* listaPasajeros, int index, char* auxCodigo);
int Passenger_comparaPorCodigoVuelo(void* Pasajero1, void* Pasajero2);
//ABM
int Passenger_add(LinkedList* listaPasajeros, int* id);
int Passenger_remove(LinkedList* listaPasajeros);
int Passenger_modificar(LinkedList* listaPasajeros);
