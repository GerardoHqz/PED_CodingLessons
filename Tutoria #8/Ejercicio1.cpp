// #1.  Calcular los productos de dos arreglos de un mismo tamaño n, luego verificar si un producto es par o 
// impar. Por último, almacenar los pares e impares en dos pilas diferentes y mostrar en consola los valores de 
// cada pila. Los arreglos iniciales pueden hacerse de manera quemada o dinámica pidiéndole al usuario que ingrese 
// los n valores para ambos arreglos

#include <iostream>
//Libreria para llamar a la estrcutura "pilas"
#include <stack>

using namespace std;

void showStack(stack<int>);

int main(){
    //Creacion de pilas
    stack<int> stackPar;
    stack<int> stackImpar;

    int cant = 0, array1[15], array2[15], array3[15];
    cout<<"Ingrese la cantidad de elementos que tendran los arreglos (max 15): ";
    cin>>cant;

    //Llenado de los arreglos
    for(int i = 0; i < cant; i++){
        cout<<"Ingrese un numero ["<<i+1<<"]: ";
        cin>>array1[i];
    }

    for(int i = 0; i < cant; i++){
        cout<<"Ingrese un numero ["<<i+1<<"]: ";
        cin>>array2[i];
    }

    //Multiplicacion de los arreglos
    for(int i = 0; i < cant; i++){
        int producto = array1[i] * array2[i];

        if(producto % 2 == 0)
            stackPar.push(producto);
        else
            stackImpar.push(producto);
    }

    //Mostrar los resultados
    cout<<"\nMostrando la pila de numeros pares: "<<endl;
    showStack(stackPar);

    cout<<"\nMostrando la pila de numeros impares: "<<endl;
    showStack(stackImpar);


    return 0;
}

void showStack(stack<int>pila){
    //creamos un clon de la pila
    stack<int>aux = pila;

    while(!aux.empty()){
        cout<<aux.top()<<" ,";
        aux.pop();
    }

}