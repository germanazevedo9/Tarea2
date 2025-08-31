#include "../include/socio.h"

struct rep_socio {
    int ciSocio;
    char nombreSocio[MAX_NOMBRE_SOCIO];
    char apellidoSocio[MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    struct rep_generos{
        int genfavs[MAX_GENEROS_FAVORITOS];
        int tope;
    }generos;
};
 
TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta){
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ciSocio = ci;
    strcpy(nuevoSocio->nombreSocio,nombre);
    strcpy(nuevoSocio->apellidoSocio,apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta,mesAlta,anioAlta);
    nuevoSocio->generos.tope=0;
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio){
    printf("Socio %d %s %s\n", socio->ciSocio,":",socio->nombreSocio,socio->apellidoSocio);
    printf("Fecha de alta: " );
    imprimirTFecha(socio->fechaAlta);
    printf("Géneros favoritos: ");
    for (int i=0;i<socio->generos.tope;i++){
        printf("%d\n",socio->generos.genfavs[i]);
    };
}

void liberarTSocio(TSocio &socio){
}

int ciTSocio(TSocio socio){
    return 0;
}

char* nombreTSocio(TSocio socio){
    return NULL;
}

char* apellidoTSocio(TSocio socio){
    return NULL;
}

TFecha fechaAltaTSocio(TSocio socio){
    return NULL;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    return 0;
}

TSocio copiarTSocio(TSocio socio){
    return NULL;
}
