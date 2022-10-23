#ifndef Astar
#define Astar

#include <string>
#include <iostream>

namespace astar {
	struct Node;
	typedef Node* NodePtr;

	struct Node {
		int val;
		NodePtr next;
	};

	class Graph {
	public:
		Graph();
		NodePtr getHead();
		void concatenate(NodePtr X, NodePtr O);
		static void display(NodePtr nodeptr);
		void initBoard();
		void modifyNode(NodePtr nodeptr, int valueToChange, int whatToChange);
		int getScore();
	protected:
		void addNode(int v);
	private:
		NodePtr head, tail;
		int G, H;
	};
}

#endif //!Opponent