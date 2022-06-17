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

public:

    void cargarMaestro();
    void mostrarMaestro();
    bool GrabarEnDiscoMaestro();
    bool LeerEnDiscoMaestro(int nroRegistro);



};
void Maestro::cargarMaestro()
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
    estado=true;
    GrabarEnDiscoMaestro();
}

void Maestro::mostrarMaestro()
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
        if(estado==true){
            cout<<"Persona activa"<<endl;
        }



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
