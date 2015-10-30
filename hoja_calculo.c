#include <stdio.h>
#include <stdlib.h>

typedef enum{ NUMERO, LETRA, FLOAT }tipo_dato;

struct nodo{
	void* dato;
	int columna;
	char fila;
	struct nodo* derecha;
	struct nodo* izquierda;
	int flag;
};

struct nodo* crear_celda();

int main( void ){
	struct nodo* hoja1 = crear_celda();
	return 0;
}

struct nodo* crear_celda(){
	int flag_01; //Se puede tomar como entero y usar en el switch como enum
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	printf( "Que tipo de dato desea ingresar? :" );
	printf( "\n\t0.Numero, 1.Letra, 2.Float\n" );
	scanf( "%d", &flag_01 );
	switch( flag_01 ){
		case NUMERO:
			nuevo->dato = malloc( sizeof(int) );
			printf( "Ingrese su numero: " );
			scanf( "%d", (int*)nuevo->dato );
			break;
		case LETRA:
			nuevo->dato = malloc( 1 );
			getchar();
			printf( "Ingrese una letra: " );
			scanf( "%c", (char*)nuevo->dato );
			break;
		case FLOAT:
			nuevo->dato = malloc( sizeof( float ) );
			printf( "Ingrese numeros con decimal: " );
			scanf( "%f", (float*)nuevo->dato );
			break;
		default:
			printf( "Opcion no valida!\n" );
			nuevo = crear_celda();
	}
	return nuevo;
}
