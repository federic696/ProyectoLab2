#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Maestro.h"
#include "Fecha.h"
#include "Alumno.h"
#include "ExamenYNotas.h"
#include "Grado.h"

using namespace std;




class Materia{
private:
    int IDMateria;
    char nombreMateria[30];
    int grado;
    int IDMaestro;
    bool estado;

public:
    //sets()
    int getIDMateria(){
        return IDMateria;
    }
    char *getNombreMateria(){
        return nombreMateria;
    }
    void cargarMateria();
    void mostrarMateria();
    void mejorPromedio();
    bool GrabarEnDiscoMateria();
    bool LeerEnDiscoMateria(int nroRegistro);
    void materiaXMaestro();
    void setEstado(bool e){estado=e;}
    void darDeBaja();
    int ModificarEnDisco(int Pos);
    //gets()



};
#endif // MATERIA_H_INCLUDED
