// Elaborar una funcion que calcule la  suma de numeros pares e impares contenidos en una pila inicial, la funcion 
// debe recibir la pila como parametro y tambien las otras dos pilas donde se guardaran los numeros pares e impares

#include <iostream>
#include <stack>

using namespace std;

void SumParImpar(stack<int>, stack<int> , stack<int> );

int main(){
    stack<int> stackPar;
    stack<int> stackImpar;
    stack<int> stackInit;
    int dato = 0;

    cout<<"Digite numeros enteros positivos, cuando ya no desee ingresar oprima una letra\n";


    do{
        cout<<"Ingrese un numero: ";
        cin>>dato;
        stackInit.push(dato);
    
    //al ingresar una letra el programa lo detectara como "cero" y rompera el ciclo
    }while(dato != 0);


    SumParImpar(stackInit, stackPar, stackImpar);

    return 0;
}

void SumParImpar(stack<int>init, stack<int>par , stack<int>impar ){
    int sumPar = 0, sumImpar = 0;
    stack<int>clone = init;
    while (!clone.empty()){
        int dato = clone.top();
        clone.pop();
        if(dato % 2 == 0){
            sumPar += dato;
            par.push(dato);
        }else{
            sumImpar += dato;
            impar.push(dato);
        }
    }

    cout<<"\nLa suma de los numeros pares es: "<<sumPar<<"\n";
    cout<<"La suma de los numeros impares es: "<<sumImpar<<"\n";
}

