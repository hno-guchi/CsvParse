#ifndef CSV_HPP
# define CSV_HPP

#include <list>
#include <string>
#include <vector>

class Csv {
 private:
	 const std::string						fileName_;
	 const bool								isHeader_;
	 size_t									countField_;
	 std::vector<std::string>				header_;
	 std::list<std::vector<std::string> >	record_;

 public:
	 // CONSTRUCTOR
	 explicit Csv(const std::string& fileName \
			 = "data.csv", const bool isHeader = true);
	 // DESTRUCTOR
	 ~Csv();
	 void	getField(std::string* field, std::string* line);
// EXCEPTION
class FatalErr : public std::logic_error {
 public:
	 explicit FatalErr(const std::string& msg = "Fatal error.");
};
class ValidErr : public std::logic_error {
 public:
	 explicit ValidErr(const std::string& msg = "Validation error.");
};
};

#endif
