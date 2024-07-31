#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodo.h"

struct Cola;

typedef struct Cola* ColaPtr;

///constructor
ColaPtr crearCola();

///getters
NodoPtr getPrimeroCola(ColaPtr cola);
NodoPtr getUltimoCola(ColaPtr cola);
int getContadorCola(ColaPtr cola);

///setters
void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero);
void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo);

///encolar
void encolar(ColaPtr cola, DatoPtr dato); //insertarUltimo

///desencolar
DatoPtr desencolar(ColaPtr cola); //eliminarPrimero



#endif // COLA_H_INCLUDED
