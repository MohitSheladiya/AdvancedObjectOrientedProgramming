/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          07/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
#include "Car.h"

using namespace std;
namespace sdds {
	Car::Car(std::istream& in) {
		string t, s, c, m;

		getline(in, t, ',');
		getline(in, m, ',');
		getline(in, c, ',');
		getline(in, s, ',');

		c.erase(0, c.find_first_not_of(' '));
		c.erase(c.find_last_not_of(' ') + 1);
		if (c == "N" || c == "n" || c == "") ccondition = "new";
		else if (c == "U" || c == "u") ccondition = "used";
		else if (c == "B" || c == "b") ccondition = "broken";
		else {
			string a = "Error!";
			throw a;
		}

		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);
		topspeed = stod(s);

		m.erase(0, m.find_first_not_of(' '));
		m.erase(m.find_last_not_of(' ') + 1);
		maker = m;
	}

	std::string Car::condition() const {
		return ccondition;
	}

	double Car::topSpeed() const {
		return topspeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << right << setw(10) << maker << " | ";
		out << left << setw(6) << condition() << " | ";
		out << right << fixed << setw(6) << setprecision(2) << topSpeed() << " |";
	}
}