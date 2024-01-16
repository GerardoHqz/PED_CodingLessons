#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *der;
	nodo *izq;
};

void Menu();
nodo *crearNodo(int );
void agregarNodo(nodo *&, int);
void MostrarArbol(nodo *, int);
bool busqueda(nodo *, int);
void PreOrden(nodo *);
void InOrden(nodo *);
void PostOrden(nodo *);

nodo *arbol = NULL;

int main(){
	Menu();
	
	
	
	getch();
	return 0;
}

void Menu(){
	int dato, opcion, contador = 0;
	
	do{
		cout<<"1. Agregar elementos al arbol. "<<endl;
		cout<<"2. Mostrar Arbol."<<endl;
		cout<<"3. Buscar en Arbol."<<endl;
		cout<<"4. Mostrar por PreOrden."<<endl;
		cout<<"5. Mostrar por InOrden."<<endl;
		cout<<"6. Mostrar por PostOrden."<<endl;
		cout<<"7. Salir."<<endl;
		cout<<"\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:	cout<<"Numero a agregar: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					break;
			case 2:	cout<<"\n.:Mostrando Arbol:."<<endl;
					MostrarArbol(arbol,contador);
					break;
			case 3: cout<<"\nNumero a Buscar: ";
					cin>>dato;
					if(busqueda(arbol,dato) == true){
						cout<<"Elemento '"<<dato<<"' SI fue encontrado.";
					}else{
						cout<<"Elemento '"<<dato<<"' NO fue encontrado.";
					}
					break;
			case 4: cout<<"\nRecorrido en PreOrden: ";
					PreOrden(arbol);
					break;
			case 5: cout<<"\nRecorrido en InOrden: ";
					InOrden(arbol);
					break;
			case 6: cout<<"\nRecorrido en InOrden: ";
					PostOrden(arbol);
					break;
		}
		system("pause");
		system("cls");
	}while(opcion != 7);
}
nodo *crearNodo(int n){
	nodo *NuevoNodo = new nodo();
	NuevoNodo->dato = n;
	NuevoNodo->der = NULL;
	NuevoNodo->izq = NULL;
	
	return NuevoNodo;
}
void agregarNodo(nodo *&arbol, int n){
	if(arbol == NULL){//verificando que arbol este vacio.
		nodo *nuevoNodo = crearNodo(n);//agregando la raiz al nuevo nodo.
		arbol = nuevoNodo;
		cout<<("Nodo raiz creado")<<endl;
	}else{
		int ValorDeRaiz = arbol->dato;//Es para saber que valor tiene la RAIZ.
		if(n < ValorDeRaiz){//Cuando el Valor es menor va al lado izquierdo.
			agregarNodo(arbol->izq,n);//Agregando al lado izquierdo.
			cout<<("Nodo izquierdo creado")<<endl;
		}else{
			agregarNodo(arbol->der,n);//Agregando al lado derecho.
			cout<<("Nodo derecho creado")<<endl;
		}
	}
}

void MostrarArbol(nodo *arbol, int cont){
	if(arbol == NULL){//Saber si el arbol esta vacio.
		return;
	}else{//Si no esta vacio.
		MostrarArbol(arbol->der,cont+1);//imprimiendo lado derecho.
		for(int i=0 ; i<cont ; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		MostrarArbol(arbol->izq,cont+1);//imprimiendo lado izquierdo.
	}
}

bool busqueda(nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}else if(n == arbol->dato){
		return true;
	}else if( n < arbol->dato){
		busqueda(arbol->izq,n);
	}else{
		busqueda(arbol->der,n);
	}
}

void PreOrden(nodo *arbol){
	if(arbol == NULL){
		return ;
	}else{
		cout<<arbol->dato<<" - ";
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
}

void InOrden(nodo *arbol){
	if(arbol == NULL){
		return ;
	}else{
		InOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		InOrden(arbol->der);
	}
}

void PostOrden(nodo *arbol){
	if(arbol == NULL){
		return ;
	}else{
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}