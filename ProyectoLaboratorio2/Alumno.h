#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <iostream>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string.h>
class Fecha
{
private:
    int dia, mes, anio;
public:
    Fecha(int dia=0, int mes=0, int anio=0)
    {
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
    }
    void Mostrar();
    void Cargar();
    ///gets()
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
    ///sets()
    void setDia(int d)
    {
        dia=d;
    }
    void setMes(int m)
    {
        if(m>=1 && m<=12) mes=m;
    }
    void setAnio(int a)
    {
        anio=a;
    }
    ~Fecha() {};
};
void Fecha::Mostrar()
{
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}
void Fecha::Cargar()
{
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

class Alumno{
private:
    char nombre[30];
    char apellido[30];
    int DNI;
    char email[30];
    Fecha fechaN;
    bool estado;

public:
    //sets()
    void setFecha(Fecha fn)
    {
        fechaN=fn;
    }
    void setNombre(const char *n)
    {
        strcpy(nombre,n);
    }
    void setApellido(const char *n)
    {
        strcpy(apellido,n);
    }
    void setDNI(int d)
    {
        DNI=d;
    }
    void setEmail(const char *e);
    void setFecha();
    void setEstado();
    void cargar();
    void mostrar();
    bool GrabarEnDisco();
    bool LeerEnDisco(int nroRegistro);

    //gets()
    char *getNombre()
    {
        return nombre;
    }
    char *getApellido()
    {
        return apellido;
    }
    int getDNI()
    {
        return DNI;
    }
    bool getEstado()
    {
        return estado;
    }
    Fecha getfecha()
    {
        return fechaN;
    }


};
void Alumno::cargar()
{
    cout << "Nombre: ";
    cin >>nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "DNI: ";
    cin >> DNI;
    cout << "Email: ";
    cin >> email;
    cout << "Fecha de nacimiento: ";
    fechaN.Cargar();
    cout << "Estado: ";
    cin >> estado;
}
void Alumno::mostrar()
{
    cout << "Nombre: ";
    cout << nombre << endl;
    cout << "Apellido: ";
    cout << apellido << endl;
    cout << "DNI: ";
    cout << DNI << endl;
    cout << "Email: ";
    cout << email << endl;
    cout << "Fecha de nacimiento: ";
    fechaN.Mostrar();
    cout << "Estado: ";
    cout << estado << endl;

}
bool Alumno::GrabarEnDisco()
{
    FILE *p;
    p=fopen ("Personas.dat","ab");
    if(p==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof(Alumno),1,p);
    fclose(p);
    return escribio;
}
bool Alumno::LeerEnDisco(int nroRegistro)
{
    FILE *p = fopen("Personas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Alumno), SEEK_SET);
    bool leyo = fread(this, sizeof(Alumno), 1, p);
    fclose(p);
    return leyo;
}

#endif // CLASES_H_INCLUDED
