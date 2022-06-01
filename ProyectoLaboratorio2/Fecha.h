#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int dia=0, int mes=0, int anio=0)
    {
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
    }
    void MostrarFecha();
    void CargarFecha();
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
    ~Fecha(){};
};
#endif // FECHA_H_INCLUDED
