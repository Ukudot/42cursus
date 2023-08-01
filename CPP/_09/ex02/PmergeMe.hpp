#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <string>
# include <exception>
# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

template <typename T>
class	MyVector: public std::vector<T>
{
	public:
		// constructors and destructor
		MyVector(void);						// default constructor
		template <class InputIterator>
		MyVector(InputIterator begin, InputIterator end);	// range constructor
		MyVector(MyVector const &mv);				// copy constructor
		~MyVector(void);					// destructor
		// operator overloads
		MyVector	&operator=(MyVector const &mv);
		// public functions
		void		mergeInsSort(void);
		void		mergeSort(void);

	private:
		// private variables
		std::vector<T>	_tmp;
		// private functions
		int		binary_search(int start, int end, MyVector v, T value);
		MyVector	binary_ins(MyVector chain, MyVector b_i, MyVector a_i, typename MyVector::iterator ite);
		MyVector	binary_ins_sort(MyVector<MyVector> v, MyVector odd);
		void		swap_elem(MyVector<MyVector> &tmp, MyVector v_2);
		void		merge(unsigned int start, unsigned int end);
		void		mySort(unsigned int ls, unsigned int le, unsigned int rs, unsigned int re);
};

template <typename T>
MyVector<T>::MyVector(void): std::vector<T>()
{
	return ;
}

template <typename T>
template <class InputIterator>
MyVector<T>::MyVector(InputIterator begin, InputIterator end): std::vector<T>(begin, end)
{
	return ;
}

template <typename T>
MyVector<T>::MyVector(MyVector<T> const &mv): std::vector<T>(mv)
{
	return ;
}

template <typename T>
MyVector<T>::~MyVector(void)
{
	return ;
}

template <typename T>
MyVector<T>	&MyVector<T>::operator=(MyVector<T> const &mv)
{
	unsigned long	len;

	if (this == &mv)
		return (*this);
	len = mv.size();
	this->resize(len);
	for (unsigned long i = 0; i < len; i++)
		this->at(i) = mv[i];
	return (*this);
}

template <typename T>
std::ostream	&operator<<(std::ostream &os, MyVector<T> &mv)
{
	typename MyVector<T>::iterator	first, last;

	first = mv.begin();
	last = mv.end();
	for (int i = 0; first != last; first++, i++)
	{
		os << " " << *first;
		if (i == 10)
		{
			os << " [...]";
			break ;
		}
	}
	return (os);
}

template <typename T>
void		MyVector<T>::mergeSort(void)
{
	unsigned int	start;
	unsigned int	end;

	if (this->size() == 0)
		return ;
	start = 0;
	end = this->size() - 1;
	this->merge(start, end);
}

template <typename T>
void		MyVector<T>::merge(unsigned int start, unsigned int end)
{
	unsigned int	ls, le, rs, re;

	if (start == end)
		return ;
	ls = start;
	le = (end + start) / 2;
	rs = le + 1;
	re = end;
	this->merge(ls, le);
	this->merge(rs, re);
	this->mySort(ls, le, rs, re);
}

template <typename T>
void		MyVector<T>::mySort(unsigned int ls, unsigned int le, unsigned int rs, unsigned int re)
{
	unsigned int start, end;

	this->_tmp.clear();
	start = ls;
	end = re;
	while (ls <= le && rs <= re)
	{
		if (this->at(ls) <= this->at(rs))
			this->_tmp.push_back(this->at(ls++));
		else
			this->_tmp.push_back(this->at(rs++));
	}
	while (ls <= le)
		this->_tmp.push_back(this->at(ls++));
	while (rs <= re)
		this->_tmp.push_back(this->at(rs++));
	for (int i = 0; start <= end; i++, start++)
		this->at(start) = this->_tmp[i];
}

