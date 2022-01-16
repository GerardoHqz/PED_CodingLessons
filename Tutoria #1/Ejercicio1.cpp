// #1.  Escribir un programa en C++ que tenga almacenado un valor entero, 
// ocupando punteros modificar el valor entero y mostrarlo en consola
#include <iostream>


using namespace std;

int main(){

    int numero = 10, *Puntero;
    *Puntero = numero;
    cout << "¿Porque valor desea cambiarlo? "; cin>>*Puntero;
    cout<<"\n El nuevo valor es: " << *Puntero;

    return 0;
}



