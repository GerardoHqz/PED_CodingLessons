// #1.  Escribir un programa en C++ que tenga almacenado un valor entero, 
// ocupando punteros modificar el valor entero y mostrarlo en consola
#include <iostream>


using namespace std;

int main(){

    int a = 5;
    int *p;

    //p = &a
    p = &a;
    cout<<"direccion: "<<p<<endl;

    //*p = a
    *p=a;
    cout<<"direccion con puntero: "<<p<<endl;

    //obteninedo el dato
    cout<<"Valor de la variuable a: "<<*p;

    //no se puede
    //p = a;
    // *p = &a;

    return 0;
}



