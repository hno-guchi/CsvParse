#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "./Csv.hpp"
#include "./color.hpp"

// CONSTRUCTOR
Csv::Csv(const std::string& fileName, const bool isHeader) :
	fileName_(fileName), isHeader_(isHeader), countField_(0) {
	(void)countField_;
	try {
		std::ifstream	fd(this->fileName_);

		if (fd.eof() || fd.fail()) {
			fd.close();
			throw Csv::FatalErr("Failed std::getline().");
		}
		std::string		line("");
		if (this->isHeader_) {
			std::getline(fd, line, '\n');
			// std::cout << line << std::endl;
		}
		while (std::getline(fd, line, '\n')) {
			this->setRecord(&line);
			// std::cout << line << std::endl;
		}
		if (!fd.eof() && fd.fail()) {
			fd.close();
			throw Csv::FatalErr("Failed std::getline().");
		}
		fd.close();
	}
	catch (const std::exception& e) {
		throw;
	}
}

Csv::~Csv() {
#if DEBUG
	debugMessage("Csv", DESTRUCT);
#endif  // DEBUG
}

void Csv::getField(std::string* field, std::string* line) {
	if (line->empty()) {
		return;
	}
	try {
		size_t	pos = line->find(",");
		if (pos == std::string::npos) {
			*field = line->substr(0);
			*line = "";
		} else {
			*field = line->substr(0, pos);
			*line = line->substr(pos + 1);
		}
	}
	catch (const std::exception& e) {
		throw;
	}
}

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

void	Csv::setRecord(std::string* line) {
	if (line->empty()) {
		return;
	}
	if (line->rfind(",") == (line->size() - 1)) {
		// std::cerr << "Invalid csv format." << std::endl;
		// return;
		throw Csv::ValidErr("Invalid csv format.");
	}
	try {
		std::vector<std::string>	record;
		std::string					field("");
		while (!line->empty()) {
			getField(&field, line);
			record.push_back(field);
			field = "";
		}
		this->records_.push_back(record);
	}
	catch (const std::exception& e) {
		throw;
	}
}

// EXCEPTION
Csv::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
Csv::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

// void	Csv::debugPrint() const
// {
// 	for (std::list<std::vector<std::string> >::const_iterator itr = \
// 	this->recordKeyString_.begin(); itr != this->recordKeyString_.end(); \
// 	itr++) {
// 		for (std::vector<std::string>::const_iterator itr2 = (*itr).begin(); \
// 		itr2 != (*itr).end(); itr2++) {
// 			std::cout << itr2->first << ": " << itr2->second << std::endl;
// 		}
// 		std::cout << std::endl;
// 	}
// }
