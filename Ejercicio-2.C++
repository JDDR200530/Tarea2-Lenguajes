#include <iostream>
#include <string>
using namespace std;

// Declaramos funciones para las operaciones básicas
double suma(double a, double b)
{
	return a + b;
}
double resta(double a, double b)
{
	return a - b;
}
double multiplicacion(double a, double b)
{
	return a * b;
}
double division(double a, double b)
{
	if (b == 0)
	{
		cerr << "Error: División por cero\n";
		return 0.0; // o podríamos lanzar una excepción si lo deseamos
	}
	return a / b;
}

int main()
{
	double a, b, resultado;
	int opcion;

	do
	{
		cout << "\n======= CALCULADORA=======\n";
		cout << "[1] Sumar \n";
		cout << "[2] Restar \n";
		cout << "[3] Multiplicar\n";
		cout << "[4] Dividirr\n";
		cout << "[0] Salir\nOpcion: ";
		cin >> opcion;

		if (opcion >= 1 && opcion <= 4)
		{
			cout << "Ingrese el primer numero: ";
			cin >> a;
			cout << "Ingrese el segundo numero: ";
			cin >> b;
		}
		switch (opcion)
		{
		case 1:
			resultado = suma(a, b);
			break;
		case 2:
			resultado = resta(a, b);
			break;
		case 3:
			resultado = multiplicacion(a, b);
			break;
		case 4:
			resultado = division(a, b);
			break;
		case 0:
			cout << "Adios!";
			break;
		default:
			cout << "Opcion incorrecta!" << endl;
		}
		if (opcion >= 1 && opcion <= 4)
		{
			cout << "Resultado: " << resultado << endl;
		}
	} while (opcion != 0);
	return 0;
}
