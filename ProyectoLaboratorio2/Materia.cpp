#include<iostream>
#include<conio.h>
#include "Materia.h"
#include "rlutil.h"
#include <cstdio>
#include <iomanip>
using namespace std;

void recuadromate(int x, int y, int ancho, int alto){

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

void recuadromate1(int x, int y, int ancho, int alto){

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

int BuscarIdMateria(int ID){
    Materia Reg;
    int Pos=0;

    while(Reg.LeerEnDiscoMateria(Pos++)){
        if(Reg.getIDMateria()==ID){
            return 0;
        }
    }

    return 1;

}

void Materia::mejorPromedio(){
    Alumno reg;
    int cantAlumnos=reg.cantidadAlumnos();

    int IDAlumn[cantAlumnos]={0};
    int sumaNota[cantAlumnos]={0};
    int cantNota[cantAlumnos]={0};
    float promedio[cantAlumnos]={0};
    ExamenYNotas reg2;
    int pos=0;
    int pos2=0;

    while(reg.LeerEnDiscoAlumno(pos++)){
        for(int i=0;i<cantAlumnos;i++){
            if(IDAlumn[i]==0){
                IDAlumn[i]=reg.GetLegajo();
                break;
            }
        }
    }
    while(reg2.LeerEnDiscoExamenYNotas(pos2++)){
        for(int i=0;i<cantAlumnos;i++){
            if(IDAlumn[i]==reg2.getIDAlumno() && reg2.getIDExamen()== getIDMateria()){
                sumaNota[i]+=reg2.getNota();
                cantNota[i]++;
            }
        }
    }

    for(int i=0; i<cantAlumnos;i++){
       promedio[i]=sumaNota[i]/cantNota[i];
    }

    int mayorAlumno=0;
    float mayorPromedio=0;

    for(int i=0; i<cantAlumnos;i++){
       if(promedio[i]>mayorPromedio){
        mayorPromedio=promedio[i];
        mayorAlumno=i;
       }
    }
    char nombreAlumno[30];
    pos=0;
    while(reg.LeerEnDiscoAlumno(pos++)){
        if(IDAlumn[mayorAlumno]==reg.GetLegajo()){
                strcpy(nombreAlumno,reg.getNombre());
            //*nombreAlumno=reg.getNombre();
            break;
        }
    }
    rlutil::locate(2,8);
    cout<<"Materia: "<<getNombreMateria()<<endl;
    rlutil::locate(2,9);
    cout<<"Mejor Promedio: "<<mayorPromedio<<endl;
    rlutil::locate(2,10);
    cout<<"Alumno: "<<nombreAlumno<<endl;
}
bool checkIdMaestro(int id){
    Maestro reg;
    int pos=0;
    while(reg.LeerEnDiscoMaestro(pos++)){
        if(reg.GetLegajo()==id){
            return true;
        }
    }

    return false;
}
void Materia::cargarMateria()
{
        int ID=10000+ (rand() % 99999);
    Grado reg2;
    Materia reg;
    rlutil::locate(2,8);
    cout<<"Grado: ";
    cin>>reg.grado;
    while(reg.grado<1 || reg.grado>12){
       rlutil::locate(2,8);
    cout<<"Ingrese un Grado valido: ";
    cin>>reg.grado;
    }
   /* cout<<"ID:";
    cin>>reg.IDMateria;
    rlutil::locate(2,10);*/
     while(BuscarIdMateria(ID)==0){
        ID=10000+ (rand() % 99999);
    }
    reg.IDMateria=ID;
    rlutil::locate(2,9);
    cout<<"Nombre Materia:";
    cin>>reg.nombreMateria;
    rlutil::locate(2,11);
    cout<<"ID Maestro:";
    cin>>reg.IDMaestro;
    while(checkIdMaestro(reg.IDMaestro)==false){
       rlutil::locate(2,11);
    cout<<"Ingrese un ID de Maestro valido:";
    cin>>reg.IDMaestro;
    }
    reg.estado=true;
    reg.GrabarEnDiscoMateria();
    reg2.LeerEnDiscoGrado(reg.grado-1);
    reg2.setIDMateria(reg.IDMateria);
    reg2.ModificarEnDisco(reg.grado-1);
     cout<<"MATERIA CARGADA CON EXITO, ID= "<<reg.getIDMateria()<<endl;
    system("pause");
}
void Materia::mostrarMateria(){
    system("cls");
    int pos=0;

    cout << left;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                            | MATERIAS REGISTRADAS |"<< endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << "ID MATERIA";
    cout << setw(30) << "NOMBRE MATERIA";
    cout << setw(30) << "ID MAESTRO";
    cout << setw(15) << "ESTADO" << endl;

    cout << "------------------------------------------------------------------------------------------------------" << endl;
      while(LeerEnDiscoMateria(pos++)==1){
            cout << left;
            cout << setw(15) << IDMateria;
            cout << setw(30) << nombreMateria;
            cout << setw(30) << IDMaestro;
            cout << setw(30) << estado<< endl;
            pos++;
      }
    system("pause");
}

//Me baso en el antiguo prototipo para el nuevo mostrar
/*
void Materia::mostrarMateria()
{
    rlutil::locate(2,8);
    cout<<"ID Materia: "<<IDMateria<<endl;
    rlutil::locate(2,9);
    cout<<"Nombre Materia: "<<nombreMateria<<endl;
    rlutil::locate(2,10);
    cout<<"ID Maestro: "<<IDMaestro<<endl;
    rlutil::locate(2,11);
    cout<<"Estado: "<<estado<<endl;

}
*/


int Materia::ModificarEnDisco(int Pos){

    FILE *pAlu;
    int escribio;
    pAlu=fopen("Materia.dat","rb+");
    if(pAlu==NULL){
        return -1;
    }
    fseek(pAlu, Pos*sizeof(Materia),0);
    escribio=fwrite(this,sizeof(Materia),1,pAlu);
	fclose(pAlu);
	return escribio;

}
bool Materia::GrabarEnDiscoMateria()
{
    FILE *p;
    p=fopen ("Materia.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Materia),1,p);
    fclose(p);
    return escribio;
}
bool Materia::LeerEnDiscoMateria(int nroRegistro)
{
    FILE *p = fopen("Materia.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Materia), SEEK_SET);
    bool leyo = fread(this, sizeof(Materia), 1, p);
    fclose(p);
    return leyo;
}

// Simplifico la funcion en 1

/*void mostrarTodasMaterias(){
    Materia reg;
    int pos=0;
    while(reg.LeerEnDiscoMateria(pos)==1){
        reg.mostrarMateria();
       // rlutil::locate(10,20);
      //  system("pause");
        pos++;

    }
}
*/

void Materia::darDeBaja(){
    Materia reg;
    Grado reg2;
    int IDreg;
    int pos=0;
    bool baja=false;
    rlutil::locate(2,8);
    cout<<"Ingrese ID de Materia: ";
    cin>>IDreg;
    while(reg.LeerEnDiscoMateria(pos++)){
        if(IDreg==reg.getIDMateria()){
            reg.setEstado(false);
            reg.ModificarEnDisco(pos-1);
            reg2.LeerEnDiscoGrado(reg.grado-1);
            for(int i=0;i<15;i++){
                if(reg.getIDMateria()==reg2.getIDMateria(i)){
                    reg2.resetIDMateria(i);
                }
            }
            reg2.ModificarEnDisco(reg.grado-1);
            rlutil::locate(10,18);
            cout<<"Materia dada de baja con exito!"<<endl;
            baja=true;
            rlutil::locate(10,20);
            system("pause");
            break;
        }
    }
    if(baja==false){
    rlutil::locate(2,8);
    cout<<"No se encontro la materia"<<endl;
    system("pause");
    }
}

void Materia::materiaXMaestro(){
    Maestro reg;
    int pos=0;
    int pos2=0;
    while(LeerEnDiscoMateria(pos++)){
            rlutil::locate(2,8);
            cout<<"ID Materia: "<<IDMateria<<endl;
            rlutil::locate(2,9);
            cout<<"Nombre Materia: "<<nombreMateria<<endl;
        while(reg.LeerEnDiscoMaestro(pos2++)){
            if(reg.GetLegajo()==IDMaestro){
                rlutil::locate(2,10);
                cout<<"ID Maestro: "<<IDMaestro<<endl;
                rlutil::locate(2,11);
                cout<<"Nombre: "<<reg.getNombre()<<endl;
                break;
            }
        }
        pos2=0;
    }
        rlutil::locate(10,20);
        system("pause");
}


int Materias()
{
    Materia reg;
    int Opc;
    int pos=0;
    while(true)
    {
        system("cls");
        recuadromate(1,1,60,20);
        recuadromate1(1,1,60,20);
        rlutil::locate(20,3);
        cout<< "| MENU MATERIA | "<<endl;
        rlutil::locate(11,7);
        cout<< "F1 - Mostrar maestros por materias"<<endl;
        rlutil::locate(11,9);
        cout<< "F2 - Mostrar mejores promedios por materia"<<endl;
        rlutil::locate(11,11);
        cout<< "F3 - Mostrar todas las materias"<<endl;
        rlutil::locate(11,13);
        cout<< "F4 - Dar de baja una materia"<<endl;
        rlutil::locate(11,15);
        cout<< "F5 - Dar de alta una materia"<<endl;
        rlutil::locate(11,17);
        cout<< "F6 - Volver a menu"<<endl;
        rlutil::locate(0,0);
        Opc=rlutil::getkey();
        switch(Opc)
        {
        case 18:
            system("cls");
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MAESTROS POR MATERIA |"<<endl;
            reg.materiaXMaestro();
            break;
        case 19:
            system("cls");
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MEJORES PROMEDIO |"<<endl;
            while(reg.LeerEnDiscoMateria(pos++)){
             reg.mejorPromedio();
            }
            rlutil::locate(10,20);
            system("pause");
            break;
        case 20:
            system("cls");
            cout<< "| MATERIAS |"<<endl;
            reg.mostrarMateria();
            break;
        case 21:
            system("cls");
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MATERIAS |"<<endl;
            reg.darDeBaja();
            break;
        case 22:
            system("cls");
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR MATERIA |"<<endl;

            reg.cargarMateria();
            break;
        /*case 23:

            break;*/
        case 23:
            return 0;
            break;


        }
    }
    cout<< endl;
    //system("pause");
    return 0;
}