template <typename T>
int		MyVector<T>::binary_search(int start, int end, MyVector<T> v, T value)
{
	if (start == end)
		return (start);
	else if (value > v[(end + start) / 2])
		return (binary_search((end + start) / 2 + 1, end, v, value));
	else
	{
		if ((end + start) / 2 == start)
			return (start);
		else
			return (binary_search(start, ((end + start) / 2 - 1), v, value));
	}
}

template <typename T>
MyVector<T>	MyVector<T>::binary_ins(MyVector<T> chain, MyVector<T> b_i, MyVector<T> a_i, typename MyVector<T>::iterator ite)
{
	int	len;
	int	pow;
	int	pos;
	int	index;
	int	upper_bound;
	int	lower_bound;

	len = b_i.size();
	pow = 1;
	upper_bound = 1;
	lower_bound = upper_bound;
	upper_bound = (2 << pow++) - upper_bound;
	while (upper_bound < len - 1)
	{
		for (int i = upper_bound; i > lower_bound; i--)
		{
			ite = chain.begin();
			for (index = 0; a_i[i] != chain[index] && (unsigned int) index < chain.size() - 1; index++) ;
			pos = binary_search(0, index, chain, b_i[i]);
			if (b_i[i] > chain[pos])
				chain.insert(ite + pos + 1, b_i[i]);
			else
				chain.insert(ite + pos, b_i[i]);
		}
		lower_bound = upper_bound;
		upper_bound = (2 << pow++) - upper_bound;
	}
	for (int i = upper_bound; i > lower_bound; i--)
	{
		if (static_cast<unsigned int>(i) >= b_i.size())
			continue ;
		ite = chain.begin();
		for (index = 0; a_i[i] != chain[index] && (unsigned int) index < chain.size() - 1; index++) ;
		pos = binary_search(0, index, chain, b_i[i]);
		if (b_i[i] > chain[pos])
			chain.insert(ite + pos + 1, b_i[i]);
		else
			chain.insert(ite + pos, b_i[i]);
	}
	return (chain);
}

template <typename T>
MyVector<T>	MyVector<T>::binary_ins_sort(MyVector<MyVector<T> > v, MyVector<T> odd)
{
	int				len;
	int				pos;
	MyVector<T>			b_i;
	MyVector<T>			a_i;
	MyVector<T>			chain;
	typename MyVector<T>::iterator	ite;

	len = v.size() * 2 + odd.size();
	chain.push_back(v[0][1]);
	chain.push_back(v[0][0]);
	ite = chain.begin();
	if (len == 2)
		return (chain);
	else if (len == 3)
	{
		pos = binary_search(0, 1, chain, odd[0]);
		if (odd[0] > chain[pos])
			chain.insert(ite + pos + 1, odd[0]);
		else
			chain.insert(ite + pos, odd[0]);
		return (chain);
	}
	for (unsigned long i = 1; i < v.size(); i++)
		chain.push_back(v[i][0]);
	a_i.push_back(0);
	for (unsigned long i = 0; i < v.size(); i++)
		a_i.push_back(v[i][0]);
	b_i.push_back(0);
	for (unsigned long i = 0; i < v.size(); i++)
		b_i.push_back(v[i][1]);
	if (!odd.empty())
		b_i.push_back(odd[0]);
	chain = binary_ins(chain, b_i, a_i, ite);
	return (chain);
}

template <typename T>
void		MyVector<T>::swap_elem(MyVector<MyVector<T> > &tmp, MyVector<T> v_2)
{
	MyVector<T>	elem;
	int		j;
	int		len;

	len = v_2.size();
	for (int i = 0; i < len; i++)
	{
		for (j = 0; tmp[j][0] != v_2[i]; j++) ;
		if (j == i)
			continue ;
		elem = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = elem;
	}
}

