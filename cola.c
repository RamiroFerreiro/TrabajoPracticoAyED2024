#include <stdio.h>
#include <stdlib.h>
#include "cola.h"


struct Cola{
    NodoPtr primero;
    NodoPtr ultimo;

    int contador;
};

///constructor
ColaPtr crearCola(){
    ColaPtr cola = malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;
    cola->contador = 0;

    return cola;
}

///getters
NodoPtr getPrimeroCola(ColaPtr cola){
    return cola->primero;
}
NodoPtr getUltimoCola(ColaPtr cola){
    return cola->ultimo;
}
int getContadorCola(ColaPtr cola){
    return cola->contador;
}

///setters
void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero){
    cola->primero = nuevoPrimero;
}
void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo){
    cola->ultimo = nuevoUltimo;
}

///encolar
void encolar(ColaPtr cola, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    if(cola->primero == NULL){
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
    }else{
        setSiguiente(cola->ultimo, nuevoNodo);
        cola->ultimo = nuevoNodo;
    }
    cola->contador = cola->contador + 1 ;


} //insertarUltimo

///desencolar
DatoPtr desencolar(ColaPtr cola){
    DatoPtr datoEliminar;



    if(cola->primero != NULL){
        NodoPtr nodoEliminar = cola->primero;

        cola->primero = getSiguiente(nodoEliminar);

        datoEliminar = getDato(nodoEliminar);
        free(nodoEliminar);

        cola->contador = cola->contador - 1 ;

        if(cola->primero == NULL){
            cola->ultimo = NULL;
            cola->contador = 0;
        }
    }




    return datoEliminar;
} //eliminarPrimero
