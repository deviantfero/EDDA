/********************************************************************
 * LIBRERIAS PARA DESGLOSAR MAS EL CONTENIDO DEL PROGRAMA           *
 * FUNCIONES PARA EL ENLACAMIENTO Y RECORRIDO DE LA HOJA DE CALCULO *
 ********************************************************************/
void establecer_fila( struct nodo** cab, int fil, int i, struct nodo* inicio ){
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( fil ){
		nuevo->dato = malloc( sizeof( int ) );
		*((int*)nuevo->dato) = i + 1;
		(*cab)->abajo = nuevo;
		(*cab)->abajo->derecha = (*cab)->abajo;
		establecer_fila( &(*cab)->abajo, fil - 1, i + 1, inicio );
	}
	if( !(*cab)->abajo )
		(*cab)->abajo = inicio;
}

void establecer_columna( struct nodo** cab, int col, int j, struct nodo* inicio ){
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( col ){
		nuevo->dato = malloc( sizeof( char ) );
		*((char*)nuevo->dato) = 'A' + j;
		(*cab)->derecha = nuevo;
		(*cab)->derecha->abajo = (*cab)->derecha;
		establecer_columna( &(*cab)->derecha, col - 1, j + 1, inicio );
	}
	if( !(*cab)->derecha )
		(*cab)->derecha = inicio;	
}

void mostrar_columnas( struct nodo** cab, struct nodo* inicio ){
	if( (*cab)->derecha && (*cab)->derecha != inicio ){
		printf( "|%-2s%c%2s", "", *((char*)(*cab)->derecha->dato), "" );
		mostrar_columnas( &(*cab)->derecha, inicio );
	}
}

void mostrar_filas( struct nodo** cab, struct nodo* inicio ){
	if( (*cab)->abajo && (*cab)->abajo != inicio ){
		printf( "\n -----\n|%-2s%d%2s|", "", *((int*)(*cab)->abajo->dato),"" );
		mostrar_filas( &(*cab)->abajo, inicio );
	}
}
