#pragma once
#ifndef SONG_H
#define SONG_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Song
{
public:
	Song(string songName = "none", string songFristLine = "null", int songPlaybackAmount = 0); //using default parameters for our constructor
	string GetSongName() const;
	string GetSongFristLine() const;
	int GetAmountPlayed() const;
	void IncrementAmountPlayed();

private:
	string songName;
	string songFristLine;
	int songPlaybackAmount;
};
#endif
