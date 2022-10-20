#ifndef Displays
#define Displays

#include <string>
#include <fstream>
#include <iostream>

namespace display {
	void printBoard(std::string fileName) {
		system("cls");
		std::ifstream f(fileName);
		std::string c;

		while (!f.eof()) {
			getline(f, c);
			std::cout << c << "\n";
		}

		f.close();
	}

	void copyFiles(std::string originalFileName, std::string copiedFileName) {
		std::ifstream f(originalFileName);
		std::ofstream g(copiedFileName);
		std::string c;

		while (!f.eof()) {
			getline(f, c);
			g << c << "\n";
		}

		f.close();
		g.close();
	}

	std::string returnLine(std::string fileName, int x) {
		std::ifstream f(fileName);
		std::string c;

		auto in = 0;
		while (!f.eof()) {
			getline(f, c);

			if (in == x) {
				break;
			}
			in++;
		}
		f.close();

		std::string goodReturnLine = c;

		return goodReturnLine;
	}

	bool checkPos(std::string fileName, int x) {
		auto lineToCheck = 0;

		switch (x) {
		case 1:
		case 2:
		case 3:
			lineToCheck = 3;
			break;
		case 4:
		case 5:
		case 6:
			lineToCheck = 11;
			break;
		case 7:
		case 8:
		case 9:
			lineToCheck = 18;
			break;
		default:
			break;
		}

		std::string c;
		c = returnLine(fileName, lineToCheck);

		int checkPos = c.find(std::to_string(x));

		if (checkPos == -1 || checkPos == std::string::npos) {
			return false;
		}
		return true;
	}

	int gameMvX(std::string fileName, int x) {
		auto lineToCheck = 0;

		switch (x) {
		case 1:
		case 2:
		case 3:
			lineToCheck = 3;
			break;
		case 4:
		case 5:
		case 6:
			lineToCheck = 11;
			break;
		case 7:
		case 8:
		case 9:
			lineToCheck = 18;
			break;
		default:
			break;
		}

		std::string c, xPlayer = "X";
		c = returnLine(fileName, lineToCheck);

		std::ofstream f;
		f.open(fileName, std::ios::trunc);


		f.close();
	}

}

#endif // !Displays
