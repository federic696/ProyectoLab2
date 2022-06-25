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
    int Grado;
    int IDExamen;
    int Nota;
    bool estado=true;

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

    void setGrado(int i){
        Grado=i;
    }

    void cargarExamenYNotas();
    void mostrarExamenYNotas();
    bool GrabarEnDiscoExamenYNotas();
    bool LeerEnDiscoExamenYNotas(int nroRegistro);
    bool GrabarEnDiscoExamenYNotas(int nroRegistro);

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

    int getGrado(){
        return Grado;
    }


bool getEstado() const
{
    return estado;
}

void setEstado(bool _estado)
{
    estado = _estado;
}

};


#endif // EXAMENYNOTAS_H_INCLUDED
