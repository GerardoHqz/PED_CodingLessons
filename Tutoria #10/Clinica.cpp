#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct Citas //se ingresan los datos de las citas
{
    string NombrePaciente;
    string DUI;
    string doctor;
    int EdadPaciente;
    int horario;
    int horarioAdulto;
    int horarioNenes;
    int pago;
    int fecha;
    bool cancelado = false;
};
typedef struct Citas citas;

vector<citas> Ancianos;
vector<citas> Adultos;
vector<citas> Nenes;
citas InformacionPersonal;

void AgendarCita();
void PagarCita();
void CancelarCita();
void Horarios();
void Informacion();

int main()
{
    bool status = true;
    int opcion;
    do
    {
        system("color 0f");
        system("cls");
        cout << "--------------------*CLINICA LA FACHADA*-------------------\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        cout << "\nLa Clinica no se hace responsable por muertes accidentales.\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout << "\n-------------------------*MENU*---------------------------\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout << "                1. Agendar una cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout << "                2. Pagar cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout << "                3. Cancelar una cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
        cout << "                4. Horarios\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << "                5. Informacion\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "                6. Salir \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout << "\n       Elija una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            AgendarCita();
            break;
        case 2:
            PagarCita();
            break;
        
        case 3:
            CancelarCita();
            break;
        
        case 4:
            Horarios();
            break;
        case 5:
            Informacion();
            break;
        case 6:
            status = false;
            cout<<"\n--> Clinica La Fachada te desea un buen dia <--\n\n";
            break;
        default:
            cout<<"\nOpcion no valida\n";
            break;
        }
    } while (status);
    return 0;
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Agendar La Cita
void AgendarCita()
{
    bool status = true, status2 = true, band = true, validaciones = true;
    int opcion, opcion2;
    int opcion3, opcion4;
    int opcion5, opcion6;
    int edad;
    string nombre, dui,doc;
    system("cls");
    system("color E");
    cout << "\n-----------*Ingreso de datos personales*-----------\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout << "\nNota: En caso de que sea menor de edad, ingrese el DUI de su representante\n";
    cin.ignore();
    do{
        
        cout << "\nNombre completo: "; getline(cin,nombre);
        if(nombre != " " && nombre != "   " ){
            InformacionPersonal.NombrePaciente = nombre;
            validaciones = false;
        }
        else{
            cout<<"Dato erroneo! , intente nuevamente,\n";
            validaciones = true;
        }
    }while(validaciones);
 
    do{
        cout << "Edad: "; cin >> edad;
        if (edad > 0 && edad < 120){
            InformacionPersonal.EdadPaciente = edad;
            validaciones = false;
        }
        else{
            cout<<"Dato erroneo! , intente nuevamente\n";
            validaciones = true;
        }
    }while (validaciones);
      
    do{
        cin.ignore();
        cout << "DUI: "; getline(cin,dui);
        if(dui != " " && dui != "   " ){
            InformacionPersonal.DUI = dui;
            validaciones = false;
        }
        else{
            cout<<"Dato erroneo! , intente nuevamente\n";
            validaciones = true;
        }
    }while(validaciones);
    
    do{
        system("cls");
        system("color E");
        cout<<"\n  *Doctores disponibles:\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout<<"\nDr.Duenas Medico General (G)-------- $12";
        cout<<"\nDra.Vega Pediatra (P)--------------- $25";
        cout<<"\nDra.Santiago Dermatologa (D)-------- $25";
        cout<<"\nDr.Henriquez Endocrinologo (E)------ $25";
        cout<<"\nDra.Escobar Cardiologa (C)---------- $25\n";
        cout<<"\nPor favor escriba la letra que corresponde a cada doctor";
        cout<<"\nEscriba el nombre de la especialidad que desea: "; getline(cin,doc);
        if((doc != " " && doc != "  ") && (doc == "G" || doc == "P" || doc == "D" || doc == "E" || doc == "C" || doc == "g" || doc == "d" || doc == "e" || doc == "c" || doc == "p")){
            InformacionPersonal.doctor = doc;
            validaciones = false;
            cout<<endl;
        }
        else{
            cout<<"\nDato erroneo! , intente nuevamente\n\n";
            validaciones = true;
            system("pause");
        }
        
    }while(validaciones);
    cout<<endl;
    system("pause");
    
//-----------------------------------ANCIANOS---------------------------------//
    if(InformacionPersonal.EdadPaciente >= 60 && InformacionPersonal.EdadPaciente < 115){
        do{
            band = true;
            system("cls");
            system("color E");
            cout<<"\n             ****HORARIOS***\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout<<"\nConsultas de lunes a sabados";
            cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
            cout<<"\nDigite la fecha que desea: "; cin>>opcion;
            cout<<"\nUsted al ser una persona de tercera edad dispone de los siguientes horarios: \n";
            cout << "1) 6:00 am - 6:30 am       2) 6:30 am - 7:00 am\n";
            cout << "3) 7:00 am - 7:30 am       4) 7:30 am - 8:00 am\n";
            cout << "5) 8:00 am - 8:30 am       6) 8:30 am - 9:00 am\n";
            cout << "7) 9:00 am - 9:30 am\n";
            cout << "\nEscoja un horario: "; cin >> opcion2;
            if(InformacionPersonal.doctor == "G" || InformacionPersonal.doctor == "g"){
                InformacionPersonal.pago = 12;
                for(int i=0; i<Ancianos.size();i++){
                    if(opcion == Ancianos[i].fecha && opcion2 == Ancianos[i].horario){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25; 
                for(int i=0; i<Ancianos.size();i++){
                    if(opcion == Ancianos[i].fecha && opcion2 == Ancianos[i].horario){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25; 
                for(int i=0; i<Ancianos.size();i++){
                    if(opcion == Ancianos[i].fecha && opcion2 == Ancianos[i].horario){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25; 
                for(int i=0; i<Ancianos.size();i++){
                    if(opcion == Ancianos[i].fecha && opcion2 == Ancianos[i].horario){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25; 
                for(int i=0; i<Ancianos.size();i++){
                    if(opcion == Ancianos[i].fecha && opcion2 == Ancianos[i].horario){
                        band = false;
                        break;
                    }
                }
            }
            if(band == true){
                if(opcion != 6 && opcion != 13 && opcion != 20 && opcion < 24 && opcion > 1 && opcion2 > 0 && opcion2 < 8){
                    InformacionPersonal.fecha = opcion;
                    InformacionPersonal.horario = opcion2;
                    status = false;
                    cout<<"\nCita registrada con exito!, prosiga a la opcion de pagar cita.\n";
                }
                else{
                    cout<<"\nEste dia es no trabajamos,no esta disponible o es un dato erroneo pruebe otro dia por favor c: \n";
                    status = true;
                }
                
            }
            else{
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n\n";
            }
            cout<<endl;
            system("pause");
        }while(status);
        Ancianos.push_back(InformacionPersonal);
    }
//-----------------------------------ADULTOS---------------------------------//
    
    if(InformacionPersonal.EdadPaciente > 17 && InformacionPersonal.EdadPaciente < 60 ){
        do{
            band = true;
            system("cls");
            system("color E");
            cout<<"\n             ****HORARIOS***\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout<<"\nConsultas de lunes a sabados";
            cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
            cout<<"\nDigite la fecha que desea: "; cin>>opcion3;
            cout<<"\nUsted al ser una persona adulta dispone de los siguientes horarios: \n";
            cout << "1) 1:30 pm - 2:00 pm       2) 2:00 pm - 2:30 pm\n";
            cout << "3) 2:30 pm - 3:00 pm       4) 3:00 pm - 3:30 pm\n";
            cout << "5) 3:30 pm - 4:00 pm       6) 4:00 pm - 4:30 pm\n";
            cout << "7) 4:30 pm - 5:00 pm\n";
            cout << "\nEscoja un horario: "; cin >> opcion4;
            if(InformacionPersonal.doctor == "g" || InformacionPersonal.doctor == "G"){
                InformacionPersonal.pago = 12;
                for(int i=0; i<Adultos.size();i++){
                    if(opcion3 == Adultos[i].fecha && opcion4 == Adultos[i].horarioAdulto){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25; 
                for(int i=0; i<Adultos.size();i++){
                    if(opcion3 == Adultos[i].fecha && opcion4 == Adultos[i].horarioAdulto){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Adultos.size();i++){
                    if(opcion3 == Adultos[i].fecha && opcion4 == Adultos[i].horarioAdulto){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Adultos.size();i++){
                    if(opcion3 == Adultos[i].fecha && opcion4 == Adultos[i].horarioAdulto){
                       band = false;
                       break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Adultos.size();i++){
                    if(opcion3 == Adultos[i].fecha && opcion4 == Adultos[i].horarioAdulto){
                        band = false;
                        break;
                    }
                }
            }
            
            if(band == true){
                if(opcion3 != 6 && opcion3 != 13 && opcion3 != 20 && opcion3 > 1 && opcion3 < 24 && opcion4 > 0 && opcion4 < 8){
                    InformacionPersonal.fecha = opcion3;
                    InformacionPersonal.horarioAdulto = opcion4;
                    status = false;
                    cout<<"\nCita registrada con exito!, prosiga a la opcion de pagar cita.\n";
                }
                else{
                    status = true;
                    cout<<"\nEste dia es no trabajamos,no esta disponible o es un dato erroneo pruebe otro dia por favor c: \n";
                }
                
            }
            else{
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n";
            }
            cout<<endl;
            system("pause");
        }while(status);
        Adultos.push_back(InformacionPersonal);
    }
//------------------------------------NENES----------------------------------//
    if(InformacionPersonal.EdadPaciente > 0 && InformacionPersonal.EdadPaciente < 18 ){
        do{
            band = true;
            system("cls");
            system("color E");
            cout<<"\n             ****HORARIOS***\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout<<"\nConsultas de lunes a sabados";
            cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
            cout<<"\nDigite la fecha que desea: "; cin>>opcion5;
            cout<<"\nUsted al ser una persona menor de edad dispone de los siguientes horarios: \n";
            cout << "1) 9:30 am - 10:00 am       2) 10:00 am - 10:30 am\n";
            cout << "3) 10:30 am - 11:00 am      4) 11:00 am - 11:30 am\n";
            cout << "5) 11:30 am - 12:00 pm      6) 12:00 pm - 12:30 pm\n";
            cout << "\nEscoja un horario: "; cin >> opcion6;
            if(InformacionPersonal.doctor == "g" || InformacionPersonal.doctor == "G"){
                InformacionPersonal.pago = 12;
                for(int i=0; i<Nenes.size();i++){
                    if(opcion5 == Nenes[i].fecha && opcion6 == Nenes[i].horarioNenes){
                       band = false;
                       break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Nenes.size();i++){
                    if(opcion5 == Nenes[i].fecha && opcion6 == Nenes[i].horarioNenes){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Nenes.size();i++){
                    if(opcion5 == Nenes[i].fecha){
                        band = false;
                        break;
                    }
                }
            }
            
            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Nenes.size();i++){
                    if(opcion5 == Nenes[i].fecha && opcion6 == Nenes[i].horarioNenes){
                        band = false;
                        break;
                    }
                }
            }
            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<Nenes.size();i++){
                    if(opcion5 == Nenes[i].fecha && opcion6 == Nenes[i].horarioNenes){
                        band == false;
                        break;
                    }
                }
            }
            
            if(band == true){
                if(opcion5 != 6 && opcion5 != 13 && opcion5 != 20 && opcion5 > 1 && opcion5 < 24 && opcion6 > 0 && opcion6 < 7){
                    InformacionPersonal.fecha = opcion5;
                    InformacionPersonal.horarioNenes = opcion6;
                    status = false;
                    cout<<"\nCita registrada con exito!, prosiga a la opcion de pagar cita.\n";
                }
                else{
                    cout<<"\nEste dia  no trabajamos,no esta disponible o es un dato erroneo, pruebe otro dia por favor c: \n";
                    status = true;
                }
                
            }
            else{    
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n";
            }
            cout<<endl;
            system("pause");
        }while(status);
        Nenes.push_back(InformacionPersonal);
    }
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Pagar la cita.
void PagarCita(){
    citas auxiliar ;
    bool found = false, band = false, validaciones = true;
    int pago;
    string ElementoBuscar, dui;
    string Tarjeta;
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n**Pago de cita**\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    do{
        cin.ignore();
        cout<<"Digite su DUI: "; getline(cin,dui);
        if(dui != " " || dui != "   " ){
            ElementoBuscar = dui;
            validaciones = false;
        }
        else{
            cout<<"\nDato erroneo! , intente nuevamente\n";
            validaciones = true;
        }   
    }while(validaciones);
    
    //----------------------------------Ancianos
    for(int i=0;i<Ancianos.size();i++){
        if(Ancianos[i].DUI == ElementoBuscar){
            found = true;
            if(Ancianos[i].cancelado == false){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                cout<<"\n**DATOS DE LA CITA**\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"\nNombre: "<<Ancianos[i].NombrePaciente;
                if(Ancianos[i].doctor == "g" || Ancianos[i].doctor == "G"){
                    Ancianos[i].doctor = "Dr.Duenas -Medico General-";
                }
                if(Ancianos[i].doctor == "p" || Ancianos[i].doctor == "P"){
                    Ancianos[i].doctor = "Dra.Vega -Pediatra-";
                }
                if(Ancianos[i].doctor == "D" || Ancianos[i].doctor == "d"){
                    Ancianos[i].doctor = "Dra.Santiago -Dermatologa-";
                }
                if(Ancianos[i].doctor == "E" || Ancianos[i].doctor == "e"){
                    Ancianos[i].doctor = "Dr.Henriquez -Endocrinologo-";
                }
                if(Ancianos[i].doctor == "C" || Ancianos[i].doctor == "C"){
                    Ancianos[i].doctor = "Dra.Escobar -Cardiologa-";
                }
                cout<<"\nDoctor: "<<Ancianos[i].doctor; 
                cout<<"\nDia: "<<Ancianos[i].fecha;
                cout<<"\nHorario: "<<Ancianos[i].horario<<" en el horario de tercera edad";
                cout<<"\nTotal: $"<<Ancianos[i].pago;
                cout<<"\n\nIntroduzca su tarjeta de pago: "; getline(cin,Tarjeta);
                cout<<"\n\nSu pago se ha realizado con exito!, te esperamos!.\n";
                cout<<endl;
                Ancianos[i].cancelado = true;
                band = true;
            }
            else{
                band = false;
            }
        }
    }
    
    //----------------------------------Adultos
    for(int i=0;i<Adultos.size();i++){
        if(Adultos[i].DUI == ElementoBuscar){
            found = true;
            if(Adultos[i].cancelado == false){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                cout<<"\n**DATOS DE LA CITA**\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"\nNombre: "<<Adultos[i].NombrePaciente;
                if(Adultos[i].doctor == "g" || Adultos[i].doctor == "G"){
                    Adultos[i].doctor = "Dr.Duenas -Medico General-";
                }
                if(Adultos[i].doctor == "P" || Adultos[i].doctor == "p"){
                    Adultos[i].doctor = "Dra.Vega -Pediatra-";
                }
                if(Adultos[i].doctor == "D" || Adultos[i].doctor == "d"){
                    Adultos[i].doctor = "Dr.Santiago -Dermatologa-";
                }
                if(Adultos[i].doctor == "E" || Adultos[i].doctor == "e"){
                    Adultos[i].doctor = "Dr.Henriquez -Endocrinologo-";
                }
                if(Adultos[i].doctor == "C" || Adultos[i].doctor == "c"){
                    Adultos[i].doctor = "Dr.Escobar -Cardiologa-";
                }
                cout<<"\nDoctor: "<<Adultos[i].doctor; 
                cout<<"\nDia: "<<Adultos[i].fecha;
                cout<<"\nHorario: "<<Adultos[i].horarioAdulto<<" en el horario de adultos";
                cout<<"\nTotal: $"<<Adultos[i].pago;
                cout<<"\n\nIntroduzca su tarjeta de pago: "; getline(cin,Tarjeta);
                cout<<"\n\nSu pago se ha realizado con exito!, te esperamos!.\n";
                cout<<endl;
                Adultos[i].cancelado = true;
                band = true;
            }
            else{
                band = false;
            }
        }
    }
    
    //----------------------------------Nenes
    for(int i=0;i<Nenes.size();i++){
        if(Nenes[i].DUI == ElementoBuscar){
            found = true;
            if(Nenes[i].cancelado == false){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                cout<<"\n**DATOS DE LA CITA**\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"\nNombre: "<<Nenes[i].NombrePaciente;
                if(Nenes[i].doctor == "g" || Nenes[i].doctor == "G"){
                    Nenes[i].doctor = "Dr.Duenas -Medico General-";
                }
                if(Nenes[i].doctor == "P" || Nenes[i].doctor == "p"){
                    Nenes[i].doctor = "Dra.Vega -Pediatra-";
                }
                if(Nenes[i].doctor == "D" || Nenes[i].doctor == "d"){
                    Nenes[i].doctor = "Dra.Santiago -Dermatologa-";
                }
                if(Nenes[i].doctor == "E" || Nenes[i].doctor == "e"){
                    Nenes[i].doctor = "Dr.Henriquez -Endocrinologo-";
                }
                if(Nenes[i].doctor == "C" || Nenes[i].doctor == "c"){
                    Nenes[i].doctor = "Dra.Escobar -Cardiologa-";
                }
                cout<<"\nDoctor: "<<Nenes[i].doctor; 
                cout<<"\nDia: "<<Nenes[i].fecha;
                cout<<"\nHorario: "<<Nenes[i].horarioNenes<<" en el horario de menores de edad";
                cout<<"\nTotal: $"<<Nenes[i].pago;
                cout<<"\n\nIntroduzca su tarjeta de pago: "; getline(cin,Tarjeta);
                cout<<"\n\nSu pago se ha realizado con exito!, te esperamos!.\n";
                cout<<endl;
                Nenes[i].cancelado = true;
                band = true;
            }
            else{
                band = false;
            }
        }
    }
    if(found == false){
        cout<<"\n No hay una persona registrada con este DUI\n";
    }
    if(band == false && found != false){
        cout<<"\nEsta cita ya esta registrada y pagada, te esperamos!\n";
    }
    
    system("pause"); 
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de mostrar los horarios.
void Horarios(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    system("cls");
    cout<< "***************HORARIOS***************\n";
     cout<<"\nConsultas de lunes a sabados";
      cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
      cout<<"\nContamos con los siguientes horarios para que tenga la mejor atencion:\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout<< "\n-----Adultos  de la tercera Edad-----\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            cout << "\n1) 6:00 am - 6:30 am       2) 6:30 am - 7:00 am\n";
            cout << "3) 7:00 am - 7:30 am       4) 7:30 am - 8:00 am\n";
            cout << "5) 8:00 am - 8:30 am       6) 8:30 am - 9:00 am\n";
            cout << "7) 9:00 am - 9:30 am\n";
            
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);   
            cout<<"\n-----Menores de Edad -----\n" ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            cout << "\n1) 9:30 am - 10:00 am       2) 10:00 am - 10:30 am\n";
            cout << "3) 10:30 am - 11:00 am       4) 11:00 am - 11:30 am\n";
            cout << "5) 11:30 am - 12:00 pm       6) 12:00 pm - 12:30 pm\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);    
            cout<<"\n-----Adultos-----\n"; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
            cout << "\n1) 1:30 pm - 2:00 pm       2) 2:00 pm - 2:30 pm\n";
            cout << "3) 2:30 pm - 3:00 pm       4) 3:00 pm - 3:30 pm\n";
            cout << "5) 3:30 pm - 4:00 pm       6) 4:00 pm - 4:30 pm\n";
            cout << "7) 4:30 pm - 5:00 pm\n\n";
            
    system("pause");        
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Cancelar la cita pre agendada.
void CancelarCita(){
    citas auxiliar ;
    bool found = false, band = false, band2 = false, band3 = false, status = true,validaciones = true;
    int pago;
    string ElementoBuscar,Tarjeta,dui;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"\n**Cancelar cita agendada**\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    do{
        cin.ignore();
        cout<<"Digite su DUI: "; getline(cin,dui);
        if(dui != " " || dui != "   " ){
            ElementoBuscar = dui;
            validaciones = false;
        }
        else{
            cout<<"\nDato erroneo! , intente nuevamente\n";
            validaciones = true;
        }   
    }while(validaciones);
    for(int i=0; i < Ancianos.size(); i++){
        if (Ancianos[i].DUI == ElementoBuscar){
            band = true;
            found = true;
            auxiliar.NombrePaciente = Ancianos[i].NombrePaciente;
            auxiliar.doctor = Ancianos[i].doctor;
            auxiliar.fecha = Ancianos[i].fecha;
            auxiliar.pago = Ancianos[i].pago;
            Ancianos.erase(Ancianos.begin()+i);
        }
    }
    for(int i=0; i < Adultos.size(); i++){
        if (Adultos[i].DUI == ElementoBuscar){
            band2 = true;
            found = true;
            auxiliar.NombrePaciente = Adultos[i].NombrePaciente;
            auxiliar.doctor = Adultos[i].doctor;
            auxiliar.fecha = Adultos[i].fecha;
            auxiliar.pago = Adultos[i].pago;
            Adultos.erase(Adultos.begin()+i);
        }
    }
    for(int i=0; i < Nenes.size(); i++){
        if (Nenes[i].DUI == ElementoBuscar){
            band3 = true;
            found = true;
            auxiliar.NombrePaciente = Nenes[i].NombrePaciente;
            auxiliar.doctor = Nenes[i].doctor;
            auxiliar.fecha = Nenes[i].fecha;
            auxiliar.pago = Nenes[i].pago;
            Nenes.erase(Nenes.begin()+i);
        }
    }
    
    if (found == false) {
      cout << "\nNo se encontro una cita registrada con este DUI\n" << endl;
    }
    else{
      if(band == true){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\n**DATOS DE LA CITA**\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\nNombre: "<<auxiliar.NombrePaciente;
            if(auxiliar.doctor == "g" || auxiliar.doctor == "G"){
                    auxiliar.doctor = "Dr.Duenas -Medico General-";
            }
            if(auxiliar.doctor == "p" || auxiliar.doctor == "P"){
                    auxiliar.doctor = "Dra.Vega -Pediatra-";
            }
            if(auxiliar.doctor == "D" || auxiliar.doctor == "d"){
                    auxiliar.doctor = "Dra.Santiago -Dermatologa-";
            }
            if(auxiliar.doctor == "E" || auxiliar.doctor == "e"){
                    auxiliar.doctor = "Dr.Henriquez -Endocrinologo-";
            }
            if(auxiliar.doctor == "C" || auxiliar.doctor == "C"){
                    auxiliar.doctor = "Dra.Escobar -Cardiologa-";
            }
            cout<<"\nDoctor: "<<auxiliar.doctor; 
            cout<<"\nDia: "<<auxiliar.fecha;
            cout<<"\nTotal: $"<<auxiliar.pago;
      }
      else if(band2 == true){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\n**DATOS DE LA CITA**\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\nNombre: "<<auxiliar.NombrePaciente;
            if(auxiliar.doctor == "g" || auxiliar.doctor == "G"){
                    auxiliar.doctor = "Dr.Duenas -Medico General-";
            }
            if(auxiliar.doctor == "p" || auxiliar.doctor == "P"){
                    auxiliar.doctor = "Dra.Vega -Pediatra-";
            }
            if(auxiliar.doctor == "D" || auxiliar.doctor == "d"){
                    auxiliar.doctor = "Dra.Santiago -Dermatologa-";
            }
            if(auxiliar.doctor == "E" || auxiliar.doctor == "e"){
                    auxiliar.doctor = "Dr.Henriquez -Endoclinologo-";
            }
            if(auxiliar.doctor == "C" || auxiliar.doctor == "C"){
                    auxiliar.doctor = "Dra.Escobar -Cardiologa-";
            }
            cout<<"\nDoctor: "<<auxiliar.doctor; 
            cout<<"\nDia: "<<auxiliar.fecha;
            cout<<"\nTotal: $"<<auxiliar.pago;
    }
    else if(band3 == true){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\n**DATOS DE LA CITA**\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout<<"\nNombre: "<<auxiliar.NombrePaciente;
            if(auxiliar.doctor == "g" || auxiliar.doctor == "G"){
                    auxiliar.doctor = "Dr.Duenas -Medico General-";
            }
            if(auxiliar.doctor == "p" || auxiliar.doctor == "P"){
                    auxiliar.doctor = "Dra.Vega -Pediatra-";
            }
            if(auxiliar.doctor == "D" || auxiliar.doctor == "d"){
                    auxiliar.doctor = "Dra.Santiago -Dermatologa-";
            }
            if(auxiliar.doctor == "E" || auxiliar.doctor == "e"){
                    auxiliar.doctor = "Dr.Henriquez -Endoclinologo-";
            }
            if(auxiliar.doctor == "C" || auxiliar.doctor == "C"){
                    auxiliar.doctor = "Dra.Escobar -Cardiologa-";
            }
            cout<<"\nDoctor: "<<auxiliar.doctor; 
            cout<<"\nDia: "<<auxiliar.fecha;
            cout<<"\nTotal: $"<<auxiliar.pago;
      }    
      cout<<"\nLa cita agendada a nombre de " <<auxiliar.NombrePaciente;
      cout<<" sera cancelada.\n\n";
      cout<<"\nSi la cita ya fue pagada en 24 horas se hara la devolucion de su dinero\n";
      system("pause");
      cout<<"\nCancelando cita agendada.....\n";
      cout<<"\nCita Cancelada, gracias.\n\n";
    }
    system("pause");
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de mostrar la informacion del negocio.
void Informacion(){
    bool status = true;
    int opcion;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    do
    {
        system("cls");
        cout << "\n-----------------------------INFORMACION-----------------------------\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << " Bienvenidos a la Clinica La Fachada";
        cout << "\n Nos complace atenderte de lunes a sabados los dias restantes del 2020"; 
        cout << "\n No hay precio para tu salud :)\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout << "\n-----------MENU DE INFORMACION-----------\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << " 1. Acerca de la  clinica \n";
        cout << " 2. Acerca del Personal \n";
        cout << " 3. Mision \n";
        cout << " 4. Vision \n";
        cout << " 5. Valores Institucionales \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << " 6. Salir \n ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << "Elija una opcion:  "; cin>>opcion;
        switch(opcion)
        {
        case 1:
            cout <<"\n --------------------------------Clinica La Fachada----------------------------------- \n";
            cout <<" Clinica La Fachada, fundada en Noviembre del 2020 por los excelentes doctores de origen\n";
            cout <<" Aleman ,Italiano, Ruso y Coreano. La clinica nace con el fin de apoyar a la poblacion, \n";
            cout <<" promoviendo el bienestar social a traves de la salud.\n\n";
            system("pause");
            break;
        case 2:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout <<"\n -------------------------------- Profesionales -------------------------------------- \n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout << " Nuestros medicos que estan al tanto de tu salud son profecionales graduados y con doctorados\n"; 
            cout << " de las Universidades y mas TOP del mundo\n\n";
            cout << " *Dr.Duenas--Medico General--\n";
            cout << " Graduado de Harvard en medicina general, con doctorado en Oxford, siempre al tanto de tu salud\n\n";
            cout << " *Dra.Vega--Pediatra--\n";
            cout << " Graduada de Stanford en pediatria, con maestria y doctorado del TEC de monterrey, vela por la salud de tus crias\n\n";
            cout << " *Dra.Santiago--Dermatologa--\n";
            cout << " Doctorada en Dermatologia de Cambridge, busca siempre el bien de tu piel para que se vea sexy y limpia\n\n";
            cout << " *Dr.Henriquez--Endocrinologo--\n";
            cout << " Graduado de Massachusetts Institute of Technology (MIT) de Endocrinologia avanzada, busca el bien de tu cuerpo\n\n";
            cout << " *Dra.Escobar--Cardiologa--\n";
            cout << " Doctorada de Trinity College Dublin de Cardiologia, casada con el apuesto Dr.Henriquez, siempre al tanto su salud\n\n";
            cout << " *Antonio--Conserje--\n";
            cout << " El es el conserje, grande antonio.\n\n";
            system("pause");
            break;
        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout << "\n--------------------------------------------MISION----------------------------------------";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout << "\n Brindar servicios de salud primaria y promover la educacion con la calidad y calidez en funcion social\n\n";
            system("pause");
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout << "\n--------------------------------------------VISION----------------------------------------";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout << "\n Impulsar el desarrollo humano a traves de la salud en medio de una pandemia mundial\n\n";
            system("pause");
            break;
        case 5:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            cout << "\n--------------------------------------VALORES INSTITUCIONALES-------------------------------\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout << "1. INTEGRIDAD: Transparencia en todo lo que hacemos\n";
            cout << "2. CALIDEZ: Trato amable con empatia\n";
            cout << "3. PROFESIONALISMO: Trabajo con responsabilidad y confianza\n";
            cout << "4. ETICA PROFESIONAL: Confidencialidad en el servicio\n";
            cout << "5. TRABAJO EN EQUIPO: Unidos somos mas efectivos\n";
            cout << "6. EQUIDAD: Trato justo y digno para todos\n";
            system("pause");
            break;
        case 6:
            status = false;
            system("pause");
            break;
        default:
            cout << "\nOpcion no valida\n";
            system("pause");
            break;
        }
    } while (status);
}