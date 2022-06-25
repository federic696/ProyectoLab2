#include<iostream>
#include<conio.h>
using namespace std;
#include "ExamenYNotas.h"
#include "rlutil.h"
#include "Alumno.h"

int BuscarID(int id)
{
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

bool ModificarID(int pos2, int ID)
{
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

void cambiarIDAlumno()
{
int idEx;
int pos;
int idAl;
  do{
    rlutil::locate(2,8);
    cout << "INGRESE ID DEL EXAMEN A MODIFICAR: ";
    cin >> idEx;
    pos=BuscarID(idEx);
      if (pos==-1){
        cout<<endl;
      }
  }while(pos==-1);
  rlutil::locate(2,8);
  cout << "INGRESE UN ID NUEVO DE ALUMNO: ";
  cin >> idAl;


if(ModificarID(pos,idAl)){cout << "SE MODIFICO EL ID DEL ALUMNO"<<endl;}

}

int BuscarIDDoble(int idEx, int idAl)
{
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
 rlutil::locate(2,10);
  cout << "EL ID NO COINCIDE CON NINGUN EXAMEN DEL ALUMNO";
return -1;
}

bool ModificarNotaEnDisco(int pos2, int Nota)
{
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
void cambiarNota()
{
int Nota;
int pos;
int idAl, idEx;
do{
    rlutil::locate(2,8);
    cout << "INGRESE ID DEL ALUMNO A MODIFICAR: ";
    cin >> idAl;
    rlutil::locate(2,9);
    cout << "INGRESE ID DEL EXAMEN A MODIFICAR: ";
    cin >> idEx;
    pos=BuscarIDDoble(idEx, idAl);
      if (pos==-1){
          cout<<endl;
      }
  }while(pos==-1);
  rlutil::locate(2,12);
  cout << "INGRESE LA NOTA CORRECTA: ";
  cin >> Nota;


if(ModificarNotaEnDisco(pos, Nota)){cout << "SE MODIFICO LA NOTA"<<endl;}

}

void recuadroexa1(int x, int y, int ancho, int alto)
{

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
void recuadroexa(int x, int y, int ancho, int alto)
{

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
void ExamenYNotas::cargarExamenYNotas()
{
    rlutil::locate(2,8);
    cout << "ID Alumno: ";
    cin >>IDAlumno;
    rlutil::locate(2,9);
    cout << "ID Maestro: ";
    cin >> IDMaestro;
    rlutil::locate(2,10);
    cout << "Grado: ";
    cin >> Grado;
    rlutil::locate(2,11);
    cout << "ID Examen: ";
    cin >> IDExamen;
    rlutil::locate(2,12);
    cout << "Nota: ";
    cin >> Nota;
}
void ExamenYNotas::mostrarExamenYNotas()
{
    rlutil::locate(2,8);
    cout << "ID Alumno: ";
    cout << IDAlumno <<endl;
    rlutil::locate(2,9);
    cout << "ID Maestro: ";
    cout << IDMaestro <<endl;
    rlutil::locate(2,10);
    cout << "Grado: ";
    cout << Grado <<endl;
    rlutil::locate(2,11);
    cout << "ID Examen: ";
    cout << IDExamen <<endl;
    rlutil::locate(2,12);
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
bool ExamenYNotas::GrabarEnDiscoExamenYNotas(int nroRegistro){
    FILE *p = fopen("ExamenYNotas.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(ExamenYNotas), SEEK_SET);
    bool guardo = fwrite(this, sizeof(ExamenYNotas), 1, p);
    fclose(p);
    return guardo;
}

bool eliminarExamen()
{
  int idExamen, idAlumno;
  bool ok = false;
  char confirmacion;
  int pos=0;

  cout << "ID Alumno: ";
  cin >> idAlumno;
  cout << "ID Examen: ";
  cin >> idExamen;

    pos=BuscarIDDoble(idExamen, idAlumno);
    ExamenYNotas reg;
    reg.LeerEnDiscoExamenYNotas(pos);
    if (reg.getEstado()) {
      cout << "Esta seguro de que lo quiere eliminarlo? S/N" << endl;
    }
    else {
      cout << "El Examen esta eliminado, desea restaurarlo ? S/N" << endl;
    }


    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
      reg.setEstado(!reg.getEstado());
      ok = reg.GrabarEnDiscoExamenYNotas(pos);
    }
    else {
      ok = true;
    }

  return ok;
}

int ExamenNotas(){
    int Opc;
    ExamenYNotas obj;
    int pos=0;
    while(true)
    {

        system("cls");
        recuadroexa(1,1,60,20);
        recuadroexa1(1,1,60,20);
        rlutil::locate(20,3);
        cout<< "| MENU EXAMEN Y NOTAS | "<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Cargar nuevo examen"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Modificar ID Alumno Por Examen"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Modificar Nota Por Examen Del Alumno"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Mostrar Mejores Notas de Alumnos"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - Eliminar Un Examen"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Mostrar Examenes"<<endl;
        rlutil::locate(11,19);
        cout<< "F7 - Volver a menu principal"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18: //F1
            system("cls");
            recuadroexa(1,1,60,20);
            recuadroexa1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR EXAMEN |"<<endl;
            obj.cargarExamenYNotas();
            obj.GrabarEnDiscoExamenYNotas();
            break;
        case 19: //F2
            system("cls");
            recuadroexa(1,1,60,20);
            recuadroexa1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR ID |"<<endl;
            cambiarIDAlumno();
            break;
        case 20: //F3
           system("cls");
            recuadroexa(1,1,60,20);
            recuadroexa1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MODIFICAR NOTA |"<<endl;
            cambiarNota();
            break;
        case 21: //F4


            break;
        case 22: //F5
            eliminarExamen();

            break;
         case 23: //F6
            system("cls");
            while(obj.LeerEnDiscoExamenYNotas(pos)){
            recuadroexa(1,1,60,20);
            recuadroexa1(1,1,60,20);
            obj.mostrarExamenYNotas();
            rlutil::locate(20,3);
            cout<< "| MODIFICAR ID |";
            rlutil::locate(10,20);
            system("pause");
            system("cls");
            pos++;
            }
            break;

        case 24: //F7
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}
