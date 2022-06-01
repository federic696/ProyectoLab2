#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"

class Alumno:public Persona{
private:
    int legajo;
    int curso;

public:
    //sets()

    void cargarAlumno();
    void mostrarAlumno();
    bool GrabarEnDiscoAlumno();
    bool LeerEnDiscoAlumno(int nroRegistro);

    //gets()



};
void Alumno::cargarAlumno()
{
    cargarPersona();
    cout << "Legajo: ";
    cin >> legajo;
    cout << "Curso: ";
    cin >> curso;
}
void Alumno::mostrarAlumno()
{
    mostrarPersona();
    cout << "Legajo: ";
    cout << legajo << endl;
    cout << "Curso: ";
    cout << curso << endl;
}
bool Alumno::GrabarEnDiscoAlumno()
{
    FILE *p;
    p=fopen ("Alumno.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Alumno),1,p);
    fclose(p);
    return escribio;
}
bool Alumno::LeerEnDiscoAlumno(int nroRegistro)
{
    FILE *p = fopen("Alumno.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Alumno), SEEK_SET);
    bool leyo = fread(this, sizeof(Alumno), 1, p);
    fclose(p);
    return leyo;
}

#endif // ALUMNO_H_INCLUDED
