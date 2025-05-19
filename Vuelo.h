#ifndef VUELO_H
#define VUELO_H
#include<iostream>

using namespace std;

class Vuelo
{
private:
    string cedulaPasajero;
    string ciudadOrigen;
    string ciudadDestino;
    string codigoAvion;
public:
    Vuelo(){
        cedulaPasajero = "";
        ciudadOrigen = "";
        ciudadDestino = "";
        codigoAvion = "";
    }
    Vuelo(string cedulaPasajero,string ciudadOrigen,string ciudadDestino,string codigoAvion){
        this->cedulaPasajero = cedulaPasajero;
        this->ciudadOrigen = ciudadOrigen;
        this->ciudadDestino = ciudadDestino;
        this->codigoAvion = codigoAvion;
    }
    ~Vuelo(){
	}

    void setCedulaPasajero(string cedulaPasajero){
        this->cedulaPasajero = cedulaPasajero;
    }
    void setCiudadOrigen(string ciudadOrigen){
        this->ciudadOrigen = ciudadOrigen;
    }
    void setCiudadDestino(string ciudadDestino){
        this->ciudadDestino = ciudadDestino;
    }
    void setCodigoAvion(string codigoAvion){
        this->codigoAvion = codigoAvion;
    }
    string getCedulaPasajero(){
        return cedulaPasajero;
    }
    string getCiudadOrigen(){
        return ciudadOrigen;
    }
    string getCiudadDestino(){
        return ciudadDestino;
    }
    string getCodigoAvion(){
        return codigoAvion;
    }

};
#endif
