#include<iostream>
#include<conio.h>
#include "Persona.h"
#include "Fecha.h"
using namespace std;

void Persona::cargarPersona()
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
    cout << "Estado: ";
    cin >> estado;
}
void Persona::mostrarPersona()
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
    cout << "Estado: ";
    cout << estado << endl;

}

bool Persona::GrabarEnDiscoPersona()
{
    FILE *p;
    p=fopen ("Persona.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Persona),1,p);
    fclose(p);
    return escribio;
}
bool Persona::LeerEnDiscoPersona(int nroRegistro)
{
    FILE *p = fopen("Persona.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Persona), SEEK_SET);
    bool leyo = fread(this, sizeof(Persona), 1, p);
    fclose(p);
    return leyo;
}
