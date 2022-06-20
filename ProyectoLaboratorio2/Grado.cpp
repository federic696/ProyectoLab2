#include<iostream>
#include<conio.h>
#include "Grado.h"

using namespace std;

void Grado::cargarGrado()
{

}
void Grado::mostrarGrado()
{

}
bool Grado::GrabarEnDiscoGrado()
{
    FILE *p;
    p=fopen ("Grado.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Grado),1,p);
    fclose(p);
    return escribio;
}
bool Grado::LeerEnDiscoGrado(int nroRegistro)
{
    FILE *p = fopen("Grado.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Grado), SEEK_SET);
    bool leyo = fread(this, sizeof(Grado), 1, p);
    fclose(p);
    return leyo;
}

int Grados(){

int Opc;
    while(true)
    {
        system("cls");
        cout<< "\t MENU GRADO "<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) Mostrar  maestros por grado y materia"<<endl;
        cout<< "2) Mostrar  estudiante por grado"<<endl;
        cout<< "3) Mostrar mejores promedios por grado"<<endl;
        cout<< "4) Mostrar mejores promedio materia por grado"<<endl;
        cout<< "0) Volver a menu"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: "<<endl;
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
