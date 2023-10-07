#include "GeneradorCuentas.h"
#include <time.h>
#include <iostream>

GeneradorCuentas::GeneradorCuentas()
{
	inicializar();
	min = 100000;
	ran = 99999; // esta cantidad, para que el numero generado siempre tenga 6 digitos(ni m�s, ni menos)
}

int GeneradorCuentas::addNumeroCuenta()
{
	inicializar();
	return min + rand() % (ran);
}

void GeneradorCuentas::inicializar()
{
	srand(time(NULL));
}
