#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Song.h"
class Playlist
{
public:
	Playlist(string playlistName = "none"); // using default parameters for our constructor
	string GetPlaylistName() const;
	void AddSongToPlaylist(Song* newSong);
	void PlaySongs() const;
	void EraseSongFromPlaylist(int indexNumber);
	void ListSongsInPlaylist() const;
	void DeleteSongsInPlaylist(string songToDelete);

private:
	string playlistName;
	vector<Song*> playlistSongs;
};
#endif