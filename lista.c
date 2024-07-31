#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct Lista{

    NodoPtr primero;
};

///CONSTRUCTOR
ListaPtr crearLista(){
    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
}

///GETTER Y SETTER
ListaPtr getPrimero(ListaPtr lista){
    return lista->primero;
}
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero){
    lista->primero = nuevoPrimero;
}


///MOSTRAR LISTA                                funcionMostrar   datoAMostrar
void mostrarListaGenerico(ListaPtr lista, void (*mostrarFuncion)(DatoPtr)){

    printf("\n <LISTA> TAM : %d", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while(actual != NULL){

        (*mostrarFuncion)(getDato(actual));
        actual = getSiguiente(actual);
    }

    printf("\n\n");

}

///INSERTAR PRIMERO
void insertarPrimero(ListaPtr lista, DatoPtr dato){

   NodoPtr nuevoNodo = crearNodo(dato, lista->primero); //el primero ahora es el siguiente
   lista->primero = nuevoNodo; //el nuevo nodo es el primero

}

///INSERTAR ULTIMO
void insertarUltimo(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    NodoPtr actual = lista->primero;

    if(actual == NULL){
        insertarPrimero(lista, dato);
    }else{

        while(getSiguiente(actual) != NULL){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);
    }

}
///INSERTAR POSICION
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){


    NodoPtr actual = lista->primero;

    if(posicion == 0){
        insertarPrimero(lista, dato);
    }else{
        if(posicion == obtenerTamanio(lista)){
            insertarUltimo(lista, dato);
        }else{

            if(posicion>0  && posicion<obtenerTamanio(lista)){

                for(int i=0; i<posicion-1; i++){

                    actual = getSiguiente(actual);
                }

                setSiguiente(actual, crearNodo(dato,getSiguiente(actual)));

            }else{

                printf("\nNo existe esa pos\n");

            }
        }
    }
}


///OBTENER PRIMERO
DatoPtr obtenerPrimero(ListaPtr lista){
    NodoPtr actual = lista->primero;
    DatoPtr datoBuscado = getDato(actual);
    return datoBuscado;

}

///OBTENER ULTIMO
DatoPtr obtenerUltimo(ListaPtr lista){
    NodoPtr actual = lista->primero;
    DatoPtr datoBuscado;

    while(getSiguiente(actual)  != NULL){
        actual = getSiguiente(actual);
    }

    datoBuscado = getDato(actual);

    return datoBuscado;
}

///OBTENER POSICION
DatoPtr obtenerPosicion(ListaPtr lista, int posicion){
    NodoPtr actual = lista->primero;
    DatoPtr datoBuscado;

    for(int i = 0; i<posicion; i++){
        actual = getSiguiente(actual);
    }

    datoBuscado = getDato(actual);
    return datoBuscado;
}

///OBTENER TAMANIO
int obtenerTamanio(ListaPtr lista){

    int tamanio = 0;
    NodoPtr actual =  lista->primero;

    while(actual != NULL){
        tamanio++;
        actual = getSiguiente(actual);
    }

    return tamanio;
}

///ELIMINACIONES
DatoPtr eliminarPrimero(ListaPtr lista){
    NodoPtr actual = lista->primero;
    lista->primero = getSiguiente(actual);

    DatoPtr eliminado = getDato(actual);
    free(actual);

    return eliminado;
}
DatoPtr eliminarUltimo(ListaPtr lista){

    NodoPtr actual = lista->primero;
    NodoPtr siguiente = getSiguiente(actual);

    while(getSiguiente(siguiente) != NULL){
        actual = siguiente;
        siguiente = getSiguiente(siguiente);
    }

    setSiguiente(actual, getSiguiente(siguiente));

    DatoPtr eliminado = getDato(siguiente);

    free(siguiente);

    return eliminado;
}
DatoPtr eliminarPosicion(ListaPtr lista, int posicion){

    NodoPtr actual = lista->primero;
    NodoPtr siguiente = getSiguiente(actual);

    if(posicion == 0){
        eliminarPrimero(lista);

    }else{
        if(posicion == obtenerTamanio(lista)-1){
            eliminarUltimo(lista);
        }else{

            for(int i=0; i< posicion-1; i++){
                actual = siguiente;
                siguiente = getSiguiente(siguiente);
            }

            setSiguiente(actual, getSiguiente(siguiente));
            free(siguiente);


        }
    }

};

///ORDENAMIENTO GENERICO
void ordenamientoBurbujeoGenerico(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){
    NodoPtr actual;
    DatoPtr aux;


    int tam = obtenerTamanio(lista);

    for(int i=0; i<tam; i++){


        actual = lista->primero; //vuelve al primero cada vez que termina el for interno

        for(int j=0; j<tam-1; j++){


            if( !((*funcionComparar)(getDato(actual), getDato(getSiguiente(actual)))) ){ //si j > j+1

                aux = getDato(actual);
                setDato(actual, getDato(getSiguiente(actual)));
                setDato(getSiguiente(actual), aux);
            }

            actual = getSiguiente(actual);
        }
    }

}

///BUSQUEDA SECUENCIAL
int busquedaSecuencial(ListaPtr lista, DatoPtr personaBuscada, int (*funcionIgualar)(DatoPtr, DatoPtr)){
    int contador=0;

    NodoPtr actual = lista->primero;

    while(actual != NULL){

        if((*funcionIgualar)(getDato(actual), personaBuscada)){
            return contador;

        }
        actual=getSiguiente(actual);
        contador++;
    }

    contador = -1;

    return contador;
}

///DUPLICAR LISTA
ListaPtr duplicarLista(ListaPtr lista){
    ListaPtr listaDuplicada = crearLista();

    NodoPtr actual = lista->primero;

    while(actual != NULL){
        insertarUltimo(listaDuplicada, getDato(actual));
        actual = getSiguiente(actual);
    }

    return listaDuplicada;

}
/*
///ORDENAR LISTA COPIA
ListaPtr ordenarListaCopia(ListaPtr lista, int (*funcionComparar)(DatoPtr, DatoPtr)){

    ListaPtr listaDuplicadaOrdenada = crearLista();
    listaDuplicadaOrdenada = duplicarLista(lista);
    ordenamientoBurbujeoGenerico(listaDuplicadaOrdenada, funcionComparar);

    return listaDuplicadaOrdenada;

}*/

///INSERTAR EN ORDEN
void insertarOrdenado(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr)){

    NodoPtr actual = lista->primero;
    int i=1;
    int bandera = 0;
    int tam = obtenerTamanio(lista);

    if( (lista->primero == NULL)  || ( (*comparar)(dato,obtenerPrimero(lista)))){
        insertarPrimero(lista, dato);
    }else{

        if((*comparar)(obtenerUltimo(lista), dato)){
            insertarUltimo(lista, dato);
        }else{

        /// L  5--8
            while(bandera == 0  && getSiguiente(actual)!=NULL){

                if((*comparar)(getDato(actual), dato)  && (*comparar)(dato, getDato(getSiguiente(actual)))){
                    insertarPosicion(lista, dato, i);
                    bandera = 1;
                }
                actual = getSiguiente(actual);
                i++;
            }

        }

    }

}

///DESTRUCTOR LISTA
void liberarLista(ListaPtr lista){

    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL){
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    };


}



