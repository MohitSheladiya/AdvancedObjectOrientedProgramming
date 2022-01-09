/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          07/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Car: public Vehicle {
		string maker = "";
		string ccondition = "";
		double topspeed = 0.00;
	public:
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif