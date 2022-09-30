// Elaborar una funcion que calcule la  suma de numeros pares e impares contenidos en una pila inicial, la funcion 
// debe recibir la pila como parametro y tambien las otras dos pilas donde se guardaran los numeros pares e impares
#include <iostream>
#include <stack>

using namespace std;

void sumParImpar(stack<int>, stack<int>, stack<int> );

int main(){
    //Creacion de pilas
    stack<int> stackInit;
    stack<int> stackImpar;
    stack<int> stackPar;

    int dato = 0;

    cout<<"Digite numeros enteros, cuando ya no quiera ingresar oprima una letra \n";
    do{
        cout<<"Ingrese un numero: ";
        cin>>dato;
        stackInit.push(dato);
    }while(dato != 0);
    
    sumParImpar(stackInit, stackPar, stackImpar);

    return 0;
}

void sumParImpar(stack<int> pilaInit, stack<int>stackPar, stack<int>stackImpar){
    int sumaPar = 0, sumaImpar = 0;

    //creamos un clon de la pila
    stack<int>clone = pilaInit;

    while(!clone.empty()){
        if(clone.top() % 2 == 0)
            stackPar.push(clone.top());
        else
            stackImpar.push(clone.top());
        clone.pop();
    }

    while(!stackPar.empty()){
        sumaPar += stackPar.top();
        stackPar.pop();
    }

    while(!stackImpar.empty()){
        sumaImpar += stackImpar.top();
        stackImpar.pop();
    }

    cout<<"La suma de los numeros pares es: "<<sumaPar<<endl;
    cout<<"La suma de los numeros impares es: "<<sumaImpar<<endl;
}
