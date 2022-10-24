/*Ejercicio 2: Crear una lista que almacene "n" números reales  y calcular su suma y promedio.*/

#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

void insertarLista(Nodo *&,float);
void eliminarNodo(Nodo *&,int);
void elminarLista(Nodo *&,int &);
void buuscarNodo(Nodo *,int);
void mostrarLista(Nodo *);


int main(){
	Nodo *lista = NULL;
	
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

//eliminar un nodo de la lista
void eliminarNodo(Nodo *&lista,int n){
    if(lista != NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;
        
        while((aux_borrar != NULL) && (aux_borrar->dato != n)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        
        if(aux_borrar == NULL){
            cout<<"El elemento "<<n<<" no se encuentra en la lista";
        }
        else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
            cout<<"Elemento "<<n<<" eliminado";
        }
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout<<"Elemento "<<n<<" eliminado";
        }
    }
}

//eliminar todos los nodos de la lista
void elminarLista(Nodo *&lista,int &n){
    Nodo *aux;
    while(lista != NULL){
        aux = lista;
        lista = lista->siguiente;
        delete aux;
    }
    cout<<"Se han eliminado todos los elementos de la lista";
}


//Buscando un nodo en la lista
void buuscarNodo(Nodo *lista,int n){
    bool band = false;
    
    Nodo *actual = new Nodo();
    actual = lista;
    
    while((actual != NULL)){
        if(actual->dato == n){
            band = true;
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

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
	while(lista != NULL){ //mientras no sea el final de la lista
		cout<<lista->dato<<" -> "; //mostramos el dato
		lista = lista->siguiente; //avanzamos una posicion mas en la lista
	}
}
