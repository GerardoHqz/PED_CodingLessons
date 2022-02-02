// #2 Se le solicita realizar un programa para poder cobrar a los 
// clientes, donde por cada cliente pedirá su nombre y el monto a 
// cobrar, el programa debe tener la opción de ingresar el nombre de 
// un cliente para registrarlo y la opción de cobrar cliente y tener una 
// opcion para ver todos los clientes en cola.

#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using  namespace std;

struct Cliente{
    string name;
    int payment;
};

void ShowQueue(queue<Cliente>);

int main(){
    //Inicializacion de la cola
    queue<Cliente> clients;
    Cliente client,aux;
    int option = 0;
    bool status = true;

    do{
        system("cls");
        cout<<"*****MENU****\n";
        cout<<"1. Ingresar un cliente\n";
        cout<<"2. Cobrar un cliente\n";
        cout<<"3. Ver todos los clientes en cola\n";
        cout<<"4. Salir\n";

        cout<<"\nIngrese una opcion: ";
        cin>>option;

        switch(option){
            case 1:
                cin.ignore();
                cout<<"\nIngrese el nombre del cliente: ";
                getline(cin, client.name);
                cout<<"Ingrese el monto a cobrar: ";
                cin>>client.payment;
                //Añadiendo un elemento a la cola
                clients.push(client);
                cout<<"\nCliente ingresado correctamente\n\n";
                system("pause");
                break;
            case 2:
                if(clients.empty()){
                    cout<<"\nNo hay clientes en cola\n";
                }else{
                    client = clients.front();
                    cout<<"\nCliente: "<<client.name<<"\n";
                    cout<<"Monto a cobrar: "<<client.payment<<"\n";
                    clients.pop();
                    cout<<"\nCliente cobrado\n\n";
                }
                system("pause");
                break;
            case 3:
                ShowQueue(clients);
                system("pause");
                break;
            case 4:
                status = false;
                system("pause");
                break;
            default:
                cout<<"\nOpcion invalida\n";
                system("pause");
                break;
        }

    }while(status);

    return 0;
}

void ShowQueue(queue<Cliente>queueClient){
    //Clonamos la cola
    queue<Cliente>clone = queueClient;

    while(!clone.empty()){
        if(clone.empty()){
            cout<<"\nLa cola esta vacia\n";
        }
        else{
            cout<<"\nCliente: "<<clone.front().name<<endl;
            cout<<"Monto a cobrar: "<<clone.front().payment<<endl<<endl;
            clone.pop();
        }
    }
    cout<<"\n";
}