template <typename T>
void		MyVector<T>::mergeInsSort(void)
{
	int			len;
	MyVector<T>		odd;
	MyVector<T>		elem;
	MyVector<T>		v_2;
	MyVector<MyVector<T> >	tmp;

	len = this->size();
	if (len <= 1)
		return ;
	if (len % 2 == 1)
	{
		odd.push_back(this->back());
		this->pop_back();
		len = this->size();
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (this->at(i) < this->at(i + len / 2))
		{
			elem.push_back(this->at(i + len / 2));
			elem.push_back(this->at(i));
			v_2.push_back(this->at(i + len / 2));
		}
		else
		{
			elem.push_back(this->at(i));
			elem.push_back(this->at(i + len / 2));
			v_2.push_back(this->at(i));
		}
		tmp.push_back(elem);
		elem.clear();
	}	
	v_2.mergeInsSort();
	swap_elem(tmp, v_2);
	*this = binary_ins_sort(tmp, odd);
}

template <typename T>
class	MyList: public std::list<T>
{
	public:
		// constructors and destructor
		MyList(void);					// default constructor
		template <class InputIterator>
		MyList(InputIterator begin, InputIterator end);	// range constructor
		MyList(MyList const &ml);			// copy constructor
		~MyList(void);					// destructor
		// operator overloads
		MyList	&operator=(MyList const &ml);
		// public functions
		void		mergeSort(void);
		void		mergeInsSort(void);

	private:
		// private variables
		std::list<T>	_tmp;
		// private functions
		int		binary_search(int start, int end, MyList l, T value);
		MyList		binary_ins(MyList chain, MyList b_i, MyList a_i, typename MyList::iterator iteChain);
		MyList		binary_ins_sort(MyList<MyList> l, MyList odd);
		void		swap_elem(MyList<MyList> &tmp, MyList l_2);
		void		merge(unsigned int start, unsigned int end);
		void		mySort(unsigned int ls, unsigned int le, unsigned int rs, unsigned int re);
};

template <typename T>
MyList<T>::MyList(void): std::list<T>()
{
	return ;
}

template <typename T>
template <class InputIterator>
MyList<T>::MyList(InputIterator begin, InputIterator end): std::list<T>(begin, end)
{
	return ;
}

template <typename T>
MyList<T>::MyList(MyList<T> const &ml): std::list<T>(ml)
{
	return ;
}

template <typename T>
MyList<T>::~MyList(void)
{
	return ;
}

template <typename T>
MyList<T>	&MyList<T>::operator=(MyList<T> const &ml)
{
	if (this == &ml)
		return (*this);
	this->assign(ml.begin(), ml.end());
	return (*this);
}

template <typename T>
std::ostream	&operator<<(std::ostream &os, MyList<T> &ml)
{
	typename MyList<T>::iterator	first, last;

	first = ml.begin();
	last = ml.end();
	for (int i = 0; first != last; first++, i++)
	{
		os << " " << *first;
		if (i == 10)
		{
			os << " [...]";
			break ;
		}
	}
	return (os);
}

template <typename T>
void		MyList<T>::mergeSort(void)
{
	unsigned int	start;
	unsigned int	end;

	if (this->size() == 0)
		return ;
	start = 0;
	end = this->size() - 1;
	this->merge(start, end);
}

template <typename T>
void		MyList<T>::merge(unsigned int start, unsigned int end)
{
	unsigned int	ls, le, rs, re;

	if (start == end)
		return ;
	ls = start;
	le = (end + start) / 2;
	rs = le + 1;
	re = end;
	this->merge(ls, le);
	this->merge(rs, re);
	this->mySort(ls, le, rs, re);
}

