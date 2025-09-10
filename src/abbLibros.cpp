
#include "../include/abbLibros.h"

struct rep_abbLibros {
    TLibro libro;
    rep_abbLibros *izq;
    rep_abbLibros *der;
};

TABBLibros crearTABBLibrosVacio(){
    return NULL;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
    if (abbLibros == NULL) {
        abbLibros = new rep_abbLibros;
        abbLibros->libro = libro; 
        abbLibros->izq = NULL;
        abbLibros->der = NULL;
    } else if (isbnTLibro(libro) < isbnTLibro(abbLibros->libro)) {
        insertarLibroTABBLibros(abbLibros->izq, libro);
    } else {
        insertarLibroTABBLibros(abbLibros->der, libro);
    }
}

void imprimirTABBLibros(TABBLibros abbLibros){
    if (abbLibros == NULL) return;
    imprimirTABBLibros(abbLibros->izq);
    imprimirTLibro(abbLibros->libro);
    imprimirTABBLibros(abbLibros->der);
}

void liberarTABBLibros(TABBLibros &abbLibros){
    if (abbLibros == NULL) return;
    liberarTABBLibros(abbLibros->izq);
    liberarTABBLibros(abbLibros->der);
    liberarTLibro(abbLibros->libro);
    delete abbLibros;
    abbLibros = NULL;
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (abbLibros == NULL) return false;
    if (isbn == isbnTLibro(abbLibros->libro)) {
        return true;
    } else if (isbn < isbnTLibro(abbLibros->libro)) {
        return existeLibroTABBLibros(abbLibros->izq, isbn);
    } else if (isbn > isbnTLibro(abbLibros->libro)) {
        return existeLibroTABBLibros(abbLibros->der, isbn);
    }
    return false;
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (isbn == isbnTLibro(abbLibros->libro)) {
        return abbLibros->libro;
    } else if (isbn < isbnTLibro(abbLibros->libro)) {
        return obtenerLibroTABBLibros(abbLibros->izq, isbn);
    } else if (isbn > isbnTLibro(abbLibros->libro)) {
        return obtenerLibroTABBLibros(abbLibros->der, isbn);
    }
    return NULL;
}

nat alturaTABBLibros(TABBLibros abbLibros){
    return 0;
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    return NULL;
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn){
}

int cantidadTABBLibros(TABBLibros abbLibros){
    return 0;
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    return NULL;
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    return NULL;
}