/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          10/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class Reservation {
		string r_id;
		string r_name;
		string r_email;
		unsigned int party_size;
		unsigned int r_day;
		unsigned int r_time;
	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend ostream& operator<<(ostream& out, const Reservation& r);
	};
}
#endif