#include "Displays.hpp"
#include "Astar.hpp"
#include <vector>
#include <algorithm>

using namespace display;
using namespace astar;

bool winCondition(std::string fileName) {
	std::string line1 = returnLine(fileName, 3);
	std::string line2 = returnLine(fileName, 11);
	std::string line3 = returnLine(fileName, 18);

	if ((line1.at(18) == line1.at(32) && line1.at(18) == line1.at(46) && line1.at(32) == line1.at(46)) ||
		(line2.at(18) == line2.at(32) && line2.at(18) == line2.at(46) && line2.at(32) == line2.at(46)) ||
		(line3.at(18) == line3.at(32) && line3.at(18) == line3.at(46) && line3.at(32) == line3.at(46)) || 
		(line1.at(18) == line2.at(18) && line1.at(18) == line3.at(18) && line2.at(18) == line3.at(18)) ||
		(line1.at(32) == line2.at(32) && line1.at(32) == line3.at(32) && line2.at(32) == line3.at(32)) ||
		(line1.at(46) == line2.at(46) && line1.at(46) == line3.at(46) && line2.at(46) == line3.at(46)) ||
		(line1.at(18) == line2.at(32) && line1.at(18) == line3.at(46) && line2.at(32) == line3.at(46)) || 
		(line3.at(18) == line2.at(32) && line3.at(18) == line1.at(46) && line2.at(32) == line1.at(46))) {
		return true;
	}
	return false;
}

bool findElement(std::vector<int> a, int elementThatWeWant) {
	for (auto in = 0; in < a.size(); in++)
		return elementThatWeWant == a.at(in);
}

void removeSameElement(std::vector<int> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}

int main() {
	bool gameLife = true;
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
	}
}