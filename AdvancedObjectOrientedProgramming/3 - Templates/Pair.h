/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          03/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
namespace sdds {
	template<typename V, typename K>
	class Pair {
		V pairValue;
		K pairKey;
	public:
		Pair() {
			pairValue = { 0 };
			pairKey = { 0 };
		}

		Pair(const K& key, const V& value){
			pairValue = value;
			pairKey = key;
		}

		const V& value() const { return pairValue; }

		const K& key() const { return pairKey; }

		virtual void display(std::ostream& os) const { os << pairKey << " : " << pairValue << endl; }

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}
	};
}
#endif