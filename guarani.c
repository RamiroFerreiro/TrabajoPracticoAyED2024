#include <stdio.h>
#include <stdlib.h>
#include "guarani.h"

struct Guarani{

    ListaPtr listadoMaterias;
};

///constructor
GuaraniPtr crearGuarani(){

    GuaraniPtr guarani = malloc(sizeof(struct Guarani));

    guarani->listadoMaterias = crearLista();

    return guarani;
}

///mostrarSistema
void mostrarGuarani(GuaraniPtr g){

    mostrarListaGenerico(g->listadoMaterias, mostrarMateriaDatoPtr);


};

///getters
ListaPtr getListadoMaterias(GuaraniPtr g){
    return g->listadoMaterias;
}
