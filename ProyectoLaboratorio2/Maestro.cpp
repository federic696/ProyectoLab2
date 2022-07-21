#include<iostream>
#include<conio.h>
#include "Maestro.h"
using namespace std;
#include "rlutil.h"
#include <cstdio>
#include <iomanip>




void recuadroma1(int x, int y, int ancho, int alto);
void recuadroma(int x, int y, int ancho, int alto);
void BuscarMaestro();
void ModificarMaestro();
void borrarRegistroMaestro();
void recuperarRegistrosMaestro();

int Maestros(){
int Opc;
int Pos=0;
Maestro mas;
    while(true)
    {
        system("cls");
        recuadroma(1,1,60,20);
        recuadroma1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU MAESTROS |"<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Cargar Maestro"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Mostrar Maestros"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Buscar por DNI"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Modificar Maestro por DNI"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - Dar de baja por DNI"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Dar de alta por DNI"<<endl;
        rlutil::locate(11,19);
        cout<< "F7 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            system("cls");
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR MAESTRO |"<<endl;
            mas.cargarMaestro();
            system("pause");
            break;
        case 19:
            system("cls");
            mas.mostrarMaestro();

            break;
        case 20:
            system("cls");
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR MAESTRO |"<<endl;
            BuscarMaestro();
            break;
        case 21:
            system("cls");
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR MAESTRO |"<<endl;
            ModificarMaestro();

        case 22:
            system("cls");
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE BAJA |"<<endl;
            borrarRegistroMaestro();


            break;
        case 23:
            system("cls");
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE ALTA |"<<endl;
            recuperarRegistrosMaestro();




          break;

        case 24:
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}




void Maestro::cargarMaestro(){
    int leg=100000+ (rand() % 999999);
    rlutil::locate(2,8);
    cout << "Nombre: ";
    cin >>nombre;
    rlutil::locate(2,9);
    cout << "Apellido: ";
    cin >> apellido;
    rlutil::locate(2,10);
    cout << "DNI: ";
    cin >> DNI;
    rlutil::locate(2,11);
    cout << "Email: ";
    cin >> email;
    rlutil::locate(2,10);
     while(BuscarLegajo(leg)==0){
        /*rlutil::locate(2,18);
        cout<< "Ingrese un legajo no exitente: ";
        cin>>legajo;*/
        leg=100000+ (rand() % 999999);
    }
    legajo=leg;
    rlutil::locate(2,12);
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    estado=true;

    if(GrabarEnDiscoMaestro()) cout << "MAESTRO CARGADO CORRECTAMENTE! LEGAJO: "<<legajo<<endl;
}

void Maestro::mostrarMaestro(){
    system("cls");
    int pos=0;

    cout << left;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "                            | MAESTROS REGISTRADOS |"<< endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(30) << "APELLIDOS";
    cout << setw(30) << "NOMBRES";
    cout << setw(15) << "DNI";
    cout << setw(15) << "EMAIL";
    cout << setw(15) << "ESTADO";
    cout << setw(15) << "LEGAJO";
    cout << setw(15) << "FECHA NAC" << endl;

    cout << "------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDiscoMaestro(pos++)){
            cout << left;
            cout << setw(30) << apellido;
            cout << setw(30) << nombre;
            cout << setw(15) << DNI;
            cout << setw(15) << email;
            cout << setw(15) << estado;
            cout << setw(15) << legajo;
            fechaN.MostrarFecha();

            //pos++;
      }


            system("pause");
}


//La nueva funcion de mostrar se basa en esta.

void Maestro::mostrarMaestro2(){
        rlutil::locate(2,8);
        cout << "Nombre: ";
        cout << nombre << endl;
        rlutil::locate(2,9);
        cout << "Apellido: ";
        cout << apellido << endl;
        rlutil::locate(2,10);
        cout << "DNI: ";
        cout << DNI << endl;
        rlutil::locate(2,11);
        cout << "Email: ";
        cout << email << endl;
        rlutil::locate(2,12);
        cout << "Fecha de nacimiento: ";
        fechaN.MostrarFecha();
        if(estado==true){
            rlutil::locate(2,13);
            cout<<"Persona activa"<<endl;
        }
        else{
          rlutil::locate(2,13);
          cout<<"Persona inactiva"<<endl;
        }



}

