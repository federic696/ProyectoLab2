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
    estado=true;
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
    if(estado==true){
        cout<<"Persona activa"<<endl;
    }

}

