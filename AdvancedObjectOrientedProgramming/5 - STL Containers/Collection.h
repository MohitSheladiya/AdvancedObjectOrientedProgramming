/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	template<class T>
	class Collection {
		string collectionName;
		T* arr = nullptr;
		size_t sizeArr = 0;
		void (*voidObserver)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(const std::string& name) {
			collectionName = name;
			voidObserver = nullptr;
		}

		~Collection() {
			delete[] arr;
			arr = nullptr;
		}

		const std::string& name() const {
			return collectionName;
		}

		size_t size() const {
			return sizeArr;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			voidObserver = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool flag = false;

			for (size_t i = 0; i < sizeArr; i++) if (arr[i].title() == item.title()) flag = true;

			if (flag == false) {
				T* t = new T[sizeArr + 1];
				for (size_t i = 0; i < sizeArr; i++) t[i] = arr[i];

				sizeArr = sizeArr + 1;
				delete[] arr;
				arr = nullptr;
				arr = new T[sizeArr];

				for (size_t i = 0; i < sizeArr; i++) arr[i] = t[i];

				delete[] t;
				arr[sizeArr-1] = item;
				if (voidObserver != nullptr) voidObserver(*this, item);
			}

			return *this;
		}

		T& operator[](size_t idx) const {
			if (sizeArr < (idx + 1)) {
				string str = "Bad index [" + to_string(idx) + "]. Collection has [" + to_string(sizeArr) + "] items.";
				throw out_of_range(str);
			} else return arr[idx];
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < sizeArr; i++) if (title == arr[i].title()) return &arr[i];
			return nullptr;
		}

		friend ostream& operator<<(ostream& out, const Collection& c) {
			for (size_t i = 0; i < c.size(); i++) out << c.arr[i];
			return out;
		}
	};
}
#endif