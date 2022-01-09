/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          26/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>
#include "StringSet.h"
#include "TimedEvents.h"

using namespace std;
namespace sdds {
	StringSet::StringSet() {
		strgs = nullptr;
		storedStrgs = 0;
	}

	StringSet::~StringSet() {
		delete[] strgs;
		strgs = nullptr;
	}

	StringSet::StringSet(const char* c) {
		string str;
		strgs = nullptr;
		storedStrgs = 0;
		ifstream f(c);
		if (f.is_open() == true) {
			while (getline(f, str, ' ')) storedStrgs++;

			f.clear();
			f.seekg(0); // Helps us to look for an arbitrary position in the 'f' file

			strgs = new string[storedStrgs];
			if(f.eof() != true) for(unsigned int i = 0; i < storedStrgs; i++) getline(f, strgs[i], ' ');
		}
	}

	StringSet::StringSet(const StringSet& a) { *this = a; }

	StringSet& StringSet::operator=(const StringSet& a) {
		if (this != &a) {
			delete[] strgs; 
			strgs = nullptr; 
			storedStrgs = a.storedStrgs;
			strgs = new string[storedStrgs];
			if (a.strgs != nullptr) for (unsigned int i = 0; i < storedStrgs; i++) strgs[i] = a.strgs[i];
		}
		return *this;
	}

	size_t StringSet::size() const { return storedStrgs; }

	string StringSet::operator[](size_t a) {
		if (a < storedStrgs) 
			return string(strgs[a]);
		else return "";
	}

	StringSet::StringSet(StringSet&& a) { *this = move(a); }

	StringSet& StringSet::operator=(StringSet&& a) {
		if (this != &a) {
			strgs = a.strgs;
			storedStrgs = a.storedStrgs;
			a.strgs = nullptr;
			a.storedStrgs = 0;
		}
		return *this;
	}
}