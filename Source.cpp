#include "Extras.hpp"
#include "Astar.hpp"

using namespace display;
using namespace astar;
using namespace extras;


int main() {
	bool gameLife = true;
	int select, turn = 0;
	std::vector<int> allPositionsTaken;
	int Board[3][3];

	copyFiles("recoveryTicTacToeBoard.txt", "TicTacToeBoard.txt");

	while (gameLife) {
		system("cls");
		printBoard("TicTacToeBoard.txt");
		std::cout << "Press 1..9\n";
		removeSameElement(allPositionsTaken);
		if (turn % 2 == 0) {
			std::cin >> select;
			allPositionsTaken.push_back(select);
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
		else { //Turn O time
			select = enemyTurn(allPositionsTaken);
			allPositionsTaken.push_back(select + 1);
			gameMvO("TicTacToeBoard.txt", select + 1);
		}
		if (winCondition("TicTacToeBoard.txt")) {
			toMatrix(Board, "TicTacToeBoard.txt");

			printBoard("TicTacToeBoard.txt");

			int startLoc, endLoc, getter;
			getter = getStartAndEnd(Board);

			myPair start, end;

			switch (getter) {
			case 0:
				if (lineCheck(Board, startLoc, endLoc)) {
					switch (startLoc) {
					case 0:
						start = std::make_pair(0, 0);
						end = std::make_pair(0, 2);
						break;
					case 1:
						start = std::make_pair(1, 0);
						end = std::make_pair(1, 2);
						break;
					case 2:
						start = std::make_pair(2, 0);
						end = std::make_pair(2, 2);
						break;
					}
				}
				break;
			case 1:
				if (colCheck(Board, startLoc, endLoc)) {
					switch (startLoc) {
					case 0:
						start = std::make_pair(0, 0);
						end = std::make_pair(2, 0);
						break;
					case 1:
						start = std::make_pair(0, 1);
						end = std::make_pair(2, 1);
						break;
					default:
						start = std::make_pair(0, 2);
						end = std::make_pair(2, 2);
						break;
					}
				}
				break;
			case 2:
				if (diagCheck(Board, startLoc, endLoc)) {
					switch (startLoc) {
					case 0:
						start = std::make_pair(0, 0);
						end= std::make_pair(2, 2);
						break;
					case 2:
						start = std::make_pair(0, 2);
						end = std::make_pair(2, 0);
						break;
					}
				}
				break;
			default:
				break;
			}

			if (turn % 2 == 0) {
				std::cout << "X wins\n";
				StarSearchX(Board, start, end);
			}
			else {
				std::cout << "O wins\n";
				StarSearchO(Board, start, end);
			}
			gameLife = false;
		}
		if (allPositionsTaken.size() == 9) {
			printBoard("TicTacToeBoard.txt");
			std::cout << "Draw\n";
		}
		turn++;
	}
}