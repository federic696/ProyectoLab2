#include <iostream>
using namespace std;

///funciones adiccionales para los demas menus
int Alumnos();
int Maestros();
int ExamenNotas();
int Grados();
int Materias();

int main()
{
    int Opc;
    while(true)
    {
        system("cls");
        cout<< "\t MENU PRINCIPAL "<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) INGRESAR MENU ALUMNO"<<endl;
        cout<< "2) INGRESAR MENU MAESTRO"<<endl;
        cout<< "3) INGRESAR MENU NOTAS Y EXAMEN"<<endl;
        cout<< "4) INGRESAR MENU GRADOS"<<endl;
        cout<< "5) INGRESAR MENU MATERIA"<<endl;
        cout<< "0) Salir"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: ";
        cin>>Opc;
        system("cls");
        switch(Opc)
        {
        case 1:
            Alumnos();
            break;
        case 2:
            Maestros();
            break;
        case 3:
            ExamenNotas();
            break;
        case 4:
            Grados();
            break;
        case 5:
            Materias();
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


