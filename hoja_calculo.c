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
void mostrar_guia( int fil_init, char col_init, int fil_fin, char col_fin, struct nodo* cab );

int main( void ){
	struct nodo* hoja1 = malloc( sizeof( struct nodo ) );
	hoja1->derecha = NULL;
	hoja1->abajo = NULL;
	establecer_hoja( &hoja1, 3, 2, 0, 0, &hoja1 );
	//mostrar_guia( 0, 'A', 4, 'D', hoja1 );
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
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( fil ){
		nuevo->dato = malloc( sizeof( int ) );
		*((int*)nuevo->dato) = i;
		printf( "FILA %d\n", *((int*)nuevo->dato) );
		(*cab)->derecha = nuevo;
		establecer_hoja( &(*cab)->derecha, fil - 1, col, i + 1, j, inicio );
	}else if( col ){
		nuevo->dato = malloc( sizeof( char ) );
		*((char*)nuevo->dato) = 'A' + j;
		printf( "COLUMNA %c\n", *((char*)nuevo->dato));
		(*cab)->abajo = nuevo;
		establecer_hoja( &(*cab)->abajo, fil, col - 1, i, j + 1, inicio );
	}
	nuevo->derecha = *inicio;
	nuevo->abajo = *inicio;
	*cab = *inicio;
}

void mostrar_guia( int fil_init, char col_init, int fil_fin, char col_fin, struct nodo* cab ){
	struct nodo* aux = cab;
	printf("%6s", "");
	for( char i = 'A'; i <= col_fin; i++ )
		printf( "|%-2s%c%2s", "", i, "" );
	printf( "|\n" );
	for( int i = 0; i <= fil_fin; i++ ){
		printf( " -----\n|%-2s%d%2s|", "", i,"" );
		if( aux ){
			switch( aux->flag ){
				case NUMERO:
					printf( "%-2s%d%2s|", "", *((int*)aux->dato), "" );
					aux = aux->derecha;
					break;
				case LETRA:
					printf( "%-2s%c%2s|", "", *((char*)aux->dato), "" );
					aux = aux->derecha;
					break;
				case FLOAT:
					printf( "%-2s%d%2s|", "", *((float*)aux->dato), "" );
					aux = aux->derecha;
					break;
			}
		}else
			break;
	}
	printf( "\n -----" );
}
