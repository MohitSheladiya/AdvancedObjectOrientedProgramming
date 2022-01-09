/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          10/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		res = nullptr;
		numofRes = 0;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] res;
		res = nullptr;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& c) {
		*this = c;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& c) noexcept {
		*this = move(c);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& c) {
		if (this != &c) {
			delete[] res;
			numofRes = c.numofRes;
			res = new const Reservation* [numofRes];

			for (unsigned int i = 0; i < numofRes; i++) res[i] = c.res[i];
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& c) noexcept {
		if (this != &c) {
			delete[] res;
			numofRes = c.numofRes;
			res = c.res;
			c.res = nullptr;
			c.numofRes = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& c) {
		bool flag = false;
		if(!flag) for (unsigned int i = 0; i < numofRes; i++) if (&c == this->res[i]) flag = true;

		if (!flag) {
			const Reservation** r = new const Reservation *[numofRes + 1];
			for (size_t i = 0; i < numofRes; i++) r[i] = res[i];
			r[numofRes] = &c;
			numofRes++;
			delete[] res;
			res = r;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& c) {
		bool flag = false;
		const Reservation** r = nullptr;
		int p = -1;
		int a = numofRes - 1;

		if(!flag)
		for (unsigned int i = 0; i < numofRes; i++) {
			if (res[i] == &c) {
				p = i;
				flag = true;
			}
		}

		if (flag) {
			if (numofRes >= 1) {
				r = new const Reservation *[numofRes - 1];
				for (int i = 0; i < a; i++)	if (i < p) r[i] = res[i]; else r[i] = res[i + 1];
			}
			delete[] res;
			res = r;
			numofRes = numofRes - 1;
		}
		return *this;
	}

	ostream& operator<<(ostream& out, const ConfirmationSender& c) {
		out << "--------------------------" << endl;
		out << "Confirmations to Send" << endl;
		out << "--------------------------" << endl;

		if (c.numofRes == 0) out << "There are no confirmations to send!" << endl;
		else for (unsigned int i = 0; i < c.numofRes; i++) out << *c.res[i];
		out << "--------------------------" << endl;
		return out;
	}
}