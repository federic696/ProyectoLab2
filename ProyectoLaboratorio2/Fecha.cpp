#include<iostream>
#include<conio.h>
#include "Fecha.h"
using namespace std;

void Fecha::MostrarFecha()
{
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}
void Fecha::CargarFecha()
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
