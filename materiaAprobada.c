#include <stdio.h>
#include <stdlib.h>
#include "materiaAprobada.h"


struct MateriaAprobada{

    int idMateriaAprobada;
    char nombreMateriaAprobada[20];
    int nota;

};
///constructor
AprobadaPtr crearMateriaAprobada(int id, char nombreMateriaAprobada[], int  nota){
    AprobadaPtr aprobada = malloc(sizeof(struct MateriaAprobada));

    aprobada->idMateriaAprobada = id;
    strcpy(aprobada->nombreMateriaAprobada, nombreMateriaAprobada);
    aprobada->nota = nota;

    return aprobada;
}

///mostrarMateriaAprobada
void mostrarMateriaAprobada(AprobadaPtr aprobada){
    printf("\n----------APROBADA---------\n");
    printf("ID --> %d\n", aprobada->idMateriaAprobada);
    printf("NOMBRE --> %s\n", aprobada->nombreMateriaAprobada);
    printf("NOTA --> %d\n", aprobada->nota);

}

///mostrarMateriaAprobadaDatoPtr
void mostrarMateriaAprobadaDatoPtr(void* data){
    AprobadaPtr a1 = *(AprobadaPtr*) data;
    mostrarMateriaAprobada(a1);
}

///getters
int getNota(AprobadaPtr aprobada){
    return aprobada->nota;
}
char* getNombreMateriaAprobada(AprobadaPtr a){
    return a->nombreMateriaAprobada;
}
