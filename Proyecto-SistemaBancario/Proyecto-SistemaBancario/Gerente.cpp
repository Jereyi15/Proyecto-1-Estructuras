#include "Gerente.h"

Gerente::Gerente(string _contrasena): contrasena(_contrasena)
{
}

Gerente::~Gerente()
{
}

string Gerente::getContrasena()
{
	return contrasena;
}
