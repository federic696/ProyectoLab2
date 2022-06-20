#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
#include "Persona.h"
#include "rlutil.h"
#include "Grado.h"

///funciones globales
int BuscarLegajo(int Leg);



class Alumno:public Persona{
private:
    int legajo;
    int curso;

public:
    //sets()
    void SetLegajo(int Leg){legajo=Leg;}
    void SetCurso(int Cur){curso=Cur;}
    void cargarAlumno();
    void mostrarAlumno();
    bool GrabarEnDiscoAlumno();
    bool LeerEnDiscoAlumno(int nroRegistro);
    void ModificarDatosAlumno();
    int ModificarEnDisco(int Pos);
    //gets()
    int GetLegajo(){return legajo;}
    int GetCurso(){return curso;}



};

void Alumno::cargarAlumno(){

    rlutil::locate(2,8);
    cout << "Nombre: ";
    cin >>nombre;
    rlutil::locate(2,9);
    cout << "Apellido: ";
    cin >> apellido;
    rlutil::locate(2,10);
    cout << "DNI: ";
    cin >> DNI;

    while(DNI<=0){
        rlutil::locate(2,11);
        cout<< "Ingrese un DNI correcto: ";
        cin>>DNI;

    }
    rlutil::locate(2,12);
    cout << "Email: ";
    cin >> email;

    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    rlutil::locate(2,13);
    cout << "Legajo: ";
    cin >> legajo;
    while(BuscarLegajo(legajo)==0){
        cout<< "Ingrese un legajo no exitente: ";
        cin>>legajo;
        rlutil::locate(2,14);
    }
    rlutil::locate(2,15);
    cout << "Grado: ";
    cin >> curso;
     estado=true;

}



///Funciones dentro de disco

void Alumno::mostrarAlumno(){
    cout << "Nombre: ";
    cout << nombre << endl;
    cout << "Apellido: ";
    cout << apellido << endl;
    cout << "DNI: ";
    cout << DNI << endl;
    cout << "Email: ";
    cout << email << endl;
    cout << "Fecha de nacimiento: ";
    fechaN.MostrarFecha();
    rlutil::locate(2,12);
    cout << "Legajo: ";
    cout << legajo << endl;
    rlutil::locate(2,13);
    cout << "Curso: ";
    cout << curso << endl;
     if(estado==true){
        cout<<"Persona activa"<<endl;
    }
}
bool Alumno::GrabarEnDiscoAlumno(){
    FILE *p;
    p=fopen ("Alumno.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Alumno),1,p);
    fclose(p);
    return escribio;
}
bool Alumno::LeerEnDiscoAlumno(int nroRegistro){
    FILE *p = fopen("Alumno.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Alumno), SEEK_SET);
    bool leyo = fread(this, sizeof(Alumno), 1, p);
    fclose(p);
    return leyo;
}
int Alumno::ModificarEnDisco(int Pos){


///funciones decoracion

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Alumnos.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Alumno),0);
    escribio=fwrite(this,sizeof(Alumno),1,pAlu);
	fclose(pAlu);
	return escribio;
}
void recuadroalu(int x, int y, int ancho, int alto){

const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    //COLOR DE FONDO
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    //COLOR DE LINEAS Y LETRAS
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    //COLOR DE LETRAS
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
    rlutil::resetColor();
    rlutil::setBackgroundColor(rlutil::DARKGREY);
}
void recuadroalu1(int x, int y, int ancho, int alto){

const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐

const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─


const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │




    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::locate(i, j);
            cout << " ";

        }
    }
    rlutil::setColor(rlutil::YELLOW);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        rlutil::locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i,4);
        cout << UI_HORIZONTAL_LINE;
        rlutil::locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;

    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        rlutil::locate(x, i);
        cout << UI_VERTICAL_LINE;
        rlutil::locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    rlutil::locate(x, y);
    cout << UI_TOP_LEFT;
    rlutil::locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    rlutil::locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}






void Alumno::ModificarDatosAlumno(){
    int Pos=0;
    int Leg=0;
    cout<< "Ingrese el legajo del alumno: ";
    cin>>Leg;
    while(LeerEnDiscoAlumno(Pos++)){
        if(Leg==GetLegajo()){
            cout<< "actualise los nuevos datos del alumno: "<<endl;
            cout<< "Nombre: ";
            cin>>  nombre;
            setNombre(nombre);
            cout<< "Apellido: ";
            cin>> apellido;
            setApellido(apellido);
            cout<< "DNI: ";
            cin >> DNI;
            setDNI(DNI);
            cout << "Email: ";
            cin >> email;
            setEmail(email);
            cout << "Fecha de nacimiento: ";
            fechaN.CargarFecha();
            setFecha(fechaN);
            ModificarEnDisco(Pos);

        }
    }


}

///funciones globales

int BuscarLegajo(int Leg){
    Alumno Reg;
    int Pos=0;

    while(Reg.LeerEnDiscoAlumno(Pos++)){
        if(Reg.GetLegajo()==Leg){
            return 0;
        }
    }
    return 1;

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




#endif // ALUMNO_H_INCLUDED
