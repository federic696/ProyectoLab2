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
    void setLegajo(int Leg){legajo=Leg;}
    void setCurso(int Cur){curso=Cur;}
    void cargarAlumno();
    void mostrarAlumno();
    bool GrabarEnDiscoAlumno();
    bool LeerEnDiscoAlumno(int nroRegistro);

    //gets()

    int getlegajo(){return legajo;}
    int getCurso(){return curso;}

};

void Alumno::cargarAlumno()
{
    cout << "Nombre: ";
    cin >>nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "DNI: ";
    cin >> DNI;
    cout << "Email: ";
    cin >> email;
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    cout << "Legajo: ";
    cin >> legajo;
    cout << "Curso: ";
    cin >> curso;
    estado=true;
    cargarAlumno();
}

void Alumno::mostrarAlumno()
{
   cout << "Nombre: ";
    cout << nombre << endl;
    cout << "Apellido: ";
    cout << apellido << endl;
    cout << "DNI: ";
    cout << DNI << endl;
    cout << "Email: ";
    cout << email << endl;
    cout << "Fecha de nacimiento: ";
    fechaN.MostrarFecha();
    cout << "Legajo: ";
    cout << legajo << endl;
    cout << "Curso: ";
    cout << curso << endl;
     if(estado==true){
        cout<<"Persona activa"<<endl;
    }
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
