#include<iostream>
#include<conio.h>
#include "Maestro.h"
using namespace std;
#include "rlutil.h"




void recuadroma1(int x, int y, int ancho, int alto);
void recuadroma(int x, int y, int ancho, int alto);
void BuscarMaestro();


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
        cout<< "F5 - Darlo de baja o alta por DNI"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Volver a menu"<<endl;
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
            break;
        case 19:
            system("cls");
            while(mas.LeerEnDiscoMaestro(Pos)==1){
            recuadroma(1,1,60,20);
            recuadroma1(1,1,60,20);
            mas.mostrarMaestro();
            rlutil::locate(20,3);
            cout<< "| MAESTROS REGISTRADOS |"<<endl;
            rlutil::locate(10,20);
            system("pause");
            system("cls");
            Pos++;
            }
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




void Maestro::cargarMaestro(){
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
    rlutil::locate(2,12);
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    estado=true;
    GrabarEnDiscoMaestro();
}

void Maestro::mostrarMaestro(){
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
            Reg.mostrarMaestro();
        }
    }
    rlutil::locate(10,20);
    system("pause");
}


void ModificarMaestro(){
    char Nombre[30],Apellido[30],Email[30];
    int Pos=0, dni=0, DNI=0,Dia=0,Mes=0,Anio=0;
    Maestro Reg;
    cout<< "ingrese el DNI del maestro: ";
    cin>> DNI;
    while(Reg.LeerEnDiscoMaestro(Pos++)){
        if(Reg.getDNI()==DNI){
            cout<< "Actualice los datos del maestro: ";
            cout << "Nombre: ";
            cin >> Nombre;
            Reg.setNombre(Nombre);
            cout << "Apellido: ";
            cin >> Apellido;
            cout << "DNI: ";
            cin >> dni;
            cout << "Email: ";
            cin >> Email;
            cout << "Fecha de nacimiento: ";


            }
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
