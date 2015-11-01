#include <stdio.h>
#include <stdlib.h>
#include "structures.c"
#include "support.c"

struct nodo* crear_celda();
void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo* inicio );
void insertar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio );
void borrar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio );
void mostrar_hoja( struct nodo** cab, struct nodo* iniciox, struct nodo* inicioy, char cont );

int main( void ){
	struct nodo* hoja1 = malloc( sizeof( struct nodo ) );
	hoja1->dato = malloc( sizeof( int ) );
	*((int*)hoja1->dato) = 0;
	establecer_hoja( &hoja1, 5, 5, 0, 0, hoja1 );
	insertar_celda( 'E', 1, &hoja1, hoja1 );
	insertar_celda( 'B', 4, &hoja1, hoja1 );
	mostrar_hoja( &hoja1, hoja1, hoja1, 'A' );
	borrar_celda( 'B', 4, &hoja1, hoja1 );
	mostrar_hoja( &hoja1, hoja1, hoja1, 'A' );
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
	establecer_fila( cab, fil, i, inicio );
}

void insertar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio ){
	struct nodo* nuevo = crear_celda();
	nuevo->columna = col;
	nuevo->fila = fil;
	insertar_fila( fil, &(*cab)->abajo, inicio->abajo, &nuevo );
	insertar_columna( col, &(*cab)->derecha, inicio->derecha, &nuevo );
}

void borrar_celda( char col, int fil, struct nodo** cab, struct nodo* inicio ){
	if( encontrar_columna( col, fil, cab, *cab )  ){
		borrar_fila( col, fil, &(*cab)->abajo, inicio );
		borrar_columna( col, fil, &(*cab)->derecha, inicio );
	}else
		printf( "La celda seleccionada no tiene ningun contenido\n" );
}

void mostrar_hoja( struct nodo** cab, struct nodo* iniciox, struct nodo* inicioy, char cont ){
	if( (*cab)->fila== 0 && (*cab)->columna == 0 )
		printf("%5s|", "");
	for( char aux = cont; cont < (*cab)->derecha->columna; cont++ )
		printf( "%5s|","" );
	if( (*cab)->derecha != iniciox ){
		switch( (*cab)->derecha->flag ){
			case NUMERO:
				printf( "%4d |", *((int*)(*cab)->derecha->dato) );
				break;
			case LETRA:
				printf( "%4c |", *((char*)(*cab)->derecha->dato) );
				break;
			case FLOAT:
				printf( "%4.2f |", "", *((float*)(*cab)->derecha->dato), "" );
				break;
		}
		mostrar_hoja( &(*cab)->derecha, iniciox, inicioy, cont + 1 );
	}else if( (*cab)->derecha->abajo != inicioy ){
		printf( "\n ----\n|%3d |", *((int*)(*cab)->derecha->dato) );
		mostrar_hoja( &(*cab)->derecha->abajo, iniciox->abajo, inicioy, 'A' );
	}else{
		printf( "\n\n" );
	}
}
