#include <array>
using std::array;
using std::cin;
using std::cout;

bool esPrimo(int pr)
{
	int j = sqrt(pr);
	for (size_t i = 2; i <= j; i++){
		if (pr % i == 0)
			return false;
	}
	return true;
}

int main() {

	cout << "Ingrese 10 numeros\n";
	array<int,10> numIngresados;
	array<array<int,10>, 2> numClasificados;

	for (int i = 0; i < 10; i++){
		cout << "Ingrese numero\n";
		cin >> numIngresados.at(i);
	}

	int numPrimos = 0;
	int numNoPrimos = 0;
	for (int i = 0; i < 10; i++){
		if (numIngresados.at(i) == 0 || numIngresados.at(i) == 1)
		{
			cout << "0 y 1 no son números primos ni compuestos\n";
		}
		else
		{
			if (esPrimo(numIngresados.at(i))){
				numClasificados.at(0).at(numPrimos) = numIngresados.at(i);
				numPrimos++;
			}
			else{
				numClasificados.at(1).at(numNoPrimos) = numIngresados.at(i);
				numNoPrimos++;
			}
		}
	}
	cout << "Numeros primos:\n";
	for (int i = 0; i < numPrimos; i++){
		cout << numClasificados.at(0).at(i) << "\n";
	}
	cout << "Numeros compuestos:\n";
	for (int i = 0; i < numNoPrimos; i++){
		cout << numClasificados.at(1).at(i) << "\n";
	}
	return 0;
}
