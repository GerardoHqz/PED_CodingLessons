// #4 Se tiene un Restaurante de 5 estrellas donde venden comida muy deliciosa, el restaurante tiene un grupo 
// de empleados muy grandes, pero tienen un problema con el orden de los platos limpios, se le solicita a usted 
// que cree un programa para poder tener control del inventario de platos, donde cada plato tendrá un material 
// específico si es vidrio, plástico o porcelana, el color del plato y el estado (sucio o limpio). Su programa 
// debe tener las siguientes opciones: ensuciar un plato individual, ensuciar n cantidad de platos, limpiar un 
// plato, limpiar n cantidad de platos y mostrar los platos limpios y otra de mostrar los platos sucios

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

struct Plate{
    string material;
    string color;
    bool estado;
};

Plate plateAux, plateI;

void showStack(stack<Plate>);

int main(){
    stack<Plate> PlatosSucios;
    stack<Plate> PlatosLimpios;

    int cant = 0, contador = 0, contAux = 0, cantPlates = 0, cantPlates2 = 0;

    //Pidiendo la cantidad de platos que tendra el usuario y llenando la pila inical
    cout<<"Ingrese la cantidad de platos que tendra su inventario: ";
    cin>>cant;
    cout<<"\n";
    cin.ignore();
    while(contador < cant){
        cout<<"Plato #"<<contAux+1<<"\n";
        cout<<"Ingrese el material del plato: ";
        getline(cin, plateI.material);
        cout<<"Ingrese el color del plato: ";
        getline(cin, plateI.color);
        plateI.estado = true;

        PlatosLimpios.push(plateI);

        contador++;
        contAux++;

        cin.ignore();
    }

    //Creacion del menu y sus opciones
    int opcion = 0;

    do{
        system("cls");
        cout<<"*****MENU RESTAURANTE GUANAO*****\n";
        cout<<"1. Ensuciar un plato\n";
        cout<<"2. Ensuciar n cantidad de platos\n";
        cout<<"3. Limpiar un plato\n";
        cout<<"4. Limpiar n cantidad de platos\n";
        cout<<"5. Mostrar platos sucios\n";
        cout<<"6. Mostrar platos limpios\n";
        cout<<"7. Salir\n";
        cout<<"Ingrese una opcion: "; cin>>opcion;

        switch (opcion) {
            case 1:
                //Ensuciar un plato
                if(!PlatosLimpios.empty()){
                    plateAux = PlatosLimpios.top();
                    PlatosLimpios.pop();
                    PlatosSucios.push(plateAux);
                    cout<<"\nPlato Ensuciado\n";
                }else{
                    cout<<"\nNo hay platos limpios\n";
                }   
                system("pause");
                break;
            case 2:
                //Ensuciar n cantidad de platos
                cout<<"\nIngrese la cantidad de platos a ensuciar: ";
                cin>>cantPlates;
                cout<<"\n";
                cin.ignore();
                if(!PlatosLimpios.empty() && cantPlates <= PlatosLimpios.size()){
                    for(int i = 0; i < cant; i++){
                        plateAux = PlatosLimpios.top();
                        PlatosLimpios.pop();
                        PlatosSucios.push(plateAux);
                    }
                    cout<<"\nPlatos Ensuciados\n";
                }
                else{
                    cout<<"\nNo hay platos limpios suficientes\n";
                }
                system("pause");
                break;
            case 3:
                //Limpiar un plato
                if(!PlatosSucios.empty()){
                    plateAux = PlatosSucios.top();
                    PlatosSucios.pop();
                    PlatosLimpios.push(plateAux);
                    cout<<"\nPlato Limpio\n";
                }else{
                    cout<<"\nNo hay platos sucios\n";
                }
                system("pause");
                break;
            case 4:
                //Limpiar n cantidad de platos
                cout<<"\nIngrese la cantidad de platos a limpiar: ";
                cin>>cantPlates2;
                cout<<"\n";
                if(!PlatosSucios.empty() && cantPlates2 <= PlatosSucios.size()){
                    for(int i = 0; i < cant; i++){
                        plateAux = PlatosSucios.top();
                        PlatosSucios.pop();
                        PlatosLimpios.push(plateAux);
                    }
                    cout<<"\nPlatos Limpiados\n";
                }
                else{
                    cout<<"\nNo hay platos sucios suficientes\n";
                }
                system("pause");
                break;
            case 5:
                //Mostrar platos sucios
                cout<<endl;
                showStack(PlatosSucios);
                system("pause");
                break;
            case 6:
                //Mostrar platos limpios
                cout<<endl;
                showStack(PlatosLimpios);
                system("pause");
                break;
            case 7:
                //Salir
                cout<<"Fin del programa\n";
                system("pause");
                break;
            default:
                cout<<"Opcion invalida\n";
                system("pause");
                break;
        }
    }while(opcion != 7);

    return 0;
}

void showStack(stack<Plate> stacks){
    //Creamos una pila auxiliar o clone para mostrar nuestra pila y que no se pierdan datos
    stack<Plate> aux = stacks;
    if(aux.empty()){
        cout<<"\nLa pila esta vacia\n";
    }
    while(!aux.empty()){
        cout<<"Plato de "<<aux.top().material<<" de color "<<aux.top().color<<"\n";
        aux.pop();
    }
}