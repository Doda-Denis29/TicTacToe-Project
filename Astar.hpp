#ifndef Astar
#define Astar

#include <string>
#include <iostream>
#include <utility>
#include <cmath>
#include <stack>
#include <limits>
#include <set>
#include <vector>
#include <cstdlib>

namespace astar {
	const int row = 3, col = 3;

	typedef std::pair<int, int> myPair;
	typedef std::pair<double, std::pair<int, int>> dPair;

	struct myVars {
		int i, j;
		double f, g, h;
	};

	bool isValid(int r, int c) {
		return (r >= 0) && (r < row) && (c >= 0) && (c < col);
	}

	bool isUnblocked_X(int board[][col], int row, int col) {
		return (board[row][col] == 1);
	}

	bool isUnblocked_O(int board[][col], int row, int col) {
		return (board[row][col] == 0);
	}

	bool Reach(int row, int col, myPair destination) {
		return (row == destination.first && col == destination.second);
	}

	double calculateHeuristic(int row, int col, myPair destination) {
		return ((double)std::sqrt(
			(row - destination.first) * (row - destination.first) +
			(col - destination.second) * (col - destination.second)
		));
	}

	void tracePath(myVars boardDetails[][col], myPair destination) {
		std::cout << "Path is ... \n";
		int r = destination.first, c = destination.second;

		std::stack<myPair> Path;

		while (!(boardDetails[r][c].i == r && boardDetails[r][c].j == c)) {
			Path.push(std::make_pair(r, c));
			int tempR = boardDetails[r][c].i;
			int tempC = boardDetails[r][c].j;
			r = tempR;
			c = tempC;
		}

		Path.push(std::make_pair(r, c));
		while (!Path.empty()) {
			std::pair<int, int> p = Path.top();
			Path.pop();
			if (Path.empty()) {
				std::cout << "Board[ " << p.first << " ][ " << p.second << " ] ";
			}
			else {
				std::cout << "Board[ " << p.first << " ][ " << p.second << " ]  -> ";
			}
		}
		std::cout << "\n";
	}

