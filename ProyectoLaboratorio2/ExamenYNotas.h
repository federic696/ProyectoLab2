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
    int Nota;
    bool estado;

public:
    //sets()

    void cargarExamenYNotas();
    void mostrarExamenYNotas();
    bool GrabarEnDiscoExamenYNotas();
    bool LeerEnDiscoExamenYNotas(int nroRegistro);

    //gets()



};
void ExamenYNotas::cargarExamenYNotas()
{

}
void ExamenYNotas::mostrarExamenYNotas()
{

}
bool ExamenYNotas::GrabarEnDiscoExamenYNotas()
{
    FILE *p;
    p=fopen ("ExamenYNotas.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(ExamenYNotas),1,p);
    fclose(p);
    return escribio;
}
bool ExamenYNotas::LeerEnDiscoExamenYNotas(int nroRegistro)
{
    FILE *p = fopen("ExamenYNotas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(ExamenYNotas), SEEK_SET);
    bool leyo = fread(this, sizeof(ExamenYNotas), 1, p);
    fclose(p);
    return leyo;
}

#endif // EXAMENYNOTAS_H_INCLUDED
