#include <stdio.h>
#include <stdlib.h>
#include "materia.h"


struct Materia{

    int idMateria;
    char nombreMateria[20];
    int cupo;
    ListaPtr listadoAux;
    ColaPtr cola;
    ListaPtr listadoInscriptos;
};


///constructorCompleto
MateriaPtr crearMateria(int id, char nombreMateria[], int cupo){
    MateriaPtr materia = malloc(sizeof(struct Materia));

    materia->idMateria = id;
    strcpy(materia->nombreMateria, nombreMateria);
    materia->listadoInscriptos = crearLista();
    materia->cupo = cupo;
    materia->listadoAux = crearLista();
    materia->cola = crearCola();

    return materia;
}



///mostrarMateria
void mostrarMateria(MateriaPtr materia){
    printf("\n ------------- MATERIA --------------\n");
    printf("ID --> %d\n", materia->idMateria);
    printf("NOMBRE --> %s\n", materia->nombreMateria);
    printf("CUPO --> %d \n", materia->cupo);

    mostrarListaGenerico(materia->listadoInscriptos, mostrarInscriptoDatoPtr);
}


///mostrarMateriaDatoPtr
void mostrarMateriaDatoPtr(void* dato){

    MateriaPtr m1 = *(MateriaPtr*) dato;
    mostrarMateria(m1);
}

///agregarInscriptos
void agregarInscripto(MateriaPtr materia, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr)){

    InscriptoPtr inscripto = *(InscriptoPtr*) dato;
    int posMateriaAprobada = busquedaSecuencial(getListadoMateriasAprobadas(inscripto), materia->nombreMateria, compararInscriptosIgualIgualDatoPtr);

    if(posMateriaAprobada != -1){ //si la materia está aprobada no lo inscribe

        printf("\n ERROR: No se puede agregar el inscripto [%s] porque ya aprobo la materia [%s]\n", getNombreInscripto(inscripto), materia->nombreMateria);

    }else{

        if(obtenerTamanio(materia->listadoInscriptos) >= getCupo(materia) ){ //si el cupo está lleno lo mandamos a la cola

            printf("\nEl cupo para [%s] esta lleno y entra en la cola \n", getNombreInscripto(inscripto));

            actualizarCola(materia, dato, funcionComparar);

        }else{  //si no supera el cupo solo inserta ultimo en el listado.

            insertarUltimo(materia->listadoInscriptos, dato);
        }
    }
}

///actualizarCola
void actualizarCola(MateriaPtr materia, DatoPtr dato, int (*funcionComparar)(DatoPtr, DatoPtr)){

            vaciarCola(materia); //vacio la cola en la lista auxiliar para poder ordenarla

            insertarOrdenado(materia->listadoAux, dato, funcionComparar); //Inserto ordenado el nuevo dato en la lista auxiliar

            llenarCola(materia); //vuelvo a pasar los datos de lista a la cola
}

///vaciarCola
void vaciarCola(MateriaPtr materia){

    //Vacio la cola ordenada y lo inserto de la misma manera en una lista aux. Si la cola está vacia no se ejecuta.

    while(getPrimeroCola(materia->cola) != NULL){
        DatoPtr valor = desencolar(materia->cola);
        insertarUltimo(materia->listadoAux, valor);
    }
}

///llenarCola
void llenarCola(MateriaPtr materia){

    //Voy recorriendo la lista auxiliar del primero al ultimo. Elimino el valor de lista
    //para quedarme el dato y luego encolar. Vacio la lista auxiliar para no repetir instancias.
    //Si dejo los valores cargados en la listaAux cuando vuelva a vaciar la cola ordenada se van a repetir.

    NodoPtr actual = getPrimero(materia->listadoAux);

    while(actual != NULL){
        DatoPtr valor = eliminarPrimero(materia->listadoAux);
        encolar(materia->cola, valor);
        actual = getSiguiente(actual);
    }

}


///actualizarColas
void actualizarColas(ListaPtr listaSistema){

    //recorro todas las listas del sistema y las actualizo. Esta funcion se llama cuando se intenta agregar materias
    //aprobadas a un inscripto que puede encontrarse en la cola. Quizas no sea lo más eficiente actualizar TODAS las colas
    //de TODAS las materias. Pero no se puede hacer busqueda en la cola y el hecho pasarlo a una lista para despues buscar
    //requeriría el mismo esfuerzo.  Además hay que tener cuenta que el inscripto puede estar en varias colas.

    NodoPtr actual = getPrimero(listaSistema);

    while(actual != NULL){

            MateriaPtr materia = *(MateriaPtr*)getDato(actual);

            vaciarCola(materia); //Paso la cola a una lista

            ordenamientoBurbujeoGenerico(materia->listadoAux, compararInscriptosDatoPtr);// ordeno la cola

            llenarCola(materia);//Paso de la lista a la cola

        actual = getSiguiente(actual);
    }

}

///eliminarInscripto
void eliminarInscripto(MateriaPtr materia, char nombre[]){

    //Elimina un inscripto del listadoInscriptos y desencola al siguiente de la lista.

    ListaPtr lista = materia->listadoInscriptos;

    int posEliminar = busquedaSecuencial(lista, nombre, compararInscriptosIgualIgualDatoPtr);

    if(posEliminar != -1){

        eliminarPosicion(lista, posEliminar);

        if(getPrimeroCola(materia->cola) != NULL){
            DatoPtr siguiente = desencolar(materia->cola);
            insertarUltimo(materia->listadoInscriptos, siguiente);

        }
    }
}

///getters
ListaPtr getListadoInscriptos(MateriaPtr materia){
    return materia->listadoInscriptos;
}
ListaPtr getListadoAux(MateriaPtr materia){
    return materia->listadoAux;
}

int getCupo(MateriaPtr materia){
    return materia->cupo;
}
ColaPtr getColaMateria(MateriaPtr materia){
    return materia->cola;
}



