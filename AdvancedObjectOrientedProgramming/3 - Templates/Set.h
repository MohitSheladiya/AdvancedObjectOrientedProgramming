/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          03/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
namespace sdds {
	template<unsigned int N, typename T>
	class Set {
		T type[N];
		unsigned int a;
	public:
		Set() { a = 0; }
		size_t size() const { return a; }
		const T& get(size_t idx) const { return type[idx]; }
		void operator+=(const T& item) {
			if (a < N) {
				type[a] = item;
				a++;
			}
		}
	};
}
#endif