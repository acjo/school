#include "Playlist.h"

void Menu() {
	cout << "add \t Adds a list of songs to the library" << endl;
	cout << "list \t Lists all the songs in the library" << endl;
	cout << "addp \t Adds a new playlist" << endl;
	cout << "addsp \t Adds a song to a playlist" << endl;
	cout << "listp \t Lists all the playlists" << endl;
	cout << "play \t Plays a playlist" << endl;
	cout << "remp \t Removes a playlist" << endl;
	cout << "remsp \t Removes a song from a playlist" << endl;
	cout << "remsl \t Removes a song from the library(and all playlists)" << endl;
	cout << "options \t Prints this options menu" << endl;
	cout << "quit \t Quits the program" << endl;
	return;
}

int main() {
	bool iterate = true;
	string userChoice = "A";
	vector<Song*> songPointers;
	Song* newSong = nullptr;
	string newSongName;
	string newSongFirstLine;
	vector<Playlist*> playlistPointers;
	Playlist* newPlaylist = nullptr;
	string newPlaylistName;
	int playlistIndexNumber;
	int songIndexNumber;

	cout << "Welcome to the Firstline Player! Enter options to see menu options." << endl;
	cout << endl;
	while (iterate == true) {
		cout << "Enter your selection now: " << endl;
		cout << endl;
		cin >> userChoice;
		cin.ignore();
		if (userChoice == "quit") {
			iterate = false;
		}
		else if (userChoice == "options" || (userChoice != "add" && userChoice != "list" && userChoice != "addp" && userChoice != "addsp" && 
				userChoice != "listp" && userChoice != "play" && userChoice != "remp" && userChoice != "remsp" && userChoice != "remsl")) {
			Menu();
		}
		else if (userChoice == "add") {
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			while (newSongName != "STOP") {
				cout << "Song Name:" << endl;
				getline(cin, newSongName);
				if (newSongName == "STOP") {
					continue;
				}
				else {
					cout << "Song's first line: " << endl;
					getline(cin, newSongFirstLine);
					newSong = new Song(newSongName, newSongFirstLine);
					songPointers.push_back(newSong);
				}
			}
			cout << endl;
		}
		else if (userChoice == "list") {
			for (unsigned int i = 0; i < songPointers.size(); ++i) {
				cout << songPointers.at(i)->GetSongName() << ": \"" << songPointers.at(i)->GetSongFristLine();
				cout << "\", " << songPointers.at(i)->GetAmountPlayed() << " play(s)." << endl;
			}
			cout << endl;
		}
		else if (userChoice == "addp") {
			cout << "Playlist name: " << endl;
			getline(cin, newPlaylistName);
			newPlaylist = new Playlist(newPlaylistName);
			playlistPointers.push_back(newPlaylist);
			cout << endl;
		}
		else if (userChoice == "listp") {
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				cout << i << ": " << playlistPointers.at(i)->GetPlaylistName() << endl;
			}
			cout << endl;
		}
		else if (userChoice == "addsp") {
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				cout << i << ": " << playlistPointers.at(i)->GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndexNumber;
			cin.ignore();
			for (unsigned int i = 0; i < songPointers.size(); ++i) {
				cout << i << ": " << songPointers.at(i)->GetSongName() << endl;
			}
			cout << "Pick a song index number: " << endl;
			cin >> songIndexNumber;
			cin.ignore();
			playlistPointers.at(playlistIndexNumber)->AddSongToPlaylist(songPointers.at(songIndexNumber));
			cout << endl;
		}
		else if (userChoice == "play") {
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				cout << i << ": " << playlistPointers.at(i)->GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndexNumber;
			cin.ignore();
			cout << endl;
			cout << "Playing first lines of playlist: " << playlistPointers.at(playlistIndexNumber)->GetPlaylistName() << endl;
			playlistPointers.at(playlistIndexNumber)->PlaySongs();
			cout << endl;
		}
		else if (userChoice == "remp") {
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				cout << i << ": " << playlistPointers.at(i)->GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number to remove: " << endl;
			cin >> playlistIndexNumber;
			cin.ignore();
			delete playlistPointers.at(playlistIndexNumber); // deleting the allocated memory of a playlist to be removed
			playlistPointers.erase(playlistPointers.begin() + playlistIndexNumber);
			cout << endl;
		}
		else if (userChoice == "remsp") {
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				cout << i << ": " << playlistPointers.at(i)->GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndexNumber;
			cin.ignore();
			playlistPointers.at(playlistIndexNumber)->ListSongsInPlaylist();
			cout << "Pick a song index number to remove: " << endl;
			cin >> songIndexNumber;
			cin.ignore();
			playlistPointers.at(playlistIndexNumber)->EraseSongFromPlaylist(songIndexNumber);
			cout << endl;
		}
		else if (userChoice == "remsl") {
			for (unsigned int i = 0; i < songPointers.size(); ++i) {
				cout << i << ": " << songPointers.at(i)->GetSongName() << endl;
			}
			cout << "Pick a song index number to remove: " << endl;
			cin >> songIndexNumber;
			cin.ignore();
			for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
				playlistPointers.at(i)->DeleteSongsInPlaylist(songPointers.at(songIndexNumber)->GetSongName());
			}
			for (unsigned int i = 0; i < songPointers.size(); ++i) {
				if (songPointers.at(i)->GetSongName() == songPointers.at(songIndexNumber)->GetSongName()) {
					delete songPointers.at(i); // deleting the allocated memory as the song gets deleted from the library
					songPointers.erase(songPointers.begin() + i);
					break;
				}
			}
			cout << endl;
		}
	}
	for (unsigned int i = 0; i < playlistPointers.size(); ++i) {
		delete playlistPointers.at(i);
	}
	for (unsigned int i = 0; i < songPointers.size(); ++i) {
		delete songPointers.at(i); //freeing memeory after the user enters "quit" 
	}
	playlistPointers.clear();
	songPointers.clear();

	cout << "Goodbye!" << endl;

	return 0;
}
