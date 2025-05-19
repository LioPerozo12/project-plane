#ifndef PASAJEROCONTROLLER_H
#define PASAJEROCONTROLLER_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "Pasajero.h"

using namespace std;

class PasajeroController
{
private:
    Pasajero pasajero;

public:
    PasajeroController(){

    }
    PasajeroController(Pasajero pasajero)
    {
        this->pasajero = pasajero;
    }

    void MenuPasajero()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "\n--- MENU DE PASAJEROS ---" << endl;
            cout << "1. Agregar un Pasajero" << endl;
            cout << "2. Editar un Pasajero" << endl;
            cout << "3. Consultar un Pasajero" << endl;
            cout << "4. Eliminar un Pasajero" << endl;
            cout << "0. Volver al sub-menu principal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            case 1:{
            	string cedula, apellido, nombre;
                cout<<"Digite el nombre: ";
                cin>>nombre;

                cout<<"Digite el apellido: ";
                cin>>apellido;

                cout<<"Digite la cedula: ";
                cin>>cedula;

                pasajero.setNombre(nombre);
                pasajero.setApellido(apellido);
                pasajero.setCedula(cedula);
                Agregar();
				break;
			}
            case 2:{
            	MostrarUsuarios();
                string cedula, apellido, nombre;
                int i;

                cout<<"\nDigite el numero que quiere editar: ";
                cin>>i;

                cout<<"Digite el nombre: ";
                cin>>nombre;

                cout<<"Digite el apellido: ";   
                cin>>apellido;

                cout<<"Digite la cedula: ";
                cin>>cedula;

                Editar(cedula,nombre,apellido,i);
                break;
            }
            case 3:{
                string cedula;

                cout<< "Digite la cedula para consultar"<<endl;
                cin >> cedula;

                Consultar(cedula);
                break;
            }
            case 4:{
                string cedula;

                cout<< "Digite la cedula para eliminar al usuario"<<endl;
                cin >> cedula;

                Eliminar(cedula);
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
        ofstream archivo("pasajero.txt", ios::app);
        archivo << pasajero.getNombre() << "," << pasajero.getApellido() << "," << pasajero.getCedula() << "\n";
        archivo.close();
    }
    void Editar(string cedulaEditar, string nuevoNombre, string nuevoApellido,int i)
    {
        ifstream archivo("pasajero.txt");
        ofstream temporal("temp.txt");

        string cedula, apellido, nombre;
        int iAux = 1;
        while (getline(archivo, nombre, ',') && getline(archivo, apellido, ',') && getline(archivo, cedula))
        {
            if (iAux == i)
            {
                temporal << nuevoNombre << "," << nuevoApellido << "," << cedulaEditar << "\n";
            }
            else
            {
                temporal << nombre << "," << apellido << "," << cedula << "\n";
            }
            iAux++;
        }

        archivo.close();
        temporal.close();

        remove("pasajero.txt");
        rename("temp.txt", "pasajero.txt");
    }

    void Consultar(string cedulaBuscar)
    {
        ifstream archivo("pasajero.txt");
        string cedula, apellido, nombre;

        while (getline(archivo, nombre, ',') && getline(archivo, apellido, ',') && getline(archivo, cedula))
        {
            if (cedula == cedulaBuscar)
            {
                Pasajero p(nombre, apellido, cedula);
                p.mostrar();
            }
        }
        archivo.close();
    }
    void Eliminar(string cedulaEliminar)
    {
        ifstream archivo("pasajero.txt");
        ofstream temporal("temp.txt");

        string cedula, apellido, nombre;
        while (getline(archivo, nombre, ',') && getline(archivo, apellido, ',') && getline(archivo, cedula))
        {
            if (cedula != cedulaEliminar)
                temporal << nombre << "," << apellido << "," << cedula << "\n";
        }

        archivo.close();
        temporal.close();
        remove("pasajero.txt");
        rename("temp.txt", "pasajero.txt");
    }

private:
    void MostrarUsuarios()
    {
        ifstream archivo("pasajero.txt");

        string cedula, apellido, nombre;
        int i = 1;

        while (getline(archivo, nombre, ',') && getline(archivo, apellido, ',') && getline(archivo, cedula))
        {
            Pasajero p(nombre, apellido, cedula);
            cout << i<<". ";
            p.mostrar();
            i++;
        }
        archivo.close();
    }
};
#endif
