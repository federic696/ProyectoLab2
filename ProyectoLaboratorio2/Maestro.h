#ifndef MAESTRO_H_INCLUDED
#define MAESTRO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
#include "Persona.h"

class Maestro:public Persona{
private:
    int IDMateria;
    int Materia;
public:
    //sets()

    void cargarMaestro();
    void mostrarMaestro();
    bool GrabarEnDiscoMaestro();
    bool LeerEnDiscoMaestro(int nroRegistro);

    //gets()

};
void Maestro::cargarMaestro()
{
    Maestro Reg;
    cargarPersona();
    Reg.GrabarEnDiscoMaestro();
}

void Maestro::mostrarMaestro()
{
    Maestro Reg;
    int Pos=0;
    while(Reg.LeerEnDiscoMaestro(Pos++)==1)
    {
        mostrarPersona();
        cout<<endl;
    }
    system("pause");

}
bool Maestro::GrabarEnDiscoMaestro()
{
    FILE *p;
    p=fopen ("Maestro.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Maestro),1,p);
    fclose(p);
    return escribio;
}

bool Maestro::LeerEnDiscoMaestro(int nroRegistro)
{
    FILE *p = fopen("Maestro.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Maestro), SEEK_SET);
    bool leyo = fread(this, sizeof(Maestro), 1, p);
    fclose(p);
    return leyo;
}

#endif // MAESTRO_H_INCLUDED
