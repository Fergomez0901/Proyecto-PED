#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

struct Persona{
    string nombre; 
    string apellido;
    bool estudiante; 
};

struct Butaca{
    int numero; 
    bool disponible = true;
    Persona persona; 
};

struct Factura{
    Persona persona; 
    Butaca butaca;
    //Lista de de product 
    int total; 
};

Butaca unaButaca; 
Persona unaPersona; 

void inicializar(vector <Butaca> &sala1, vector<Butaca> &sala2, vector<Butaca> &sala3)
{
    for(int i = 0; i < sala1.size(); i++)
    {
        sala1.at(i).numero = i+1; 
    }

    for(int i = 0; i < sala2.size(); i++)
    {
        sala2.at(i).numero = i+1; 
    }

    for(int i = 0; i < sala3.size(); i++)
    {
        sala3.at(i).numero = i+1; 
    }
}

void mostrarDisponibles(vector <Butaca> &sala)
{
    for(int i = 0; i < sala.size(); i++)             //Mostrando todos los disponibles de una sala
    {
        if(sala.at(i).disponible)
        {
            cout << " |Butaca # " << sala.at(i).numero; 
        }
    }
    cout << endl; 
}

bool asignarButaca(vector<Butaca> &sala, int puesto, Persona &person)
{
    bool asignado = false; 
    for(int i = 0; i < sala.size(); i++)
    {
        if(sala.at(i).numero == puesto && sala.at(i).disponible == true)  //Buscando puesto deseado
        {
            sala.at(i).disponible = false;
            sala.at(i).persona = person;  
            asignado = true;
            return asignado; 
        }
    }
    if(!asignado)
    {
        cout << "La butaca no se encuentra disponible" << endl;
        return asignado;  
    }
}

void agregarPersona(vector<Butaca> &sala1, vector<Butaca> &sala2, vector<Butaca> &sala3)
{
    int opcion = 0, numButaca = 0;
    char estudiante; 
    bool asignado;

    cout << "Que pelicula desea ver?" << endl; 
    cout << "1) Pelicula 1" << endl; 
    cout << "2) Pelicula 2" << endl; 
    cout << "3) Pelicula 3" << endl;
    cout << "4) Salir" << endl; 
    cout << "Ingrese una opcion: ";      cin >> opcion;     cin.ignore(); 

    switch (opcion)
    {
        case 1:
            cout << "Ingrese el nombre del cliente: ";      getline(cin, unaPersona.nombre);
            cout << "Ingrese el apellido del cliente: ";    getline(cin, unaPersona.apellido);
            cout << "El cliente es estudiante? (s/n): ";    cin >> estudiante;      cin.ignore(); 
            if(estudiante == 's' || estudiante == 'S')
            {
                unaPersona.estudiante = true;
            } 
            else
            {
                unaPersona.estudiante = false; 
            }
            //Mostrar butacas disponibles
            mostrarDisponibles(sala1);
            //Escoger una butaca
            cout << "Ingrese el numero de butaca que desea: ";  cin >> numButaca;   cin.ignore();
            //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo. 
            asignado = asignarButaca(sala1, numButaca, unaPersona); 
            if(asignado)
            {
                cout << "Se ha asignado la butaca de manera exitosa." << endl << endl; 
            }
            else
            {
                cout << "Error." << endl << endl; 
            }
            break;
        
        case 2:
            cout << "Ingrese el nombre del cliente: ";      getline(cin, unaButaca.persona.nombre);
            cout << "Ingrese el apellido del cliente: ";    getline(cin, unaButaca.persona.apellido);
            cout << "El cliente es estudiante? (s/n): ";    cin >> estudiante;
            if(estudiante == 's' || estudiante == 'S')
            {
                unaButaca.persona.estudiante = true;
            } 
            else
            {
                unaButaca.persona.estudiante = false; 
            }
            //Mostrar butacas disponibles
            mostrarDisponibles(sala2);
            //Escoger una butaca
            cout << "Ingrese el numero de butaca que desea: ";  cin >> numButaca;   cin.ignore();
            //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo. 
            asignado = asignarButaca(sala2, numButaca, unaPersona); 
            if(asignado)
            {
                cout << "Se ha asignado la butaca de manera exitosa." << endl << endl; 
            }
            else
            {
                cout << "Error." << endl << endl; 
            }

            //Fubcion de Dulceria
            //Cobro

            break;

        case 3:
            cout << "Ingrese el nombre del cliente: ";      getline(cin, unaButaca.persona.nombre);
            cout << "Ingrese el apellido del cliente: ";    getline(cin, unaButaca.persona.apellido);
            if(estudiante == 's' || estudiante == 'S')
            {
                unaButaca.persona.estudiante = true;
            }
            else
            {
                unaButaca.persona.estudiante = false; 
            }
            //Mostrar butacas disponibles
            mostrarDisponibles(sala2);
            //Escoger una butaca
            cout << "Ingrese el numero de butaca que desea: ";  cin >> numButaca;   cin.ignore();
            //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo. 
            asignado = asignarButaca(sala3, numButaca, unaPersona); 
            if(asignado)
            {
                cout << "Se ha asignado la butaca de manera exitosa." << endl << endl; 
            }
            else
            {
                cout << "Error." << endl << endl; 
            }
            break; 

        case 4: cout << "Saliendo..." << endl; break; 
            
        default: cout << "Opcion invalida"; break;
    }
}

void menu(vector<Butaca> &sala1, vector<Butaca> &sala2, vector<Butaca> &sala3)
{
    int opcion = 0; 
    bool status = true; 

    while(status)
    {
        cout << "Menu" << endl; 
        cout << "1) Agregar persona a la cola" << endl; 
        cout << "2) Cobrar" << endl;
        cout << "3) Verificar disponibilidad" << endl; 
        cout << "4) Salir" << endl;
        cout << "Ingrese una opcion: ";     cin >> opcion; 

        switch (opcion)
        {
            case 1: agregarPersona(sala1, sala2, sala3); break;
            
            case 2: break; 

            case 3: break; 

            case 4: cout << "Fin del programa." << endl << endl; break; 

            default: cout << "Opcion invalida. Intentalo de nuevo. " << endl << endl;  break;
        }
    }
}

int main()
{
    vector<Butaca> sala1(30);
    vector<Butaca> sala2(30);
    vector<Butaca> sala3(30);
    inicializar(sala1, sala2, sala3); 
    menu(sala1, sala2, sala3); 
}