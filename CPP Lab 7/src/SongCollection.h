//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       7 
// Date:		   Nov 5, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
namespace sdds {
	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		double m_price = 0;
		size_t m_release_year = 0;
		size_t m_length = 0;
	};
	class SongCollection
	{
		std::vector<Song> m_songs{};
	public:
		SongCollection(const std::string&);
		void display(std::ostream&)const;
		void sort(const std::string&);
		void cleanAlbum();
		bool inCollection(const std::string&)const;
		std::list<Song> getSongsForArtist(const std::string&)const;
	};
	std::ostream& operator<<(std::ostream&, const Song&);
}
#endif // !SDDS_SONGCOLLECTION_H