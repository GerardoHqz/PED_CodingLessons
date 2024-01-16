#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void addText();

int main(){

    addText();

    return 0;
}

void addText(){
    ofstream fichero;
    //abrimos el fichero en modo añadir
    fichero.open("nombres.txt",ios::app);
    if (fichero.fail()){
        cout<<"No se pudo abrir el fichero";
        exit(1);
    }
    //leemos el fichero
    string texto;
    char rpt;
    do{
        cout<<"Digite un nombre: ";
        cin>>texto;
        fichero<<texto<<endl;
        cout<<"Desea agregar otro nombre (S/N): ";
        cin>>rpt;
    }while((rpt == 'S') || (rpt == 's'));
    //cerramos el fichero
    fichero.close();
}