#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

///1    STRUCT
///2    PUNTERO A NODO
///3    PUNTERO A DATO PTR
///3    CONSTRUCTOR
///4    GETTERS
///5    SETTERS
///6    DESTRUCTOR

struct Nodo;

typedef struct Nodo* NodoPtr;

typedef void* DatoPtr;


NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

NodoPtr getSiguiente(NodoPtr n);
DatoPtr getDato(NodoPtr n);

void setSiguiente(NodoPtr nodo, NodoPtr nuevoNodo);
void setDato(NodoPtr nodo, DatoPtr nuevoDato);

void liberarNodo(NodoPtr n);



#endif // NODO_H_INCLUDED
