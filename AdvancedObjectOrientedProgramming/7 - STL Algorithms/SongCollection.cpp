/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          12/11/21
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include "SongCollection.h"

using namespace std;
namespace sdds {
	SongCollection::SongCollection(string s) {
		string a;
		string z; 
		size_t p;
		Song ss;
		ifstream file(s);
		try {
			while (file) {
				getline(file, a);
				if (file) {
					z = a.substr(0, 25);
					p = z.find_first_not_of(" ");
					z.erase(0, p);
					p = z.find_last_not_of(" ");
					if (string::npos != p) z.erase(p + 1);
					ss.title = z;

					z = a.substr(25, 25);
					p = z.find_first_not_of(" ");
					z.erase(0, p);
					p = z.find_last_not_of(" ");
					if (string::npos != p) z.erase(p + 1);
					ss.artist = z;

					z = a.substr(50, 25);
					p = z.find_first_not_of(" ");
					z.erase(0, p);
					p = z.find_last_not_of(" ");
					if (string::npos != p) z.erase(p + 1);
					ss.album = z;

					if (a.substr(75, 5) == "     ") {
						ss.year = 0;
					} else ss.year = stoi(a.substr(75, 5));

					if (a.substr(80, 5) == "     ") {
						ss.length = 0;
					} else ss.length = stoi(a.substr(80, 5));

					if (a.substr(85, 5) == "     ") {
						ss.m_price = 0;
					} else ss.m_price = stod(a.substr(85, 5));

					song.push_back(ss);
				}
			}
			file.close();
		} catch (...) {
			throw "Error";
		}
	}

	void SongCollection::display(std::ostream& out) const { 
		for_each(song.begin(), song.end(), [&out](const Song& s) { out << s << endl; });
		out << "----------------------------------------------------------------------------------------" << endl;
		int total = accumulate(song.begin(), song.end(), 0, [](int i, const Song& s)->int {
			auto a = s.length + i;
			return a;
		});

		size_t h = total/3600;
		size_t m = (total%3600)/60;
		size_t s = total%60;
		out << "|                                                        Total Listening Time: " << h << ":" << m << ":" << s << " |" << endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		int h = theSong.length / 60;
		int m = theSong.length % 60;
		out << "| " << left << setw(20) << theSong.title << " ";
		out << "| " << left << setw(15) << theSong.artist << " ";
		out << "| " << left << setw(20) << theSong.album << " ";
		out << "| " << right << setw(6);

		if (theSong.year == 0) out << " ";
		else out << theSong.year;

		out << " | " << h << ":" << setw(2) << setfill('0') << m << " ";
		out	<< "| " << fixed << setprecision(2) << setfill(' ') << theSong.m_price << " |";

		return out;
	}

	void SongCollection::sort(string s) {
		if (s == "title")
			std::sort(song.begin(), song.end(), [](Song& s1, Song& s2) {
				return (s1.title > s2.title) == false; 
			});
		else if (s == "album")
			std::sort(song.begin(), song.end(), [](Song& s1, Song& s2) {
				return (s1.album > s2.album) == false;
			});
		else if (s == "length")
			std::sort(song.begin(), song.end(), [](Song& s1, Song& s2) {
				return (s1.length < s2.length) == true;
			});
	}

	void SongCollection::cleanAlbum() {
		for_each(song.begin(), song.end(), [](Song& s) {
			if (s.album == "[None]")
				s.album = "";
		});
	}

	bool SongCollection::inCollection(string s) const {
		bool flag = false;
		flag = any_of(song.begin(), song.end(), [=](const Song& a)->bool {
			return (a.artist == s);
		});
		return flag;
	}

	std::list<Song> SongCollection::getSongsForArtist(string s) const {
		list<Song> ls;
		for_each(song.begin(), song.end(), [&](Song a) {
			if (s == a.artist)
				ls.push_back(a);
		});
		return ls;
	}
}