/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          07/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif