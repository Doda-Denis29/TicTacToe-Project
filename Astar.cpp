#include "Astar.hpp"

using namespace astar;

Graph::Graph(graphEdge edges[], int n, int N) {
    head = new NodePtr [N]();
    this->N = N;
    for (auto in = 0; in < N; in++)
        head[in] = nullptr;
    for (auto in = 0; in < n; in++) {
        char start = edges[in].start;
        char end = edges[in].end;
        int weight = edges[in].weight;
        bool ob = edges[in].isObstacle;
        NodePtr newNode = getListNode(end, weight, head[start]);
        head[start] = new Node;
    }
}

Graph::~Graph() {
    for (auto in = 0; in < N; in++) {
        delete[] head[in];
        delete[] head;
    }
}

//void printAll(NodePtr nodeptr, int in) {
//    while (nodeptr != nullptr) {
//        std::cout << "( " << in << ", " << nodeptr->val << ", " << nodeptr->cost << ") ";
//        nodeptr = nodeptr->next;
//    }
//    std::cout << "\n";
//}

NodePtr Graph::getListNode(char v, int weight, NodePtr h) {
    NodePtr newNode = new Node;
    newNode->val = v;
    newNode->cost = weight;
    newNode->next = h;
    return newNode;
}

void Graph::initMatrix(char(*m)[3], size_t rows) {
    for (auto in = 0; in < 3; in++) {
        for (auto inR = 0; inR < 3; inR++) {
            m[in][inR] = '1';
        }
    }
}

void Graph::addNodesAfterMatrix(char(*m)[3], char v, int posX, int posY) {
    m[posX][posY] = v;
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

