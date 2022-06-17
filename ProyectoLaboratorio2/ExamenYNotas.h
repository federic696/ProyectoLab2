#ifndef EXAMENYNOTAS_H_INCLUDED
#define EXAMENYNOTAS_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Fecha.h"
class ExamenYNotas{
private:
    int IDAlumno;
    int IDMaestro;
    int IDMateria;
    int IDExamen;
    int Nota;
    bool estado;

public:
    //sets()
    void setIDExamen(int i){
        IDExamen=i;
    }
    void setIDAlumno(int i){
        IDAlumno=i;
    }

    void setNota(int i){
        Nota=i;
    }

    void cargarExamenYNotas();
    void mostrarExamenYNotas();
    bool GrabarEnDiscoExamenYNotas();
    bool LeerEnDiscoExamenYNotas(int nroRegistro);

    //gets()
    int getIDExamen(){
        return IDExamen;
    }
    int getIDAlumno(){
        return IDAlumno;
    }

    int getNota(){
        return Nota;
    }


};

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

#endif // EXAMENYNOTAS_H_INCLUDED
