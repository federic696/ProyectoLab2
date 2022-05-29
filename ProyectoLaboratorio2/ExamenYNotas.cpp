#include<iostream>
#include<conio.h>
using namespace std;

int ExamenNotas(){
    int Opc;
    while(true)
    {
        system("cls");
        cout<< "\t MENU Examen y Notas "<<endl;
        cout<< "1.Cargar nuevo examen"<<endl;
        cout<< "2.Modificar examen"<<endl;
        cout<< "3.Modificar nota alumnos"<<endl;
        cout<< "4.Cargar promedio alumno por grado"<<endl;
        cout<< "5.Ver mejores notas de alumnos"<<endl;
        cout<< "0.Volver a menu"<<endl;
        cin>>Opc;
        system("cls");
        switch(Opc)
        {
        case 1:

            break;
        case 2:

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
