/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          20/11/21
Project Part:  Milestone 2
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

//Updated in MS3 isItemFilled() and fillItem()

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const string& s) {
		size_t a = 0, b = 0;
		bool flag = true;
		Utilities u;
		Item* it[107];

		m_name = u.extractToken(s, a, flag);
		m_product = u.extractToken(s, a, flag);
		b = a;

		m_cntItem = 0;
		for (;;) {
			if (!flag) break;
			u.extractToken(s, b, flag);
			m_cntItem = m_cntItem + 1;
		}
		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++) {
			it[i] = new Item(u.extractToken(s, a, flag));
			m_lstItem[i] = it[i];
		}
		m_widthField = max(u.getFieldWidth(), m_widthField);
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& c) noexcept {
		m_name = c.m_name;
		c.m_name = "";
		m_product = c.m_product;
		c.m_product = "";
		m_cntItem = c.m_cntItem;
		c.m_cntItem = 0;
		m_lstItem = c.m_lstItem;
		c.m_lstItem = nullptr;
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c) noexcept {
		if (this != &c) {
			m_name = c.m_name;
			c.m_name = "";
			m_product = c.m_product;
			c.m_product = "";
			if (m_lstItem != nullptr) {
				for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
				delete[] m_lstItem;
			}
			m_cntItem = c.m_cntItem;
			c.m_cntItem = 0;
			m_lstItem = c.m_lstItem;
			c.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (m_lstItem != nullptr) {
			for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
			delete[] m_lstItem;
		}
	}

	bool CustomerOrder::isFilled() const {
		bool flag = true;
		for (size_t i = 0; i < m_cntItem; i++)
			if (!m_lstItem[i]->m_isFilled) flag = false;
		return flag;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool flag = true;
		for (size_t i = 0; i < m_cntItem && flag; i++) {
			if (m_lstItem[i] && m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled != true) flag = false;
		}
		return flag;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() >= 1) {
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled)
				os << "FILLED" << endl;
			else os << "TO BE FILLED" << endl;
		}
	}
}