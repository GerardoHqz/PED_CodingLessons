// #1.  Calcular los productos de dos arreglos de un mismo tamaño n, luego verificar si un producto es par o 
// impar. Por último, almacenar los pares e impares en dos pilas diferentes y mostrar en consola los valores de 
// cada pila. Los arreglos iniciales pueden hacerse de manera quemada o dinámica pidiéndole al usuario que ingrese 
// los n valores para ambos arreglos

#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

void showStack(stack<int>);

int main(){

    //Creacion de pilas
    stack<int> stackPar;
    stack<int> stackImpar;

    int cant = 0, array1[15], array2[15], array3[15];
    cout<<"Cuantos numeros desea ingresar (maximo 15 numeros): ";
    cin>>cant;

    cout<<"\nRellenando el arreglo 1 \n";
    for(int i = 0; i < cant; i++){
        cout<<"Ingrese el numero "<<i+1<<": ";
        cin>>array1[i];
    }

    cout<<"\nRellenando el arreglo 2 \n";
    for(int i = 0; i < cant; i++){
        cout<<"Ingrese el numero "<<i+1<<": ";
        cin>>array2[i];
    }

    cout<<"\nCalculando los productos de los arreglos \n";
    for(int i = 0; i < cant; i++){
        int producto = array1[i] * array2[i];
        if(producto % 2 == 0){
            stackPar.push(producto);
        }else{
            stackImpar.push(producto);
        }
    }


    cout<<"\nMostrando los productos pares \n";
    showStack(stackPar);

    cout<<"\nMostrando los productos impares \n";
    showStack(stackImpar);



    return 0;
}

void showStack(stack<int> stacks){
    //Creamos una pila auxiliar o clone para mostrar nuestra pila y que no se pierdan datos
    stack<int> aux = stacks;
    while(!aux.empty()){
        cout<<aux.top()<<" ";
        aux.pop();
    }
}
