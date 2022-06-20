#ifndef GRADO_H_INCLUDED
#define GRADO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
class Grado{
private:
    int IDAlumno;
    int IDMaestro;
    int numGrado;
    int IDMaterias;

public:
    //sets()

    void cargarGrado();
    void mostrarGrado();
    bool GrabarEnDiscoGrado();
    bool LeerEnDiscoGrado(int nroRegistro);

    //gets()



};


#endif // GRADO_H_INCLUDED
