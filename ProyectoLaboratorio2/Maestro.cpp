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
