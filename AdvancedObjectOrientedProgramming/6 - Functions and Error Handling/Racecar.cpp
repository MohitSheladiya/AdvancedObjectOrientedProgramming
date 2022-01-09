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
#include <fstream>
#include <algorithm>
#include "Racecar.h"

using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in){
		string s;
		getline(in, s, '\n');
		m_booster = stod(s);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		auto a = (Car::topSpeed() * (1 + m_booster));
		return a;
	}
}