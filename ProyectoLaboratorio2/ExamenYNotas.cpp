#include<iostream>
#include<conio.h>
using namespace std;
#include "ExamenYNotas.h"

int BuscarID(int id){
ExamenYNotas obj;
int pos=0;
while(obj.LeerEnDiscoExamenYNotas(pos)){
        if(id==obj.getIDExamen()){

            return pos;
        }
    pos++;
}
cout << "EL ID NO COINCIDE CON NINGUN EXAMEN";
return -1;
}

bool ModificarID(int pos2, int ID){
if(pos2>=0){
        ExamenYNotas obj;

     FILE *p;
     p=fopen("ExamenYNotas.dat", "rb+");
     if(p==NULL){return false;}
     int pos=0;
     while(obj.LeerEnDiscoExamenYNotas(pos)){
            if(pos==pos2){
     obj.setIDAlumno(ID);
     fseek(p, pos2*sizeof obj, 0);
     fwrite(&obj, sizeof obj, 1, p);
     fseek(p,0,2);
            }
            pos++;
     }
     fclose(p);
     return true;

}
return false;
}

void cambiarIDAlumno(){
int idEx;
int pos;
int idAl;
do{
cout << "INGRESE ID DEL EXAMEN A MODIFICAR: ";
cin >> idEx;
pos=BuscarID(idEx);
if (pos==-1){
    cout<<endl;
}
}while(pos==-1);

cout << "INGRESE UN ID NUEVO DE ALUMNO: ";
cin >> idAl;


if(ModificarID(pos,idAl)){cout << "SE MODIFICO EL ID DEL ALUMNO"<<endl;}

}

int BuscarIDDoble(int idEx, int idAl){
ExamenYNotas obj;
int pos=0;
while(obj.LeerEnDiscoExamenYNotas(pos)){
        if(idEx==obj.getIDExamen()){
                if(idAl==obj.getIDAlumno()){

            return pos;
            }
        }
    pos++;
}
cout << "EL ID NO COINCIDE CON NINGUN EXAMEN DEL ALUMNO";
return -1;
}

bool ModificarNotaEnDisco(int pos2, int Nota){
if(pos2>=0){
        ExamenYNotas obj;

     FILE *p;
     p=fopen("ExamenYNotas.dat", "rb+");
     if(p==NULL){return false;}
     int pos=0;
     while(obj.LeerEnDiscoExamenYNotas(pos)){
            if(pos==pos2){
     obj.setNota(Nota);
     fseek(p, pos2*sizeof obj, 0);
     fwrite(&obj, sizeof obj, 1, p);
     fseek(p,0,2);
            }
            pos++;
     }
     fclose(p);
     return true;

}
return false;
}

void cambiarNota(){
int Nota;
int pos;
int idAl, idEx;
do{
cout << "INGRESE ID DEL ALUMNO A MODIFICAR: ";
cin >> idAl;
cout << "INGRESE ID DEL EXAMEN A MODIFICAR: ";
cin >> idEx;
pos=BuscarIDDoble(idEx, idAl);
if (pos==-1){
    cout<<endl;
}
}while(pos==-1);

cout << "INGRESE LA NOTA CORRECTA: ";
cin >> Nota;


if(ModificarNotaEnDisco(pos, Nota)){cout << "SE MODIFICO LA NOTA"<<endl;}

}

void ExamenYNotas::cargarExamenYNotas()
{
    cout << "ID Alumno: ";
    cin >>IDAlumno;
    cout << "ID Maestro: ";
    cin >> IDMaestro;
    cout << "ID Materia: ";
    cin >> IDMateria;
    cout << "ID Examen: ";
    cin >> IDExamen;
    cout << "Nota: ";
    cin >> Nota;
}
void ExamenYNotas::mostrarExamenYNotas()
{
    cout << "ID Alumno: ";
    cout << IDAlumno <<endl;
    cout << "ID Maestro: ";
    cout << IDMaestro <<endl;
    cout << "ID Materia: ";
    cout << IDMateria <<endl;
    cout << "ID Examen: ";
    cout << IDExamen <<endl;
    cout << "Nota: ";
    cout << Nota <<endl;
}
bool ExamenYNotas::GrabarEnDiscoExamenYNotas()
{
    FILE *p;
    p=fopen ("ExamenYNotas.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(ExamenYNotas),1,p);
    fclose(p);
    return escribio;
}
bool ExamenYNotas::LeerEnDiscoExamenYNotas(int nroRegistro)
{
    FILE *p = fopen("ExamenYNotas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(ExamenYNotas), SEEK_SET);
    bool leyo = fread(this, sizeof(ExamenYNotas), 1, p);
    fclose(p);
    return leyo;
}

int ExamenNotas(){
    int Opc;
    ExamenYNotas obj;
    int pos=0;
    while(true)
    {
        system("cls");
        cout<< "| MENU Examen y Notas | "<<endl;
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
