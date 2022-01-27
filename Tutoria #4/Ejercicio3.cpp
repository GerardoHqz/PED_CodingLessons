// #3 Elabore una función recursiva o normal que reciba una pila y la devuelva con los elementos colocados de forma inversa.

#include <iostream>
#include <stack>

using namespace std;

void showStack(stack<int>);
void showStackInvert(stack<int>);

int main(){
    stack<int> stackInit;
    int dato = 0;

    cout<<"Ingrese numeros enteros positivos y cuando desee parar ingrese una letra \n";

    do{
        cout<<"Ingrese un numero: ";
        cin>>dato;
        stackInit.push(dato);
    }while(dato != 0);

    cout<<"\nMostrando la pila inicial \n";
    showStack(stackInit);

    cout<<"\nMostrando la pila inversa \n";
    showStackInvert(stackInit);


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

void showStackInvert(stack<int> stackInit){
    stack<int> clone = stackInit;
    stack<int> stackInvert;
    int dato = 0;

    while(!clone.empty()){
        dato = clone.top();
        clone.pop();
        stackInvert.push(dato);
    }

    while (!stackInvert.empty()) {
        cout<<stackInvert.top()<<" ";
        stackInvert.pop();
    }
}
