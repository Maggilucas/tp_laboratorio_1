int SizeString(char string[]); // convierte toda la cadena en minuscula excepto la primer letra
int isChar(char string[]);//verifica si la cadena es de tipo
int getString(char string[], int tam);//verifica en mi cadena si tengo un enter y convierte mi \n en mi final \0
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos,char input[]);//paso un mensaje pidiendo un input de tipo cadena, si encuentra un error me descuenta en los reintentos y envia el mensaje de error
int utn_getStringInt(char mensaje[], char mensajeError[], int tam, int reintentos, char input[]);//revisa si la cadena tiene incluido numeros
int isInt(char resultado[]);// revisa si la cadena tiene incluido numeros
int getInt(int* input);//revisa que sea cadena de numeros tipo int
int utn_getInt(char mensaje[],char mensajeError[],int min,int max,int reintentos,int* input);//funcion que imprime un mensaje solicitando un int, en caso de error en las validaciones imprime el mensaje de error y va descontando los reintentos
int isFloat(char resultado[]);//revisa si es numero y tiene '.' para ser de tipo float
int getFloat(float* input);//revisa si es una cadena de flotantes
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);//funcion que imprime un mensaje solicitando un float, en caso de error en las validaciones imprime el mensaje de error y va descontando los reintentos
