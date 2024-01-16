/*
    Realizar un programa mediante arboles en el cual pueda agregar pokemons,
    cada pokemon tendra una estructura con un nombre, numero de pokedex, tipo 
    primario y tipo secundario, el programa debe tener las opciones de agregar
    pokemon, mostrar pokemons, y buscar pokemons por tipo (usted puede definir
    el tipo a buscar de manera quemada).
*/

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Creando estructura de pokemon
struct Pokemon{
    string nombre;
    int nPokedex;
    string tipo1;
    string tipo2;
};
typedef struct Pokemon pokemon;

struct nodo{
    pokemon dato;
    nodo *izq;
    nodo *der;
};
typedef struct nodo *ABB;

//Prototipo de funciones
ABB CrearNodo(pokemon);
void AsignarNodo(ABB,pokemon);
void InOrden(ABB);
void postOrder(ABB,string);

int main(){
    ABB arbol;
    pokemon poke, raiz;
    bool status = true;
    int option;
    string typePoke;

    //Creando el primer nodo del arbol
    cout<<"*REGISTRO DE POKEMONS*"<<endl;
    cout<<"Ingrese un registro de pokemon para iniciar el arbol: ";
    cout<<"\nDatos del pokemon: ";
    cout<<"\nNombre: "; getline(cin,raiz.nombre);
    cout<<"Numero de pokedex: "; cin>>raiz.nPokedex;
    cin.ignore();
    cout<<"Tipo primario: "; getline(cin,raiz.tipo1);
    cout<<"Tipo secundario: "; getline(cin,raiz.tipo2);
    arbol = CrearNodo(raiz);


    do{
        system("cls");
        cout<<"*REGISTRO DE POKEMONS*"<<endl;
        cout<<"1. Agregar pokemon."<<endl;
        cout<<"2. Mostrar pokemons."<<endl;
        cout<<"3. Buscar pokemon por tipo."<<endl;
        cout<<"4. Salir."<<endl;
        cout<<"\nOpcion: ";
        cin>>option;

        switch(option){
            case 1: 
                cin.ignore();
                cout<<"\nNombre: "; getline(cin,poke.nombre);
                cout<<"Numero de pokedex: "; cin>>poke.nPokedex;
                cin.ignore();
                cout<<"Tipo primario: "; getline(cin,poke.tipo1);
                cout<<"Tipo secundario: "; getline(cin,poke.tipo2);
                AsignarNodo(arbol,poke);
                system("pause");
                break;
            
            case 2: 
                cout<<"\n*MOSTRANDO POKEMONS*"<<endl;
                InOrden(arbol);
                cout<<endl;
                system("pause");
                break;
            
            case 3:
                cin.ignore();
                cout<<"\nIngrese el tipo de pokemon a buscar: ";
                getline(cin,typePoke);
                postOrder(arbol,typePoke);
                system("pause");
                break;

            case 4: 
                status = false;
                break;
            
            default:
                cout<<"\nOpcion no valida."<<endl;
                system("pause");
                break;
        }

    }while(status);


    return 0;
}

ABB CrearNodo( pokemon valor){
    ABB hijo = new nodo();
    hijo->dato = valor;
    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void AsignarNodo(ABB arbol,pokemon valor){
    ABB temporal = arbol;

    while(true){
        if(temporal->dato.nPokedex == valor.nPokedex){
            cout<<"\nEl pokemon ya existe\n";
            break;
        }
        else if(temporal->dato.nPokedex > valor.nPokedex){
            if(temporal->izq == NULL){
                temporal->izq = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->izq;
            }
        }
        else{
            if(temporal->der == NULL){
                temporal->der = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->der;
            }
        }
    }
}

void InOrden(ABB arbol){
	if(arbol != NULL){
        InOrden(arbol->izq);
        cout<<"\nDatos del pokemon: ";
        cout<<"\nNombre: "<<arbol->dato.nombre;
        cout<<"\nNumero de pokedex: "<<arbol->dato.nPokedex;
        cout<<"\nTipo primario: "<<arbol->dato.tipo1;
        cout<<"\nTipo secundario: "<<arbol->dato.tipo2<<"\n";
        InOrden(arbol->der);
    }
}

void postOrder(ABB arbol, string type){
    if(arbol != NULL){
        cout<<"\nPokemons encontrados:\n";
        if(type.empty() || (arbol->dato.tipo1 == type || arbol->dato.tipo2 == type)){
            cout<<"\nNombre: "<<arbol->dato.nombre;
            cout<<"\nNumero de pokedex: "<<arbol->dato.nPokedex;
            cout<<"\nTipo primario: "<<arbol->dato.tipo1;
            cout<<"\nTipo secundario: "<<arbol->dato.tipo2<<"\n";
        }
        postOrder(arbol->izq,type);
        postOrder(arbol->der,type);
    }
}



