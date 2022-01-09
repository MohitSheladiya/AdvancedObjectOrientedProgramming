/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned long g_sysClock; // can be used in multiple transition units

using namespace std;
namespace sdds {

	Event::Event() { //sets the value of variable to null
		secs = 0; 
		desc = nullptr;
	}

	Event::Event(const Event& a) { // ensures desc is empty and fills an Event class 'a' with data
		desc = nullptr;
		*this = a;
	}

	void Event::display() {
		int hour = 0;
		int minute = 0;
		int second = 0;
		static int i = 1; // static ensures that int i if used more than once, it does not make i = 1 again

		hour = secs/3600;
		minute = (secs/60) % 60;
		second = secs % 60;

		if (desc != nullptr) {
			cout << setw(2) << setfill(' ') << i << ". ";
			cout << setw(2) << setfill('0') << hour << ":";
			cout << setw(2) << setfill('0') << minute << ":";
			cout << setw(2) << setfill('0') << second << " => ";
			cout << desc << endl;
			i++;
		} else {
			cout << setw(2) << setfill(' ') << i << ". " << "| No Event |" << endl;
			i++;
		}
	}

	void Event::set(char* arr) { // sets the value of desc and secs
		secs = 0;
		delete[] desc; // ensures that desc is empty so that it does not cause problems in another step
		desc = nullptr;
		if (arr != nullptr) {
			desc = new char[strlen(arr) + 1]; // gives a new size to the desc variable 
			strcpy(desc, arr);
			secs = g_sysClock; 
		} 
	}

	Event& Event::operator=(const Event& a) {
		if (this != &a) {
			secs = 0;
			delete[] desc; // may prevent data leaks
			desc = nullptr;
			if (a.desc != nullptr) {
				secs = a.secs;
				desc = new char[strlen(a.desc) + 1];
				strcpy(desc, a.desc);
			}
		}
		return *this;
	}

	Event::~Event() { // frees the data space 
		delete[] desc;
		desc = nullptr;
	}
}