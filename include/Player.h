#pragma once
#include "Track.h"
#include <vector>

using namespace std;

class Player {
private:
	vector<Track> trackList;
	Track correntTrack;
public:
	void add(Track track) {
		this->trackList.push_back(track);
	}
	void play() {
		if (this->correntTrack.getPlay() == 2 && this->correntTrack.getName() != "no name") {
			this->correntTrack.setPlay(1);
			cout << "Воспроизведение композиции " << this->correntTrack.toString() << " возобновлено." << endl;
		}
		else {
			string findName;
			Track track;
			cout << "Введите название комппозиции: -> ";
			cin >> findName;
			for (Track t : this->trackList) {
				if (t.getName() == findName) {
					track = t;
				}
			}
			this->correntTrack = track;
			cout << "Проигрывается композация: " << correntTrack.toString() << endl;
			this->correntTrack.setPlay(1);
		}
	}
	void play(int index) {
		this->correntTrack = trackList.at(index);
		cout << "Проигрывается композация: " << correntTrack.toString() << endl;		
		this->correntTrack.setPlay(1);
	}
	void pause() {
		if (this->correntTrack.getPlay() == 1) {
			this->correntTrack.setPlay(2);
			cout << "Проигрываемая композиция: " << correntTrack.toString() << " поставлена на паузу!" << endl;
		}
	}
	void stop() {
		Track emp;
		if (this->correntTrack.getName() != "no name") {			
			cout << "Проигрывание композиции: " << this->correntTrack.toString() << " завершено." << endl;
			this->correntTrack = emp;
		}
	}
	void next() {
		int sizePlayList = trackList.size();
		string nameTrack;
		int idx = abs(rand() % sizePlayList);
		if (idx < sizePlayList) {
			play(idx);
		}
	}
};