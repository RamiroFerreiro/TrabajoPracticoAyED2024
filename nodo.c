#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo{
    DatoPtr dato;
    NodoPtr siguiente;
};

///CONSTRUCTOR

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){

    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;


    return nodo;
}

///GETTERS
DatoPtr getDato(NodoPtr n){
    return n->dato;
}

NodoPtr getSiguiente(NodoPtr n){

    return n->siguiente;
}

///SETTERS
void setSiguiente(NodoPtr nodo, NodoPtr nuevoNodo){
    nodo->siguiente = nuevoNodo;
}
void setDato(NodoPtr nodo, DatoPtr nuevoDato){
    nodo->dato = nuevoDato;
}

///LIBERAR NODO
void liberarNodo(NodoPtr n){
    free(n);
}


