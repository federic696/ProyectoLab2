#include<iostream>
#include<conio.h>
#include "Alumno.h"
#include "Fecha.h"
using namespace std;
#include "rlutil.h"

void Alumno::cargarAlumno();
void Alumno::mostrarAlumno();
bool Alumno::GrabarEnDiscoAlumno();
bool Alumno::LeerEnDiscoAlumno(int nroRegistro);
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
      recuadroalu(1,1,60,20);
      recuadroalu1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU ALUMNOS |"<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Cargar Estudiante"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Mostrar Estudiantes"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Buscar por DNI o Legajo"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Modificar Estudiante Por DNI o Legajo"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - Darlo de baja o alta por Legajo o DNI"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR ALUMNO |"<<endl;
            obj.cargarAlumno();
            //obj.GrabarEnDiscoAlumno();
            rlutil::locate(14,17);
            cout << "ALUMNO CARGADO CORRECTAMENTE!";
            rlutil::locate(10,20);
            system("pause");
            system("cls");

            break;
        case 19:
           // system("cls");
            recuadroalu1(1,1,60,20);
            while(obj.LeerEnDiscoAlumno(pos++)==1){
            recuadroalu1(1,1,60,20);
            rlutil::locate(2,5);
            obj.mostrarAlumno();
            rlutil::locate(20,3);
            cout<< "| ALUMNOS REGISTRADOS |"<<endl;
            rlutil::locate(10,20);
            system("pause");
            }
            break;






        case 20:
                system("cls");
            cout<< "1 Buscar alumno por DNI"<<endl;
            cout<< "2 Buscar alumno por legajo"<<endl;
            cout<<"Elija una opcion: ";
            cin>>Opc;
                system("cls");
                switch(Opc){
            case 1:
                BuscarAlumnoDNI();
                break;
            case 2:
                BuscarAlumnoLegajo();
                break;
                }

            break;
        case 21:

            break;
        case 22:
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
        if(Reg.GetLegajo()==Legajo){
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


