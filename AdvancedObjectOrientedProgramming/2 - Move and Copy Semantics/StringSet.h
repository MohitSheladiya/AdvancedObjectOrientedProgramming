/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          26/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
namespace sdds {

	class StringSet {
		string* strgs = nullptr;
		unsigned int storedStrgs = 0;
	public:
		StringSet();
		StringSet(const char* c);
		StringSet(const StringSet& a);
		StringSet& operator=(const StringSet& a);
		size_t size() const;
		string operator[](size_t a);
		StringSet(StringSet&& a);
		StringSet& operator=(StringSet&& a);
		~StringSet();
	};
}
#endif