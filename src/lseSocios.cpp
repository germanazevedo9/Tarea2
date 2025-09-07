
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
    if (lseSocios != NULL) {
		liberarTLSESocios(lseSocios->sig);                         
    }
	delete lseSocios;
    lseSocios = NULL;                     
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){

}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (lseSocios == NULL)return;
	while((lseSocios != NULL) && (ciTSocio(lseSocios->socio) != ci)){
		lseSocios = lseSocios->sig;
	}
	return (ciTSocio(lseSocios->socio) == ci);
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (!(existeSocioTLSESocios(lseSocios, ci) != true))return;
	while(ciTSocio(lseSocios->socio) == ci){
		lseSocios = lseSocios->sig;
	}
    return lseSocios->socio;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	if (lseSocios == NULL)return 0;
	else return (1 + cantidadTLSESocios(lseSocios->sig));
}


TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	if ((n>cantidadTLSESocios(lseSocios))|| n < 1)return;
	int i=1;
	while (i<n){
		lseSocios = lseSocios->sig;
		i++;
	}
	return lseSocios->socio;
}



void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
}