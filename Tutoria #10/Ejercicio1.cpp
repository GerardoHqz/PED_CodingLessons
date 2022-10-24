/*Ejercicio 1: Crear una lista que almacene "n" números enteros  y calcular el menor y mayor 
de ellos.*/

#include <iostream>

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

using namespace std;

void insertarLista(Nodo *&,float);
void mostrarLista(Nodo *);
void calcularNumMayor(Nodo *);
void buuscarNodo(Nodo *,int);

int main(){
    //declarando o inicializando la lista
    Nodo *lista = NULL;
    int dato;
    char option;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        //insertando elementos a la lista
        insertarLista(lista,dato);
        cout<<"Desea agregar otro elemento a la lista(s/n): ";
        cin>>option;
    }while(option == 's' || option == 'S');

    cout<<"\nMostrando la lista completa: ";
    //Llamamos la funcion de mostrar lista
    mostrarLista(lista);

    //Llamamos la funcion de calcular el numero mayor
    calcularNumMayor(lista);






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

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
	while(lista != NULL){ //mientras no sea el final de la lista
		cout<<lista->dato<<" -> "; //mostramos el dato
		lista = lista->siguiente; //avanzamos una posicion mas en la lista
	}
}

//Creando funcion para calcular el mayor numero de la lista
void calcularNumMayor(Nodo *lista){
    int mayor = 0, menor = 999999;

    while(lista != NULL){ //mientras no sea el final de la lista
        if(lista->dato > mayor){ //comprabdo el numero mayor y guardandolo
            mayor = lista->dato;
        }
        if(lista->dato < menor){ //comprobando el numero menor y guardandolo
            menor = lista->dato;
        }
        lista = lista->siguiente;  //avanzamos una posicion mas en la lista
    }

    cout<<"\nEl numero mayor de la lista es: "<<mayor;
    cout<<"\nEl numero menor de la lista es: "<<menor;

    //buscando dato
    int dato;
    cout<<"\nDigite el numero que desea buscar: ";
    cin>>dato;
    buuscarNodo(lista,1);
}

//Ingresando numero en medio de la lista
void insertarLista(Nodo *lista){
    int a = 1, b = 3, aux;
    bool band = false;

    while(lista != NULL){ //mientras no sea el final de la lista
        if(lista->dato == a){ //comprabdo el numero mayor y guardandolo
            band = true;
        }
        lista = lista->siguiente;  //avanzamos una posicion mas en la lista
    }
}

//Buscando un nodo en la lista
void buuscarNodo(Nodo *lista,int n){
    bool band = false;
    
    Nodo *actual = new Nodo();
    actual = lista;
    
    while((actual != NULL) && (actual->dato <= n)){
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