/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          20/11/21
Project Part:  Milestone 2
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Utilities.h"
#include "Station.h"

using namespace std;
namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name = "";
		std::string m_product = "";
		size_t m_cntItem = 0;

		Item** m_lstItem = nullptr;

		static size_t m_widthField;
	public:
		CustomerOrder();
		CustomerOrder(const string& s);
		CustomerOrder(const CustomerOrder& c) { throw "Error"; };
		CustomerOrder& operator=(const CustomerOrder& c) = delete;
		CustomerOrder(CustomerOrder&& c) noexcept;
		CustomerOrder& operator=(CustomerOrder&& c) noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif