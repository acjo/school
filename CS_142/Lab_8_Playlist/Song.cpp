#include "Song.h"

Song::Song(string songName, string songFirstLine, int songPlaybackAmount)
{
	this->songName = songName;
	this->songFristLine = songFirstLine;
	this->songPlaybackAmount = songPlaybackAmount;
}
string Song::GetSongName() const
{
	return songName;
}
string Song::GetSongFristLine() const
{
	return songFristLine;
}
int Song::GetAmountPlayed() const
{
	return songPlaybackAmount;
}
void Song::IncrementAmountPlayed()
{
	songPlaybackAmount += 1;
}
