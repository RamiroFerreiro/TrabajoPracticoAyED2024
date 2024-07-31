#ifndef INSCRIPTO_H_INCLUDED
#define INSCRIPTO_H_INCLUDED
#include "lista.h"
#include "materia.h"
#include "materiaAprobada.h"

struct Inscripto;

typedef struct Inscripto* InscriptoPtr;

///constructorCompleto
InscriptoPtr crearInscripto(int id, char nombreInscripto[]);

///mostrarInscripto
void mostrarInscripto(InscriptoPtr inscripto);

///mostrarInscriptoDatoPtr
void mostrarInscriptoDatoPtr(void * data);

///agregarMateriaAprobada
void agregarAprobada(ListaPtr listaSis, InscriptoPtr inscripto, DatoPtr dato);

///calcularPromedio
float calcularPromedio(InscriptoPtr inscripto);

///compararInscriptos
int compararInscriptosDatoPtr(void* data1, void* data2);

///compararInscriptosIgualIgual
int compararInscriptosIgualIgualDatoPtr(void* data1, void* data2);

///getters
ListaPtr getListadoMateriasAprobadas(InscriptoPtr i);
char* getNombreInscripto(InscriptoPtr i);

#endif // INSCRIPTO_H_INCLUDED
