/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <iomanip>
#include <cstring>

extern unsigned long g_sysClock; // exports g_sysClock to other modules

using namespace std;
namespace sdds {
	class Event {
		char* desc;
		unsigned long secs; // positive long numbers
	public:
		Event();
		Event(const Event& a);
		void display();
		void set(char* arr = nullptr);
		Event& operator=(const Event& a);
		~Event();
	};
}

#endif