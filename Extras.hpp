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
}


#endif // !Extras
