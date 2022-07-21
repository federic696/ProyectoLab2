#include<iostream>
#include<conio.h>
#include "Alumno.h"
#include "Maestro.h"
#include "Fecha.h"
using namespace std;
#include "rlutil.h"
#include <cstdio>
#include <iomanip>

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
    while(DNI<=0){
        rlutil::locate(2,11);
        cout<< "Ingrese un DNI correcto: ";
        cin>>DNI;

    }
    rlutil::locate(2,12);
    cout << "Email: ";
    cin >> email;
    rlutil::locate(2,13);
    cout << "Fecha de nacimiento: ";
    fechaN.CargarFecha();
    rlutil::locate(2,17);
    //cout << "Legajo: ";
    //cin >> legajo;
    while(BuscarLegajo(leg)==0){
        /*rlutil::locate(2,18);
        cout<< "Ingrese un legajo no exitente: ";
        cin>>legajo;*/
        leg=100000+ (rand() % 999999);
    }
    legajo=leg;
    rlutil::locate(2,19);
    cout << "Grado: ";
    cin >> curso;
     estado=true;
    GrabarEnDiscoAlumno();
    rlutil::locate(12,20);
    if(GrabarEnDiscoAlumno())cout << "ALUMNO CARGADO CORRECTAMENTE! LEGAJO: "<<legajo<<endl;

}



///Funciones dentro de disco

void Alumno::mostrarAlumno(){
    system("cls");
    int pos=0;

    cout << left;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | ESTUDIANTES REGISTRADOS |"<< endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "LEGAJO";
    cout << setw(30) << "APELLIDOS";
    cout << setw(30) << "NOMBRES";
    cout << setw(15) << "DNI";
    cout << setw(15) << "ESTADO" << endl;

    cout << "------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDiscoAlumno(pos++)==1){
            cout << left;
            cout << setw(15) << legajo;
            cout << setw(30) << apellido;
            cout << setw(30) << nombre;
            cout << setw(15) << DNI;
            cout << setw(15) << estado<< endl;
            pos++;
      }

            system("pause");
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
    pAlu=fopen("Alumno.dat","rb+");
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
    Alumno reg;
    int Pos=0;
    int Leg=0;
    char n[30],mail[30];
    int dn;
    rlutil::locate(2,6);
    cout<< "Ingrese el legajo del alumno: ";
    cin>>Leg;
    while(reg.LeerEnDiscoAlumno(Pos++)==1){
        if(Leg==reg.GetLegajo()){
            rlutil::locate(10,7);
            cout<< "Actualice los nuevos datos del alumno"<<endl;
            rlutil::locate(2,8);
            cout<< "Nombre: ";
            cin>>  n;
            reg.setNombre(n);
            rlutil::locate(2,9);
            cout<< "Apellido: ";
            cin>> n;
            reg.setApellido(n);
            rlutil::locate(2,10);
            cout<< "DNI: ";
            cin >> dn;
            reg.setDNI(dn);
            rlutil::locate(2,11);
            cout << "Email: ";
            cin >> mail;
            reg.setEmail(mail);
            rlutil::locate(2,12);
            cout << "Fecha de nacimiento: ";
            reg.getfecha().CargarFecha();
            reg.ModificarEnDisco(Pos-1);
            break;
        }
    }


}

///funciones globales


