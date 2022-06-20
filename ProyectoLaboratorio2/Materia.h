#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include <iostream>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Maestro.h"
#include "Fecha.h"

using namespace std;




class Materia{
private:
    int IDMateria;
    char nombreMateria[30];
    int IDMaestro;
    bool estado;

public:
    //sets()

    void cargarMateria();
    void mostrarMateria();
    bool GrabarEnDiscoMateria();
    bool LeerEnDiscoMateria(int nroRegistro);
    void materiaXMaestro();
    //gets()



};
#endif // MATERIA_H_INCLUDED
