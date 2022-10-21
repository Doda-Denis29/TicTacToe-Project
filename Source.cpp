#include "Displays.hpp"
#include "Astar.hpp"

using namespace display;
using namespace astar;

int main() {
    int x;
    bool lmao = true;

    /*while (lmao) {
        printBoard("TicTacToeBoard.txt");
        std::cout << "Press 1..9\n";
        std::cin >> x;

        
        

        lmao = false;
    }*/

    Graph g;
    g.addNode(1);
    g.addNode(2);
    g.addNode(1);
    Graph::display(g.getHead());
}