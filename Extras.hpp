#ifndef Extras
#define Extras

#include <vector>
#include <algorithm>
#include "Displays.hpp"

namespace extras {
	bool winCondition(std::string fileName) {
		std::string line1 = display::returnLine(fileName, 3);
		std::string line2 = display::returnLine(fileName, 11);
		std::string line3 = display::returnLine(fileName, 18);

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

	void removeSameElement(std::vector<int>& a) {
		std::sort(a.begin(), a.end());
		a.erase(std::unique(a.begin(), a.end()), a.end());
	}

	void toMatrix(int board[][3], std::string fileName) {
		std::string line1 = display::returnLine(fileName, 3);
		std::string line2 = display::returnLine(fileName, 11);
		std::string line3 = display::returnLine(fileName, 18);

		std::vector<char> temp;

		auto tempIndex = 0;
		while (tempIndex < 9) {
			switch (tempIndex) {
			case 0:
				temp.push_back((char)line1.at(18));
				break;
			case 1:
				temp.push_back((char)line1.at(32));
				break;
			case 2:
				temp.push_back((char)line1.at(46));
				break;
			case 3:
				temp.push_back((char)line2.at(18));
				break;
			case 4:
				temp.push_back((char)line2.at(32));
				break;
			case 5:
				temp.push_back((char)line2.at(46));
				break;
			case 6:
				temp.push_back((char)line3.at(18));
				break;
			case 7:
				temp.push_back((char)line3.at(32));
				break;
			case 8:
				temp.push_back((char)line3.at(46));
				break;
			default:
				break;
			}
			tempIndex++;
		}

		tempIndex = 0;
		for (auto in = 0; in < 3; in++) {
			for (auto inj = 0; inj < 3; inj++) {
				if (temp.at(tempIndex) == 'X') {
					board[in][inj] = 1;
				}
				else {
					board[in][inj] = 0;
				}
				tempIndex++;
			}
		}

		for (auto in = 0; in < temp.size(); in++) {
			std::cout << temp.at(in) << " ";
		}
		std::cout << "\n";
	}
}


#endif // !Extras
