#include "Displays.hpp"
using namespace display;

int main() {
    int x;
    bool lmao = true;

    while (lmao) {
        printBoard("TicTacToeBoard.txt");
        std::cout << "Press 1..9\n";
        std::cin >> x;

        
        

        lmao = false;
    }
}