/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Movie.h"

using namespace std;
namespace sdds {
	Movie::Movie() {
		movieTitle = "";
		movieYear = 0;
		movieDesc = "";
	}

	const std::string& Movie::title() const { return movieTitle; }

	Movie::Movie(const std::string& strMovie) {
		string title;
		string year;
		string desc;
		string s = strMovie;

		title = s.substr(0, s.find(','));

		title.erase(title.find_last_not_of(' ') + 1);
		title.erase(0, title.find_first_not_of(' '));

		s.erase(0, s.find(',') + 1);
		year = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		desc = s;

		desc.erase(desc.find_last_not_of(' ') + 1);
		desc.erase(0, desc.find_first_not_of(' '));

		movieTitle = title;
		movieYear = stoi(year);
		movieDesc = desc;
	}

	ostream& operator<<(ostream& out, const Movie& m) {
		out << right << setw(40) << m.movieTitle << " | ";
		out << right << setw(4) << m.movieYear << " | ";
		out << left << m.movieDesc << endl;
		return out;
	}
}