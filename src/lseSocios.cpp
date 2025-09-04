
#include "../include/lseSocios.h"

struct rep_lseSocios {
	TSocio socio;
	rep_lseSocios* sig;
};

TLSESocios crearTLSESociosVacia(){
	TLSESocios lseSocios = new rep_lseSocios;
	lseSocios->socio = NULL;
	lseSocios->sig = NULL;
	return lseSocios;
}

bool esVaciaTLSESocios(TLSESocios lseSocios){
	return (lseSocios->socio == NULL && lseSocios->sig == NULL);
}

void imprimirTLSESocios(TLSESocios lseSocios){
	printf("Lista de Socios:\n");
	while (!esVaciaTLSESocios(lseSocios) || lseSocios->socio != NULL) {
		imprimirTSocio(lseSocios->socio);
		lseSocios = lseSocios->sig;
	}
}

void liberarTLSESocios(TLSESocios &lseSocios){
    while (lseSocios != NULL) {
        TLSESocios nodo = lseSocios;        // nodo actual
        lseSocios = lseSocios->sig;              // guardar el siguiente ANTES de liberar

        // 1) liberar el contenido que guarda el nodo
        liberarTSocio(nodo->socio);      // esto a su vez libera la fecha, etc.

        // 2) liberar el propio nodo
        delete nodo;
    }
    lseSocios = NULL;                        // lista vacía segura
}


void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
	
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
    return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	return 0;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
}