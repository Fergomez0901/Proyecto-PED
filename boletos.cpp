#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Productos
{
    string tipodeproducto;
    float precio;
};

struct Butaca
{
    int numero;
    bool disponible = true;
};

struct Persona
{
    string nombre;
    string apellido;
    vector<Productos> producto;
    bool estudiante;
    struct Butaca butaca;
};

Butaca unaButaca;
Persona unaPersona;
Productos producto;
Persona cliente;

//******************************************************************************************************************************
void inicializar(vector<Persona> &sala1, vector<Persona> &sala2, vector<Persona> &sala3)
{
    for (int i = 0; i < sala1.size(); i++)
    {
        sala1.at(i).butaca.numero = i + 1;
    }

    for (int i = 0; i < sala2.size(); i++)
    {
        sala2.at(i).butaca.numero = i + 1;
    }

    for (int i = 0; i < sala3.size(); i++)
    {
        sala3.at(i).butaca.numero = i + 1;
    }
}
//******************************************************************************************************************************
void mostrarDisponibles(vector<Persona> &sala)
{
    for (int i = 0; i < sala.size(); i++) //Mostrando todos los disponibles de una sala
    {
        if (sala.at(i).butaca.disponible)
        {
            cout << "Butaca # " << sala.at(i).butaca.numero << " - ";
        }
    }
    cout << endl;
}
//******************************************************************************************************************************
bool asignarButaca(vector<Persona> &sala, int puesto, string nombre, string apellido, bool estudiante, queue<Persona> &colaClients)
{
    bool asignado = false;
    for (int i = 0; i < sala.size(); i++)
    {
        if (sala.at(i).butaca.numero == puesto && sala.at(i).butaca.disponible == true) //Buscando puesto deseado
        {
            sala.at(i).butaca.disponible = false;
            sala.at(i).nombre = nombre;
            sala.at(i).apellido = apellido;
            sala.at(1).estudiante = estudiante;
            asignado = true;
            colaClients.push(sala.at(i));
            return asignado;
        }
    }
    if (!asignado)
    {
        cout << "La butaca no se encuentra disponible" << endl;
        return asignado;
    }
}
//******************************************************************************************************************************
void agregarPersona(vector<Persona> &sala1, vector<Persona> &sala2, vector<Persona> &sala3, queue<Persona> &colaClients)
{
    int opcion = 0, numButaca = 0;

    char estudiante;
    bool asignado;

    cout << "Que pelicula desea ver?" << endl;
    cout << "1) Pelicula 1" << endl;
    cout << "2) Pelicula 2" << endl;
    cout << "3) Pelicula 3" << endl;
    cout << "4) Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion)
    {
    case 1:
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, unaPersona.nombre);
        cout << "Ingrese el apellido del cliente: ";
        getline(cin, unaPersona.apellido);
        cout << "El cliente es estudiante? (s/n): ";
        cin >> estudiante;
        cin.ignore();
        if (estudiante == 's' || estudiante == 'S')
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
        cout << "Ingrese el numero de butaca que desea: ";
        cin >> numButaca;
        cin.ignore();
        //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo.
        asignado = asignarButaca(sala1, numButaca, unaPersona.nombre, unaPersona.apellido, estudiante, colaClients);
        if (asignado)
        {
            cout << "Se ha asignado la butaca de manera exitosa." << endl << endl;
        }
        else
        {
            cout << "Error." << endl << endl;
        }
        break;

    case 2:
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, unaPersona.nombre);
        cout << "Ingrese el apellido del cliente: ";
        getline(cin, unaPersona.apellido);
        cout << "El cliente es estudiante? (s/n): ";
        cin >> estudiante;
        cin.ignore();
        if (estudiante == 's' || estudiante == 'S')
        {
            unaPersona.estudiante = true;
        }
        else
        {
            unaPersona.estudiante = false;
        }
        //Mostrar butacas disponibles
        mostrarDisponibles(sala2);
        //Escoger una butaca
        cout << "Ingrese el numero de butaca que desea: ";
        cin >> numButaca;
        cin.ignore();
        //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo.
        asignado = asignarButaca(sala2, numButaca, unaPersona.nombre, unaPersona.apellido, estudiante, colaClients);
        if (asignado)
        {
            cout << "Se ha asignado la butaca de manera exitosa." << endl << endl;
        }
        else
        {
            cout << "Error." << endl << endl;
        }
        break;

    case 3:
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, unaPersona.nombre);
        cout << "Ingrese el apellido del cliente: ";
        getline(cin, unaPersona.apellido);
        cout << "El cliente es estudiante? (s/n): ";
        cin >> estudiante;
        cin.ignore();
        if (estudiante == 's' || estudiante == 'S')
        {
            unaPersona.estudiante = true;
        }
        else
        {
            unaPersona.estudiante = false;
        }
        //Mostrar butacas disponibles
        mostrarDisponibles(sala3);
        //Escoger una butaca
        cout << "Ingrese el numero de butaca que desea: ";
        cin >> numButaca;
        cin.ignore();
        //Cambiar el estado de disponibilidad de la butaca y asignarle el cliente  nuevo.
        asignado = asignarButaca(sala3, numButaca, unaPersona.nombre, unaPersona.apellido, estudiante, colaClients);
        if (asignado)
        {
            cout << "Se ha asignado la butaca de manera exitosa." << endl << endl;
        }
        else
        {
            cout << "Error." << endl << endl;
        }
        break;

    case 4:
        cout << "Saliendo..." << endl << endl;
        break;

    default:
        cout << "Opcion invalida" << endl << endl;
        break;
    }
}
//******************************************************************************************************************************
float cobrar(queue<Persona> *colaClientes, float pago)
{
    //Verificación que haya clientes en la cola
    if (colaClientes->empty())
    {
        cout << "No se ha realizado ningún cobro, no hab1a clientes en la cola" << endl;
        return 0;
    }
    else
    {
        //Recorrer la cola por medio de un while, cuya condición sea que la cola NO esté vacía
        while (!colaClientes->empty())
        {
            //Asignar el cliente que se encuentra al frente de la cola a la variable cliente
            Persona cliente = colaClientes->front();

            cout << endl << "Factura de: " << cliente.nombre << " " << cliente.apellido << "\t" << endl;
            //Recorrer la lista de los productos del cliente actuales con un for
            for (int i = 0; i < cliente.producto.size(); i++)
            {
                //Almacenar los valores de precio del producto en la posición i en la variable pago
                pago += cliente.producto.at(i).precio;

                cout << cliente.producto.at(i).tipodeproducto << ": $" << cliente.producto.at(i).precio << endl;
            }
            if(cliente.estudiante)
            {
                cout << "Boleto de cine: $3.00" << endl; 
                pago += 3.00;
            }
            else
            {
                cout << "Boleto de cine: $4.50" << endl;
                pago += 4.50; 
            }
            cout << endl; 
            //Eliminar el cliente al frente de la cola porque ya fue atendido, y avanzar en la cola
            colaClientes->pop();
        }
        return pago;
    }
}
//******************************************************************************************************************************
void dulceria(vector<Productos> &lista, queue<Persona> &colaClientes)
{
    char opcion;
    int opcion2;
    int opcion3;
    bool status = true;
    cout << "Desea comprar en la dulceria? (s/n)" << endl;
    cin >> opcion;
    if (opcion == 's' || opcion == 'S')
    {
        while (status)
        {
            cout << endl;
            cout << "***************Menu***************" << endl;
            cout << "1) Soda " << endl;
            cout << "2) Nachos " << endl;
            cout << "3) Hot Dog " << endl;
            cout << "4) Palomitas " << endl;
            cout << "5) Combo Nachos " << endl;
            cout << "6) Combo Hot Dogs" << endl;
            cout << "7) Combo Mix" << endl;
            cout << "8) Combito" << endl;
            cout << "9) Salir a cobrar" << endl;
            cin >> opcion2;

            switch (opcion2)
            {
            case 1:

                cout << "1)Pequeña" << endl;
                cout << "2)Mediana" << endl;
                cout << "3)Grande" << endl;
                cin >> opcion3;
                switch (opcion3)
                {
                case 1:
                    producto.tipodeproducto = "Soda (Pequeña)";
                    producto.precio = 0.50;
                    lista.push_back(producto);
                    break;
                case 2:
                    producto.tipodeproducto = "Soda (Mediana)";
                    producto.precio = 1;
                    lista.push_back(producto);
                    break;
                case 3:
                    producto.tipodeproducto = "Soda (Grande)";
                    producto.precio = 1.50;
                    lista.push_back(producto);
                    break;
                default:
                    cout << "ingrese un numero valido." << endl;
                    break;
                }
                break;
            case 2:
                cout << "1)Normales" << endl;
                cout << "2)Con Queso" << endl;
                cout << "3)Con Carne" << endl;
                cout << "4)Con Todo" << endl;
                cin >> opcion3;
                switch (opcion3)
                {
                case 1:
                    producto.tipodeproducto = "Nachos (Normales)";
                    producto.precio = 1;
                    lista.push_back(producto);
                    break;
                case 2:
                    producto.tipodeproducto = "Nachos (Con Queso)";
                    producto.precio = 1.25;
                    lista.push_back(producto);
                    break;
                case 3:
                    producto.tipodeproducto = "Nachos (Con Carne)";
                    producto.precio = 1.50;
                    lista.push_back(producto);
                    break;
                case 4:
                    producto.tipodeproducto = "Nachos (Con Todo)";
                    producto.precio = 1.75;
                    lista.push_back(producto);
                    break;
                default:
                    cout << "ingrese un numero valido." << endl;
                    break;
                }
                break;
            case 3:
                cout << "1)Normal" << endl;
                cout << "2)Con Aderesos" << endl;
                cout << "3)Con aderesos y chile" << endl;
                cin >> opcion3;
                switch (opcion3)
                {
                case 1:
                    producto.tipodeproducto = "Hot dog (Normal)";
                    producto.precio = 1;
                    lista.push_back(producto);
                    break;
                case 2:
                    producto.tipodeproducto = "Hot dog (Con Aderesos)";
                    producto.precio = 1.50;
                    lista.push_back(producto);
                    break;
                case 3:
                    producto.tipodeproducto = "Hot dog (Con aderesos y chile)";
                    producto.precio = 2;
                    lista.push_back(producto);
                    break;
                default:
                    cout << "ingrese un numero valido." << endl;
                    break;
                }
                break;
            case 4:
                cout << "1)Pequeñas" << endl;
                cout << "2)Mediana" << endl;
                cout << "3)Grandes" << endl;
                cin >> opcion3;
                switch (opcion3)
                {
                case 1:
                    producto.tipodeproducto = "Palomitas (Pequeñas)";
                    producto.precio = 2;
                    lista.push_back(producto);
                    break;
                case 2:
                    producto.tipodeproducto = "Palomitas (Mediana)";
                    producto.precio = 3;
                    lista.push_back(producto);
                    break;
                case 3:
                    producto.tipodeproducto = "Palomitas (Grandes)";
                    producto.precio = 4.50;
                    lista.push_back(producto);
                    break;
                default:
                    cout << "ingrese un numero valido." << endl;
                    break;
                }
                break;
            case 5:
                producto.tipodeproducto = "Combo Nachos";
                producto.precio = 8.50;
                lista.push_back(producto);
                break;
            case 6:
                producto.tipodeproducto = "Combo Hot Dogs";
                producto.precio = 9;    
                lista.push_back(producto);
                break;
            case 7:
                producto.tipodeproducto = "Combo Mix";
                producto.precio = 7.75;
                lista.push_back(producto);
                break;

            case 8:
                producto.tipodeproducto = "Combito";
                producto.precio = 6;
                lista.push_back(producto);
                break;
            case 9:
                status = false;
                cout << "volviendo al menu...." << endl
                     << endl;
                break;

            default:
                cout << "ingrese un numero valido." << endl;
                break;
            }
        }
        cliente.producto = lista;
        //Agregando el cliente a la cola
        colaClientes.push(cliente);
        lista.clear();
        return;
    }
}
//******************************************************************************************************************************
int main()
{
    vector<Persona> sala1(30);
    vector<Persona> sala2(30);
    vector<Persona> sala3(30);

    queue<Persona> colaClientes;

    vector<Productos> lista;

    inicializar(sala1, sala2, sala3);

    int opcion = 0;
    bool status = true;
    float totalPagado = 0;
    while (status)
    {
        cout << "Menu" << endl;
        cout << "1) Agregar persona a la cola" << endl;
        cout << "2) Cobrar" << endl;
        cout << "3) Verificar disponibilidad" << endl;
        cout << "4) Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarPersona(sala1, sala2, sala3, colaClientes);
            dulceria(lista, colaClientes);
            break;
        case 2:
            totalPagado = cobrar(&colaClientes, 0);
            cout << "Se ha cobrado un total de $" << totalPagado << " al/los cliente/s" << endl << endl; ;
            break;

        case 3:
            cout << endl << "Mostrando disponibilidad Sala 1: " << endl; 
            mostrarDisponibles(sala1);
            cout << endl; 

            cout << "Mostrando disponibilidad Sala 2: " << endl; 
            mostrarDisponibles(sala2);
            cout << endl; 

            cout << "Mostrando disponibilidad Sala 3: " << endl; 
            mostrarDisponibles(sala3);
            cout << endl; 
            break;

        case 4:
            cout << "Fin del programa." << endl;
            status = false; 
            break;
        }
    }
}
//******************************************************************************************************************************
