/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          07/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Car.h"

using namespace std;
namespace sdds {
	class Racecar : public Car {
		double m_booster = 0.00;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif