/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          11/11/21
Project Part:  Milestone 1
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class Station {
		int m_id;
		string m_ItemName;
		string m_description;
		size_t m_serial;
		size_t m_items; 

		static size_t m_widthField; 
		static int id_generator; 
	public:
		Station(const string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif
