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
		void initMatrix(char(*m)[3], size_t rows);

		void display_Dev(char(*m)[3], size_t rows);
	protected:
		int getScore();
	private:
		NodePtr head, tail;
		int G, H;
	};
}

#endif //!Opponent