template <typename T>
void		MyList<T>::mySort(unsigned int ls, unsigned int le, unsigned int rs, unsigned int re)
{
	typename MyList<T>::iterator start, end, ils, ile, irs, ire;

	this->_tmp.clear();
	start = this->begin();
	end = this->begin();
	ils = this->begin();
	ile = this->begin();
	irs = this->begin();
	ire = this->begin();
	std::advance(start, ls);
	std::advance(end, re + 1);
	std::advance(ils, ls);
	std::advance(ile, le + 1);
	std::advance(irs, rs);
	std::advance(ire, re + 1);
	while (std::distance(ils, ile) > 0 && std::distance(irs, ire) > 0)
	{
		if (*ils <= *irs)
			this->_tmp.push_back(*(ils++));
		else
			this->_tmp.push_back(*(irs++));
	}
	while (std::distance(ils, ile) > 0)
		this->_tmp.push_back(*(ils++));
	while (std::distance(irs, ire) > 0)
		this->_tmp.push_back(*(irs++));
	for (typename MyList<T>::iterator ite = this->_tmp.begin(); std::distance(start, end) > 0; ite++, start++)
		*start = *ite;
}

template <typename T>
int		MyList<T>::binary_search(int start, int end, MyList<T> l, T value)
{
	typename MyList<T>::iterator	iteList;

	iteList = l.begin();
	std::advance(iteList, (end + start) / 2);
	if (start == end)
		return (start);
	else if (value > *iteList)
		return (binary_search((end + start) / 2 + 1, end, l, value));
	else
	{
		if ((end + start) / 2 == start)
			return (start);
		else
			return (binary_search(start, ((end + start) / 2 - 1), l, value));
	}
}

template <typename T>
MyList<T>	MyList<T>::binary_ins(MyList<T> chain, MyList<T> b_i, MyList<T> a_i, typename MyList<T>::iterator iteChain)
{
	int				len;
	int				pow;
	int				pos;
	int				index;
	int				upper_bound;
	int				lower_bound;
	typename MyList<T>::iterator	iteTmp;

	len = b_i.size();
	pow = 1;
	upper_bound = 1;
	lower_bound = upper_bound;
	upper_bound = (2 << pow++) - upper_bound;
	while (upper_bound < len - 1)
	{
		for (int i = upper_bound; i > lower_bound; i--)
		{
			iteChain = chain.begin();
			iteTmp = a_i.begin();
			std::advance(iteTmp, i);
			for (index = 0; *iteTmp != *iteChain && (unsigned int) index < chain.size() - 1; iteChain++, index++) ;
			iteChain = chain.begin();
			iteTmp = b_i.begin();
			std::advance(iteTmp, i);
			pos = binary_search(0, index, chain, *iteTmp);
			std::advance(iteChain, pos);
			if (*iteTmp > *iteChain)
			{
				std::advance(iteChain, 1);
				chain.insert(iteChain, *iteTmp);
			}
			else
				chain.insert(iteChain, *iteTmp);
		}
		lower_bound = upper_bound;
		upper_bound = (2 << pow++) - upper_bound;
	}
	for (int i = upper_bound; i > lower_bound; i--)
	{
		if (static_cast<unsigned int>(i) >= b_i.size())
			continue ;
		iteChain = chain.begin();
		iteTmp = a_i.begin();
		std::advance(iteTmp, i);
		for (index = 0; *iteTmp != *iteChain && (unsigned int) index < chain.size() - 1; iteChain++, index++) ;
		iteChain = chain.begin();
		iteTmp = b_i.begin();
		std::advance(iteTmp, i);
		pos = binary_search(0, index, chain, *iteTmp);
		std::advance(iteChain, pos);
		if (*iteTmp > *iteChain)
		{
			std::advance(iteChain, 1);
			chain.insert(iteChain, *iteTmp);
		}
		else
			chain.insert(iteChain, *iteTmp);
	}
	return (chain);
}

