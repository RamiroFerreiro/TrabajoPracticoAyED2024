#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED

struct MateriaAprobada;

typedef struct MateriaAprobada* AprobadaPtr;

///constructor
AprobadaPtr crearMateriaAprobada(int id, char nombreMateriaAprobada[], int nota);

///mostrarMateriaAprobada
void mostrarMateriaAprobada(AprobadaPtr aprobada);

///mostrarMateriaAprobadaDatoPtr
void mostrarMateriaAprobadaDatoPtr(void* data);

///getters
int getNota(AprobadaPtr aprobada);
char* getNombreMateriaAprobada(AprobadaPtr a);



#endif // MATERIAAPROBADA_H_INCLUDED
