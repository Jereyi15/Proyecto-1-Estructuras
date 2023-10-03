#include <iostream>

using namespace std;

class Utiles
{
public:
	static int validarEntero();
	static double validarDecimal();
	static string opcionInvalida();

protected:
	Utiles();
	virtual ~Utiles();

};