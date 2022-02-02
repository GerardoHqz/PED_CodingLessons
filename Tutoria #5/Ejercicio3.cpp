// #3 Realizar un programa con colas en el cual se almacenen 
// caracteres ingresados por el usuario, debe contener una opción para 
// poder buscar un carácter en especifico dentro de la cola dicho 
// carácter es dado por el usuario

#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void searchChar(queue<char>, char );
void ShowQueue (queue<char>);

int main(){
    queue<char> charQueue;
    char character,search;
    int option = 0;
    bool status = true;

    do{
        system("cls");
        cout<<"*****MENU*****"<<endl;
        cout<<"1. Insertar caracter"<<endl;
        cout<<"2. Buscar caracter"<<endl;
        cout<<"3. Mostrar cola de caracterese"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"\nIngrese una opcion: ";
        cin>>option;

        switch(option){
            case 1:
                cout<<"\nIngrese un caracter: ";
                cin>>character;
                //utilizamos push como palabra definida para colas para agregar un elemento a la cola
                charQueue.push(character);
                system("pause");
                break;
            case 2:
                cout<<"\nIngrese un caracter a buscar: ";
                cin>>search;
                searchChar(charQueue,search);
                system("pause");
                break;
            case 3:
                ShowQueue(charQueue);
                system("pause");
                break;
            case 4:
                status = false;
                break;
            default:
                cout<<"\nOpcion no valida"<<endl;
                system("pause");
                break;
        }

    }while(status);




    return 0;
}

void searchChar(queue<char> queueChar, char search){
    queue<char> clone = queueChar;
    int cont = 1;
    bool status = false;

    while(!clone.empty()){
        if(clone.front() == search){
            cout<<"\nEl caracter "<<search<<" se encuentra en la posicion "<<cont<<endl;
            status = true;
            break;
        }
        else{
            clone.pop();
            cont++;
        }
    }

    if(!status){
        cout<<"\nEl caracter "<<search<<" no se encuentra en la cola"<<endl;
    }
}

void ShowQueue (queue<char>cola){
    queue<char>clone = cola;
    while(!clone.empty()){
        if(clone.empty()){
            cout<<"\nLa cola esta vacia\n";
        }
        else{
            cout<<clone.front()<<" ";
            clone.pop();
        }
    }
    cout<<endl;
}