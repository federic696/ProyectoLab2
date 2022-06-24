#include<iostream>
#include<conio.h>
#include "Alumno.h"
#include "Fecha.h"
using namespace std;
#include "rlutil.h"

int Alumno::cantidadAlumnos(){
    FILE *p = fopen("Alumnos.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Alumno);
    return cant_reg;
}

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
    while(LeerEnDiscoAlumno(Pos++)==1){
        if(Leg==GetLegajo()){
            LeerEnDiscoAlumno(Pos);
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
            Leg=0;
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



int Alumnos()
{

    int Opc;
    int pos=0;
    Alumno obj;

    while(true)
    {
      system("cls");
      recuadroalu(1,1,60,20);
      recuadroalu1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU ALUMNOS |"<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Cargar Estudiante"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Mostrar Estudiantes"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Buscar por DNI o Legajo"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Modificar Estudiante Por Legajo"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - Darlo de baja o alta por Legajo o DNI"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR ALUMNO |"<<endl;
            obj.cargarAlumno();
            obj.GrabarEnDiscoAlumno();
            rlutil::locate(14,17);
            if(obj.GrabarEnDiscoAlumno())cout << "ALUMNO CARGADO CORRECTAMENTE!";
            rlutil::locate(10,20);
            system("pause");
            system("cls");

            break;
        case 19:

            system("cls");
            while(obj.LeerEnDiscoAlumno(pos++)==1){

            obj.mostrarAlumno();
            cout<<endl;
            pos++;
            }
            rlutil::locate(20,3);
            cout<< "| ALUMNOS REGISTRADOS |"<<endl;
            rlutil::locate(10,20);
            system("pause");

            break;






        case 20:
                system("cls");
            cout<< "1 Buscar alumno por DNI"<<endl;
            cout<< "2 Buscar alumno por legajo"<<endl;
            cout<<"Elija una opcion: ";
            cin>>Opc;
                system("cls");
                switch(Opc){
            case 1:
                BuscarAlumnoDNI();
                break;
            case 2:
                BuscarAlumnoLegajo();
                break;
                }

            break;
        case 21:system("cls");
                obj.ModificarDatosAlumno();

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


