/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          03/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Set.h"

using namespace std;
namespace sdds {
	template<unsigned int N, class T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const string& filter) const {
			T obj(filter);
			for (unsigned int i = 0; i < this->size(); i++) if (obj.isCompatibleWith(this->get(i)) == true) obj += this->get(i);
			return obj;
		}
	};
}
#endif