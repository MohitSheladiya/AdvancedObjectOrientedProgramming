/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          3/12/21
Project Part:  Milestone 3
*/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "LineManager.h"
#include "Workstation.h"

using namespace std;
namespace sdds {
	LineManager::LineManager() {
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) : m_cntCustomerOrder{} {
		string s;
		string s1 = "";
		string s2 = "";
		bool flag = false;
		size_t p = 0;
		fstream f(file);
		Utilities u;
		u.setDelimiter('|');

		if (f.is_open() != true) throw "Error";

		while (getline(f, s)) {
			s1 = u.extractToken(s, p, flag);

			auto a = *find_if(begin(stations), end(stations), [&](Workstation* w) {
				if (w->getItemName() == s1) return true;
				else return false;
				});
			activeLine.push_back(a);

			if (flag == true) {
				s2 = u.extractToken(s, p, flag);
				auto b = *find_if(begin(stations), end(stations), [&](Workstation* w) {
					if (w->getItemName() == s2) return true;
					else return false;
					});
				a->setNextStation(b);
			}
		}
		f.close();
		m_cntCustomerOrder = pending.size();
		m_firstStation = activeLine.front();
	}

	void LineManager::linkStations() {
		int i = 0;
		const Workstation* w = m_firstStation;
		while (w != nullptr) {
			activeLine[i++] = const_cast<Workstation*>(w);
			w = w->getNextStation();
		}
	}

	bool LineManager::run(std::ostream& os) {
		static size_t fix = 1;
		bool flag = false;

		os << "Line Manager Iteration: " << fix << endl;

		if (!pending.empty()) {
			*activeLine.front() += move(pending.front());
			pending.pop_front();
		}

		for (auto i = 0u; i < activeLine.size(); i++) activeLine[i]->fill(os);
		for (auto i = 0u; i < activeLine.size(); i++) activeLine[i]->attemptToMoveOrder();
		fix++;

		if (m_cntCustomerOrder == (completed.size() + incomplete.size())) flag = true;
		return flag;
	}

	void LineManager::display(std::ostream& os) const {
		for (auto& a : activeLine) if (a != nullptr) a->display(os);
	}
}