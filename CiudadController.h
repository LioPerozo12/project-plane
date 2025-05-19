#ifndef CIUDADCONTROLLER_H
#define CIUDADCONTROLLER_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "Avion.h"
#include "Piloto.h"
#include "Ciudad.h"

using namespace std;

class CiudadController
{
private:
    Ciudad ciudad;

public:
    CiudadController(){

    }
    CiudadController(Ciudad ciudad)
    {
        this->ciudad = ciudad;
    }

    void MenuCiudad()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "\n--- MENU DE CUIDADES ---" << endl;
            cout << "1. Agregar un Ciudad" << endl;
            cout << "2. Editar un Ciudad" << endl;
            cout << "3. Consultar un Ciudad" << endl;
            cout << "4. Eliminar un Ciudad" << endl;
            cout << "0. Volver al sub-menu principal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            case 1:{
            	string nombre;
                fflush(stdin);
                cout<<"Digite el nombre de la ciudad: ";
                getline(cin,nombre);
                ciudad.setNombre(nombre);
                Agregar();
				break;
			}
            case 2:{
            	MostrarCiudad();
                int i;
                string nombre;

                cout<<"\nDigite el numero que quiere editar: ";
                cin>>i;
                
                cout<<"Digite el nombre de la ciudad: ";
                cin>>nombre;

                Editar(nombre,i);
                break;
            }
            case 3:{
                string nombre;

                cout<< "Digite el nombre de la ciudad para consultar"<<endl;
                cin >> nombre;

                Consultar(nombre);
                break;
            }
            case 4:{
                string nombre;

                cout<< "Digite el nombre de la ciudad para eliminar"<<endl;
                cin >> nombre;

                Eliminar(nombre);
                break;
            }
            
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
            }
            system("pause");
        } while (opcion != 0);
    }

    void Agregar()
    {
        ofstream archivo("Ciudades.txt", ios::app);
        archivo << ciudad.getNombre() << "\n";
        archivo.close();
    }
    void Editar(string nuevoNombre,int i)
    {
        ifstream archivo("Ciudades.txt");
        ofstream temporal("temp.txt");

        string nombre;
        int iAux = 1;
        while (getline(archivo, nombre))
        {
            if (iAux == i)
            {
                temporal << nuevoNombre << "\n";
            }
            else
            {
                temporal << nombre << "\n";
            }
            iAux++;
        }

        archivo.close();
        temporal.close();

        remove("Ciudades.txt");
        rename("temp.txt", "Ciudades.txt");
    }

    void Consultar(string nombreBuscar)
    {
        ifstream archivo("Ciudades.txt");
        string nombre;
        while (getline(archivo, nombre))
        {
            if (nombre == nombreBuscar)
            {
                Ciudad ciudad(nombre);
                ciudad.mostrar();
            }
        }
        archivo.close();
    }
    void Eliminar(string ciudadEliminar)
    {
        ifstream archivo("Ciudades.txt");
        ofstream temporal("temp.txt");

        string nombre;
        while (getline(archivo, nombre))
        {
            if (nombre != ciudadEliminar){
                temporal << nombre << "\n";
            }
        }

        archivo.close();
        temporal.close();
        remove("Ciudades.txt");
        rename("temp.txt", "Ciudades.txt");
    }

private:
    void MostrarCiudad()
    {
        ifstream archivo("Ciudades.txt");

        int i = 1;
        string nombre;
        while (getline(archivo, nombre))
        {
            Ciudad ciudad(nombre);
            cout << i<<". ";
            ciudad.mostrar();
            i++;
        }
        archivo.close();
    }
};
#endif
