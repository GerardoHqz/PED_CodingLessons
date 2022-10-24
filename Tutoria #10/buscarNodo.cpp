#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

void insertarLista(Nodo *&,float);
void buuscarNodo(Nodo *,int);

int main(){
    Nodo *lista = NULL;
    int dato,search;
    char option;
    
    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        //insertando elementos a la lista
        insertarLista(lista,dato);
        cout<<"Desea agregar otro elemento a la lista(s/n): ";
        cin>>option;
    }while(option == 's' || option == 'S');

    cout<<"Ingrese un caracter a buscar: ";
    cin>>search;

    buuscarNodo(lista,search);
    
    return 0;
}

//Insertar elementos al final de la lista
void insertarLista(Nodo *&lista,float n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//lista vacia
		lista = nuevo_nodo;
	}
	else{
		aux = lista; //aux señala el inicio de la lista
		while(aux->siguiente != NULL){ //recorremos la lista
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
	}
	cout<<"\tElemento "<<n<<" insertado a lista correctamente\n";
}

//Buscando un nodo en la lista
void buuscarNodo(Nodo *lista,int n){
    bool band = false;
    
    Nodo *actual = new Nodo();
    actual = lista;
    
    while((actual != NULL)){
        if(actual->dato == n){
            band = true;
            break;
        }
        actual = actual->siguiente;
    }
    
    if(band == true){
        cout<<"El elemento "<<n<<" si se encuentra en la lista";
    }
    else{
        cout<<"El elemento "<<n<<" no se encuentra en la lista";
    }
}