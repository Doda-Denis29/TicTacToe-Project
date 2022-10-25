#ifndef Astar
#define Astar

#include <string>
#include <iostream>

namespace astar {
	struct Node;
	typedef Node* NodePtr;

	struct Node {
		char val;
		int cost;
		NodePtr next;
	};

	struct graphEdge {
		char start, end;
		int weight;
		bool isObstacle;
	};

	class Graph {
	public:
		Graph(graphEdge edges[], int n, int N);
		~Graph();
		void initMatrix(char(*m)[3], size_t rows);
		void addNodesAfterMatrix(char(*m)[3], char v, int posX, int posY);
		void createGraphX(graphEdge edges[], int n, int N);
		void createGraphO(graphEdge edges[], int n, int N);
		void display_Dev(char(*m)[3], size_t rows);
		NodePtr getListNode(char v, int weight, NodePtr h);
		NodePtr* head;
		int N;
	protected:
		int getScore();
	private:
		//NodePtr getListNode(char v, int weight, NodePtr h);
		int G, H;
	};
}

#endif //!Opponent