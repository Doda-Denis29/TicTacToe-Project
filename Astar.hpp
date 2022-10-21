#ifndef Astar
#define Astar

//Includes

namespace astar {
	struct Node;
	typedef Node* NodePtr;

	struct Node {
		int val;
		NodePtr nodeptr;
		void addNode(Node);
		void deleteNode(Node);
		bool checkPath();
	};
}

#endif //!Opponent