void borrarRegistro(){
    Alumno alu;
    int pos=0;
    int leg;
    rlutil::locate(2,6);
    cout<<"Ingrese el legajo del alumno a borrar: ";
    cin>>leg;
    while(alu.LeerEnDiscoAlumno(pos)){
    if(alu.GetLegajo()==leg){
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
          if(alu.GetLegajo()!=leg){
          rlutil::locate(2,8);
          cout << "No se encontro un maestro con el DNI ingresado" << endl;
        }
}


int BuscarLegajo(int Leg){
    Alumno Reg;
    Maestro Reg2;
    int Pos=0;

    while(Reg.LeerEnDiscoAlumno(Pos++)){
        if(Reg.GetLegajo()==Leg){
            return 0;
        }
    }
    Pos=0;
    while(Reg2.LeerEnDiscoMaestro(Pos++)){
        if(Reg2.GetLegajo()==Leg){
            return 0;
        }
    }
    return 1;

}
void BuscarAlumnoLegajo(){
    Alumno Reg;
    int Pos=0;
    int Legajo=0;
    rlutil::locate(2,6);
    cout<< "Ingrese el legajo del alumno: ";
    cin>>Legajo;
    while(Reg.LeerEnDiscoAlumno(Pos++)){
        if(Reg.GetLegajo()==Legajo){
            Reg.mostrarAlumno();
        }
    }
    rlutil::locate(10,20);
    system("pause");

}
void BuscarAlumnoDNI(){
    Alumno Reg;
    int Pos=0;
    int DNI=0;
    rlutil::locate(2,6);
    cout<< "Ingrese DNI del alumno: ";
    cin>> DNI;
    while(Reg.LeerEnDiscoAlumno(Pos++)==1){
        if(Reg.getDNI()==DNI){
            Reg.mostrarAlumno();
        }
    }
    rlutil::locate(10,20);
    system("pause");
}

void recuperarRegistros(){
    Alumno alu;
    int pos=0;
    int leg;
    rlutil::locate(2,6);
    cout<<"Ingrese el legajo del alumno a dar de alta: ";
    cin>>leg;
    while(alu.LeerEnDiscoAlumno(pos)==1){
        if(alu.getEstado()==false && alu.GetLegajo()==leg){
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
          if(alu.GetLegajo()!=leg){
          rlutil::locate(2,8);
          cout << "No se encontro alumno con el legajo ingresado" << endl;
        }
}

float Alumno::sacarPromedio(int leg){
    //Alumno reg;

    int pos=0;
    ExamenYNotas reg2;
    int examenes[reg2.cantidadExamenesXAlumno(leg)];
    bool encontrado=false;
    int i=0;
    while(reg2.LeerEnDiscoExamenYNotas(pos++)){
        if(reg2.getIDAlumno()==leg){
                encontrado=true;
            examenes[i]=reg2.getNota();
            i++;
        }
    }
    if(encontrado==false){
        return -1;
    }
    int total=0;

    for(int f=0;f<reg2.cantidadExamenesXAlumno(leg);f++){
        total+=examenes[f];
    }
    return total/reg2.cantidadExamenesXAlumno(leg);
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
        rlutil::locate(11,6);
        cout<< "F1 - Cargar Estudiante"<<endl;
        rlutil::locate(11,8);
        cout<< "F2 - Mostrar Estudiantes"<<endl;
        rlutil::locate(11,10);
        cout<< "F3 - Buscar por DNI o Legajo"<<endl;
        rlutil::locate(11,12);
        cout<< "F4 - Modificar Estudiante Por Legajo"<<endl;
        rlutil::locate(11,14);
        cout<< "F5 - Dar de baja por Legajo"<<endl;
        rlutil::locate(11,16);
        cout<< "F6 - Dar de alta por Legajo"<<endl;
        rlutil::locate(11,18);
        cout <<"F7 - Promedios por alumno" << endl;
        rlutil::locate(11,20);
        cout<< "F8 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR ALUMNO |"<<endl;
            obj.cargarAlumno();
            rlutil::locate(10,20);
            system("pause");
            system("cls");

            break;


        case 19: //F2
        system("cls");
        obj.mostrarAlumno();



        break;


        case 20: //F3
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR ALUMNO |"<<endl;
            rlutil::locate(11,8);
            cout<< "F1 - Buscar alumno por DNI"<<endl;
            rlutil::locate(11,10);
            cout<< "F2 - Buscar alumno por legajo"<<endl;
            Opc=rlutil::getkey();
            system("cls");
            switch(Opc){
            case 18:
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR POR DNI |"<<endl;
                BuscarAlumnoDNI();
                break;
            case 19:
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| BUSCAR POR LEJAGO |"<<endl;
                BuscarAlumnoLegajo();
                break;
                }

            break;
        case 21: //F4
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR ALUMNO |"<<endl;
                obj.ModificarDatosAlumno();

            break;
        case 22: //F5
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE BAJA ALUMNO |"<<endl;
            borrarRegistro();

            break;
        case 23:
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| DAR DE ALTA ALUMNO |"<<endl;
            recuperarRegistros();

            break;
        case 24:
            system("cls");
            recuadroalu(1,1,60,20);
            recuadroalu1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| PROMEDIO DE ALUMNO |"<<endl;
            int i;
            rlutil::locate(2,8);
            cout<<"Ingrese legajo alumno: ";
            cin>>i;
            rlutil::locate(20,10);
            if(obj.sacarPromedio(i)==-1){
                cout<<"No se encontro el alumno o no tiene notas"<<endl;
                system("pause");
            }else{
            cout<<"Promedio: "<<obj.sacarPromedio(i)<<endl;
            system("pause");
            }
            break;
        case 25: //F6
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}

