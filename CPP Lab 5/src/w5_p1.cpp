// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		std::ifstream fptr{ argv[1] };
		if (fptr)
		{
			std::string line{};
			int i = 0;
			while (!fptr.eof()) {
				std::getline(fptr, line, '\n');
				if (line[0] == '#' || line == "") continue;
				sdds::Book book(line);
				library[i++] = book;
			}
		}
		else 
		{
			std::cerr << "ERROR: Cannot open file.\n";
			exit(AppErrors::CannotOpenFile);
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto lambda = [&](sdds::Book& book) 
	{ 
		if (book.country() == "US") book.price() *= usdToCadRate; 
		else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) book.price() *= gbpToCadRate; 
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	
	for (auto i = 0; i < 7; ++i)
		std::cout << library[i];


	std::cout << "-----------------------------------------\n\n";

	for (auto i = 0; i < 7; ++i)
		lambda(library[i]);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	
	for (auto i = 0; i < 7; ++i)
		std::cout << library[i];


	std::cout << "-----------------------------------------\n";

	return 0;
}
