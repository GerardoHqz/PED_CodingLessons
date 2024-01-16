// #3 Realizar un programa con colas en el cual se almacenen 
// caracteres ingresados por el usuario, debe contener una opción para 
// poder buscar un carácter en especifico dentro de la cola dicho 
// carácter es dado por el usuario

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>
//Libreria para el manejo de archivos
#include <fstream>

using namespace std;

void ShowQueue();
void SearchChar(char);
void write(char);
void read();

queue<char> cola;

int main(){
    
    char dato, buscar;
    int opcion = 0;
    bool status = true;

    read();
    do{
        system("cls");
        cout<<"*****Menu de opciones*****\n"<<endl;
        cout<<"1. Ingresar un caracter a la cola"<<endl;
        cout<<"2. Buscar un caracter en la cola"<<endl;
        cout<<"3. Mostrar los caracteres de la cola"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese un caracter: ";
                cin>>dato;
                //Agregamos el dato a la cola
                cola.push(dato);
                write(dato);
                cout<<"\nCaracter agregado correctamente!\n";
                system("pause");
                break;
            case 2:
                cout<<"Ingrese el caracter a buscar: ";
                cin>>buscar;
                SearchChar(buscar);
                system("pause");
                break;
            case 3:
                ShowQueue();
                system("pause");
                break;
            case 4:
                status = false;
                break;
            default:    
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    }while(status);

    
    return 0;
}

void SearchChar(char dato){
    queue<char>clone = cola;
    int posicion = 1;
    bool status = false;

    while(!clone.empty()){
        if(clone.front() == dato){
            cout<<"El caracter se encuentra en la posicion: "<<posicion<<endl;
            status = true;
            break;
        }
        else{
            clone.pop();
            posicion++;
        }
    }
    //status == false
        if(!status){
            cout<<"El caracter no se encuentra en la cola"<<endl;
        }
}

void write(char dato){
    ofstream archivo;
    archivo.open("fichero.txt", ios::app);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    archivo<<dato<<endl;
    archivo.close();
}

void read(){
    ifstream archivo;
    archivo.open("fichero.txt", ios::in);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!archivo.eof()){
        char dato;
        archivo>>dato;
        cola.push(dato);
    }
    archivo.close();
}

void ShowQueue(){
    queue<char>clone = cola;

    while(!clone.empty()){
        if(clone.empty()){
            cout<<"La cola esta vacia!\n";
        }
        else{
            cout<<clone.front()<<" ";
            clone.pop();
        }
    }
    cout<<"\n";
}