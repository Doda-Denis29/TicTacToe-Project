#include "Displays.hpp"
using namespace display;

int main() {
    /*Generator generator;
    generator.setBoardSize({ 25, 25 });
    generator.setHeuristic(Heuristic::euclidean);
    generator.setDiagonalMovement(true);

    std::cout << "Generate path ... \n";
    auto path = generator.findPath({ 0, 0 }, { 20, 20 });

    for (auto& coordinate : path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }*/
    int x;
    bool lmao = true;

    while (lmao) {
        printBoard("TicTacToeBoard.txt");
        std::cout << "Press 1..9\n";
        std::cin >> x;

        if (checkPos("TicTacToeBoard.txt", x)) {
            system("cls");
            std::cout << "Nice";
            lmao = false;
        }
        else {
            system("cls");
            std::cout << "Bruh moment";
            lmao = false;
        }
    }
}