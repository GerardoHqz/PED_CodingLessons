/*Ejercicio 2: Crear una lista que almacene "n" números reales  y calcular su suma y promedio.*/
#include <iostream>

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

using namespace std;

void insertarLista(Nodo *&,float);
void mostrarLista(Nodo *);
void calcularSumaPromedio(Nodo *);

int main(){
    //declarando o inicializando la lista
    Nodo *lista = NULL;
    float dato;
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
    calcularSumaPromedio(lista);

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

//Calcular la suma y promedio de los elementos de la lista
void calcularSumaPromedio(Nodo *lista){
    float suma = 0;
    int contador = 0; //denominador
    float promedio = 0;
    
    while(lista != NULL){  //mientras no sea el final de la lista
        suma += lista->dato; //sumando todos los datos de la lista
        contador++;         //incrementando el contador para saber el numero de datos
        lista = lista->siguiente; //avanzamos una posicion mas en la lista
    }
    
    promedio = suma / contador;
    
    cout<<"\nLa suma de los elementos de la lista es: "<<suma;
    cout<<"\nEl promedio de los elementos de la lista es: "<<promedio;
}