/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          11/11/21
Project Part:  Milestone 1
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class Utilities {
		size_t m_widthField = 1; //1
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif
