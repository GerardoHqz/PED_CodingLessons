// #3. Escribir un programa en C++ que permita calcular el valor máximo de una lista de enteros. 
// El programa le debe pedir al usuario que ingrese la cantidad de valores enteros que va a tener 
// la lista y luego cada uno de estos valores. Por último, el programa muestra en pantalla un puntero 
// que apunta al valor máximo

#include <iostream>

using namespace std;

void ingresar_valores(int size, int array[100]);

int main(){

    int size, array[100];
    cout << "Ingrese la cantidad de valores que desea ingresar: "; cin >> size;
    ingresar_valores(size, array);

    return 0;
}

void ingresar_valores(int size, int array[100]){
    
    int max=0, *puntero;

    for (int i = 0; i < size; i++){
        cout << "Ingrese el valor " << i+1 << ": "; cin >> array[i];

        if (array[i] > max){
            max = array[i];
            puntero = &max;
        }
    }

    cout << "El valor maximo es: " << *puntero << " y su direccion es: " << puntero;
}

