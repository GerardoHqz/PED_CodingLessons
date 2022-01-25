// #3 Hacer un programa en C++ que le pida al usuario ingresar una opción de un menú, dicho menú debe contener las 
// opciones de: ingresar y sacar datos de una pila. Por cada operación realizada se debe mostrar en pantalla la pila 
// actualizada. Para este caso utilizar una pila de enteros y al correrse por primera vez el programa la pila debe de 
// estar vacía.

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
void ShowList(Pilas*);

int main(){
    Pilas stack;
    inicializar(&stack);
    int num = 0, option = 0;


    do{
        system("cls");
        cout<<"*****MENU DE PILA*****"<<endl;
        cout<<"1. Ingresar dato\n"; 
        cout<<"2. Sacar dato\n";
        cout<<"3. Mostrar datos\n";
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese una opcion: "; cin>>option;

        switch(option){
            case 1:
                cout<<"\nIngrese un numero: "; cin>>num;
                push(&stack,num);
                cout<<"\nLa pila se ha actualiazdo"<<endl;
                ShowList(&stack);
                cout<<endl;
                system("pause");
                break;
            case 2:
                cout<<"sacando un dato....\n";
                pop(&stack);
                cout<<"\nLa pila se ha actualiazdo"<<endl;
                ShowList(&stack);
                cout<<endl;
                system("pause");
                break;
            case 3:
                cout<<"Mostrando pila:\n";
                ShowList(&stack);
                cout<<endl;
                system("pause");
                break;
            case 4:
                cout<<"\nSaliendo..."<<endl;
                system("pause");
                break;
            default:
                cout<<"\nOpcion no valida"<<endl;
                system("pause");
                break;
        }

    }while(option != 4);

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

void ShowList(Pilas *stack){
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