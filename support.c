void establecer_fila( struct nodo** cab, int fil, int i, struct nodo** inicio ){
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( fil ){
		nuevo->dato = malloc( sizeof( int ) );
		*((int*)nuevo->dato) = i;
		(*cab)->abajo = nuevo;
		establecer_fila( &(*cab)->abajo, fil - 1, i + 1, inicio );
	}
}

void establecer_columna( struct nodo** cab, int col, int j, struct nodo** inicio ){
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( col ){
		nuevo->dato = malloc( sizeof( char ) );
		*((char*)nuevo->dato) = 'A' + j;
		(*cab)->derecha = nuevo;
		establecer_columna( &(*cab)->derecha, col - 1, j + 1, inicio );
	}
}

void mostrar_columnas( struct nodo** cab ){
	if( (*cab)->derecha && (*cab)->derecha != (*cab) ){
		printf( "|%-2s%c%2s", "", *((char*)(*cab)->derecha->dato), "" );
		mostrar_columnas( &(*cab)->derecha );
	}
}

void mostrar_filas( struct nodo** cab ){
	if( (*cab)->abajo && (*cab)->abajo != (*cab) ){
		printf( "\n -----\n|%-2s%d%2s|", "", *((int*)(*cab)->abajo->dato),"" );
		mostrar_filas( &(*cab)->abajo );
	}
}
