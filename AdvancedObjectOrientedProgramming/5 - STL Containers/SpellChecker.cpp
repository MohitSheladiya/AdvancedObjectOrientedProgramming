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
#include "SpellChecker.h"

using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);

		if (file.is_open() == false) throw("Bad file name!");
		else {
			for (int i = 0; i < 6 ; i++) {
				if (file) {
					getline(file, m_badWords[i], ' ');
					getline(file, m_goodWords[i], '\n');

					m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
					m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
					m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
					m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				}
			}
		}
	}

	void SpellChecker::operator()(std::string& text) {
		for (int i = 0; i < 6; i++)
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				badwords[i] = badwords[i] + 1;
			}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		cout << "Spellchecker Statistics" << endl;
		for (int i = 0; i < 6; i++) out << right << setw(15) << m_badWords[i] << ": " << badwords[i] << " replacements" << endl;
	}
}