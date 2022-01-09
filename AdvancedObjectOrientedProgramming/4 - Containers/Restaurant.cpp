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
#include "Restaurant.h"

using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		res = nullptr;
		numofRes = 0;
	}

	Restaurant::~Restaurant() {
		delete[] res;
		res = nullptr;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		numofRes = cnt;
		res = new Reservation[cnt];
		for (unsigned int i = 0; i < cnt; i++) res[i] = *reservations[i];
	}

	Restaurant::Restaurant(const Restaurant& r) {
		*this = r;
	}

	Restaurant::Restaurant(Restaurant&& r) noexcept {
		*this = move(r);
	}

	Restaurant& Restaurant::operator=(const Restaurant& r) {
		if (this != &r) {
			delete[] res;
			numofRes = r.numofRes;
			res = new Reservation[numofRes];

			for (unsigned int i = 0; i < numofRes; i++) res[i] = r.res[i];
		}
		return *this;
	}

	Restaurant&& Restaurant::operator=(Restaurant&& r) noexcept {
		if (this != &r) {
			delete[] res;
			numofRes = r.numofRes;
			res = r.res;
			r.res = nullptr;
			r.numofRes = 0;
		}
		return move(*this);
	}

	size_t Restaurant::size() const {
		return numofRes;
	}

	ostream& operator<<(ostream& out, const Restaurant& r) {
		static size_t CALL_CNT;
		++CALL_CNT;
		out << "--------------------------" << endl;
		out << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
		out << "--------------------------" << endl;

		if (r.numofRes == 0) out << "This restaurant is empty!" << endl;
		else for (unsigned int i = 0; i < r.numofRes; i++) out << r.res[i];
		out << "--------------------------" << endl;
		return out;
	}
}