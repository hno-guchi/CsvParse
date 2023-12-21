#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "./Csv.hpp"
#include "./color.hpp"

static void	setRecord(std::list<std::vector<std::string> >* records, \
		std::string* line);
static void	checkCountField(const size_t countField, \
		const std::list<std::vector<std::string> >& records);

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
			setRecord(&this->records_, &line);
		}
		if (!fd.eof() && fd.fail()) {
			throw Csv::FatalErr("Failed std::getline().");
		}
		if (this->isHeader_) {
			this->header_ = this->records_.front();
			this->records_.pop_front();
			checkCountField(this->header_.size(), this->records_);
		} else {
			checkCountField(this->records_.front().size(), this->records_);
		}
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

static void	getField(std::string* field, std::string* line) {
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

static void	setRecord(std::list<std::vector<std::string> >* records,
		std::string* line) {
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
		records->push_back(record);
	}
	catch (const std::exception& e) {
		throw;
	}
}

static void	checkCountField(const size_t countField, \
		const std::list<std::vector<std::string> >& records) {
	for (std::list<std::vector<std::string> >::const_iterator itr = \
	records.begin(); itr != records.end(); itr++) {
		if (countField != itr->size()) {
			throw Csv::ValidErr("Invalid csv format.");
		}
	}
}

// EXCEPTION
Csv::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
Csv::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

void	Csv::debugPrint() const {
	if (this->isHeader_) {
		for (std::vector<std::string>::const_iterator itr = this->header_.begin(); \
		itr != this->header_.end(); itr++) {
			std::cout << *itr << std::flush;
			if (itr + 1 != this->header_.end()) {
				std::cout << ",";
			}
		}
		std::cout << std::endl;
	}
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

