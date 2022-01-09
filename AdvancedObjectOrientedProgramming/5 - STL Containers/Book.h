/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
namespace sdds {
	class Book {
		string bookAuthor;
		string bookTitle;
		string bookCountry;
		size_t bookYear;
		double bookPrice;
		string bookDesc;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend ostream& operator<<(ostream& out, const Book& b);

		template<class T>
		void fixSpelling(T& spellChecker) {
			spellChecker(bookDesc);
		}
	};
}
#endif