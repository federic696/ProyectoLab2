#include<iostream>
#include<conio.h>
#include "Grado.h"
#include "rlutil.h"

using namespace std;

void recuadrogra1(int x, int y, int ancho, int alto){

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
void recuadrogra(int x, int y, int ancho, int alto){

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


void cargarGrado()
{
    Grado aux;
    int pos=1;
    while(pos<=12){
        aux.setNumGrado(pos);
        aux.clearMaterias();
        aux.GrabarEnDiscoGrado();
        pos++;
    }

}
void mostrarGrado()
{
    Materia aux2;
    Grado aux;
    int pos=0;
    int pos1=0;
    while(aux.LeerEnDiscoGrado(pos++)){
       cout<<"Grado "<<aux.getNumGrado()<<endl;
       cout<<"Materias: "<<endl;
       for(int i=0;i<15;i++){
        //cout<<aux.getIDMateria(i)<<endl;
        if(aux.getIDMateria(i)!=0){
            while(aux2.LeerEnDiscoMateria(pos1++)){
                if(aux.getIDMateria(i)==aux2.getIDMateria()){
                    cout<<aux2.getNombreMateria()<<endl;
                }
            }
            pos1=0;
        }
       }
        cout<<"---------------------------"<<endl;
    }
        system("pause");
}

int Grado::ModificarEnDisco(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Grado.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Grado),0);
    escribio=fwrite(this,sizeof(Grado),1,pAlu);
	fclose(pAlu);
	return escribio;

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
int Grado::cantidadGrado()
{
    FILE *p = fopen("Grado.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Grado);
    return cant_reg;
}

void Grado::mostrarAlumnos(){
    Alumno reg;
    int pos=0;
    rlutil::locate(2,8);
    cout<<"Grado "<<numGrado<<":"<<endl;
    while(reg.LeerEnDiscoAlumno(pos++)){
        if(reg.GetCurso()==numGrado){
            cout<<reg.getNombre()<<" "<<reg.getApellido()<<endl;
        }
    }
}

int Grados(){
Grado reg;
int Opc;
    while(true)
    {
        system("cls");
        recuadrogra(1,1,60,20);
        recuadrogra1(1,1,60,20);
        rlutil::locate(23,3);
        cout<< "| MENU GRADOS |"<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Mostrar maestros y materias por grado"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Mostrar  estudiantes por grado"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Mostrar mejores promedios por grado"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            system("cls");
            recuadrogra(1,1,60,20);
            recuadrogra1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MOSTRAR GRADOS |"<<endl;
            mostrarGrado();
            break;
        case 19:
            system("cls");
            for(int i=0;i<12;i++){
              recuadrogra(1,1,60,20);
              recuadrogra1(1,1,60,20);
              rlutil::locate(20,3);
              cout<< "| MOSTRAR ESTUDIANTES |"<<endl;
              reg.LeerEnDiscoGrado(i);
              reg.mostrarAlumnos();
              rlutil::locate(10,20);
              system("pause");




            }
            break;
        case 20:

            break;
        case 21:
            return 0;
            break;
        case 23:
            cargarGrado();
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;

}
