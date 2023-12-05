#ifndef CSV_HPP
# define CSV_HPP

#include <list>

class Csv {
private:
	const std::string						fileName_;
	const bool								isHeader_;
	size_t									countField_;
	std::vector<std::string>				header_;
	std::list<std::vector<std::string> >	record_;

public:
	// CONSTRUCTOR
	Csv(const std::string& fileName = "data.csv", const bool isHeader = true);
	// DESTRUCTOR
	~Csv();
	// EXCEPTION
	class FatalErr : public std::logic_error {
	public:
		FatalErr(const std::string& msg = "Fatal error.");
	};
	class ValidErr : public std::logic_error {
	public:
		ValidErr(const std::string& msg = "Validation error.");
	};
};

#endif