	void StarSearchX(int board[][col], myPair source, myPair destination) {
		if (isUnblocked_X(board, source.first, source.second) == false ||
			isUnblocked_X(board, destination.first, destination.second) == false) {
			std::cout << "Source or the destination is blocked\n";
		}

		bool closedQueue[row][col];
		memset(closedQueue, false, sizeof(closedQueue));

		myVars boardDetails[row][col];
		
		for (auto in = 0; in < row; in++) {
			for (auto inj = 0; inj < col; inj++) {
				boardDetails[in][inj].f = FLT_MAX;
				boardDetails[in][inj].g = FLT_MAX;
				boardDetails[in][inj].h = FLT_MAX;
				boardDetails[in][inj].i = -1;
				boardDetails[in][inj].j = -1;
			}
		}

		boardDetails[source.first][source.second].f = 0.0;
		boardDetails[source.first][source.second].g = 0.0;
		boardDetails[source.first][source.second].h = 0.0;
		boardDetails[source.first][source.second].i = source.first;
		boardDetails[source.first][source.second].j = source.second;
		
		std::set<dPair> openQueue;

		openQueue.insert(std::make_pair(0.0, std::make_pair(source.first, source.second)));

		bool foundDestination = false;

		while (!openQueue.empty()) {
			dPair doublePair = *openQueue.begin();

			openQueue.erase(openQueue.begin());

			auto in = doublePair.second.first;
			auto inj = doublePair.second.second;
			closedQueue[in][inj] = true;

			double newF, newG, newH;

			//1st North
			if (isValid(in - 1, inj) == true) {
				if (Reach(in - 1, inj, destination) == true) {
					boardDetails[in - 1][inj].i = in;
					boardDetails[in - 1][inj].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj] == false && isUnblocked_X(board, in - 1, inj) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in - 1, inj, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj].f == FLT_MAX ||
						boardDetails[in - 1][inj].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj)));

						boardDetails[in - 1][inj].f = newF;
						boardDetails[in - 1][inj].g = newG;
						boardDetails[in - 1][inj].h = newH;
						boardDetails[in - 1][inj].i = in;
						boardDetails[in - 1][inj].j = inj;
					}
				}
			}

			//2nd South
			if (isValid(in + 1, inj) == true) {
				if (Reach(in + 1, inj, destination) == true) {
					boardDetails[in + 1][inj].i = in;
					boardDetails[in + 1][inj].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj] == false && isUnblocked_X(board, in + 1, inj) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in + 1, inj, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj].f == FLT_MAX ||
						boardDetails[in + 1][inj].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj)));

						boardDetails[in + 1][inj].f = newF;
						boardDetails[in + 1][inj].g = newG;
						boardDetails[in + 1][inj].h = newH;
						boardDetails[in + 1][inj].i = in;
						boardDetails[in + 1][inj].j = inj;
					}
				}
			}

			//3rd East
			if (isValid(in, inj + 1) == true) {
				if (Reach(in, inj + 1, destination) == true) {
					boardDetails[in][inj + 1].i = in;
					boardDetails[in][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in][inj + 1] == false && isUnblocked_X(board, in, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in][inj + 1].f == FLT_MAX ||
						boardDetails[in][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in, inj + 1)));

						boardDetails[in][inj + 1].f = newF;
						boardDetails[in][inj + 1].g = newG;
						boardDetails[in][inj + 1].h = newH;
						boardDetails[in][inj + 1].i = in;
						boardDetails[in][inj + 1].j = inj;
					}
				}
			}

			//4th West
			if (isValid(in, inj - 1) == true) {
				if (Reach(in, inj - 1, destination) == true) {
					boardDetails[in][inj - 1].i = in;
					boardDetails[in][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in][inj - 1] == false && isUnblocked_X(board, in, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in][inj - 1].f == FLT_MAX ||
						boardDetails[in][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in, inj - 1)));

						boardDetails[in][inj - 1].f = newF;
						boardDetails[in][inj - 1].g = newG;
						boardDetails[in][inj - 1].h = newH;
						boardDetails[in][inj - 1].i = in;
						boardDetails[in][inj - 1].j = inj;
					}
				}
			}

			//5th North-East
			if (isValid(in - 1, inj + 1) == true) {
				if (Reach(in - 1, inj + 1, destination) == true) {
					boardDetails[in - 1][inj + 1].i = in;
					boardDetails[in - 1][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj + 1] == false && isUnblocked_X(board, in - 1, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in - 1, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj + 1].f == FLT_MAX ||
						boardDetails[in - 1][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj + 1)));

						boardDetails[in - 1][inj + 1].f = newF;
						boardDetails[in - 1][inj + 1].g = newG;
						boardDetails[in - 1][inj + 1].h = newH;
						boardDetails[in - 1][inj + 1].i = in;
						boardDetails[in - 1][inj + 1].j = inj;
					}
				}
			}

			//6th North-West
			if (isValid(in - 1, inj - 1) == true) {
				if (Reach(in - 1, inj - 1, destination) == true) {
					boardDetails[in - 1][inj - 1].i = in;
					boardDetails[in - 1][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj - 1] == false && isUnblocked_X(board, in - 1, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in - 1, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj - 1].f == FLT_MAX ||
						boardDetails[in - 1][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj - 1)));

						boardDetails[in - 1][inj - 1].f = newF;
						boardDetails[in - 1][inj - 1].g = newG;
						boardDetails[in - 1][inj - 1].h = newH;
						boardDetails[in - 1][inj - 1].i = in;
						boardDetails[in - 1][inj - 1].j = inj;
					}
				}
			}

			//7th South-East
			if (isValid(in + 1, inj + 1) == true) {
				if (Reach(in + 1, inj + 1, destination) == true) {
					boardDetails[in + 1][inj + 1].i = in;
					boardDetails[in + 1][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj + 1] == false && isUnblocked_X(board, in + 1, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in + 1, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj + 1].f == FLT_MAX ||
						boardDetails[in + 1][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj + 1)));

						boardDetails[in + 1][inj + 1].f = newF;
						boardDetails[in + 1][inj + 1].g = newG;
						boardDetails[in + 1][inj + 1].h = newH;
						boardDetails[in + 1][inj + 1].i = in;
						boardDetails[in + 1][inj + 1].j = inj;
					}
				}
			}

			//8th South-West
			if (isValid(in + 1, inj - 1) == true) {
				if (Reach(in + 1, inj - 1, destination) == true) {
					boardDetails[in + 1][inj - 1].i = in;
					boardDetails[in + 1][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj - 1] == false && isUnblocked_X(board, in + 1, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in + 1, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj - 1].f == FLT_MAX ||
						boardDetails[in + 1][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj - 1)));

						boardDetails[in + 1][inj - 1].f = newF;
						boardDetails[in + 1][inj - 1].g = newG;
						boardDetails[in + 1][inj - 1].h = newH;
						boardDetails[in + 1][inj - 1].i = in;
						boardDetails[in + 1][inj - 1].j = inj;
					}
				}
			}
		}
		if (foundDestination == false) {
			std::cout << "Failed to find destination\n";
		}
		return;
	}

	void StarSearchO(int board[][col], myPair source, myPair destination) {
		if (isUnblocked_O(board, source.first, source.second) == false ||
			isUnblocked_O(board, destination.first, destination.second) == false) {
			std::cout << "Source or the destination is blocked\n";
		}

		bool closedQueue[row][col];
		memset(closedQueue, false, sizeof(closedQueue));

		myVars boardDetails[row][col];

		for (auto in = 0; in < row; in++) {
			for (auto inj = 0; inj < col; inj++) {
				boardDetails[in][inj].f = FLT_MAX;
				boardDetails[in][inj].g = FLT_MAX;
				boardDetails[in][inj].h = FLT_MAX;
				boardDetails[in][inj].i = -1;
				boardDetails[in][inj].j = -1;
			}
		}

		boardDetails[source.first][source.second].f = 0.0;
		boardDetails[source.first][source.second].g = 0.0;
		boardDetails[source.first][source.second].h = 0.0;
		boardDetails[source.first][source.second].i = source.first;
		boardDetails[source.first][source.second].j = source.second;

		std::set<dPair> openQueue;

		openQueue.insert(std::make_pair(0.0, std::make_pair(source.first, source.second)));

		bool foundDestination = false;

		while (!openQueue.empty()) {
			dPair doublePair = *openQueue.begin();

			openQueue.erase(openQueue.begin());

			auto in = doublePair.second.first;
			auto inj = doublePair.second.second;
			closedQueue[in][inj] = true;

			double newF, newG, newH;

			//1st North
			if (isValid(in - 1, inj) == true) {
				if (Reach(in - 1, inj, destination) == true) {
					boardDetails[in - 1][inj].i = in;
					boardDetails[in - 1][inj].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj] == false && isUnblocked_X(board, in - 1, inj) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in - 1, inj, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj].f == FLT_MAX ||
						boardDetails[in - 1][inj].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj)));

						boardDetails[in - 1][inj].f = newF;
						boardDetails[in - 1][inj].g = newG;
						boardDetails[in - 1][inj].h = newH;
						boardDetails[in - 1][inj].i = in;
						boardDetails[in - 1][inj].j = inj;
					}
				}
			}

			//2nd South
			if (isValid(in + 1, inj) == true) {
				if (Reach(in + 1, inj, destination) == true) {
					boardDetails[in + 1][inj].i = in;
					boardDetails[in + 1][inj].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj] == false && isUnblocked_X(board, in + 1, inj) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in + 1, inj, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj].f == FLT_MAX ||
						boardDetails[in + 1][inj].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj)));

						boardDetails[in + 1][inj].f = newF;
						boardDetails[in + 1][inj].g = newG;
						boardDetails[in + 1][inj].h = newH;
						boardDetails[in + 1][inj].i = in;
						boardDetails[in + 1][inj].j = inj;
					}
				}
			}

			//3rd East
			if (isValid(in, inj + 1) == true) {
				if (Reach(in, inj + 1, destination) == true) {
					boardDetails[in][inj + 1].i = in;
					boardDetails[in][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in][inj + 1] == false && isUnblocked_X(board, in, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in][inj + 1].f == FLT_MAX ||
						boardDetails[in][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in, inj + 1)));

						boardDetails[in][inj + 1].f = newF;
						boardDetails[in][inj + 1].g = newG;
						boardDetails[in][inj + 1].h = newH;
						boardDetails[in][inj + 1].i = in;
						boardDetails[in][inj + 1].j = inj;
					}
				}
			}

			//4th West
			if (isValid(in, inj - 1) == true) {
				if (Reach(in, inj - 1, destination) == true) {
					boardDetails[in][inj - 1].i = in;
					boardDetails[in][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in][inj - 1] == false && isUnblocked_X(board, in, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.0;
					newH = calculateHeuristic(in, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in][inj - 1].f == FLT_MAX ||
						boardDetails[in][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in, inj - 1)));

						boardDetails[in][inj - 1].f = newF;
						boardDetails[in][inj - 1].g = newG;
						boardDetails[in][inj - 1].h = newH;
						boardDetails[in][inj - 1].i = in;
						boardDetails[in][inj - 1].j = inj;
					}
				}
			}

			//5th North-East
			if (isValid(in - 1, inj + 1) == true) {
				if (Reach(in - 1, inj + 1, destination) == true) {
					boardDetails[in - 1][inj + 1].i = in;
					boardDetails[in - 1][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj + 1] == false && isUnblocked_X(board, in - 1, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in - 1, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj + 1].f == FLT_MAX ||
						boardDetails[in - 1][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj + 1)));

						boardDetails[in - 1][inj + 1].f = newF;
						boardDetails[in - 1][inj + 1].g = newG;
						boardDetails[in - 1][inj + 1].h = newH;
						boardDetails[in - 1][inj + 1].i = in;
						boardDetails[in - 1][inj + 1].j = inj;
					}
				}
			}

			//6th North-West
			if (isValid(in - 1, inj - 1) == true) {
				if (Reach(in - 1, inj - 1, destination) == true) {
					boardDetails[in - 1][inj - 1].i = in;
					boardDetails[in - 1][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in - 1][inj - 1] == false && isUnblocked_X(board, in - 1, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in - 1, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in - 1][inj - 1].f == FLT_MAX ||
						boardDetails[in - 1][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in - 1, inj - 1)));

						boardDetails[in - 1][inj - 1].f = newF;
						boardDetails[in - 1][inj - 1].g = newG;
						boardDetails[in - 1][inj - 1].h = newH;
						boardDetails[in - 1][inj - 1].i = in;
						boardDetails[in - 1][inj - 1].j = inj;
					}
				}
			}

			//7th South-East
			if (isValid(in + 1, inj + 1) == true) {
				if (Reach(in + 1, inj + 1, destination) == true) {
					boardDetails[in + 1][inj + 1].i = in;
					boardDetails[in + 1][inj + 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj + 1] == false && isUnblocked_X(board, in + 1, inj + 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in + 1, inj + 1, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj + 1].f == FLT_MAX ||
						boardDetails[in + 1][inj + 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj + 1)));

						boardDetails[in + 1][inj + 1].f = newF;
						boardDetails[in + 1][inj + 1].g = newG;
						boardDetails[in + 1][inj + 1].h = newH;
						boardDetails[in + 1][inj + 1].i = in;
						boardDetails[in + 1][inj + 1].j = inj;
					}
				}
			}

			//8th South-West
			if (isValid(in + 1, inj - 1) == true) {
				if (Reach(in + 1, inj - 1, destination) == true) {
					boardDetails[in + 1][inj - 1].i = in;
					boardDetails[in + 1][inj - 1].j = inj;
					std::cout << "Destination reached\n";
					tracePath(boardDetails, destination);
					foundDestination = true;
					return;
				}
				else if (closedQueue[in + 1][inj - 1] == false && isUnblocked_X(board, in + 1, inj - 1) == true) {
					newG = boardDetails[in][inj].g + 1.414;
					newH = calculateHeuristic(in + 1, inj - 1, destination);
					newF = newG + newH;

					if (boardDetails[in + 1][inj - 1].f == FLT_MAX ||
						boardDetails[in + 1][inj - 1].f > newF) {
						openQueue.insert(std::make_pair(newF, std::make_pair(in + 1, inj - 1)));

						boardDetails[in + 1][inj - 1].f = newF;
						boardDetails[in + 1][inj - 1].g = newG;
						boardDetails[in + 1][inj - 1].h = newH;
						boardDetails[in + 1][inj - 1].i = in;
						boardDetails[in + 1][inj - 1].j = inj;
					}
				}
			}
		}
		if (foundDestination == false) {
			std::cout << "Failed to find destination\n";
		}
		return;
	}

	int enemyTurn(std::vector<int> alreadyTaken) {
		std::srand((unsigned)time(NULL));

		int turn = std::rand() % 9;

		while (extras::findElement(alreadyTaken, turn + 1)) {
			turn = std::rand() % 9;
		}

		return turn;
	}
}

#endif //!Astar