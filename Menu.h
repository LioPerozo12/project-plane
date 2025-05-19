#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstdlib>
#include "PasajeroController.h"
#include "AvionController.h"
#include "CiudadController.h"
#include "VueloController.h"

using namespace std;

class Menu{
private:
    int opcion;
    PasajeroController pasajero;
    AvionController avion;
    CiudadController ciudad;
    VueloController vuelo;
    public:
    void MenuPrincipal()
    {
        do
        {
            system("cls");
            cout << "=== MENU PRINCIPAL ===" << endl;
            cout << "1. Submenu de Gestion (Pasajeros, Aviones, Ciudades)" << endl;
            cout << "2. Submenu de Vuelos (Compra, Flota, Traslado)" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
                case 1:
                menuGestion();
                break;
            case 2:
                menuVuelos();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
            }
            cout << endl;
            system("cls");
            system("pause");
        } while (opcion != 0);
    }

    void menuGestion()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "\n--- SUBMENU DE GESTION ---" << endl;
            cout << "1. Gestion de Pasajeros" << endl;
            cout << "2. Gestion de Avion y Piloto" << endl;
            cout << "3. Gestion de Ciudades" << endl;
            cout << "0. Volver al menu principal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
                case 1:                    
                    pasajero.MenuPasajero();
                break;
            case 2:
                    avion.MenuAvion();
                break;
            case 3:
                    ciudad.MenuCiudad();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
            }
            system("cls");
            system("pause");
        } while (opcion != 0);
    }

    void menuVuelos()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "\n--- SUBMENU DE VUELOS ---" << endl;
            cout << "1. Compra de Pasaje" << endl;
            cout << "2. Seleccionar Flota" << endl;
            cout << "3. Finalizar Traslado" << endl;
            cout << "0. Volver al menu principal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            case 1:
                vuelo.comprarPasaje();
                break;
            case 2:
                cout << "Seleccionar Flota" << endl;
                break;
            case 3:
                cout << "Finalizar Traslado" << endl;
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
            }
            system("pause");
        } while (opcion != 0);
    }
};
#endif
