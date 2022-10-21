#include "Astar.hpp"

using namespace astar;

Graph::Graph() {
	head = nullptr;
	tail = nullptr;
}

void Graph::addNode(int v) {
	NodePtr temp = new Node;
	temp->val = v;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		tail = temp;
	} 
	else {
		tail->next = temp;
		tail = tail->next;
	}
}

NodePtr Graph::getHead() {
	return head;
}

void Graph::concatenate(NodePtr X, NodePtr O) {
	if (X != nullptr && O != nullptr) {
		if (X->next == nullptr) {
			X->next = O;
		}
		else {
			concatenate(X->next, O);
		}
	}
	else {
		std::cout << "X or O is NULL\n";
	}
}

void Graph::display(NodePtr nodeptr) {
	if (nodeptr == nullptr) {
		std::cout << "NULLPTR\n";
	}
	else {
		std::cout << nodeptr->val << " ";
		display(nodeptr->next);
	}
}
