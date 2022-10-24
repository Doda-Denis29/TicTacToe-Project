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
    char m[3][3];
    g.initMatrix(m, 3);
    g.display(m, 3);
}