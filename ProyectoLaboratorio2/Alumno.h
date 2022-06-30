#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"
#include "rlutil.h"
#include "Grado.h"

///funciones globales
int BuscarLegajo(int Leg);



class Alumno:public Persona{
private:
    //int legajo;
    int curso;

public:
    //sets()
    void SetLegajo(int Leg){legajo=Leg;}
    void SetCurso(int Cur){curso=Cur;}
    void cargarAlumno();
    void mostrarAlumno();
    bool GrabarEnDiscoAlumno();
    bool LeerEnDiscoAlumno(int nroRegistro);
    void ModificarDatosAlumno();
    int ModificarEnDisco(int Pos);
    //gets()
    int GetCurso(){return curso;}
    int cantidadAlumnos();


};



#endif // ALUMNO_H_INCLUDED
