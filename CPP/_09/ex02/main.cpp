#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	long timeVector;
	long timeList;

	/*
	int		myint[] = {23, 1, 31, 42, 342, 31, 21};
	MyVector<int>	v(myint, myint + 6);

	std::cout << "Before v: " << v << std::endl;
	v.mergeSort();
	std::cout << "After v: " << v << std::endl;
	return (0);
	*/
	MyVector<int>	mv;
	MyList<int>	ml;

	if (argc == 1)
	{
		std::cout << "Error Usage: ./PmergeMe <n_1> [n_2] ..." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe::checkInput(argc, argv);
	}
	catch (std::exception const &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	std::cout << "Before:"; 
	for (int i = 1; i < argc; i++)
	{
		if (i == 11)
		{
			std::cout << " [...]";
			break ;
		}
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
	timeVector = PmergeMe::pmergeVector(mv, argc, argv);
	timeList = PmergeMe::pmergeList(ml, argc, argv);
	std::cout << "Vector After: " << mv << std::endl;
	std::cout << "List After: " << ml << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements ";
	std::cout << "with std::vector<int> : " << (double) timeVector / CLOCKS_PER_SEC * 1000000 << " \u03BCs" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements ";
	std::cout << "with std::list<int> : " << (double) timeList / CLOCKS_PER_SEC * 1000000 << " \u03BCs" << std::endl;
	return (0);
}
