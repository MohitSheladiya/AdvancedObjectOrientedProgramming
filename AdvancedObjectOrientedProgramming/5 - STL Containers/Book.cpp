/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          16/10/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book() {
		bookAuthor = "";
		bookTitle = "";
		bookCountry = "";
		bookYear = 0;
		bookPrice = 0;
		bookDesc = "";
	}

	const std::string& Book::title() const { return bookTitle; }

	const std::string& Book::country() const { return bookCountry; }

	const size_t& Book::year() const { return bookYear; }

	double& Book::price() { return bookPrice; }

	Book::Book(const std::string& strBook) {
		string author;
		string title;
		string country;
		string price; 
		string year; 
		string desc;
		string s = strBook;
		
		author = s.substr(0, s.find(','));

		author.erase(author.find_last_not_of(' ') + 1);
		author.erase(0, author.find_first_not_of(' '));

		s.erase(0, s.find(',') + 1);
		title = s.substr(0, s.find(','));

		title.erase(title.find_last_not_of(' ') + 1);
		title.erase(0, title.find_first_not_of(' '));

		s.erase(0, s.find(',') + 1);
		country = s.substr(0, s.find(','));

		country.erase(country.find_last_not_of(' ') + 1);
		country.erase(0, country.find_first_not_of(' '));

		s.erase(0, s.find(',') + 1);
		price = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		year = s.substr(0, s.find(','));

		s.erase(0, s.find(',') + 1);
		desc = s;

		desc.erase(desc.find_last_not_of(' ') + 1);
		desc.erase(0, desc.find_first_not_of(' '));

		bookAuthor = author;
		bookTitle = title;
		bookCountry = country;
		bookPrice = stod(price);
		bookYear = stoi(year);
		bookDesc = desc;
	}

	ostream& operator<<(ostream& out, const Book& b) {
		out << right << setw(20) << b.bookAuthor << " | ";
		out << right << setw(22) << b.bookTitle << " | ";
		out << right << setw(5) << b.bookCountry << " | ";
		out << right << setw(4) << b.bookYear << " | ";
		out << right << setw(6) << fixed << setprecision(2) << b.bookPrice << " | ";
		out << left << b.bookDesc << endl;

		return out;
	}
}