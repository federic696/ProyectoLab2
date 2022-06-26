#include<iostream>
#include<conio.h>
#include "Materia.h"
#include "rlutil.h"

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

void Materia::cargarMateria()
{
    Materia reg;
    rlutil::locate(2,8);
    cout<<"ID:";
    cin>>reg.IDMateria;
    rlutil::locate(2,9);
    cout<<"Nombre Materia:";
    cin>>reg.nombreMateria;
    rlutil::locate(2,10);
    cout<<"ID Maestro:";
    cin>>reg.IDMaestro;
    reg.estado=true;
    reg.GrabarEnDiscoMateria();
}
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

void mostrarTodasMaterias(){
    Materia reg;
    int pos=0;
    while(reg.LeerEnDiscoMateria(pos)==1){
        reg.mostrarMateria();
        rlutil::locate(10,20);
        system("pause");
        pos++;

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
        cout<< "F6 - Subir materia  por grado"<<endl;
        rlutil::locate(11,19);
        cout<< "F7 - Volver a menu"<<endl;
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
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| MATERIAS |"<<endl;
            mostrarTodasMaterias();
            break;
        case 21:

            break;
        case 22:
            system("cls");
            recuadromate(1,1,60,20);
            recuadromate1(1,1,60,20);
            rlutil::locate(20,3);
            cout<< "| CARGAR MATERIA |"<<endl;

            reg.cargarMateria();
            break;
        case 23:

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

