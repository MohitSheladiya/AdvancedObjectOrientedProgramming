/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          26/09/19
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
namespace sdds {

	class TimedEvents {
		int num = 0;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct {
			std::string eventName{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[10];
	public:
		void startClock();
		void stopClock();
		void addEvent(const char* a);
		friend std::ostream& operator<<(std::ostream& ccout, const TimedEvents& events);
	};
}
#endif