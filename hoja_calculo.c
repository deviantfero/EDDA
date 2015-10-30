#include <stdio.h>
#include <stdlib.h>

typedef enum{ NUMERO, LETRA, FLOAT }tipo_dato;

struct nodo{
	void* dato;
	char columna;
	int fila;
	struct nodo* derecha;
	struct nodo* abajo;
	int flag;
};

struct nodo* crear_celda();
void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo** inicio );

int main( void ){
	struct nodo* hoja1 = crear_celda();
	hoja1->columna = 'A';
	hoja1->fila = 0;
	establecer_hoja( &hoja1, 1, 3, 1, 1, &hoja1 );
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
			nuevo->flag = NUMERO;
			break;
		case LETRA:
			nuevo->dato = malloc( 1 );
			getchar();
			printf( "Ingrese una letra: " );
			scanf( "%c", (char*)nuevo->dato );
			nuevo->flag = LETRA;
			break;
		case FLOAT:
			nuevo->dato = malloc( sizeof( float ) );
			printf( "Ingrese numeros con decimal: " );
			scanf( "%f", (float*)nuevo->dato );
			nuevo->flag = FLOAT;
			break;
		default:
			printf( "Opcion no valida!\n" );
			nuevo = crear_celda();
	}
	return nuevo;
}

void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo** inicio ){
	struct nodo* nuevo;
	if( fil - 1 > 0 ){
		nuevo->fila = 0;
		nuevo->columna = 'A' +  i;
		printf( "CELDA %c, %d\n", nuevo->columna, nuevo->fila );
		nuevo = crear_celda();
		(*cab)->derecha = nuevo;
		establecer_hoja( &(*cab)->derecha, fil - 1, col, i + 1, j, inicio );
	}else if( col - 1 > 0 ){
		nuevo->fila = j;
		nuevo->columna = 'A';
		printf( "CELDA %c, %d\n", nuevo->columna, nuevo->fila );
		nuevo = crear_celda();
		(*cab)->abajo = nuevo;
		establecer_hoja( &(*cab)->abajo, fil, col - 1, i, j + 1, inicio );
	}
	nuevo->derecha = *inicio;
	nuevo->abajo = *inicio;
	*cab = *inicio;
}
