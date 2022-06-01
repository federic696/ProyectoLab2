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


public:
    //sets()

    void cargarGrado();
    void mostrarGrado();
    bool GrabarEnDiscoGrado();
    bool LeerEnDiscoGrado(int nroRegistro);

    //gets()



};
void Grado::cargarGrado()
{

}
void Grado::mostrarGrado()
{

}
bool Grado::GrabarEnDiscoGrado()
{
    FILE *p;
    p=fopen ("Grado.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Grado),1,p);
    fclose(p);
    return escribio;
}
bool Grado::LeerEnDiscoGrado(int nroRegistro)
{
    FILE *p = fopen("Grado.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Grado), SEEK_SET);
    bool leyo = fread(this, sizeof(Grado), 1, p);
    fclose(p);
    return leyo;
}

#endif // GRADO_H_INCLUDED
