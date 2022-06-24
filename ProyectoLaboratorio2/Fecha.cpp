#include<iostream>
#include<conio.h>
#include "Fecha.h"
using namespace std;
#include "rlutil.h"

void Fecha::MostrarFecha()
{
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}
void Fecha::CargarFecha()
{
    int d;
    rlutil::locate(2,14);
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    rlutil::locate(2,15);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    rlutil::locate(2,16);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}
