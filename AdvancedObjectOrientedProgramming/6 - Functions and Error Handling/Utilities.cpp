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
#include <sstream>
#include <algorithm>
#include <fstream>
#include "Utilities.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		char c = ' ';
		string s;
		getline(in, s);
		stringstream stream(s);
		stream >> c;
		Vehicle* v;
		v = nullptr;
		if (s != "") {
			if (c == 'c' || c == 'C') v = new Car(stream);
			else if (c == 'r' || c == 'R') v = new Racecar(stream);
			else throw c;
		}
		return v;
	}
}