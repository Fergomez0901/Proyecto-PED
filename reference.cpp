#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

struct Producto{
    string nombre; 
    float precioUni;
    int cantidad; 
};

vector<Producto> list; 

struct Pedido{
    string apellido; 
    vector<Producto> listaProd; 
};

struct Producto producto; 
struct Pedido pedido; 
queue<Pedido> colaDonas; 
queue<Pedido> colaPlatoFuerte; 


void atenderPedido()
{
    int option, option2; 
    bool estado = true; 
    cout << "1) Comprar donas" << endl; 
    cout << "2) Comprar platos fuertes" << endl; 
    cout << "3) Salir" << endl; 
    cout << "Ingrese una opcion: ";   cin >> option; cin.ignore();
    cout << endl;

    switch(option)
    {
        case 1:
            while(estado)
            {
                cout << "1) Dona sencilla" << endl; 
                cout << "2) Dona rellena de leche" << endl; 
                cout << "3) Dona sabor mocca" << endl; 
                cout << "4) Dona sabor caramelo" << endl; 
                cout << "5) Salir" << endl; 
                cout << "Ingrese una opcion: ";  cin >> option2; cin.ignore(); 
                cout << endl;

                switch(option2)
                {
                    case 1:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de donas que desea comprar: "; cin >> producto.cantidad; 
                        producto.nombre = "Dona sencilla";
                        producto.precioUni = 1.00;
                        pedido.listaProd.push_back(producto); 
                        colaDonas.push(pedido);
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl; 
                        estado = false; 
                        break;
                    case 2:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de donas que desea comprar: ";  cin >> producto.cantidad;
                        producto.nombre = "Dona rellena de leche"; 
                        producto.precioUni = 1.25;
                        pedido.listaProd.push_back(producto);
                        colaDonas.push(pedido);
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl; 
                        estado = false; 
                        break; 
                    case 3:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de donas que desea comprar: ";  cin >> producto.cantidad;
                        producto.nombre = "Dona sabor mocca"; 
                        producto.precioUni = 1.50;
                        pedido.listaProd.push_back(producto);
                        colaDonas.push(pedido);
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl; 
                        estado = false; 
                        break; 
                    case 4: 
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de donas que desea comprar: ";  cin >> producto.cantidad;
                        producto.nombre = "Dona sabor caramelo"; 
                        producto.precioUni = 1.50;
                        pedido.listaProd.push_back(producto);
                        colaDonas.push(pedido);
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl; 
                        estado = false; 
                        break; 
                    case 5:
                        cout << "Saliendo..." << endl << endl; 
                        estado = false;
                        break;
                    default:
                        cout << "Opcion invalida. Intentalo de nuevo" << endl << endl; 
                        break; 
                }
            }
            break; 

        case 2:
            while(estado)
            {
                cout << "1) Desayuno" << endl; 
                cout << "2) Almuerzo" << endl; 
                cout << "3) Cena" << endl;
                cout << "4) Salir" << endl;
                cout << "Ingrese una opcion: ";     cin >> option2; cin.ignore(); 
                cout << endl;

                switch(option2)
                {
                    case 1:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de desayunos que desea comprar: "; cin >> producto.cantidad;
                        producto.nombre = "Desayuno";
                        producto.precioUni = 2.50;
                        pedido.listaProd.push_back(producto); //Se envia el producto a la lista del cliente
                        colaPlatoFuerte.push(pedido); // Se envia el pedido a la cola de platos fuertes
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl;
                        estado = false; 
                        break;
                    case 2:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de almuerzos que desea comprar: "; cin >> producto.cantidad;
                        producto.nombre = "Almuerzo";
                        producto.precioUni = 5.00;
                        pedido.listaProd.push_back(producto); //Se envia el producto a la lista del cliente
                        colaPlatoFuerte.push(pedido); // Se envia el pedido a la cola de platos fuertes
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl;
                        estado = false; 
                        break;
                    case 3:
                        cout << "Ingrese el apellido del cliente: "; getline(cin, pedido.apellido);
                        cout << "Ingrese la cantidad de cenas que desea comprar: "; cin >> producto.cantidad;
                        producto.nombre = "Cena";
                        producto.precioUni = 3.50;
                        pedido.listaProd.push_back(producto); //Se envia el producto a la lista del cliente
                        colaPlatoFuerte.push(pedido); // Se envia el pedido a la cola de platos fuertes
                        cout << "Monto a pagar: " << producto.cantidad * producto.precioUni;
                        cout << "Pedido agregado exitosamente" << endl << endl;
                        estado = false; 
                        break;
                    case 4: 
                        estado = false; 
                        cout << "Saliendo..." << endl << endl; 
                        break; 
                    default:
                        cout << "Opcion invalida. Intentalo de nuevo" << endl << endl; 
                        break; 
                }
            }
            break; 
        case 3: 
            cout << "Saliendo..." << endl; 
            break;
    }
}

void cobrarDonas()
{
    float total = 0; 
    if(colaDonas.empty())
    {
        cout << "No hay clientes en la cola de donas" << endl; 
        return; 
    }
    else
    {
        while(!colaDonas.empty())
        {
            for(int i = 0; i < colaDonas.front().listaProd.size(); i++)
            {
                total += colaDonas.front().listaProd[i].cantidad * colaDonas.front().listaProd[i].precioUni;
            }
            colaDonas.pop(); 
        }
        cout << "Se ha obtenido una ganancia de : $" << total << " en concepto de venta de donas." << endl; 
    }
}

void cobrarPlatosFuertes()
{
    float total = 0; 
    if(colaPlatoFuerte.empty())
    {
        cout << "No hay clientes en la cola de platos fuertes" << endl; 
        return; 
    }
    else
    {
        while(!colaPlatoFuerte.empty())
        {
            for(int i = 0; i < colaPlatoFuerte.front().listaProd.size(); i++)
            {
                total += colaPlatoFuerte.front().listaProd[i].cantidad * colaPlatoFuerte.front().listaProd[i].precioUni;
            }
            colaPlatoFuerte.pop(); 
        }
        cout << "Se ha obtenido una ganancia de : $" << total << " en concepto de venta de platos fuertes." << endl; 
    }
}


void menu()
{
    int option; 
    bool estado = true; 

    while(estado)
    {
        cout << "<----- MENU ----->" << endl; 
        cout << "1) Atender pedidos de clientes" << endl; 
        cout << "2) Calcular ganancias por venta de donas (Cobrar cola de donas)" << endl; 
        cout << "3) Calcular ganancias por venta de platos fuertes (Cobrar cola de platos fuertes)" << endl; 
        cout << "4) Salir" << endl; 
        cout << "Ingrese una opcion: "; cin >> option; cin.ignore();
        cout << endl;

        switch (option)
        {
        case 1: atenderPedido(); break;
        case 2: cobrarDonas(); break; 
        case 3: cobrarPlatosFuertes(); break; 
        case 4: estado = false; cout << "Fin del programa" << endl; break; 
        default: cout << "Opcion invalida. Intentalo de nuevo" << endl; break;
        }
    }
}

int main()
{
    menu(); 
}
