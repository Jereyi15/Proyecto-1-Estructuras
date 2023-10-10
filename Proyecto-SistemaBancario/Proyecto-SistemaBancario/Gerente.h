#pragma once
#include <string>
using namespace std;
class Gerente
{
public:
	Gerente(string);
	~Gerente();
	string getContrasena();
private:
	string contrasena;
};

