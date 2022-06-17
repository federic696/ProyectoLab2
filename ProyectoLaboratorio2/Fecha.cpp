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
    rlutil::locate(4,10);
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    rlutil::locate(4,11);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    rlutil::locate(4,12);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}
