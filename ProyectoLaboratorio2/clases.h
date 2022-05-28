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
    char Nombre[30];
    char Apellido[30];
    int DNI;
    char Email[30];
    Fecha FechaN
    bool Estado;

  public:
    //sets()
    void SetNombre(char *n);
    void SetApellido(char *a);
    void SetDNI(int d);
    void SetEmail(int e);
    void SetFecha();
    void SetEstado();

    //gets()
    char *GetNombre();
    char *GetApellido();
    int GetDNI();
    bool GetEstado();












};

#endif // CLASES_H_INCLUDED
