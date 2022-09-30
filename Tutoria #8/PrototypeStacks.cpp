#include <iostream>
#include <string>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};
typedef nodo *Pilas;

void inicializar(Pilas *);
bool Empty(Pilas *);
void push(Pilas *,int);
void pop(Pilas *);
void showstack(Pilas *);

int main(){
  Pilas stack;





  return 0;
}

void inicializar(Pilas *stack){
    *stack = NULL;
}

bool Empty(Pilas *stack){
    return *stack == NULL;
}

void push(Pilas *stack,int n){
    nodo *AuxNodo = new nodo();
    AuxNodo ->dato = n;
    AuxNodo->siguiente = *stack;
    *stack = AuxNodo;
}

void pop(Pilas *stack){
    if(!Empty(stack)){
        nodo *aux = *stack;
        *stack = (*stack)->siguiente;
        delete aux;
    }
    else{
        return;
    }
}

void showstack(Pilas *stack){
    nodo *clone = *stack;
    bool isEmpty = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            cout<<clone->dato<<" , ";
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
}