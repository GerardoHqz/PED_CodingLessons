#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void read();

int main(){

    read();

    return 0;
}

void read(){
    //creamos un fichero
    ifstream fichero;
    //abrimos el fichero
    fichero.open("nombres.txt",ios::in);
    if (fichero.fail()){
        cout<<"No se pudo abrir el fichero";
        exit(1);
    }
    //leemos el fichero
    string texto;
    while(!fichero.eof()){
        getline(fichero,texto);
        cout<<texto<<endl;
    }
    //cerramos el fichero
    fichero.close();
}