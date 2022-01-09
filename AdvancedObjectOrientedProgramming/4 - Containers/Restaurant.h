/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          10/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Reservation.h"

using namespace std;
namespace sdds {
	class Restaurant {
		Reservation* res{ nullptr };
		unsigned int numofRes;
	public:
		Restaurant();
		~Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& r);
		Restaurant(Restaurant&& r) noexcept;
		Restaurant& operator=(const Restaurant& r);
		Restaurant&& operator=(Restaurant&& r) noexcept;
		size_t size() const;
		friend ostream& operator<<(ostream& out, const Restaurant& r);
	};
}
#endif