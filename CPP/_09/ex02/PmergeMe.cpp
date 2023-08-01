#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &pm)
{
	*this = pm;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &pm)
{
	if (this == &pm)
		return (*this);
	return (*this);
}

void		PmergeMe::checkInput(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		PmergeMe::allDigits(argv[i]);
		PmergeMe::checkBounds(argv[i]);
	}
}

void		PmergeMe::allDigits(std::string str)
{
	int	len;

	len = str.length();
	for (int i = 0; i < len; i++)
		if (!isdigit(str[i]))
			throw (PmergeMe::BadInputException());
}

void		PmergeMe::checkBounds(std::string str)
{
	if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
		throw (PmergeMe::BadInputException());
	if (atoi(str.c_str()) <= 0)
		throw (PmergeMe::BadInputException());
}

long		gettime(long time)
{
	struct	timeval t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000000 + t.tv_usec - time);
}

long		PmergeMe::pmergeVector(MyVector<int> &mv, int argc, char *argv[])
{
	typename MyVector<int>::iterator	ite_1;
	typename MyVector<int>::iterator	ite_2;
	clock_t 				t;

	t = clock();
	for (int i = 1; i < argc; i++)
		mv.push_back(atoi(argv[i]));
	mv.mergeInsSort();
	t = clock() - t;
	ite_1 = mv.begin();
	ite_2 = mv.begin();
	ite_2++;
	for (; ite_2 != mv.end(); ite_1++, ite_2++)
		if ( *ite_1 > *ite_2)
		{
			std::cout << "Vector isn't correctly sorted" << std::endl; 
			break ;
		}
	return (t);
}

long		PmergeMe::pmergeList(MyList<int> &ml, int argc, char *argv[])
{
	clock_t 			t;
	typename MyList<int>::iterator	ite_1;
	typename MyList<int>::iterator	ite_2;

	t = clock();
	for (int i = 1; i < argc; i++)
		ml.push_back(atoi(argv[i]));
	ml.mergeInsSort();
	t = clock() - t;
	ite_1 = ml.begin();
	ite_2 = ml.begin();
	ite_2++;
	for (; ite_2 != ml.end(); ite_1++, ite_2++)
	{
		if ( *ite_1 > *ite_2)
		{
			std::cout << "List isn't correctly sorted" << std::endl; 
			break ;
		}
	}
	return (t);
}
