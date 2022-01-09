/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          03/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Pair.h"

using namespace std;
namespace sdds {
	template <class V, class K>
	class PairSummable : public Pair<V, K> {
		static V in;
		static size_t min;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = in) : Pair<V, K>(key, value) { if (key.size() > min) min = key.size(); }
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			bool flag = false;
			if (this->key() == b.key()) flag = true;
			return flag;
		}
		PairSummable& operator+=(const PairSummable& a) {
			*this = PairSummable(this->key(), this->value() + a.value());
			return *this;
		}
		virtual void display(std::ostream& os) const {
			os << left << setw(min);
			Pair<V, K>::display(os);
		}
	};

	template<typename V, typename K> V PairSummable<V, K>::in = {};

	template<typename V, typename K> size_t PairSummable<V, K>::min = 0;

	template<> PairSummable<string,string>& PairSummable<string,string>::operator+=(const PairSummable& a) {
		if (this->value() == "") {
			*this = PairSummable(this->key(), this->value() + a.value());
		} else {
			*this = PairSummable(this->key(), this->value() + ", " + a.value());
		}
		return *this;
	}
}
#endif