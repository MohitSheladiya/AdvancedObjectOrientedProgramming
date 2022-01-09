/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          11/11/21
Project Part:  Milestone 1
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
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 1;

	Station::Station(const string& str) {
		size_t a = 0;
		bool flag = true;
		Utilities u;

		try {
			m_ItemName = u.extractToken(str, a, flag);
			m_serial = stoi(u.extractToken(str, a, flag));
			m_items = stoi(u.extractToken(str, a, flag));
			m_widthField = max(u.getFieldWidth(), m_widthField);
			m_description = u.extractToken(str, a, flag);
		} catch (string& s) {
			cout << s;
		}
		m_id = id_generator;
		id_generator = id_generator + 1;
	}

	const std::string& Station::getItemName() const {
		return m_ItemName;
	}

	size_t Station::getNextSerialNumber() {
		m_serial = m_serial + 1;
		return m_serial - 1;
	}

	size_t Station::getQuantity() const {
		return m_items;
	}

	void Station::updateQuantity() {
		m_items = m_items - 1;
		if (m_items < 0) m_items = 0;
	}

	void Station::display(std::ostream& os, bool full) const {
		os << "[" << right << setw(3) << setfill('0') << m_id << "]";
		os << " Item: " << left << setw(m_widthField) << setfill(' ') << m_ItemName;
		os << " [" << right << setw(6) << setfill('0') << m_serial << "]";

		if (!full) os << endl;
		else {
			os << " Quantity: " << left << setw(m_widthField) << setfill(' ') << m_items;
			os << " Description: ";
			os << m_description << endl;
		}
	}
}