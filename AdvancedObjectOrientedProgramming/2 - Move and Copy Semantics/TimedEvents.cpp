/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          26/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>
#include "TimedEvents.h"
#include "StringSet.h"

using namespace std;
namespace sdds {
	void TimedEvents::startClock() { startTime = std::chrono::steady_clock::now(); }

	void TimedEvents::stopClock() { endTime = std::chrono::steady_clock::now(); }

	void TimedEvents::addEvent(const char* a) {
		auto m = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime); // auto helps to define a complicated data type
		if (num < 10) {
			this->events[num].eventName = a;
			this->events[num].units = "nanoseconds";
			this->events[num].duration = m;
			num++;
		}
	}

	std::ostream& operator<<(std::ostream& ccout, const TimedEvents& events) {
		ccout << "--------------------------" << endl;
		ccout << "Execution Times:" << endl;
		ccout << "--------------------------" << endl;

		for (int i = 0; i < events.num; i++) {
			ccout << setw(21) << left << events.events[i].eventName << ' ';
			ccout << setw(13) << right << events.events[i].duration.count() << ' ';
			ccout << events.events[i].units << endl;
		}

		ccout << "--------------------------" << endl;
		return ccout;
	}
}