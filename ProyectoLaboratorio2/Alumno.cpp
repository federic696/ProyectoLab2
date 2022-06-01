#include<iostream>
#include<conio.h>
#include "Alumno.h"
#include "Fecha.h"
using namespace std;

void Alumno::cargarAlumno();
void Alumno::mostrarAlumno();
bool Alumno::GrabarEnDiscoAlumno();
bool Alumno::LeerEnDiscoAlumno(int nroRegistro);

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
            obj.GrabarEnDiscoAlumno();
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
