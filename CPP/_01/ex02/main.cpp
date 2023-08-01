#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "\033[1mAdress of string: " << &str << "\033[0m" << std::endl;
	std::cout << "\033[1;31mAdress of stringPTR: " << &strPTR << "\033[0m" << std::endl;
	std::cout << "\033[1;34mAdress of stringREF: " << &strREF << "\033[0m" << std::endl;
	std::cout << "\033[1mValue of string: " << str << "\033[0m" << std::endl;
	std::cout << "\033[1;31mValue of stringPTR: " << strPTR << "\033[0m" << std::endl;
	std::cout << "\033[1;34mValue of stringREF: " << strREF << "\033[0m" << std::endl;
	
}
