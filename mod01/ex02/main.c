	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory adress of string = " << &string << std::endl;
	std::cout << "Memory adress held by PTR = " << stringPTR << std::endl;
	std::cout << "Memory adress held by REF = " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Memory adress of string = " << &string << std::endl;
	std::cout << "Memory adress held by PTR = " << stringPTR << std::endl;
	std::cout << "Memory adress held by REF = " << &stringREF << std::endl;
