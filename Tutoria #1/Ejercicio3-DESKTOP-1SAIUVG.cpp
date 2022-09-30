// #3. Escribir un programa en C++ que permita calcular el valor máximo de una lista de enteros. 
// El programa le debe pedir al usuario que ingrese la cantidad de valores enteros que va a tener 
// la lista y luego cada uno de estos valores. Por último, el programa muestra en pantalla un puntero 
// que apunta al valor máximo

// p=&numero estoy obteniendo la direccion de memoria
// *p=numero estoy obteniendo el valor de la direccion de memoria
// *p=&numero; //p es un puntero que apunta a numero1


#include <iostream>

using namespace std;

void ingresar_valores(int size, int *array[10]);
void valor_maximo(int size, int *array[100]);

int main(){

    int size, array[10],*puntero;
    puntero=&array[0];

    cout << "Ingrese la cantidad de valores que desea ingresar: "; cin >> size;

    ingresar_valores(size, &puntero);
    //valor_maximo(size, &array);

    return 0;
}

void ingresar_valores(int size, int puntero){
    //recupernaod array
    for(int i=0; i<size; i++){
        cout << "Ingrese el valor " << i+1 << ": "; cin >> puntero;
        puntero++;
    }
    
}


