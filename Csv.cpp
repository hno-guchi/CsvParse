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
	fileName_(fileName), isHeader_(isHeader) {
	std::ifstream	fd(this->fileName_);

	try {
		if (fd.eof() || fd.fail()) {
			throw Csv::FatalErr("Failed std::getline().");
		}
		std::string		line("");
		while (std::getline(fd, line, '\n')) {
			this->setRecord(&line);
		}
		if (!fd.eof() && fd.fail()) {
			throw Csv::FatalErr("Failed std::getline().");
		}
		if (this->isHeader_) {
			this->setHeader();
		}
		this->checkCountField();
	}
	catch (const std::exception& e) {
		fd.close();
		throw;
	}
	fd.close();
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

void	Csv::setRecord(std::string* line) {
	if (line->empty()) {
		return;
	}
	if (line->rfind(",") == (line->size() - 1)) {
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

void	Csv::setHeader() {
	try {
		this->header_ = this->records_.front();
		this->records_.pop_front();
	}
	catch (const std::exception& e) {
		throw;
	}
}

void	Csv::checkCountField() {
	size_t countField(0);

	if (this->isHeader_) {
		countField = this->header_.size();
	} else {
		countField = this->records_.front().size();
	}
	for (std::list<std::vector<std::string> >::const_iterator itr = \
	this->records_.begin(); itr != this->records_.end(); itr++) {
		if (countField != itr->size()) {
			throw Csv::ValidErr("Invalid csv format.");
		}
	}
}

// EXCEPTION
Csv::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
Csv::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

void	Csv::debugPrint() const {
	for (std::list<std::vector<std::string> >::const_iterator itr = \
	this->records_.begin(); itr != this->records_.end(); \
	itr++) {
		for (std::vector<std::string>::const_iterator itr2 = (*itr).begin(); \
		itr2 != (*itr).end(); itr2++) {
			std::cout << *itr2 << std::flush;
			if (itr2 + 1 != (*itr).end()) {
				std::cout << ",";
			}
		}
		std::cout << std::endl;
	}
}
