#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct Producto{
    string nombre;
    float precio_unitario;

};

struct Pedido{
    string apellido;
    vector<Producto>lista_comida;
};

void cobrar(queue<Pedido>,Producto);

int main(){
  Producto producto;
  Pedido pedido;
  vector<Producto>lista;
  queue<Pedido>donas;
  queue<Pedido>platos_fuertes;

  bool status = true, status2 = true,status3 = true, status4 = true;
  int opcion,costo;
  string nombre_dona;
  float totalDonoas = 0, totalPlatos = 0,costos = 0,costos2=0;

  do
  {
    system("cls");
    cout<<"\n*Caja Registradora*";
    cout<<"\n1) Atender pedidos de clientes";
    cout<<"\n2) Calcular ganancias por ventas de donas";
    cout<<"\n3) Calcular ganancias por venta de platos fuertes";
    cout<<"\n4) Salir\n";
    cout<<"\nElige una opcion: "; cin>>opcion;

    switch(opcion)
    {
      int opcion2,opcion3;
      case 1:
        do
        {
          cout<<endl;
          cout<<"\t*Ejecutar Pedido*\n";
          cout<<"\t1) Ordenar Donas";
          cout<<"\t2) Ordenar Plato Fuerte";
          cout<<"\t5)Salir\n";
          cout<<"\tElija una opcion: ";cin>>opcion2;
        
          switch(opcion2)
          {
            case 1:
              status3 = true;
              cin.ignore();
              cout<<"Digite el apellido del cliente: "; getline(cin,pedido.apellido);
              do{
                system("cls");
                cout<<"\n*MENU  DE  DONAS*";
                cout<<"\n*Donas sencilla $1";    
                cout<<"\n*Donas rellena de leche $1.25";
                cout<<"\n*Donas especiales (moca,caramelo) $1.50";
                cout<<"\n1) Ordenar";
                cout<<"\n2) Dejar de ordenar y cobrar\n";
                cout<<"\nDigite la opcion: "; cin>>opcion3;
                switch(opcion3){
                  case 1:
                    cin.ignore();
                    cout<<"\nDigite el nombre de la doni que quiere: "; getline(cin,producto.nombre);
                    cout<<"Precio unitario: $"; cin>>producto.precio_unitario;
                    lista.push_back(producto);
                    donas.push(pedido);
                    system("pause");
                    break;
                
                  case 2:
                    cout<<"\nPedido de "<<pedido.apellido<<endl;
                    for(int i=0; i<lista.size();i++){
                      totalDonoas += lista[i].precio_unitario;
                      cout<<lista[i].nombre<<"    $"<<lista[i].precio_unitario<<endl;
                    }
                    cout<<"Total de la cuenta: $"<<totalDonoas<<endl;
                    costos += totalDonoas;
                    totalDonoas = 0;
                    donas.pop();
                    status3 = false;
                    system("pause");
                    break;
                }
              }while(status3);
              break;

            case 2:
              status4 = true;
              cin.ignore();
              cout<<"\nDigite el apellido del cliente: "; getline(cin,pedido.apellido);
              do{
                system("cls");
                cout<<"\n*MENU  DE  PLATOS FUERTES*";
                cout<<"\n*Desayunos $1.25";    
                cout<<"\n*Almuerzos $5.00";
                cout<<"\n*Cenas $3.50";
                cout<<"\n1) Ordenar";
                cout<<"\n2) Dejar de ordenar y cobrar\n";
                cout<<"\nDigite la opcion: "; cin>>opcion3;
                switch(opcion3){
                  case 1:
                    cin.ignore();
                    cout<<"\nDigite el nombre de la doni que quiere: "; getline(cin,producto.nombre);
                    cout<<"Precio unitario: $"; cin>>producto.precio_unitario;
                    lista.push_back(producto);
                    platos_fuertes.push(pedido);
                    system("pause");
                    break;
                
                  case 2:
                    cout<<"\nPedido de "<<pedido.apellido<<endl;
                    for(int i=0; i<lista.size();i++){
                      totalPlatos += lista[i].precio_unitario;
                      cout<<lista[i].nombre<<"    $"<<lista[i].precio_unitario<<endl;
                    }
                    cout<<"Total de la cuenta: $"<<totalPlatos<<endl;
                    costos2 += totalPlatos;
                    totalPlatos = 0;
                    platos_fuertes.pop();
                    status3 = false;
                    system("pause");
                    break;
                }
                break;
              }while(status4);

            case 5:
            status2 = false;
            break;
          }    
        }while(status2);
        break;
      
      case 2:
        cout<<"\nLas ganancias por donas son: $"<<costos;
        cout<<endl;
        system("pause");
        break;

      case 3:
        cout<<"\nLas ganancias de los platos fuertes son $"<<costos2;
        cout<<endl;
        system("pause");
        break;

      case 4:
        status = false;
        break;  
    }     
  }while(status);

  return 0;
}