bool Maestro::GrabarEnDiscoMaestro(){
    FILE *p;
    p=fopen ("Maestro.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Maestro),1,p);
    fclose(p);
    return escribio;
}

bool Maestro::LeerEnDiscoMaestro(int nroRegistro){
    FILE *p = fopen("Maestro.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Maestro), SEEK_SET);
    bool leyo = fread(this, sizeof(Maestro), 1, p);
    fclose(p);
    return leyo;
}

int Maestro::ModificarEnDisco(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Maestro.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Maestro),0);
    escribio=fwrite(this,sizeof(Maestro),1,pAlu);
	fclose(pAlu);
	return escribio;

}

///funciones goables


void BuscarMaestro(){
    Maestro Reg;
    int Pos=0;
    int DNI=0;
    rlutil::locate(2,6);
    cout<< "Ingrese el DNI del maestro: ";
    cin>>DNI;
    while(Reg.LeerEnDiscoMaestro(Pos++))
    {
        if(Reg.getDNI()==DNI)
        {
            Reg.mostrarMaestro2();
            break;
        }
        else{
        rlutil::locate(2,10);
        cout << "No se encontro un maestro con el DNI ingresado"<<endl;
        }
    }
    rlutil::locate(10,20);
    system("pause");
}


void ModificarMaestro(){
    char Nombre[30],Apellido[30],Email[30];
    int Pos=0, dni=0, DNI=0,Dia=0,Mes=0,Anio=0;
    Maestro Reg;
    rlutil::locate(2,6);
    cout<< "ingrese el DNI del maestro: ";
    cin>> DNI;
    while(Reg.LeerEnDiscoMaestro(Pos++)){
        if(Reg.getDNI()==DNI){
            rlutil::locate(10,7);
            cout<< "Actualice los datos del maestro: ";
            rlutil::locate(2,8);
            cout << "Nombre: ";
            cin >> Nombre;
            Reg.setNombre(Nombre);
            rlutil::locate(2,9);
            cout << "Apellido: ";
            cin >> Apellido;
            Reg.setApellido(Apellido);
            rlutil::locate(2,10);
            cout << "DNI: ";
            cin >> dni;
            Reg.setDNI(dni);
            rlutil::locate(2,11);
            cout << "Email: ";
            cin >> Email;
            Reg.setEmail(Email);
            rlutil::locate(2,12);
            cout << "Fecha de nacimiento: ";
            Reg.getfecha().CargarFecha();
            Reg.ModificarEnDisco(Pos-1);
            rlutil::locate(10,20);
            system("pause");
            break;
            }
    }
        if(Reg.getDNI()!=DNI){
          rlutil::locate(2,8);
          cout << "No se encontro un maestro con el DNI ingresado" << endl;
        }
}

void borrarRegistroMaestro(){
    Maestro alu;
    int pos=0;
    int dni;
    rlutil::locate(2,6);
    cout<<"Ingrese el dni del profesor a borrar: ";
    cin>>dni;
    while(alu.LeerEnDiscoMaestro(pos)){
    if(alu.getDNI()==dni){
        alu.setEstado(false);
        alu.ModificarEnDisco(pos);
        rlutil::locate(2,8);
        cout << "Se realizo la baja" << endl;
        rlutil::locate(10,20);
        system("pause");
        break;
    }
    pos++;
  }
    cout << "No se encontro el id" << endl;
}

void recuperarRegistrosMaestro(){
    Maestro alu;
    int pos=0;
    int dni;
    rlutil::locate(2,6);
    cout<<"Ingrese el dni del maestro a dar de alta: ";
    cin>>dni;
    while(alu.LeerEnDiscoMaestro(pos)==1){
        if(alu.getEstado()==false && alu.getDNI()==dni){
            alu.setEstado(true);
            alu.ModificarEnDisco(pos);
            rlutil::locate(2,10);
            cout << "Se realizo el alta" << endl;
            rlutil::locate(10,20);
            system("pause");
            break;

        }
        pos++;
    }
      if(alu.getDNI()!=dni){
        rlutil::locate(2,8);
        cout << "No se encontro alumno con el legajo ingresado" << endl;
      }
}


void recuadroma1(int x, int y, int ancho, int alto){

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
void recuadroma(int x, int y, int ancho, int alto){

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
