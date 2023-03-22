#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, char *argv[]) {
	if (argc < 2)
		ScalarConverter::convert("");
	else
		ScalarConverter::convert(argv[1]);
}
