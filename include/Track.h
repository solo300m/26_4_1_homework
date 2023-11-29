#pragma once
#include <chrono>
#include <string>
#include <iostream>

using namespace std;


class Track {
private:
	string name;
	tm date;
	int longTrack;
	int play;
public:
	Track() {
		time_t tmp = chrono::system_clock::to_time_t(chrono::system_clock::now());
		this->name = "no name";
		this->date = *localtime(&tmp);
		this->longTrack = 0.0;
		this->play = 0;
	};
	Track(string name, tm date, double lTrack) {
		this->name = name;
		this->date = date;
		this->longTrack = lTrack;
		this->play = 0;
	};
	Track(string name, int day, int month, int year, double lTrack) {
		this->name = name;		
		this->longTrack = lTrack;
		tm tmp = { 0 };
		tmp.tm_mday = { day };
		tmp.tm_mon = { month - 1 };
		tmp.tm_year = { year - 1900 };
		tmp.tm_hour = { 0 };
		tmp.tm_min = { 0 };
		tmp.tm_sec = { 0 };
		this->date = tmp;
		this->play = 0;
	}
	string toString() {
		string longTime = "";
		if (this->longTrack > 60) {			
			longTime = "Время звучания - " + to_string(this->longTrack / 60) + " мин. " + to_string(this->longTrack % 60)+" сек.";			
		}
		else {
			longTime = "Время звучания - " + to_string(this->longTrack) + " сек.";
		}
		string rez = "Наименование композиции - " + this->name + " Дата размещения - " + to_string(this->date.tm_mday) + "/" + to_string(this->date.tm_mon + 1) + "/" + to_string(this->date.tm_year + 1900) +" "+longTime;
		return rez;
	}
	string getName() {
		return this->name;
	}
	int getPlay() {
		return this->play;
	}
	void setPlay(int param) {
		if (param == 0) {
			this->play = 0;
		}
		else if (param == 1) {
			this->play = 1;
		}
		else {
			this->play = 2;
		}
	}
};