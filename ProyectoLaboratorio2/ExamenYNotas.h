#ifndef EXAMENYNOTAS_H_INCLUDED
#define EXAMENYNOTAS_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
class ExamenYNotas{
private:
    int IDAlumno;
    int IDMaestro;
    int IDMateria;
    int IDExamen;
    int Nota;
    bool estado;

public:
    //sets()
    void setIDExamen(int i){
        IDExamen=i;
    }
    void setIDAlumno(int i){
        IDAlumno=i;
    }

    void setNota(int i){
        Nota=i;
    }

    void cargarExamenYNotas();
    void mostrarExamenYNotas();
    bool GrabarEnDiscoExamenYNotas();
    bool LeerEnDiscoExamenYNotas(int nroRegistro);

    //gets()
    int getIDExamen(){
        return IDExamen;
    }
    int getIDAlumno(){
        return IDAlumno;
    }

    int getNota(){
        return Nota;
    }


};


#endif // EXAMENYNOTAS_H_INCLUDED
