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
#include "Reservation.h"

using namespace std;
namespace sdds {
	Reservation::Reservation() {
		r_id = "";
		r_name = "";
		r_email = "";
		party_size = 0;
		r_day = 0;
		r_time = 0;
	}

	void Reservation::update(int day, int time) {
		r_day = day;
		r_time = time;
	}

	Reservation::Reservation(const std::string& res) {
		string id;
		string name;
		string email;
		string size;
		string day;
		string time;
		string s = res;

		id = s.substr(0, s.find(':'));
		s.erase(0, s.find(':') + 1);
		name = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		email = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		size = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		day = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		time = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		id.erase(0, id.find_first_not_of(' '));
		id.erase(id.find_last_not_of(' ') + 1);
		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);
		email.erase(0, email.find_first_not_of(' '));
		email.erase(email.find_last_not_of(' ') + 1);

		email = "<" + email + ">";

		r_id = id;
		r_name = name;
		r_email = email;
		party_size = stoi(size);
		r_day = stoi(day);
		r_time = stoi(time);
	}

	ostream& operator<<(ostream& out,const Reservation& r) {
		out << "Reservation " << right << setw(10) << r.r_id << ": " << right << setw(20) << r.r_name << "  " << left << setw(24) << r.r_email;

		if (r.r_time >= 6 && r.r_time <= 9) out << "Breakfast ";
		else if (r.r_time >= 11 && r.r_time <= 15) out << "Lunch ";
		else if (r.r_time >= 17 && r.r_time <= 21) out << "Dinner ";
		else out << "Drinks ";

		out << "on day " << r.r_day << " @ " << r.r_time << ":00 for " << r.party_size;
		if (r.party_size > 1) out << " people." << endl; else out << " person." << endl;
		return out;
	}
}