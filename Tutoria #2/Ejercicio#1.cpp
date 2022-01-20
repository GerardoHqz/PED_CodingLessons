// Crear un registro “Estudiante” que almacenará: nombre, apellido, estado (asignarle “Indefinido” como 
// valor inicial) y notas (definir “notas” como un arreglo de float de tamaño n). Luego crear una función 
// que reciba las notas del estudiante y calcule el promedio, una vez calculado el promedio de las notas, 
// modificar el estado de dicho estudiante dependiendo de su promedio, si su nota es menor a 6 modificarlo 
// a “Reprobado” y si es mayor o igual a 6 modificarlo a “Aprobado”. Por último, mostrar la información del 
// estudiante en consola.

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Estudiante{
    string nombre;
    string apellido;
    string estado = "Indefinido";
    float notas[];
};

//Prototipo de funciones
float CalcularPromedio(int);
string EstadoEstudiante(float);

//Declarando una variable global
Estudiante student;

int main(){

    int cant=0;

    cout<<"CALCULARDORA DE PROMEDIO DE NOTAS"<<endl<<endl;
    cout<<"Ingrese el nombre del estudiante: "; 
    cin>>student.nombre;
    cout<<"Ingrese el apellido del estudiante: ";
    cin>>student.apellido;

    cout<<"\nCuantas notas desea registrar al estudiante: "<<endl;
    cin>>cant;

    //guardamos el promedio en una variable
    float promedio = CalcularPromedio(cant);
    //Mostrar la informacion
    cout<<"\n\n Informacion del estudiante \n\n";
    cout<<"Nombre: "<<student.nombre<<endl;
    cout<<"Apellido: "<<student.apellido<<endl;
    cout<<"Estado: "<<EstadoEstudiante(promedio)<<endl;
    cout<<"Promedio: " <<promedio<<endl;

    system("pause");
    system("cls");
    
    return 0;
}

//Desarollanmos funcion Calcular Promedio
float CalcularPromedio(int cant){
    float suma=0, promedio=0;

    for(int i=0; i<cant; i++){
        cout<<"Ingrese la nota "<<i+1<<": ";
        cin>>student.notas[i];
        suma += student.notas[i];
    }
    promedio = suma/cant;

    return promedio;
}

string EstadoEstudiante(float promedio){
    
    if(promedio < 6){
        student.estado = "Reprobado";
    }else{
        student.estado = "Aprobado";
    }

    return student.estado;
}