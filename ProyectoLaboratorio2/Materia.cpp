#include<iostream>
#include<conio.h>
#include "Materia.h"

using namespace std;


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
                IDAlumn[i]=reg.getID();
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
        if(IDAlumn[mayorAlumno]==reg.getID()){
                strcpy(nombreAlumno,reg.getNombre());
            //*nombreAlumno=reg.getNombre();
            break;
        }
    }
    cout<<"Materia: "<<getNombreMateria()<<endl;
    cout<<"Mejor Promedio: "<<mayorPromedio<<endl;
    cout<<"Alumno: "<<nombreAlumno<<endl;
    cout<< "-------------------------------"<<endl;

}

void Materia::cargarMateria()
{
    Materia reg;
    cout<<"ID:";
    cin>>reg.IDMateria;
    cout<<"Nombre Materia:";
    cin>>reg.nombreMateria;
    cout<<"ID Maestro:";
    cin>>reg.IDMaestro;
    reg.estado=true;
    reg.GrabarEnDiscoMateria();
}
void Materia::mostrarMateria()
{
    cout<<"ID Materia: "<<IDMateria<<endl;
    cout<<"Nombre Materia: "<<nombreMateria<<endl;
    cout<<"ID Maestro: "<<IDMaestro<<endl;
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
    while(reg.LeerEnDiscoMateria(pos++)==1){
        reg.mostrarMateria();
        cout<<endl;
    }
        system("pause");
}

void Materia::materiaXMaestro(){
    Maestro reg;
    int pos=0;
    int pos2=0;
    while(LeerEnDiscoMateria(pos++)){
            cout<<"ID Materia: "<<IDMateria<<endl;
            cout<<"Nombre Materia: "<<nombreMateria<<endl;
        while(reg.LeerEnDiscoMaestro(pos2++)){
            if(reg.getID()==IDMaestro){
                cout<<"ID Maestro: "<<IDMaestro<<endl;
                cout<<"Nombre: "<<reg.getNombre()<<endl;
                break;
            }
        }
            cout<< "-------------------------------"<<endl;
        pos2=0;
    }
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
        cout<< "\t MENU MATERIA "<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "1) Mostrar maestros por materias"<<endl;
        cout<< "2) Mostrar mejores promedios de alumnos por materia"<<endl;
        cout<< "3) Mostrar todas las materias"<<endl;
        cout<< "4) Dar de baja una materia"<<endl;
        cout<< "5) Dar de alta una materia"<<endl;
        cout<< "6) Subir materia  por grado"<<endl;
        cout<< "0) Volver a menu"<<endl;
        cout<< "-------------------------------"<<endl;
        cout<< "Opcion: "<<endl;
        cin>>Opc;

        system("cls");
        switch(Opc)
        {
        case 1:
            reg.materiaXMaestro();
            break;
        case 2:
            while(reg.LeerEnDiscoMateria(pos++)){
             reg.mejorPromedio();
            }
            system("pause");
            break;
        case 3:
            mostrarTodasMaterias();
            break;
        case 4:

            break;
        case 5:
            reg.cargarMateria();
            break;
        case 6:

            break;
        case 0:
            return 0;
            break;


        }
    }
    cout<< endl;
    system("pause");
    return 0;
}

