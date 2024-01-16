// #1 Realizar un programa que contenga un menú con las opciones 
// de ingresar un elemento a la cola, sacar un elemento y mostrar los 
// elementos de la cola

#include <iostream>
#include <stdlib.h>
#include "cabecera.h"

using namespace std;

int main(){
    Nodo node;
    Cola queue;

    //Crear e inicializar nuestra cola
    initialize(&queue);

    int opcion = 0, dato = 0;
    bool status = true;

    do{
        system("cls");
        cout<<"*****Menu de opciones*****\n"<<endl;
        cout<<"1. Ingresar un elemento a la cola"<<endl;
        cout<<"2. Sacar un elemento de la cola"<<endl;
        cout<<"3. Mostrar los elementos de la cola"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: 
                cout<<"Ingrese un numero: ";
                cin>>dato;
                push(&queue,dato);
                system("pause");
                break;
            case 2:
                pop(&queue);
                system("pause");
                break;
            case 3:
                ShowQueue(&queue);
                system("pause");
                break;
            case 4:
                status = false;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                system("pause");
                break;
        }

    }while(status);

    return 0;
}

