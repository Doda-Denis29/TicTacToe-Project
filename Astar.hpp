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
		void addNode(int v);
		NodePtr getHead();
		void concatenate(NodePtr X, NodePtr O);
		static void display(NodePtr nodeptr);
		int getScore();
	private:
		NodePtr head, tail;
		int G, H;
	};
}

#endif //!Opponent