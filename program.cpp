#include <iostream>

#include "node.hpp"
#include "graph.hpp"

void leer();

int main (int argc, char **argv) {
	graph *g = new graph (std::atoi (argv[1]), std::atoi (argv[2]));
	bool stop = false;
	int option = ' ';
	char NArchivo;
	float w = 0;
	float **m;
	do {
		std::cout << "Opciones:\n 1. Vértice \n2. Arco \n3. Imprimir \n4. Matriz \n5. Salir";
		std::cin >> option;

		switch (option) {
			case 1:
				std::cout << "Nombre del archivo que desea cargar: ";
				std::cin >> NArchivo;
				break;
			case 2:
				std::cout << "Nombre del vértice 1: ";
				std::cin >> v1;
				std::cout << "Nombre del vértice 2: ";
				std::cin >> v2;
				if (g->getWeighted ()) {
					std::cout << "Peso de la conexión: ";
					std::cin >> w;
					g->insertConnection (v1, v2, w);
				}
				else g->insertConnection (v1, v2);
				break;
			case 3:
				g->print ();
				break;
			case 4:
				m = g->ToMatrix ();
				if (m != nullptr)
					for (int i = 0; i < g->getVCount (); i++) {
						for (int j = 0; j < g->getVCount (); j++)
							std::cout << " | " << m[i][j];
						std:: cout << " |" << std::endl;
					}
				break;
			case 5:
				stop = true;
				break;
			default:
				std::cout << "Opción inválida." << std::endl;
				break;
		}
	} while (!stop);
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
