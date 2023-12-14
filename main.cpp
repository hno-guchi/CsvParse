#include <iostream>
#include <exception>

#include "./Csv.hpp"

int	main() {
	try {
		Csv	csv("data.csv");
		csv.debugPrint();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
