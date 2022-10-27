#include <iostream>

#include "node.hpp"
#include "graph.hpp"

int main (int argc, char **argv) {
	graph *g = new graph (std::atoi (argv[1]), std::atoi (argv[2]));
	bool stop = false;
	int option = ' ';
	char v1 = ' ', v2 = ' ';
	float w = 0;
	float **m;
	do {
		std::cout << "Opciones: [1. Vértice | 2. Arco | 3. Imprimir | 4. Matriz | 5. Anchura | 6. Salir]: ";
		std::cin >> option;

		switch (option) {
			case 1:
				std::cout << "Nombre del nuevo vértice: ";
				std::cin >> v1;
				if (g->seekV (v1) == nullptr)
					g->insertVertex (new node (v1));
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
				std::cout << "Nombre del vértice de partida: ";
				std::cin >> v1;
				g->width (v1);
				break;
			case 6:
				stop = true;
				break;
			default:
				std::cout << "Opción inválida." << std::endl;
				break;
		}
	} while (!stop);
}
