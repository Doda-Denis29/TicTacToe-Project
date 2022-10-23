#include "Astar.hpp"

using namespace astar;

Graph::Graph() {
	head = nullptr;
	tail = nullptr;
	G = H = 0;
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
		std::cout << "END\n";
	}
	else {
		std::cout << nodeptr->val << " ";
		display(nodeptr->next);
	}
}

void Graph::initBoard() {
	addNode(11);
	addNode(12);
	addNode(13);
	addNode(21);
	addNode(22);
	addNode(23);
	addNode(31);
	addNode(32);
	addNode(33);
}

void Graph::modifyNode(NodePtr nodeptr, int valueToChange, int whatToChange) {
	if (nodeptr == nullptr) {
		std::cout << "The value was not found";
		return;
	}
	else if (nodeptr->val == valueToChange) {
		nodeptr->val = whatToChange;
	}
	else {
		modifyNode(nodeptr->next, valueToChange, whatToChange);
	}
}
