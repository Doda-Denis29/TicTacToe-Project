#include "Extras.hpp"
#include "Astar.hpp"

using namespace display;
using namespace astar;
using namespace extras;


int main() {
	/*bool gameLife = true;
	int select, turn = 0;
	std::vector<int> allPositionsTaken;

	copyFiles("recoveryTicTacToeBoard.txt", "TicTacToeBoard.txt");

	while (gameLife) {
		system("cls");
		printBoard("TicTacToeBoard.txt");
		std::cout << "Press 1..9\n";
		std::cin >> select;
		allPositionsTaken.push_back(select);
		removeSameElement(allPositionsTaken);
		if (turn % 2 == 0) {
			if (illegalMove("TicTacToeBoard.txt", select)) {
				while (findElement(allPositionsTaken, select) || select > 9) {
					printBoard("TicTacToeBoard.txt");
					std::cout << "Press 1..9\n";
					std::cin >> select;
					gameMvX("TicTacToeBoard.txt", select);
				}
			}
			else {
				gameMvX("TicTacToeBoard.txt", select);
			}
		}
		else {
			if (illegalMove("TicTacToeBoard.txt", select)) {
				while (findElement(allPositionsTaken, select) || select > 9) {
					printBoard("TicTacToeBoard.txt");
					std::cout << "Press 1..9\n";
					std::cin >> select;
					gameMvO("TicTacToeBoard.txt", select);
				}
			}
			else {
				gameMvO("TicTacToeBoard.txt", select);
			}
		}
		if (winCondition("TicTacToeBoard.txt")) {
			printBoard("TicTacToeBoard.txt");
			if (turn % 2 == 0) {
				std::cout << "X wins";
			}
			else {
				std::cout << "O wins";
			}
			gameLife = false;
		}
		if (allPositionsTaken.size() == 9) {

		}
		turn++;
	}*/

	int testBord[3][3] = {
		{1,0,1},
		{1,0,0},
		{1,0,1}
	};

	myPair start = std::make_pair(0, 0);
	myPair end = std::make_pair(2, 0);

	StarSearchX(testBord, start, end);
}