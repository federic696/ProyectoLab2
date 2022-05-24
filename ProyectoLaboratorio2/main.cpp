#include <iostream>

using namespace std;
int Alumno();
int main(){
 int Opc;
    while(true)
    {
        system("cls");
        cout<< "\t MENU PRINCIPAL "<<endl;
        cout<< "INGRESAR ALUMNO"<<endl;
        cout<< "INGRESAR MAESTRO"<<endl;
        cout<< "INGRESAR NOTAS"<<endl;
        cout<< "INGRESAR GRADOS"<<endl;
        cout<< "0.  Salir"<<endl;
        cin>>Opc;
        system("cls");
        switch(Opc)
        {
        case 1:
                Alumno();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

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
