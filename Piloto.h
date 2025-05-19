#ifndef PILOTO_H
#define PILOTO_H
#include<iostream>

using namespace std;

class Piloto
{
private:
    string id;
    string nombre;
public:
    Piloto(){
        id = "";
        nombre = "";
    }
    Piloto(string id,string nombre){
        this->id = id;
        this->nombre = nombre;
    }
    ~Piloto(){

    }

    string getId(){
        return id;
    }
    string getNombre(){
        return nombre;
    }
};

#endif
