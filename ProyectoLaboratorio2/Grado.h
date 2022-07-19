#ifndef GRADO_H_INCLUDED
#define GRADO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
#include "Materia.h"
class Grado{
private:
   // int IDAlumno;
  //  int IDMaestro;
    int numGrado;
    int IDMaterias[15];

public:
    //sets()
    int ModificarEnDisco(int pos);
    //void cargarGrado();
    //void mostrarGrado();
    bool GrabarEnDiscoGrado();
    bool LeerEnDiscoGrado(int nroRegistro);
    int cantidadGrado();
    void setNumGrado(int num){numGrado=num;}
    void clearMaterias(){
        for(int i=0;i<15;i++){
            IDMaterias[i]=0;
        }
    }
    int getNumGrado(){return numGrado;}
    int getIDMateria(int loc){ return IDMaterias[loc];}
    void resetIDMateria(int loc){ IDMaterias[loc]=0;}
    void setIDMateria(int id){
        for(int i=0;i<15;i++){
            if(IDMaterias[i]==0){
                IDMaterias[i]=id;
                break;
            }
        }
    }
    void mostrarMejoresPromedios();
    void mostrarAlumnos();
    //gets()



};


#endif // GRADO_H_INCLUDED
