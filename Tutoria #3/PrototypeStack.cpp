#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};
typedef nodo *Pilas;

//Prototipos de funciones
void inicializar(Pilas*);
bool Empty(Pilas*);
void push(Pilas*,int);
void pop(Pilas*);
int size(Pilas*);
void mostrar(Pilas*);

int main(){


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

void mostrar(Pilas *stack){
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

int size(Pilas *stack){
    nodo *clone = *stack;
    int cont = 0;
    bool isEmpty = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            cont++;
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
    return cont;
}