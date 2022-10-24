#include "Astar.hpp"

using namespace astar;

Graph::Graph() {
    G = H = 0;
}

void Graph::initMatrix(char(*m)[3], size_t rows) {
    for (auto in = 0; in < 3; in++) {
        for (auto inR = 0; inR < 3; inR++) {
            m[in][inR] = '1';
        }
    }
}

void Graph::display_Dev(char(*m)[3], size_t rows) {
    for (auto in = 0; in < 3; in++) {
        for (auto inR = 0; inR < 3; inR++) {
            std::cout << "m[ " << in << " ][ " << inR << " ] = " << m[in][inR] << "\n";
        }
    }
}

int Graph::getScore() {
	return G + H;
}

