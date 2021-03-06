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
    int IDMateria;
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

    void setIDMateria(int i){
        IDMateria=i;
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

    int getIDMateria(){
        return IDMateria;
    }
    int cantidadExamenesXAlumno(int id);

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
