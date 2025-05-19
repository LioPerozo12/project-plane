#ifndef AVION_H
#define AVION_H
#include "Piloto.h"
#include<iostream>

using namespace std;

class Avion
{
private:
    string codigo;
    string capacidad;
    Piloto pilotoAsignado;
    string ciudadActual;
    string estado;
public:
    Avion(){
        codigo = "";
        capacidad ="";
        ciudadActual = "";
		estado = "disponible";
    }
    Avion(string codigo,string capacidad,Piloto pilotoAsignado,string ciudadActual){
        this->codigo = codigo;
        this->capacidad = capacidad;
        this->pilotoAsignado = pilotoAsignado;
        this->ciudadActual = ciudadActual;
        estado = "disponible";
    }
    ~Avion(){

    }
    void setCodigo(string codigo){
        this->codigo = codigo;
    }
    void setCapacidad(string capacidad){	
        this->capacidad = capacidad;
    }
    void setPilotoAsignado(Piloto pilotoAsignado){
        this->pilotoAsignado = pilotoAsignado;
    }
    void setCiudadActual(string ciudadActual){
        this->ciudadActual = ciudadActual;
    }
    string getCodigo(){
        return codigo;
    }
    string getCapacidad(){
        return capacidad;
    }
    Piloto getPilotoAsignado(){
        return pilotoAsignado;
    }
    string getCiudadActual(){
        return ciudadActual;
    }
    string getDisponible(){
    	return estado;
	}
    void mostrar() {
        cout << "Codigo: " << codigo << " | Capacidad: " << capacidad << " | ciudad Actual: "<< ciudadActual << " | id piloto: " << pilotoAsignado.getId() << " | Nombre Piloto: " << pilotoAsignado.getNombre()  << endl;
    }
};

#endif
