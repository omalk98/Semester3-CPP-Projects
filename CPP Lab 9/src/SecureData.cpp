// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <utility>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}
	void SecureData::code(char key)
	{
		const size_t nu_partitions = 4;
		std::vector<std::thread> threads{};
		size_t partition = nbytes / nu_partitions;

		auto bound_converter = std::bind(converter, std::placeholders::_1, key, std::placeholders::_2, Cryptor());

		// second placeholder made for cases when nbytes does not evenly devide over nu_partitions (not necissary for this workshop since 1936 devides evenly over 4)
		for (size_t i = 0; i < nu_partitions; ++i)
			threads.push_back(std::thread(bound_converter, &text[partition * i], 
				(( i == nu_partitions - 1 && nbytes % nu_partitions) ? 
					partition - (nbytes % nu_partitions) : partition)));

		for (auto& thread : threads)
			thread.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			if (!file) throw std::string("\n***No file name provided***\n");
			ofstream fptr(file, ios::out | ios::binary);

			// TODO: write data into the binary file
			//         and close the file
			fptr.write(text, nbytes);
			fptr.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream fptr(file, ios::in | ios::binary);
		if (!fptr) throw std::string("\n***Unable to open file***\n");

		// TODO: - allocate memory here for the file content
		delete[] text;
		text = new char[nbytes];

		// TODO: - read the content of the binary file
		fptr.read(text, nbytes);
		fptr.close();
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
