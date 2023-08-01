#include "ScalarConverter.hpp"

bool	ft_isnum(char *c_str)
{
	int	i;

	i = 0;
	while (c_str[i])
	{
		if (!isdigit(c_str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	std::string	str;

	if (argc < 2 || argc > 3)
	{
		std::cerr << "Usage error: ./converter <string> [precision]" << std::endl;
		return (1);
	}
	if (argc == 3 && !ft_isnum(argv[2]))
	{
		std::cerr << "Syntax error: precision must be a positive interger or zero" << std::endl;
		return (1);
	}
	str = argv[1];
	if (argc == 3)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(atoi(argv[2]));
	}
	ScalarConverter::convert(str);
	return (0);
}
