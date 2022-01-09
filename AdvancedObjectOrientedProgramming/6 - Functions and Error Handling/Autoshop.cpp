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
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "Autoshop.h"

using namespace std;
namespace sdds {
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto a = m_vehicles.begin(); a < m_vehicles.end(); a++) { 
			(*a)->display(out); out << endl; 
		}
		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop() {                  
		for (auto a = m_vehicles.begin(); a < m_vehicles.end(); a++) delete* a;
	}
}