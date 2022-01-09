/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          10/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Reservation.h"

using namespace std;
namespace sdds {
	class ConfirmationSender {
		const Reservation** res{ nullptr };
		unsigned int numofRes = 0;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& c);
		ConfirmationSender(ConfirmationSender&& c) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender& c);
		ConfirmationSender& operator=(ConfirmationSender&& c) noexcept; 
		ConfirmationSender& operator+=(const Reservation& c);
		ConfirmationSender& operator-=(const Reservation& c);
		friend ostream& operator<<(ostream& out, const ConfirmationSender& c);
	};
}
#endif