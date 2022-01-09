/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          3/12/21
Project Part:  Milestone 3
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "Workstation.h"

using namespace std;
namespace sdds {
	deque<CustomerOrder> pending, completed, incomplete;

	Workstation::Workstation(const string& s) : Station(s) {

	}

	void Workstation::fill(std::ostream& os) {
		if (m_orders.empty() != true)
			m_orders.begin()->fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder() {
		bool flag = false;

		if (m_orders.empty() != true) {
			if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName()) == true) {
				if (m_pNextStation != nullptr) {
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
					flag = true;
				}
				else if (m_orders.front().isFilled() == true) {
					completed.push_back(move(m_orders.front()));
					m_orders.pop_front();
					flag = true;
				}
				else {
					incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
					flag = true;
				}
			}
		}
		return flag;
	}

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation != nullptr)
			os << Station::getItemName() << " --> " << m_pNextStation->getItemName() << endl;
		else
			os << Station::getItemName() << " --> " << "End of Line" << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(move(newOrder));
		return *this;
	}
}