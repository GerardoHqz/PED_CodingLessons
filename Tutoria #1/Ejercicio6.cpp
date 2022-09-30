// #3. Cree un programa donde se le solicite al usuario que ingrese una cantidad de valores enteros
// formando un arreglo, en dicho arreglo localize el valor máximo y muestre en pantalla el puntero que apunta al valor máximo.
// UTILIZANDO FUNCIONES

#include <iostream>

using namespace std;

int completeArray(int *array, int size);
int MaxNumber(int *array, int size);

int main(){

    int size = 5;
    int array[size];
    array[size] = completeArray(array, size);
    int max = MaxNumber(array,size);
    
    cout<<"El numero maximo del arreglo es: "<<max<<endl;

    return 0;
}

int completeArray(int *array, int size){
    for(int i=0; i<size; i++){
        cout<<"Ingrese el valor "<<i+1<<": ";
        cin>>array[i];
    }
    return 0;
}

int MaxNumber(int *array, int size){
    int max = 0;
    for(int i=0; i<size; i++){
        if(*array>max){
            max = *array;
        }
        array++;
    }
    return max;
}