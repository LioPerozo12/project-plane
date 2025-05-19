#ifndef AVIONCONTROLLER_H
#define AVIONCONTROLLER_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "Avion.h"
#include "Piloto.h"

using namespace std;

class AvionController
{
private:
    Avion avion;

public:
    AvionController(){

    }
    AvionController(Avion avion)
    {
        this->avion = avion;
    }

    void MenuAvion()
    {
        int opcion;
        do
        {
            system("cls");
            cout << "\n--- MENU DE AVIONES ---" << endl;
            cout << "1. Agregar un Avion" << endl;
            cout << "2. Editar un Avion" << endl;
            cout << "3. Consultar un Avion" << endl;
            cout << "4. Eliminar un Avion" << endl;
            cout << "0. Volver al sub-menu principal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            system("cls");
            switch (opcion)
            {
            case 1:{
            	string codigo, ciudadActual,nombrePiloto,capacidad,id;
                
                cout<<"Digite la capacidad del avion: ";
                cin>>capacidad;
                
                cout<<"Digite el codigo del avion: ";
                cin>>codigo;

                cout<<"Digite la ciudadActual: ";
                cin>>ciudadActual;

                cout<<"Digite el nombre del piloto: ";
                cin>>nombrePiloto;

                cout<<"Digite el id del piloto: ";
                cin>>id;
                
                Piloto pilotoAsignado(id,nombrePiloto);

                avion.setCodigo(codigo);
                avion.setCapacidad(capacidad);
                avion.setPilotoAsignado(pilotoAsignado);
                avion.setCiudadActual(ciudadActual);
                Agregar();
				break;
			}
            case 2:{
            	MostrarAviones();
                int i;
                string codigo, ciudadActual,nombrePiloto,capacidad,id;

                cout<<"\nDigite el numero que quiere editar: ";
                cin>>i;
                
                cout<<"Digite la capacidad del avion: ";
                cin>>capacidad;
                
                cout<<"Digite el codigo del avion: ";
                cin>>codigo;

                cout<<"Digite la ciudadActual: ";
                cin>>ciudadActual;

                cout<<"Digite el nombre del piloto: ";
                cin>>nombrePiloto;

                cout<<"Digite el id del piloto: ";
                cin>>id;

                Editar(codigo,capacidad,ciudadActual,id,nombrePiloto,i);
                break;
            }
            case 3:{
                string codigo;

                cout<< "Digite el codigo para consultar"<<endl;
                cin >> codigo;

                Consultar(codigo);
                break;
            }
            case 4:{
                string codigo;

                cout<< "Digite el codigo para eliminar al usuario"<<endl;
                cin >> codigo;

                Eliminar(codigo);
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
        ofstream archivo("Avion.txt", ios::app);
        archivo << avion.getCodigo() << "," << avion.getCiudadActual() <<","<< avion.getDisponible() << "," << avion.getCapacidad() <<","<< avion.getPilotoAsignado().getId() << "," << avion.getPilotoAsignado().getNombre() << "\n";
        archivo.close();
    }
    void Editar(string nuevoCodigo, string nuevaCapacidad, string nuevaCiudadActual,string nuevoIdPiloto,string nuevoNombrePiloto,int i)
    {
        ifstream archivo("Avion.txt");
        ofstream temporal("temp.txt");

        string codigo, capacidad, ciudadActual,id,nombre;
        int iAux = 1;
        while (getline(archivo, codigo, ',') && getline(archivo, capacidad, ',') && getline(archivo, ciudadActual, ',') && getline(archivo, id, ',') && getline(archivo, nombre))
        {
            if (iAux == i)
            {
                temporal << nuevoCodigo << "," << nuevaCapacidad << "," << nuevaCiudadActual <<"," << nuevoIdPiloto << "," << nuevoNombrePiloto << "\n";
            }
            else
            {
                temporal << codigo << "," << capacidad << "," << ciudadActual << "," << id << "," <<nombre << "\n";
            }
            iAux++;
        }

        archivo.close();
        temporal.close();

        remove("Avion.txt");
        rename("temp.txt", "Avion.txt");
    }

    void Consultar(string codigoBuscar)
    {
        ifstream archivo("Avion.txt");
        string codigo, ciudadActual,id,nombre,capacidad;
        while (getline(archivo, codigo, ',') && getline(archivo, capacidad, ',') && getline(archivo, ciudadActual, ',') && getline(archivo, id, ',') && getline(archivo, nombre))
        {
            if (codigo == codigoBuscar)
            {
                Piloto pilotoAsignado(id,nombre);
                Avion a(codigo,capacidad,pilotoAsignado,ciudadActual);
                a.mostrar();
            }
        }
        archivo.close();
    }
    void Eliminar(string codigoELiminar)
    {
        ifstream archivo("Avion.txt");
        ofstream temporal("temp.txt");

        string codigo, capacidad, ciudadActual,id,nombre;
        while (getline(archivo, codigo, ',') && getline(archivo, capacidad, ',') && getline(archivo, ciudadActual, ',') && getline(archivo, id, ',') && getline(archivo, nombre))
        {
            if (codigo != codigoELiminar){
                temporal << codigo << "," << capacidad << "," << ciudadActual << "," << id << "," <<nombre << "\n";
            }
        }

        archivo.close();
        temporal.close();
        remove("Avion.txt");
        rename("temp.txt", "Avion.txt");
    }

private:
    void MostrarAviones()
    {
        ifstream archivo("Avion.txt");

        int i = 1;
        string codigo, capacidad, ciudadActual,id,nombre;
        while (getline(archivo, codigo, ',') && getline(archivo, capacidad, ',') && getline(archivo, ciudadActual, ',') && getline(archivo, id, ',') && getline(archivo, nombre))
        {
            Piloto pilotoAsignado(id,nombre);
            Avion a(codigo,capacidad,pilotoAsignado,ciudadActual);
            cout << i<<". ";
            a.mostrar();
            i++;
        }
        archivo.close();
    }
};
#endif
