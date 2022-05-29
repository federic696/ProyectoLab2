#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Mostrar();
        void Cargar();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){if(m>=1 && m<=12) mes=m;}
        void setAnio(int a){anio=a;}
        ~Fecha(){};
};
void Fecha::Mostrar(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}
void Fecha::Cargar(){
    int d;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}

class Persona{
  private:
    char nombre[30];
    char apellido[30];
    int DNI;
    char email[30];
    Fecha fechaN;
    bool estado;

  public:
    //sets()
     Fecha getfecha(){return fechaN;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *n){strcpy(apellido,n);}
    void setDNI(int d){DNI=d;}
    void setEmail(const char *e);
    void setFecha();
    void setEstado();

    //gets()
    char *getNombre(){return nombre;}
    char *getApellido(){return apellido;}
    int getDNI(){return DNI;}
    bool getEstado(){return estado;}













};

#endif // CLASES_H_INCLUDED
