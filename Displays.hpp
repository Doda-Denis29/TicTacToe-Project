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

	void copyFilesLineChanged(std::string originalFileName, std::string copiedFileName, std::string lineToChange, int index) {
		std::ifstream f(originalFileName);
		std::ofstream g(copiedFileName);
		std::string c;
		auto in = 0;

		while (!f.eof()) {
			getline(f, c);
			if (in == index) {
				g << lineToChange << "\n";
			}
			else {
				g << c << "\n";
			}
			in++;
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

	bool illegalMove(std::string fileName, int x) {
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
			return true;
		}
		return false;
	}

	void gameMvX(std::string fileName, int x) {

		if (checkPos(fileName, x)) {
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

			std::ifstream f(fileName);
			std::string c;
			auto in = 0;

			while (!f.eof()) {
				getline(f, c);
				if (in == lineToCheck) {
					break;
				}
				in++;
			}
			f.close();

			int checkPos = c.find(std::to_string(x));
			c.at(checkPos) = 'X';
			copyFilesLineChanged(fileName, "temp.txt", c, lineToCheck);
			copyFiles("temp.txt", fileName);
			remove("temp.txt");
		}

	}

	void gameMvO(std::string fileName, int x) {

		if (checkPos(fileName, x)) {
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

			std::ifstream f(fileName);
			std::string c;
			auto in = 0;

			while (!f.eof()) {
				getline(f, c);
				if (in == lineToCheck) {
					break;
				}
				in++;
			}
			f.close();

			int checkPos = c.find(std::to_string(x));
			c.at(checkPos) = 'O';
			copyFilesLineChanged(fileName, "temp.txt", c, lineToCheck);
			copyFiles("temp.txt", fileName);
			remove("temp.txt");
		}

	}

}

#endif // !Displays
