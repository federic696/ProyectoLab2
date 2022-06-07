#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
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

    //gets()



};
void Materia::cargarMateria()
{

}
void Materia::mostrarMateria()
{

}
bool Materia::GrabarEnDiscoMateria()
{
    FILE *p;
    p=fopen ("Materia.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Materia),1,p);
    fclose(p);
    return escribio;
}
bool Materia::LeerEnDiscoMateria(int nroRegistro)
{
    FILE *p = fopen("Materia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Materia), SEEK_SET);
    bool leyo = fread(this, sizeof(Materia), 1, p);
    fclose(p);
    return leyo;
}

#endif // MATERIA_H_INCLUDED
