#ifndef CIUDAD_H
#define CIUDAD_H
#include<iostream>
#include<cstring>

using namespace std;

class Ciudad
{
private:
    string nombre;
public:
    Ciudad(){
        nombre = "";
    }

    Ciudad(string nombre){
        this->nombre = nombre;
    }
    ~Ciudad(){

    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }

    string getNombre(){
        return nombre;
    }
    void mostrar() {
        cout << "Nombre Ciudad: " << nombre << endl;
    }
};
#endif
