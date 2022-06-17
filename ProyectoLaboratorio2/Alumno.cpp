#include<iostream>
#include<conio.h>
#include "Alumno.h"
#include "Fecha.h"
using namespace std;

void BuscarAlumnoDNI();
void BuscarAlumnoLegajo();
int Alumnos()
{

    int Opc;
    int pos=0;
    Alumno obj;

    while(true)
    {
        system("cls");
        cout<< "\t MENU ALUMNOS "<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) Cargar Estudiante"<<endl;
        cout<< "2) Mostrar Estudiantes"<<endl;
        cout<< "3) Buscar por DNI o Legajo"<<endl;
        cout<< "4) Modificar Estudiante Por DNI o Legajo"<<endl;
        cout<< "5) Darlo de baja o alta por Legajo o DNI"<<endl;
        cout<< "0) Volver a menu"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: "<<endl;
        cin>>Opc;
        system("cls");
        switch(Opc)
        {
        case 1:
            obj.cargarAlumno();
            break;
        case 2:
            while(obj.LeerEnDiscoAlumno(pos)==1){
            obj.mostrarAlumno();
            cout<<endl;
            pos++;
            }
            system("pause");

            break;
        case 3:

            cout<< "1 Buscar alumno por DNI"<<endl;
            cout<< "2 Buscar alumno por legajo"<<endl;
            cout<<"Elija una opcion: ";
            cin>>Opc;
                switch(Opc){
            case 1:
                BuscarAlumnoDNI();
                break;
            case 2:
                BuscarAlumnoLegajo();
                break;
                }
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

void BuscarAlumnoLegajo(){
    Alumno Reg;
    int Pos=0;
    int Legajo=0;
    cout<< "Ingrese legajo del alumno: ";
    cin>>Legajo;
    while(Reg.LeerEnDiscoAlumno(Pos++)){
        if(Reg.getlegajo()==Legajo){
            Reg.mostrarAlumno();
        }
    }
    system("pause");

}



void BuscarAlumnoDNI(){
    Alumno Reg;
    int Pos=0;
    int DNI=0;
    cout<< "Ingrese DNI del alumno: ";
    cin>> DNI;
    while(Reg.LeerEnDiscoAlumno(Pos++)==1){
        if(Reg.getDNI()==DNI){
            Reg.mostrarAlumno();
        }
    }
    system("pause");
}
