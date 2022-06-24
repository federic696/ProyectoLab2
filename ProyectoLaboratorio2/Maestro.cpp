#include<iostream>
#include<conio.h>
#include "Maestro.h"
using namespace std;
void BuscarMaestro();
int Maestros(){
int Opc;
int Pos=0;
Maestro mas;
    while(true)
    {
        system("cls");
        cout<< "\t MENU MAESTROS"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) Cargar Maestro"<<endl;
        cout<< "2) Mostrar Maestros"<<endl;
        cout<< "3) Buscar por DNI"<<endl;
        cout<< "4) Modificar Maestro por DNI"<<endl;
        cout<< "5) Darlo de baja o alta por DNI"<<endl;
        cout<< "0) Volver a menu"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: "<<endl;
        cin>>Opc;
        system("cls");

        switch(Opc)
        {
        case 1:
            mas.cargarMaestro();
            break;
        case 2:
            while(mas.LeerEnDiscoMaestro(Pos++)==1){
            mas.mostrarMaestro();
            cout<<endl;
            }
            system("pause");
            break;
        case 3:
            BuscarMaestro();
            break;
        case 4:

            break;
        case 0:
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}




void Maestro::cargarMaestro(){
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

void Maestro::mostrarMaestro(){

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

bool Maestro::GrabarEnDiscoMaestro(){
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

bool Maestro::LeerEnDiscoMaestro(int nroRegistro){
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


///funciones goables


void BuscarMaestro(){
    Maestro Reg;
    int Pos=0;
    int DNI=0;
    cout<< "Ingrese el DNI del maestro: ";
    cin>>DNI;
    while(Reg.LeerEnDiscoMaestro(Pos++))
    {
        if(Reg.getDNI()==DNI)
        {
            Reg.mostrarMaestro();
        }
    }
    system("pause");
}


void ModificarMaestro(){
    char Nombre[30],Apellido[30],Email[30];
    int Pos=0, dni=0, DNI=0,Dia=0,Mes=0,Anio=0;
    Maestro Reg;
    cout<< "ingrese el DNI del maestro: ";
    cin>> DNI;
    while(Reg.LeerEnDiscoMaestro(Pos++)){
        if(Reg.getDNI()==DNI){
            cout<< "Actualice los datos del maestro: ";
            cout << "Nombre: ";
            cin >> Nombre;
            Reg.setNombre(Nombre);
            cout << "Apellido: ";
            cin >> Apellido;
            cout << "DNI: ";
            cin >> dni;
            cout << "Email: ";
            cin >> Email;
            cout << "Fecha de nacimiento: ";


            }
    }
}
