/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          11/11/21
Project Part:  Milestone 1
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "Utilities.h"

using namespace std;
namespace sdds {
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string s;
		size_t start = next_pos;
		next_pos = str.find(m_delimiter, start);
		size_t a = 0;

		if (next_pos == start) {
			more = false;
			throw "Error: empty";			
		} else if (next_pos == string::npos) {
			s = str.substr(start);
			a = s.length();
			m_widthField = max(a, m_widthField);
			more = false;
		} else {
			s = str.substr(start, next_pos - start);
			a = s.length();
			m_widthField = max(a, m_widthField);
			more = true;
		}
		next_pos = next_pos + 1;
		return s;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}