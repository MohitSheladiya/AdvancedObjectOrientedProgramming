/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          3/12/21
Project Part:  Milestone 3
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Workstation.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder = 0;
		Workstation* m_firstStation = nullptr;
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif