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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"

using namespace std;
namespace sdds {
	extern deque<CustomerOrder> pending, completed, incomplete;

	class Workstation : public Station {
		deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation = nullptr;
	public:
		Workstation();
		Workstation(const string& s);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif