// #3 Elabore una función recursiva o normal que reciba una pila y la devuelva con los elementos colocados de forma inversa.
#include <iostream>
#include <stack>

using namespace std;

void ShowStack(stack<int>);
void ShowStackInvert(stack<int>);

int main(){

    stack<int> pila;
    int dato = 0;

    cout<<"Digite numeros enteros, cuando ya no quiera ingresar oprima una letra \n";
    do{
        cout<<"Ingrese un numero: ";
        cin>>dato;
        pila.push(dato);
    }while(dato != 0);

    cout<<"\nMotrando la pila inicial: \n";
    ShowStack(pila);

    cout<<"\nMotrando la pila invertida: \n";
    ShowStackInvert(pila);

    return 0;
}

void ShowStack(stack<int> pila){
    while(!pila.empty()){
        cout<<pila.top()<<endl;
        pila.pop();
    }
}

void ShowStackInvert(stack<int> pila){
    stack<int> clone = pila;
    stack<int> invert;
    int dato = 0;

    //invirtiendo la pila
    while(!clone.empty()){
        invert.push(clone.top());
        clone.pop();
    }

    //imprimiendo la pila
    while(!invert.empty()){
        cout<<invert.top()<<endl;
        invert.pop();
    }
}