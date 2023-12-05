#ifndef CSV_HPP
# define CSV_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "color.hpp"

class Csv {
private:
	const std::string						fileName_;
	const bool								isHeader_;
	size_t									countField_;
	std::vector<std::string>				header_;
	std::list<std::vector<std::string> >	record_;

	// void	setHeader(std::string line, const std::string& delimiter);
	// void	setRecord(std::ifstream& fd, const std::string& delimiter);
	// void	getField(std::string& field, std::string& line, const std::string& delimiter);
public:
	// CONSTRUCTOR
	Csv(const std::string& fileName = "data.csv", const bool isHeader = true);
	// DESTRUCTOR
	~Csv();
	// OPERATOR
	// GETTER
	const std::string&							getFileName() const;
	size_t										getCountField() const;
	bool										getIsHeader() const;
	const std::vector<std::string>				getHeader() const;
	const std::list<std::vector<std::string> >&	getRecord() const;
	// SETTER
	// EXCEPTION
	class FatalErr : public std::logic_error {
	public:
		FatalErr(const std::string& msg = "Fatal error.");
	};
	class ValidErr : public std::logic_error {
	public:
		ValidErr(const std::string& msg = "Validation error.");
	};
	// DEBUG
// #if DEBUG
// 	void	debugPrint() const;
// #endif // DEBUG

};

#endif
