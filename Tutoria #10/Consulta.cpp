#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

void insertarLista(Nodo *&,float);
void insertarEnXPosicion(Nodo*&,float,float,float);
void mostrarLista(Nodo *);


int main(){
	Nodo *lista = NULL;
    //insertar elementos a la lista
    int dato,add,A,B;
    char option;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        //insertando elementos a la lista
        insertarLista(lista,dato);
        cout<<"Desea agregar otro elemento a la lista(s/n): ";
        cin>>option;
    }while(option == 's' || option == 'S');
	
    cout<<"\n\nIngrese el dato a ingresar: ";
    cin>>add;
    cout<<"Despues de que dato ira: ";
    cin>>A;
    cout<<"Antes de que dato ira: ";
    cin>>B;

    insertarEnXPosicion(lista,add,A,B);
    mostrarLista(lista);

	return 0;
}

void insertarEnXPosicion(Nodo *&lista,float add,float A, float B){
    Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = add;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//lista vacia
		lista = nuevo_nodo;
	}
	else{
		aux = lista; //aux señala el inicio de la lista
		while(aux->siguiente != NULL){ //recorremos la lista
			//añadiendo dato despues de A y antes de B
            if(aux->dato == A && aux->siguiente->dato == B){
                nuevo_nodo->siguiente = aux->siguiente;
                aux->siguiente = nuevo_nodo;
            }
            aux = aux->siguiente;
		}
	}
	cout<<"\tElemento "<<add<<" insertado a lista correctamente\n";
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

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
	while(lista != NULL){ //mientras no sea el final de la lista
		cout<<lista->dato<<" -> "; //mostramos el dato
		lista = lista->siguiente; //avanzamos una posicion mas en la lista
	}
}