#include <stdio.h>
#include <stdlib.h>
#include "structures.c"
#include "support.c"

struct nodo* crear_celda();
void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo** inicio );
void mostrar_guia( struct nodo** cab, struct nodo** inicio );

int main( void ){
	struct nodo* hoja1 = malloc( sizeof( struct nodo ) );
	establecer_hoja( &hoja1, 5, 3, 0, 0, &hoja1 );
	printf("%6s", "");
	mostrar_guia( &(hoja1), &(hoja1) );
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


//esto hace el margen basico de la hoja, donde se ubicaran el resto
//los hice nodos para que en la funcion de imprimir solo imprimo el dato
//y luego imprimo los adyacentes!
void establecer_hoja( struct nodo** cab, int fil, int col, int i, int j, struct nodo** inicio ){
	establecer_columna( cab, col, j, inicio );
	*cab = *inicio;
	establecer_fila( cab, fil, i, inicio );
	*cab = *inicio;
}

void mostrar_guia( struct nodo** cab, struct nodo** inicio ){
	mostrar_columnas( cab );
	*cab = *inicio;
	mostrar_filas( cab );
	*cab = *inicio;
}
