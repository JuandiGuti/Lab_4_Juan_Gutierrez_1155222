#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>

using namespace std;


int main() {
	srand(time(NULL));
	string respuesta;

	cout << "BIENVENIDOS A LA CARRERA DEL SIGLO!" << endl;
	cout << "*Puedes iniciar la carrera tecleando \"1\" en el siguiente espacio:" << endl;
	cin >> respuesta;
	if (respuesta != "1") {
		cout << "Tu te lo pierdes, adios" << endl;
		return 0;
	}
	cout << "BANG!" << endl;
	cout << "Y ARRANCAN!" << endl;

	string pista[72];
	string* fin_pista;

	fin_pista = &pista[70];
	string* dirtortuga = &pista[1];
	string* dirliebre = &pista[1];

	for (int i = 0; i < 70; i++) {
		pista[i] = "_";
	}
	pista[70] = "A";
	pista[71] = "A";
	bool win_t = false;
	bool win_l = false;
	
	while (win_t != true || win_l == true) {
			int num_t = 1 + rand() % (11 - 1);
			int num_l = 1 + rand() % (11 - 1);

			if (num_t >= 1 && num_t <= 5) {
				//paso veloz
				if (*(dirtortuga + 3) == "H") {
					*(dirtortuga + 3) = "OUCH";
					*dirtortuga = "_";
					dirtortuga = dirtortuga + 3;
				}
				else if (*(dirtortuga + 3) == "A") {
					win_t = true;
					break;
				}
				else {
					*(dirtortuga + 3) = "T";
					*dirtortuga = "_";
					dirtortuga = dirtortuga + 3;
				}

			}
			else if (num_t >= 6 && num_t <= 7) {
				//paso resbalon
				if (*(dirtortuga - 6) == "_") {
					*(dirtortuga - 6) = "T";
					*dirtortuga = "_";
					dirtortuga = dirtortuga - 6;
				}
				else if (*(dirtortuga - 6) == "H") {
					*(dirtortuga - 6) = "OUCH";
					*dirtortuga = "_";
					dirtortuga = dirtortuga - 6;
				}
				else {
					if (pista[0] == "H") {
						pista[0] = "OUCH";
						*dirtortuga = "_";
						dirtortuga = &pista[0];
					}
					else {
						pista[0] = "T";
						*dirtortuga = "_";
						dirtortuga = &pista[0];
					}
				}
			}
			else if (num_t >= 8 && num_t <= 10) {
				//paso lento
				if (*(dirtortuga + 1) == "H") {
					*(dirtortuga + 1) = "OUCH";
					*dirtortuga = "_";
					dirtortuga = dirtortuga + 1;
				}
				else if (*(dirtortuga + 1) == "A") {
					win_t = true;
					break;
				}
				else {
					*(dirtortuga + 1) = "T";
					*dirtortuga = "_";
					dirtortuga = dirtortuga + 1;
				}
			}


			//LIEBRE


			if (num_l >= 1 && num_l <= 3) {
				//paso veloz
				if (*(dirliebre + 3) == "T") {
					*(dirliebre + 3) = "OUCH";
					*dirliebre = "_";
					dirliebre = dirliebre + 3;
				}
				else if (*(dirliebre + 3) == "A") {
					win_l = true;
					break;
				}
				else {
					*(dirliebre + 3) = "H";
					*dirliebre = "_";
					dirliebre = dirliebre + 3;
				}

			}
			else if (num_l >= 4 && num_l <= 5) {
				//paso resbalon
				if (*(dirliebre - 6) == "_") {
					*(dirliebre - 6) = "H";
					*dirliebre = "_";
					dirliebre = dirliebre - 6;
				}
				else if (*(dirliebre - 6) == "T") {
					*(dirliebre - 6) = "OUCH";
					*dirliebre = "_";
					dirliebre = dirliebre - 6;
				}
				else {
					if (pista[0] == "T") {
						pista[0] = "OUCH";
						*dirliebre = "_";
						dirliebre = &pista[0];
					}
					else {
						pista[0] = "H";
						*dirliebre = "_";
						dirliebre = &pista[0];
					}
				}
			}
			else if (num_l >= 6 && num_l <= 10) {
				//paso lento
				if (*(dirliebre + 1) == "T") {
					*(dirliebre + 1) = "OUCH";
					*dirliebre = "_";
					dirliebre = dirliebre + 1;
				}
				else if (*(dirliebre + 1) == "A") {
					win_l = true;
					break;
				}
				else {
					*(dirliebre + 1) = "H";
					*dirliebre = "_";
					dirliebre = dirliebre + 1;
				}
			}

			//COMPROBACIONES
			
			if (pista[69] == "T") {
				win_t = true;
			}
			else if (pista[69] == "H") {
				win_l = true;
			}

			for (int i = 0; i < 70; i++) {
				cout << pista[i];
			}
			cout << endl;
	}
	
	if (win_t == true) {
		for (int i = 0; i < 69; i++) {
			if (pista[i] == "T") {
				cout << "_";
			}
			else {
				cout << pista[i];
			}
		}
		cout << "T";
		cout << endl;
		cout << "LA TORTUGA GANA! BRAVO!";
	}
	else {
		for (int i = 0; i < 69; i++) {
			if (pista[i] == "H") {
				cout << "_";
			}
			else {
				cout << pista[i];
			}
		}
		cout << "H";
		cout << endl;
		cout << "La liebre gana. Ni hablar";
	}
	return 0;
}