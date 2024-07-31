#include <stdio.h>
#include <stdlib.h>
#include "inscripto.h"
#include <string.h>


struct Inscripto{
    int idInscripto;
    char nombreInscripto[20];
    float promedio;
    ListaPtr listadoMateriasAprobadas;
};


///constructorCompleto
InscriptoPtr crearInscripto(int id, char nombreInscripto[]){
    InscriptoPtr inscripto = malloc(sizeof(struct Inscripto));

    inscripto->idInscripto = id;
    strcpy(inscripto->nombreInscripto, nombreInscripto);
    inscripto->listadoMateriasAprobadas = crearLista();
    inscripto->promedio =0;

    return inscripto;
}

///mostrarInscripto
void mostrarInscripto(InscriptoPtr inscripto){

    printf("\n------------INSCRIPTO---------\n");
    printf("ID --> %d\n", inscripto->idInscripto);
    printf("NOMBRE --> %s\n", inscripto->nombreInscripto);
    printf("PROMEDIO -->% f\n", inscripto->promedio);

    mostrarListaGenerico(inscripto->listadoMateriasAprobadas, mostrarMateriaAprobadaDatoPtr);

}

///mostrarInscriptoDatoPtr
void mostrarInscriptoDatoPtr(void * data){

    InscriptoPtr i1 = *(InscriptoPtr*) data;
    mostrarInscripto(i1);

}
///agregarMateriaAprobada
void agregarAprobada(ListaPtr listaSis, InscriptoPtr inscripto, DatoPtr dato){

    AprobadaPtr aprobada = *(AprobadaPtr*) dato;
    int posMateriaAprobada = busquedaSecuencial(inscripto->listadoMateriasAprobadas, getNombreMateriaAprobada(aprobada), compararInscriptosIgualIgualDatoPtr );

    if(posMateriaAprobada == -1){//si no la encuentra en el listado de aprobadas la agrega

        insertarUltimo(inscripto->listadoMateriasAprobadas, dato);

        //Si el inscripto tiene solamente una materia aprobada el promedio es igual a la nota
        //de la materia que acaba de insertar. Nunca puede ser nulo porque se acaba de insertar.
        if(obtenerTamanio(inscripto->listadoMateriasAprobadas) == 1){
            inscripto->promedio = getNota (*(AprobadaPtr*)dato);

        }

        //Promedio es un atributo calculable. Cada vez que agregamos una materia aprobada hay que calcularlo.
        inscripto->promedio = calcularPromedio(inscripto);

        //actualizo la colas del sistema
        actualizarColas(listaSis);

    }else{
        printf("\nERROR: La materia [%s] ya esta aprobada por el inscripto [%s]\n", getNombreMateriaAprobada(aprobada), getNombreInscripto(inscripto));
    }



}

///calcularPromedio
float calcularPromedio(InscriptoPtr inscripto){
    //Sumo en total y divido por el tamaño de la lista (cantidad de aprobadas)

    float total = 0;
    ListaPtr lista = inscripto->listadoMateriasAprobadas;

    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){

        AprobadaPtr aprobada = *(AprobadaPtr*) getDato(actual);
        total =  total + getNota(aprobada);
        actual = getSiguiente(actual);
    }

    int tamLista = obtenerTamanio(lista);
    total = total/tamLista;

    return total;
}
///compararInscriptos
int compararInscriptosDatoPtr(void* data1, void* data2){

    InscriptoPtr i1 = *(InscriptoPtr*) data1;
    InscriptoPtr i2 = *(InscriptoPtr*) data2;

    //comparo inscriptos por la cantidad de materias aprobadas. Si la cantidad de materias
    //aprobadas son iguales comparon por promedio.

    if(obtenerTamanio(i1->listadoMateriasAprobadas) != obtenerTamanio(i2->listadoMateriasAprobadas)){

        return obtenerTamanio(i1->listadoMateriasAprobadas) > obtenerTamanio(i2->listadoMateriasAprobadas);

    }else{

        return i1->promedio > i2->promedio;
    }


}

///compararInscriptosIgualIgual
int compararInscriptosIgualIgualDatoPtr(void* data1, void* data2){

    InscriptoPtr i1 = *(InscriptoPtr*) data1;
    char* aux = (char*)data2;

    if(strcmp(i1->nombreInscripto, aux) == 0){
        return 1;
    }else{
        return 0;
    }

}

///getters
ListaPtr getListadoMateriasAprobadas(InscriptoPtr i){
    return i->listadoMateriasAprobadas;
}
char* getNombreInscripto(InscriptoPtr i){
    return i->nombreInscripto;
}
