/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class SpellChecker {
		string m_badWords[6];
		string m_goodWords[6];
		int badwords[6];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif
