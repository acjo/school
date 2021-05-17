#include "Playlist.h"

Playlist::Playlist(string playListName)
{
	this->playlistName = playListName;
}
string Playlist::GetPlaylistName() const
{
	return playlistName;
}
void Playlist::AddSongToPlaylist(Song* newSongToAdd)
{
	playlistSongs.push_back(newSongToAdd);
}
void Playlist::PlaySongs() const
{
	for (unsigned int i = 0; i < playlistSongs.size(); ++i)
	{
		cout << playlistSongs.at(i)->GetSongFristLine() << endl;
		playlistSongs.at(i)->IncrementAmountPlayed();
	}
}
void Playlist::EraseSongFromPlaylist(int indexNumber)
{
	playlistSongs.erase(playlistSongs.begin() + indexNumber);
}
void Playlist::ListSongsInPlaylist() const
{
	for (unsigned int i = 0; i < playlistSongs.size(); ++i)
		cout << i << ": " << playlistSongs.at(i)->GetSongName() << endl;
}
void Playlist::DeleteSongsInPlaylist(string songToDelete)
{
	for (int i = playlistSongs.size() -1 ; i >= 0; --i)
	{
		if (playlistSongs.at(i)->GetSongName() == songToDelete)
			EraseSongFromPlaylist(i);
		else
			continue;
	}
}
