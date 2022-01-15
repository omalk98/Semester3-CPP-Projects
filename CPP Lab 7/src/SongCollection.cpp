//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       7 
// Date:		   Nov 5, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include "SongCollection.h"
using namespace std;
namespace sdds {
	SongCollection::SongCollection(const string& filename)
	{
		if (filename != "") {
			ifstream file{ filename };
			if (file) {
				string temp{};
				size_t idx = 0;
				while (file) {
					temp = "";
					getline(file, temp);
					if (temp != "") {
						Song new_song = {};
						idx = 0;
						new_song.m_title = temp.substr(idx, 25);
						if (new_song.m_title[0] == ' ') new_song.m_title.erase(0, new_song.m_title.find_first_not_of(" "));
						new_song.m_title.erase(new_song.m_title.find_last_not_of(" ") + 1);
						idx += 25;

						new_song.m_artist = temp.substr(idx, 25);
						if (new_song.m_artist[0] == ' ') new_song.m_artist.erase(0, new_song.m_artist.find_first_not_of(" "));
						new_song.m_artist.erase(new_song.m_artist.find_last_not_of(" ") + 1);
						idx += 25;

						new_song.m_album = temp.substr(idx, 25);
						if (new_song.m_album[0] == ' ') new_song.m_album.erase(0, new_song.m_album.find_first_not_of(" "));
						new_song.m_album.erase(new_song.m_album.find_last_not_of(" ") + 1);
						idx += 25;
						try {
							new_song.m_release_year = stoi(temp.substr(idx, 5));
						}
						catch (...) {
							new_song.m_release_year = 0;
						}
						idx += 5;
						new_song.m_length = stoi(temp.substr(idx, 5));
						idx += 5;
						new_song.m_price = stod(temp.substr(idx, temp.size() - idx));
						m_songs.push_back(new_song);
					}
				}
			}
			else throw string{ "ERROR: Cannot open file!" };
		}
		else throw string{ "ERROR: No file name provided!" };
	}
	void SongCollection::display(ostream& os) const
	{
		size_t collection_length = 0;
		for_each(m_songs.cbegin(), m_songs.cend(), [&](const Song& song) { os << song << "\n"; });
		collection_length = accumulate(m_songs.cbegin(), m_songs.cend(), collection_length, [](const size_t acc, const Song& song) {return acc + song.m_length; });

		os << setfill('-') << setw(89) << "\n" << setfill(' ') << "| " << setw(77) << "Total Listening Time: " << setfill('0');
		if (collection_length > 3600)
			os << collection_length / 3600 << ":" << setw(2) << (collection_length - 3600) / 60 << ":" << setw(2) << (collection_length - 3600) % 60;
		else
			os << collection_length / 60 << collection_length % 60;
		os << setfill(' ') << " |\n";
	}
	void SongCollection::sort(const std::string& mode)
	{
		std::sort(m_songs.begin(), m_songs.end(), [&](const Song& lhs, const Song& rhs) 
			{
				bool ok = false;
				if(mode == "title")
					ok = lhs.m_title < rhs.m_title; 
				else if (mode == "album")
					ok = lhs.m_album < rhs.m_album;
				else if (mode == "length")
					ok = lhs.m_length < rhs.m_length;
				return ok;
			});
	}
	void SongCollection::cleanAlbum()
	{
		transform(m_songs.begin(), m_songs.end(), m_songs.begin(), [](Song& song) { if (song.m_album == "[None]") song.m_album = ""; return song; });
	}
	bool SongCollection::inCollection(const std::string& artist) const
	{
		return any_of(m_songs.cbegin(), m_songs.cend(), [&](const Song& song) { return song.m_artist == artist; });
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		list<Song> artist_songs(count_if(m_songs.begin(), m_songs.end(), [&](const Song song) { return song.m_artist == artist; }));
		copy_if(m_songs.begin(), m_songs.end(), artist_songs.begin(), [&](const Song song) { return song.m_artist == artist; });
		return artist_songs;
	}
	ostream& operator<<(ostream& os, const Song& song)
	{
		os << left << "| " << setw(20) << song.m_title << " | " << setw(15) << song.m_artist << " | " << setw(20) << song.m_album << " | " << setw(6) << right; 
		if (song.m_release_year)
			os << song.m_release_year;
		else os << "";
		return os << " | " << song.m_length / 60 << ":" << setw(2) << setfill('0') << song.m_length % 60 << " | " << setfill(' ') << song.m_price << " |";
	}
}