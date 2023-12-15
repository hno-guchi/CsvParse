#include <iostream>
#include <exception>

#include "./Csv.hpp"
#include "./color.hpp"

int	main(int argc, char *argv[]) {
	try {
		if (argc != 3) {
			Csv	csv("./test/001_ok_data.csv");
			csv.debugPrint();
		} else {
			if (argv[2][0] == '1') {
				Csv	csv(argv[1], true);
				csv.debugPrint();
			} else {
				Csv	csv(argv[1], false);
				csv.debugPrint();
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN << "Usage: ./csv [file] [1|0]" << END << std::endl;
	system("leaks -q csv");
}
