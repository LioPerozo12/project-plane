#ifndef SISTEMAVULOS_H
#define SISTEMAVULOS_H
#include "Avion.h"
#include "AvionController.h"
#include "Ciudad.h"
#include <iostream>
#include <vector>
#include <sstream>

class SistemaVuelos
{
private:
    vector<Avion> flota;
    vector<Ciudad> ciudades;

public:
    void distribuirAviones()
    {
        srand(time(0));
        for (size_t i = 0; i < flota.size(); ++i)
        {
            if (!ciudades.empty())
            {
                int idx = rand() % ciudades.size();
                flota[i].setCiudadActual(ciudades[idx].getNombre());
                cout << "Avion " << flota[i].getCodigo() << " asignado a la ciudad " << ciudades[idx].getNombre() << endl;
            }
        }
    }

    void seleccionarAvion(string ciudadOrigen)
    {
        ifstream archivo("Avion.txt");
        if (!archivo.is_open())
        {
            cout << "No se pudo abrir el archivo Avion.txt" << endl;
            return;
        }
        string linea;
        bool encontrado = false;
        while (getline(archivo, linea))
        {
            stringstream ss(linea);
            string codigo, ciudad, disponible, capacidad, id, piloto;
            getline(ss, codigo, ',');
            getline(ss, ciudad, ',');
            getline(ss, disponible, ',');
            getline(ss, capacidad, ',');
            getline(ss, id, ',');
            getline(ss, piloto, ',');

            if (ciudad == ciudadOrigen && disponible == "disponible")
            {
                cout << "Codigo: " << codigo
                     << ", Ciudad: " << ciudad
                     << ", Estado: " << disponible
                     << ", Capacidad: " << capacidad
                     << ", ID: " << id
                     << ", Piloto: " << piloto << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            cout << "No hay aviones disponibles en la ciudad " << ciudadOrigen << endl;
        }
        archivo.close();
    }

    void finalizarVuelo(string idAvion, string ciudadDestino)
    {
        for (size_t i = 0; i < flota.size(); ++i)
        {
            if (flota[i].getCodigo() == idAvion && flota[i].getDisponible() != "disponible")
            {
                AvionController avionController;
                avionController.FinalizarVuelo(idAvion, ciudadDestino);
                cout << "Vuelo finalizado correctamente.\n";
                cout << ciudadDestino << endl;
                return;
            }
        }
        cout << "Error: Avion no encontrado o ya disponible.\n";
    }
};

#endif