#ifndef GUARANI_H_INCLUDED
#define GUARANI_H_INCLUDED
#include "lista.h"
#include "materia.h"

struct Guarani;

typedef struct Guarani* GuaraniPtr;

///constructor
GuaraniPtr crearGuarani();

///mostrarSistema
void mostrarGuarani(GuaraniPtr g);

///getters
ListaPtr getListadoMaterias(GuaraniPtr g);




#endif // GUARANI_H_INCLUDED
