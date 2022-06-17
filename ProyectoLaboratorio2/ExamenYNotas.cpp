#include<iostream>
#include<conio.h>
using namespace std;
#include "ExamenYNotas.h"

int ExamenNotas(){
    int Opc;
    ExamenYNotas obj;
    int pos=0;
    while(true)
    {
        system("cls");
        cout<< "\t MENU Examen y Notas "<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) Cargar nuevo examen"<<endl;
        cout<< "2) Modificar ID Alumno Por Examen"<<endl;
        cout<< "3) Modificar Nota Por Examen Del Alumno"<<endl;
        cout<< "4) Cargar promedio alumno por grado"<<endl;
        cout<< "5) Ver mejores notas de alumnos"<<endl;
        cout<< "9) Mostrar Examenes (Provisorio)"<<endl;
        cout<< "0) Volver a menu"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: "<<endl;
        cin>>Opc;
        system("cls");
        switch(Opc)
        {
        case 1:
            obj.cargarExamenYNotas();
            obj.GrabarEnDiscoExamenYNotas();
            break;
        case 2:
            cambiarIDAlumno();
            break;
        case 3:
            cambiarNota();
            break;
        case 4:
            break;
        case 9:
            while(obj.LeerEnDiscoExamenYNotas(pos)){
                obj.mostrarExamenYNotas();
                pos++;
            }
            system("pause");
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
