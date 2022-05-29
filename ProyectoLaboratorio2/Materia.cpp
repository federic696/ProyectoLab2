#include<iostream>
#include<conio.h>
using namespace std;

int Materia()
{

    int Opc;
    while(true)
    {
        system("cls");
        cout<< "\t MENU MATERIA "<<endl;
        cout<< "1.Mostrar maestros por materias"<<endl;
        cout<< "2.Mostrar mejores promedios de alumnos por materia"<<endl;
        cout<< "3.Mostrar todas las materias"<<endl;
        cout<< "4.Dar de baja una materia"<<endl;
        cout<< "5.Dar de alta una materia"<<endl;
        cout<< "6.Subir materia  por grado"<<endl;
        cout<< "0.Volver a menu"<<endl;;
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
        case 5:

            break;
        case 6:

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
