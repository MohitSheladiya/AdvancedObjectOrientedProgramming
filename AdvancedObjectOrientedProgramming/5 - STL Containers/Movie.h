/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class Movie {
		string movieTitle;
		size_t movieYear;
		string movieDesc;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(movieTitle);
			spellChecker(movieDesc);
		}

		friend ostream& operator<<(ostream& out, const Movie& m);
	};
}
#endif
