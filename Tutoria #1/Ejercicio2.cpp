// #2. Escribir un programa en C++ que reciba dos valores enteros y los almacene en dos variables. 
// Crear dos punteros, asignarlos a las variables y por medio de éstos, mostrar los valores de las 
// variables y las direcciones

#include <iostream>

using namespace std;

int main(){

    int numero1, numero2, *puntero1, *puntero2;

    cout << "Ingrese el primer numero: "; cin >> numero1;
    cout << "Ingrese el segundo numero: "; cin >> numero2;

    puntero1 = &numero1;
    puntero2 = &numero2;

    cout << "\nEl valor de la variable numero 1 es: " << numero1 << " y su direccion es: " << puntero1;
    cout << "\nEl valor de la variable numero 2 es: " << numero2 << " y su direccion es: " << puntero2;


    return 0;
}