#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

struct lista;

typedef struct Lista* ListaPtr;


///Constructor
ListaPtr crearLista();

///Getters y setters
ListaPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

///Mostrar lista
void mostrarListaGenerico(ListaPtr lista, void (*mostrarFuncion)(DatoPtr));

///Destructor lista
void liberarLisa(ListaPtr lista);

///inserciones
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);
void insertarOrdenado(ListaPtr lista, DatoPtr dato, int (*compararMenorIgual)(DatoPtr, DatoPtr));

///Obtenciones
int obtenerTamanio(ListaPtr lista);
DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

///ELIMINACIONES
DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

///duplicar lista
ListaPtr duplicarLista(ListaPtr lista);

///Ordenamiento generico
void ordenamientoBurbujeoGenerico(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));
ListaPtr ordenarListaCopia(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr));

///Busqueda secuencial
int busquedaSecuencial(ListaPtr lista, DatoPtr personaBuscada, int (*funcionIgualar)(DatoPtr, DatoPtr));

///DESTRUCTOR LISTA
void liberarLista(ListaPtr lista);

///obtenerSumatoria
int sumar(ListaPtr lista);

#endif // LISTA_H_INCLUDED
