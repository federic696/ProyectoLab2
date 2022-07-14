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
    rlutil::locate(4,14);
    cout<<"DIA: ";
    cin>>d;
    while(d<1 || d>31){
        cout<<"ELIGA UN DIA VALIDO: ";
        cin>>d;
    }
    setDia(d);
    rlutil::locate(4,15);
    cout<<"MES: ";
    cin>>d;
    while(d<1 || d>12){
        cout<<"ELIGA UN MES VALIDO: ";
        cin>>d;
    }
    setMes(d);
    rlutil::locate(4,16);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}
