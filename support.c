/********************************************************************
 * LIBRERIAS PARA DESGLOSAR MAS EL CONTENIDO DEL PROGRAMA           *
 * FUNCIONES PARA EL ENLACAMIENTO Y RECORRIDO DE LA HOJA DE CALCULO *
 ********************************************************************/

void establecer_fila( struct nodo** cab, int fil, int i, struct nodo* inicio ){
	struct nodo* nuevo = malloc( sizeof( struct nodo ) );
	if( fil ){
		nuevo->dato = malloc( sizeof( int ) );
		*((int*)nuevo->dato) = i + 1;
		nuevo->flag = NUMERO;
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
		nuevo->flag = LETRA;
		(*cab)->derecha = nuevo;
		(*cab)->derecha->abajo = (*cab)->derecha;
		establecer_columna( &(*cab)->derecha, col - 1, j + 1, inicio );
	}
	if( !(*cab)->derecha )
		(*cab)->derecha = inicio;	
}

void insertar_columna( char col, struct nodo** cab, struct nodo* inicio, struct nodo** nuevo ){
	if( *((char*)(*cab)->derecha->dato) < col )
		insertar_columna( col, &(*cab)->derecha, inicio, nuevo );
	else{
		(*cab)->derecha->abajo = *nuevo;
		(*nuevo)->abajo = (*cab)->derecha;
		(*cab) = inicio;
	}
}

void insertar_fila( int fil, struct nodo** cab, struct nodo* inicio, struct nodo** nuevo ){
	if( *((int*)(*cab)->abajo->dato) < fil )
		insertar_fila( fil, &(*cab)->abajo, inicio, nuevo );
	else{
		(*cab)->abajo->derecha = *nuevo;
		(*nuevo)->derecha = (*cab)->abajo;
		(*cab) = inicio;
	}
}