template <typename T>
MyList<T>	MyList<T>::binary_ins_sort(MyList<MyList<T> > l, MyList<T> odd)
{
	int					len;
	int					pos;
	MyList<T>				b_i;
	MyList<T>				a_i;
	MyList<T>				chain;
	typename MyList<T>::iterator		iteChain;
	typename MyList<MyList<T> >::iterator	iteList;

	len = l.size() * 2 + odd.size();
	iteList = l.begin();
	chain.push_back((*iteList).back());
	chain.push_back((*iteList).front());
	iteChain = chain.begin();
	if (len == 2)
		return (chain);
	else if (len == 3)
	{
		pos = binary_search(0, 1, chain, odd.front());
		std::advance(iteChain, pos);
		if (odd.front() > *iteChain)
		{
			std::advance(iteChain, 1);
			chain.insert(iteChain, odd.front());
		}
		else
			chain.insert(iteChain, odd.front());
		return (chain);
	}
	iteList++;
	for (; iteList != l.end(); iteList++)
		chain.push_back((*iteList).front());
	iteList = l.begin();
	a_i.push_back(0);
	for (; iteList != l.end(); iteList++)
		a_i.push_back((*iteList).back());
	iteList = l.begin();
	b_i.push_back(0);
	for (; iteList != l.end(); iteList++)
		b_i.push_back((*iteList).back());
	if (!odd.empty())
		b_i.push_back(odd.front());
	chain = binary_ins(chain, b_i, a_i, iteChain);
	return (chain);
}

template <typename T>
void		MyList<T>::swap_elem(MyList<MyList<T> > &tmp, MyList<T> l_2)
{
	MyList<T>				elem;
	int					j;
	int					len;
	typename MyList<MyList<T> >::iterator	iteTmp_1;
	typename MyList<MyList<T> >::iterator	iteTmp_2;
	typename MyList<T>::iterator		iteList;

	len = l_2.size();
	iteList = l_2.begin();
	for (int i = 0; i < len; i++)
	{
		iteTmp_1 = tmp.begin();
		iteTmp_2 = tmp.begin();
		for (j = 0; (*iteTmp_1).front() != *iteList; j++) 
			iteTmp_1++;
		iteList++;
		if (j == i)
			continue ;
		std::advance(iteTmp_2, i);
		elem = *iteTmp_2;
		*iteTmp_2 = *iteTmp_1;
		*iteTmp_1 = elem;
	}
}

template <typename T>
void		MyList<T>::mergeInsSort(void)
{
	int				len;
	MyList<T>			odd;
	MyList<T>			elem;
	MyList<T>			l_2;
	MyList<MyList<T> >		tmp;
	typename MyList<T>::iterator	ite_1;
	typename MyList<T>::iterator	ite_2;

	len = this->size();
	if (len <= 1)
		return ;
	if (len % 2 == 1)
	{
		odd.push_back(this->back());
		this->pop_back();
		len = this->size();
	}
	for (int i = 0; i < len / 2; i++)
	{
		ite_1 = this->begin();
		ite_2 = this->begin();
		std::advance(ite_1, i);
		std::advance(ite_2, i + len / 2);
		if (*ite_1 < *ite_2)
		{
			elem.push_back(*ite_2);
			elem.push_back(*ite_1);
			l_2.push_back(*ite_2);
		}
		else
		{
			elem.push_back(*ite_1);
			elem.push_back(*ite_2);
			l_2.push_back(*ite_1);
		}
		tmp.push_back(elem);
		elem.clear();
	}	
	l_2.mergeInsSort();
	swap_elem(tmp, l_2);
	*this = binary_ins_sort(tmp, odd);
}

// static class
class	PmergeMe
{
	public:
		// functions
		static void		checkInput(int argc, char *argv[]);
		static long		pmergeVector(MyVector<int> &mv, int argc, char *argv[]);
		static long		pmergeList(MyList<int> &ml, int argc, char *argv[]);
		// exception classes
		class	BadInputException: public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("bad input");
			}
		};

	private:
		// constructors and destructor
		PmergeMe(void);			// default constructor
		PmergeMe(PmergeMe const &pm);	// copy consttructor
		~PmergeMe(void);		// destructor
		// operator overloads 
		PmergeMe		&operator=(PmergeMe const &pm);
		// private functions
		static void		allDigits(std::string str);
		static void		checkBounds(std::string str);
};

#endif
