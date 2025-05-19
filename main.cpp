#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Pasajero.h"
#include "Piloto.h"
#include "Avion.h"
#include "Ciudad.h"
#include "Vuelo.h"
#include "PasajeroController.h"

using namespace std;
int main(int argc, char **argv)
{
	Menu menu;
	Pasajero usuario("leo", "lobo", "1234567");
	Piloto piloto;
	Avion avion;
	Ciudad ciudad;
	Vuelo vuelo;
	PasajeroController controller(usuario);
	controller.Consultar("1234567");
	controller.Eliminar("1234567");

	menu.MenuPrincipal();
	return 0;
}
