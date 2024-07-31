#include <stdio.h>
#include <stdlib.h>
#include "materia.h"
#include "inscripto.h"
#include "lista.h"
#include "materiaAprobada.h"
#include "guarani.h"

/*
CONSIGNA TP 2024
Realizar un programa que simule las principales funciones del sistema Guarani.
El sistema debe tener una lista de materias, las materias una lista de inscriptos,
y cada inscripto debe tener una lista de materias aprobadas con su promedio.
Cada materia tiene un cupo, en caso de que se anoten más estudiantes que el cupo se debe generar una cola,
para generar la cola se evaluará como prioridad primero la cantidad de materias aprobadas y luego el
promedio del estudiante.

*/


int main()
{
    //eliminarInscripto y actualizarCola
    //noAgregarInscriptoEnMateriaQueYaTieneAprobada
    //actualizarColaCuandoAgregoAprobada
    //noTenerAprobadasDuplicadas


    ///instancia guarani
    ListaPtr guarani = crearLista();

    GuaraniPtr sistemaGuarani = crearGuarani();

    ///instancia de materia
    MateriaPtr m1 = crearMateria( 1 , "Matematica 1", 2);
    MateriaPtr m2 = crearMateria( 2 , "Matematica 2", 4);
    MateriaPtr m3 = crearMateria( 3 , "Matematica 3", 5);

    ///intancias de inscripto
    InscriptoPtr i1 = crearInscripto(1 , "Ramiro");
    InscriptoPtr i2 = crearInscripto(2, "Juan Domingo");
    InscriptoPtr i3 = crearInscripto(3, "Eva");
    InscriptoPtr i4 = crearInscripto(4, "Nestor");
    InscriptoPtr i5 = crearInscripto(5, "Messi");

    ///instancias de materias aprobadas
    AprobadaPtr a1 = crearMateriaAprobada( 1, "Promagramacion 1", 3);
    AprobadaPtr a2 = crearMateriaAprobada( 2, "Matematica 2", 7);
    AprobadaPtr a3 = crearMateriaAprobada( 3, "AyED", 4);


    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n-----------------------------------------------------TEST 1 -----------------------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    /*
    El test1 testea lo pedido en la consigna: Se intenta agregar 5 inscriptos en la materia "Matematica 1". Esta tiene un
    cupo maximo de 2 inscriptos por ende Eva, Nestor y Messi ingresan en la cola. Eva tiene prioridad por tener mayor
    cantidad de materias aprobadas. Luego Messi y Nestor desempatan por promedio.

    La cola no se puede recorrer solo la muestro a modo ilustrativo para que se vea el funcionamiento.

    */

    ///inserto materias en guarani
    insertarUltimo(getListadoMaterias(sistemaGuarani), &m1); //inserto "Matematica 1"
    insertarUltimo(getListadoMaterias(sistemaGuarani), &m2); //inserto "Matematica 2"
    insertarUltimo(getListadoMaterias(sistemaGuarani), &m3); //inserto "Matematica 3"


    ///inserto materias aprobadas a un inscripto
    agregarAprobada(getListadoMaterias(sistemaGuarani), i3, &a1); //eva aprobo "programacion 1"
    agregarAprobada(getListadoMaterias(sistemaGuarani), i3, &a2); //eva aprobo "programacion 2"
    agregarAprobada(getListadoMaterias(sistemaGuarani), i4, &a2); //nestor aprobo "programacion 2"
    agregarAprobada(getListadoMaterias(sistemaGuarani), i5, &a3); //messi aprobo "AyED"


    ///inserto inscriptos a las materias

    agregarInscripto(m1, &i1, compararInscriptosDatoPtr); //inscribo Ramiro a "Matematica 1"
    agregarInscripto(m1, &i2, compararInscriptosDatoPtr); //inscripto Juan Domingo a "Matematica 1"
    agregarInscripto(m1, &i4, compararInscriptosDatoPtr); //inscripto Nestor a "Matematica 1"
    agregarInscripto(m1, &i5, compararInscriptosDatoPtr); //inscripto Messi a "Matematica 1"
    agregarInscripto(m1, &i3, compararInscriptosDatoPtr); //inscripto Eva a "Matematica 1"


    mostrarGuarani(sistemaGuarani);

    printf("\n\n\n <<<<COLA>>>> \n");
    mostrarListaGenerico(getColaMateria(m1), mostrarInscriptoDatoPtr); //no se debe hacer



    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n-----------------------------------------------------TEST 2 -----------------------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    /*
    Test2: Se intenta eliminar el inscripto "Ramiro1" el cual no existe. Se elimina a "Juan Domingo" y automaticamente se
    inscribe al primero que esta esperando en la cola. Nestor y Messi siguen en la cola.

    */
    eliminarInscripto(m1, "Ramiro1");
    eliminarInscripto(m1, "Juan Domingo");
    mostrarGuarani(sistemaGuarani);

    printf("\n\n\n <<<<COLA>>>> \n");
    mostrarListaGenerico(getColaMateria(m1), mostrarInscriptoDatoPtr);



    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n-----------------------------------------------------TEST 3 -----------------------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    /*
    Test3: Se intenta agregar un inscripto en "Matematica 2"  que tiene aprobada la materia. Se trata de una
    validacion en la logica del negocio, no te podes inscribir a una materia que ya aprobaste.
    */

    agregarInscripto(m2, &i3, compararInscriptosDatoPtr);
    mostrarGuarani(sistemaGuarani);

    printf("\n\n\n <<<<COLA>>>> \n");
    mostrarListaGenerico(getColaMateria(m1), mostrarInscriptoDatoPtr);




    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n-----------------------------------------------------TEST 4 -----------------------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    /*
    Test4: Se agregan aprobadas a un inscripto en la cola, esto hace que mejore su prioridad. Messi estaba ultimo en la
    cola hasta que aprobo materias y quedo primero.

    */
    agregarAprobada(getListadoMaterias(sistemaGuarani), i5, &a2);
    agregarAprobada(getListadoMaterias(sistemaGuarani), i5, &a1);

    printf("\n\n\n <<<<COLA>>>> \n");
    mostrarListaGenerico(getColaMateria(m1), mostrarInscriptoDatoPtr);


    printf("\n-----------------------------------------------------------------------------------------------------------------");
    printf("\n-----------------------------------------------------TEST 5 -----------------------------------------------------");
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");

    /*
    Test5: Se intenta agregar "Promagramacion 1" como aprobada dos veces al mismo inscripto.
    */
    agregarAprobada(getListadoMaterias(sistemaGuarani), i1, &a1);
    agregarAprobada(getListadoMaterias(sistemaGuarani), i1, &a1);

    mostrarGuarani(sistemaGuarani);




    return 0;
}
