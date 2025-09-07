
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
	while (lseSocios != NULL && lseSocios->socio != NULL) {
		imprimirTSocio(lseSocios->socio);
		lseSocios = lseSocios->sig;
	}
}

void liberarTLSESocios(TLSESocios &lseSocios){
    if (lseSocios->sig != NULL) {
		liberarTLSESocios(lseSocios->sig);                         
    }
	if(lseSocios->socio != NULL){
		liberarTSocio(lseSocios->socio);
	}
	delete lseSocios;
    lseSocios = NULL;                     
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
	if(lseSocios->socio == NULL){
		lseSocios->socio = socio;
		lseSocios->sig = NULL;
	}
	else{
		if(compararTFechas(fechaAltaTSocio(socio),fechaAltaTSocio(lseSocios->socio)) >= 0){
			if(lseSocios->sig == NULL){
				TLSESocios nuevo = new rep_lseSocios;
				nuevo->socio = socio;
				nuevo->sig = NULL;
				lseSocios->sig = nuevo;
				delete nuevo;
				nuevo = NULL;
			}
			else{
				insertarTLSESocios(lseSocios->sig, socio);
			}
		}
		else{
			TLSESocios nuevo = new rep_lseSocios;
			nuevo->socio = lseSocios->socio;
			nuevo->sig = lseSocios->sig;
			lseSocios->socio = socio;
			lseSocios->sig = nuevo;
			delete nuevo;
			nuevo = NULL;
		}	
	}
}
bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (lseSocios == NULL){return false;}
	while((lseSocios != NULL) && (ciTSocio(lseSocios->socio) != ci)){
		lseSocios = lseSocios->sig;
	}
	return (ciTSocio(lseSocios->socio) == ci);
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
	if (!(existeSocioTLSESocios(lseSocios, ci) != true)){return NULL;}
	while(ciTSocio(lseSocios->socio) == ci){
		lseSocios = lseSocios->sig;
	}
    return lseSocios->socio;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	if (lseSocios == NULL){return 0;}
	else return (1 + cantidadTLSESocios(lseSocios->sig));
}


TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	nat x = n;
	if ((cantidadTLSESocios(lseSocios) < x)|| (n < 1)){return NULL;}
	int i=1;
	while (i<n){
		lseSocios = lseSocios->sig;
		i++;
	}
	return lseSocios->socio;
}



void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
}