#include <stdio.h>
#include <stdlib.h>
#include "structures.c"
#include "support.c"

struct nodo* crear_celda();
void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo* inicio );
void insertar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio );
void mostrar_guia( struct nodo** cab, struct nodo* inicio );
void mostrar_hoja( struct nodo** cab, struct nodo* iniciox, struct nodo* inicioy );

int main( void ){
	struct nodo* hoja1 = malloc( sizeof( struct nodo ) );
	hoja1->dato = malloc( sizeof( int ) );
	*((int*)hoja1->dato) = 0;
	establecer_hoja( &hoja1, 6, 6, 0, 0, hoja1 );
//	insertar_celda( 'A', 0, &hoja1, hoja1 );
//	insertar_celda( 'A', 1, &hoja1, hoja1 );
	printf("%6s", "");
	mostrar_hoja( &hoja1, hoja1, hoja1 );
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

void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo* inicio ){
	establecer_columna( cab, col, j, inicio );
	*cab = inicio;
	establecer_fila( cab, fil, i, inicio );
	*cab = inicio;
}

void insertar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio ){
	struct nodo* nuevo = crear_celda();
	insertar_columna( col, cab, inicio, &nuevo );
	insertar_fila( fil, cab, inicio, &nuevo );
}

void mostrar_hoja( struct nodo** cab, struct nodo* iniciox, struct nodo* inicioy ){
	if( (*cab)->derecha != iniciox ){
		switch( (*cab)->derecha->flag ){
			case NUMERO:
				printf( "%-1s%d%2s|", "", *((int*)(*cab)->derecha->dato), "" );
				break;
			case LETRA:
				printf( "%-2s%c%2s|", "", *((char*)(*cab)->derecha->dato), "" );
				break;
			case FLOAT:
				printf( "%-2s%3.2f%2s|", "", *((float*)(*cab)->derecha->dato), "" );
				break;
		}
		mostrar_hoja( &(*cab)->derecha, iniciox, inicioy );
	}else if( (*cab)->derecha->abajo != inicioy ){
		printf( "\n -----\n|%-2s%d%2s|", "", *((int*)(*cab)->derecha->dato),"" );
		mostrar_hoja( &(*cab)->derecha->abajo, iniciox->abajo, inicioy );
	}
}
