#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "lista.h"
#include "cola.h"
#include "inscripto.h"

struct Materia;

typedef struct Materia * MateriaPtr;

///constructorCompleto
MateriaPtr crearMateria(int id, char nombreMateria[], int cupo);

///mostrarMateria
void mostrarMateria(MateriaPtr materia);

///mostrarMateriaDatoPtr
void mostrarMateriaDatoPtr(void* dato);

///agregarInscriptos
void agregarInscripto(MateriaPtr materia, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr));

///eliminarInscripto
void eliminarInscripto(MateriaPtr materia, char nombre[]);

///actualizarColas
void actualizarColas(ListaPtr listaSistema);

///actualizarCola
void actualizarCola(MateriaPtr materia, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr));

///getters
ListaPtr getListadoInscriptos(MateriaPtr materia);
ListaPtr getListadoAux(MateriaPtr materia);
ColaPtr getColaMateria(MateriaPtr materia);
int getCupo(MateriaPtr materia);

#endif // MATERIA_H_INCLUDED
