#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string encriptar(string);
string desencriptar(string);
bool validarTarjeta(string);
int main(int argc, char const *argv[]){
	int opcion;
	do {
		cout << "\n--------------------------------------------MENU---------------------------------------" << endl;
		cout << "Ingrese una opcion" << endl;
		cout << "1.\tEncriptar" << endl;
		cout << "2.\tDesencriptar" << endl;
		cout << "3.\tValidar Tarjeta" << endl;
		cout << "4.\tSalir\nOpcion = ";
		cin >> opcion;
		if (opcion == 1 || opcion == 2) {
			if (opcion == 1) {
				cout << "\n-------------------------------------ENCRIPTADOR---------------------------------------\n" << endl;
			} else {
				cout << "\n------------------------------------DESENCRIPTADOR-------------------------------------\n" << endl;
			}
			cout << "Ingrese la cadena. Solo deben ser minusculas y no debe tener espacios\nCadena = ";
			string cadena;
			cin >> cadena;
			bool esValida = true;
			for (int i = 0; i < cadena.size(); i++) {
				if (cadena.at(i) < 97 || cadena.at(i) > 122) {
					esValida = false;
				}
			}
			if (esValida) {
				if (opcion == 1) {
					cout << "Cadena Normal = " << cadena << endl;
					cout << "Cadena Encriptada = " << encriptar(cadena) << endl;
				} else {
					cout << "Cadena Encriptada = " << cadena << endl;
					cout << "Cadena Normal = " << desencriptar(cadena) << endl;
				}
			} else {
				cerr << "Cadena no valida" << endl;
			}
		} else if (opcion == 3) {
			cout << "\n-----------------------------------VALIDADOR DE TARJETAS--------------------------------\n" << endl;
			string cadena;
			cout << "Ingrese la tarjeta de credito = ";
			cin >> cadena;
			if (validarTarjeta(cadena)) {
				cout << "Numero de tarjeta valida" << endl;
			} else {
				cerr << "Numero de tarjeta invalida" << endl;
			}
		} else if (opcion == 4) {
			break;
		} else {
			cerr << "OPCION INVALIDA" << endl;
		}
	} while(1);
	return 0;
}

string encriptar(string normal) {
	stringstream clave;
	for (int i = 0; i < normal.size(); i++) {
		if (normal.at(i) >= 120){
			clave << (char)(normal.at(i) - 23);
		} else {
			clave << (char)(normal.at(i) + 3);
		}
	}
	return clave.str();
}

string desencriptar(string normal) {
	stringstream clave;
	for (int i = 0; i < normal.size(); i++) {
		if (normal.at(i) <= 99) {
			clave << (char)(normal.at(i) + 23);
		} else {
			clave << (char)(normal.at(i) - 3);
		}
	}
	return clave.str();
}
bool validarTarjeta(string tarjeta) {
	if (tarjeta.size() == 16) {
		int suma = 0;
		for (int i = 0; i < tarjeta.size(); i++) {
			int digito = tarjeta.at(i) - '0';
			if (tarjeta.at(i) < 48 || tarjeta.at(i) > 57) {
				return false;
			}
			if (digito != 0 && i % 2 == 0) {
				if (digito * 2 >= 10) {
					suma += (digito * 2 - 10) + 1;
				} else {
					suma += digito * 2;
				}
			} else {
				suma += digito;
			}
		}
		return suma % 10 == 0;
	}
	return false;
}