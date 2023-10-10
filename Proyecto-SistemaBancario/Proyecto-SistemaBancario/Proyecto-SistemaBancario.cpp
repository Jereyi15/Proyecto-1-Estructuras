#include <iostream>
using namespace std;


#include "Interfaz.h"
int main() {
	Interfaz* i = new Interfaz();
	i->iniciar();
	delete i;
}

