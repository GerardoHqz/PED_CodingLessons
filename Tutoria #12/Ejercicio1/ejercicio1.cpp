#include <iostream>
//libreria para ficheros
#include <fstream>

using namespace std;

//funcion para escribir txt
void write();

int main(){

    write();

    return 0;
}

void write(){
    //Pedimos un nombre
    string nombre;
    cout << "Introduce un nombre: ";
    cin >> nombre;

    //creamos un fichero
    ofstream fichero;
    //abrimos el fichero
    fichero.open("fichero.txt",ios::out);
    if (fichero.fail()){
        cout<<"No se pudo abrir el fichero";
        exit(1);
    }
    //escribimos en el fichero
    fichero << "Hola "<<nombre<<", que tengas un buen dia!" << endl;
    //cerramos el fichero
    fichero.close();
}
