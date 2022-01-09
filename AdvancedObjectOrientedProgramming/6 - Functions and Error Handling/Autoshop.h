/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          07/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto a = m_vehicles.begin(); a != m_vehicles.end(); a++)
				if (test(*a)) vehicles.push_back(*a);
		}
	};
}
#endif