#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "Csv.hpp"
#include "debugMessage.hpp"

// CONSTRUCTOR
Csv::Csv(const std::string& fileName, const bool isHeader) :
	fileName_(fileName), isHeader_(isHeader), countField_(0)
{
#if DEBUG
	debugMessage("Csv", HAS_ARG_CONSTRUCT);
#endif // DEBUG
	try {
		std::ifstream	fd(this->fileName_);

		if (fd.fail() || fd.eof()) {
			throw Csv::FatalErr("Failed std::ifstream().");
		}
		std::string		line("");
		while (std::getline(fd, line, '\n')) {
			if (fd.fail()) {
				throw Csv::FatalErr("Failed std::getline().");
			}
			std::cout << line << std::endl;
		}
		if (!fd.eof() && fd.fail()) {
			throw Csv::FatalErr("Failed std::getline().");
		}
		// if (this->isHeader_) {
		// 	// this->setHeader(fd, ",");
		// 	std::string		line("");

		// 	std::getline(fd, line, '\n');
		// 	if (fd.fail()) {
		// 		throw Csv::FatalErr("Failed std::getline().");
		// 	}
		// 	this->setHeader(line, ",");
		// }
		// this->setRecord(fd, ",");
		fd.close();
	}
	catch (const std::exception& e) {
		throw ;
	}
}

Csv::~Csv()
{
#if DEBUG
	debugMessage("Csv", DESTRUCT);
#endif // DEBUG
}

// GETTER
const std::string&	Csv::getFileName() const
{
	return (this->fileName_);
}

size_t	Csv::getCountField() const
{
	return (this->countField_);
}

bool	Csv::getIsHeader() const
{
	return (this->isHeader_);
}

const std::vector<std::string>	Csv::getHeader() const
{
	return (this->header_);
}

// void	Csv::getField(std::string& field, std::string& line, const std::string& delimiter)
// {
// 	if (line.empty()) {
// 		// throw Csv::ValidErr("Empty field.");
// 		return ;
// 	}
// 	try {
// 		// if (line == delimiter) {
// 		// 	throw Csv::ValidErr("Bad line format.");
// 		// }
// 		size_t	pos = line.find(delimiter);
// 		if (pos == std::string::npos) {
// 			field = line.substr(0);
// 			line = "";
// 		}
// 		// else if (pos == 0) {
// 		// 	throw Csv::ValidErr("Bad line format.");
// 		// }
// 		else if (pos == line.size() - delimiter.size()) {
// 			throw Csv::ValidErr("Bad line format.");
// 		}
// 		else {
// 			field = line.substr(0, pos);
// 			line = line.substr(pos + delimiter.size());
// 		}
// 		// if (line == delimiter) {
// 		// 	throw Csv::ValidErr("Bad line format.");
// 		// }
// 
// 		// if (field.empty()) {
// 		// 	throw Csv::ValidErr("Empty field.");
// 		// }
// 
// 		// if (field.find(' ') != std::string::npos) {
// 		// 	throw Csv::ValidErr("Bad field format.");
// 		// }
// 	}
// 	catch (const std::exception& e) {
// 		throw ;
// 	}
// }

// void	Csv::setHeader(std::string line, const std::string& delimiter)
// {
// 	try {
// 		size_t		i(0);
// 		std::string	field("");
// 
// 		while (!line.empty()) {
// 			getField(field, line, delimiter);
// 			this->header_[i] = field;
// 			i += 1;
// 		}
// 		this->countField_ = i;
// 	}
// 	catch (const std::exception& e) {
// 		throw ;
// 	}
// }

// void	Csv::setRecord(std::ifstream& fd, const std::string& delimiter)
// {
// 	try {
// 		std::string	line("");
// 
// 		while (std::getline(fd, line, '\n')) {
// 			size_t	i(0);
// 			if (this->isHeader_) {
// 				std::vector<std::string>	record;
// 				while (!line.empty()) {
// 					std::string	field("");
// 					getField(field, line, delimiter);
// 					if (i >= this->countField_) {
// 						throw Csv::ValidErr("Bad line format.");
// 					}
// 					record[this->header_[i]] = field;
// 					i += 1;
// 				}
// 				this->recordKeyString_.push_back(record);
// 			}
// 			else {
// 				std::vector<std::string>	record;
// 				while (!line.empty()) {
// 					std::string	field("");
// 
// 					getField(field, line, delimiter);
// 					record[i] = field;
// 					i += 1;
// 				}
// 				this->recordKeySize_t_.push_back(record);
// 			}
// 		}
// 		if (!fd.eof() && fd.fail()) {
// 			throw Csv::FatalErr("Failed std::getline().");
// 		}
// 	}
// 	catch (const std::exception& e) {
// 		throw ;
// 	}
// }

// EXCEPTION
Csv::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
Csv::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

// void	Csv::debugPrint() const
// {
// 	for (std::list<std::vector<std::string> >::const_iterator itr = this->recordKeyString_.begin(); itr != this->recordKeyString_.end(); itr++) {
// 		for (std::vector<std::string>::const_iterator itr2 = (*itr).begin(); itr2 != (*itr).end(); itr2++) {
// 			std::cout << itr2->first << ": " << itr2->second << std::endl;
// 		}
// 		std::cout << std::endl;
// 	}
// }
