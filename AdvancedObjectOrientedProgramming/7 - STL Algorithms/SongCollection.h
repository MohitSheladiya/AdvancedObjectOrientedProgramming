/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          12/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <list>
#include <vector>
#include <functional>

using namespace std;
namespace sdds {
	struct Song {
		string artist;
		string title;
		string album;
		double m_price;
		size_t year;
		size_t length;
	};

	class SongCollection {
		vector<sdds::Song> song;
	public:
		SongCollection(string s); 
		void display(std::ostream& out) const;
		void sort(string s);
		void cleanAlbum();
		bool inCollection(string s) const;
		std::list<Song> getSongsForArtist(string s) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif