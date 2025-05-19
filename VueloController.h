#ifndef VUELOCONTROLLER_H
#define VUELOCONTROLLER_H
#include <iostream>
#include "Vuelo.h"
class VueloController
{
private:
    Vuelo vuelo;

public:
    
    string seleccionarAvion(string ciudadOrigen)
    {
        ifstream archivo("Avion.txt");
        ofstream temp("temp_aviones.txt");
        string codigoAvion, ciudadActual, estado;
        string avionSeleccionado = "";

        while (getline(archivo, codigoAvion, ',') &&
               getline(archivo, ciudadActual, ',') &&
               getline(archivo, estado,','))
        {
            if (ciudadActual == ciudadOrigen && estado == "disponible" && avionSeleccionado == "")
            {
                avionSeleccionado = codigoAvion;
                temp << codigoAvion << "," << ciudadActual << ",ocupado\n";
            }
            else
            {
                temp << codigoAvion << "," << ciudadActual << "," << estado << "\n";
            }
        }

        archivo.close();
        temp.close();

        remove("Avion.txt");
        rename("temp_aviones.txt", "Avion.txt");

        return avionSeleccionado;
    }

    void comprarPasaje()
    {
        string cedula, ciudadOrigen, ciudadDestino;
        cout << "Ingrese cedula del pasajero: ";
        cin >> cedula;
        cout << "Ingrese ciudad de origen: ";
        cin >> ciudadOrigen;
        cout << "Ingrese ciudad de destino: ";
        cin >> ciudadDestino;

        string avion = seleccionarAvion(ciudadOrigen);
        if (avion == "")
        {
            cout << "No hay aviones disponibles en " << ciudadOrigen << endl;
            return;
        }

        ofstream archivo("pasajes.txt", ios::app);
        archivo << cedula << "," << ciudadOrigen << "," << ciudadDestino << "," << avion << "\n";
        archivo.close();

        cout << "Pasaje comprado exitosamente. Avion asignado: " << avion << endl;
    }

    void finalizarTraslado(string codigoAvion)
    {
        ifstream archivo("aviones.txt");
        ofstream temp("temp_aviones.txt");
        string cod, ciudad, estado;

        while (getline(archivo, cod, ',') &&
               getline(archivo, ciudad, ',') &&
               getline(archivo, estado))
        {
            if (cod == codigoAvion)
            {
                temp << cod << "," << ciudad << ",disponible\n";
            }
            else
            {
                temp << cod << "," << ciudad << "," << estado << "\n";
            }
        }

        archivo.close();
        temp.close();

        remove("aviones.txt");
        rename("temp_aviones.txt", "aviones.txt");

        cout << "Traslado finalizado. Avion " << codigoAvion << " disponible nuevamente.\n";
    }
};
#endif
