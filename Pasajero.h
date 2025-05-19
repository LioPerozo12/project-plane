#ifndef Pasajero_H
#define Pasajero_H
#include<iostream>
#include<cstring>

using namespace std;

class Pasajero
{
private:
    string nombre;
    string apellido;
    string cedula;

public:
    Pasajero(){
        nombre = "";
        apellido = "";
        cedula = "";
    }
    Pasajero(string nombre,string apellido,string cedula){
        this->nombre = nombre;
        this->apellido = apellido;
        this->cedula = cedula;
    }
    ~Pasajero(){

    }
    string getNombre() {
        return nombre;
    }

    void setNombre( string nombre) {
        this->nombre = nombre;
    }

    string getApellido() {
        return apellido;
    }

    void setApellido( string apellido) {
        this->apellido = apellido;
    }

    string getCedula() {
        return cedula;
    }

    void setCedula(string cedula) {
        this->cedula = cedula;
    }
    void mostrar() {
        cout << "Cedula: " << cedula << " | Nombre: " << nombre << " | Apellido: "<< apellido << endl;
    }
};
#endif
