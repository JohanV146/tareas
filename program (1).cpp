#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void leer();

int main () {
  leer();
}

void leer(){
	ifstream archivo;
	char texto;
	char* total;
	int count = 0;

	archivo.open("example.txt", ios::in); //Abre archivos

	if (archivo.fail()){
		cout << "No se puede abrir el archivo";
		exit(1);
	} else {
		archivo.seekg(0, std::ios_base::end);
		int size = archivo.tellg ();
		archivo.seekg(0);
		cout << "File size" << size << endl;
		total = new char[size];
	}

	while (!archivo.eof()){
		texto = archivo.get();
		
		if (!archivo.failbit) {
			cout << "No se leyó" << endl;
		} else {
			cout << "Caracter: " << texto << endl;
		}
		
		int auxC = 0;
		total[count++] = texto;
	}
	
	total[count] = '\0';
	cout << total << endl;
}