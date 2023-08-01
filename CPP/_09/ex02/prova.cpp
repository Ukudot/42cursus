#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int			binary_search(int start, int end, std::vector<int> v, int value);
std::vector<int>	binary_ins(std::vector<int> chain, std::vector<int> tmp, std::vector<int>::iterator ite);

int			binary_search(int start, int end, std::vector<int> v, int value)
{
	if (value == 66)
		std::cout << "start: " << start << " end: " << end << "v[..]: " << v[(end + start) / 2] << std::endl;
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

std::vector<int>	binary_ins(std::vector<int> chain, std::vector<int> tmp, std::vector<int> a_i, std::vector<int>::iterator ite)
{
	int	len;
	int	pow;
	int	pos;
	int	index;
	int	upper_bound;
	int	lower_bound;

	len = tmp.size();
	pow = 1;
	upper_bound = 1;
	lower_bound = upper_bound;
	upper_bound = (2 << pow++) - upper_bound;
	while (upper_bound < len - 1)
	{
		for (int i = upper_bound; i > lower_bound; i--)
		{
			ite = chain.begin();
			for (index = 0; a_i[i] != chain[index] && index < chain.size(); index++) ;
			if (index == chain.size())
				index--;
			pos = binary_search(0, index, chain, tmp[i]);
			if (tmp[i] > chain[pos])
				chain.insert(ite + pos + 1, tmp[i]);
			else
				chain.insert(ite + pos, tmp[i]);
		}
		lower_bound = upper_bound;
		upper_bound = (2 << pow++) - upper_bound;
	}
	//-----------
	std::cout << "-------------" << std::endl;
	std::cout << "chain in ins:" << std::endl;
	for (int i = 0; i < chain.size(); i++)
		std::cout << " " << chain[i];
	std::cout << std::endl;
	//-----------
	for (int i = upper_bound; i > lower_bound; i--)
	{
		if (i >= tmp.size())
			continue ;
		ite = chain.begin();
		for (index = 0; a_i[i] != chain[index] && index < chain.size(); index++) ;
		if (index == chain.size())
			index--;
		pos = binary_search(0, index, chain, tmp[i]);
		if (tmp[i] == 66)
			std::cout << "pos: " << pos << std::endl;
		if (tmp[i] > chain[pos])
			chain.insert(ite + pos + 1, tmp[i]);
		else
			chain.insert(ite + pos, tmp[i]);
		//-----------
		std::cout << "-------------" << std::endl;
		std::cout << "chain in ins:" << std::endl;
		for (int i = 0; i < chain.size(); i++)
			std::cout << " " << chain[i];
		std::cout << std::endl;
		//-----------
	}
	return (chain);
}

std::vector<int>	binary_ins_sort(std::vector<std::vector<int> > v, std::vector<int> odd)
{
	int				len;
	int				pos;
	std::vector<int>		tmp;
	std::vector<int>		chain;
	std::vector<int>		a_i;
	std::vector<int>::iterator	ite;

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
	for (int i = 1; i < v.size(); i++)
		chain.push_back(v[i][0]);
	//-----------
	std::cout << "-------------" << std::endl;
	std::cout << "chain:" << std::endl;
	for (int i = 0; i < chain.size(); i++)
		std::cout << " " << chain[i];
	std::cout << std::endl;
	//-----------
	a_i.push_back(0);
	for (int i = 0; i < v.size(); i++)
		a_i.push_back(v[i][0]);
	tmp.push_back(0);
	for (int i = 0; i < v.size(); i++)
		tmp.push_back(v[i][1]);
	if (!odd.empty())
		tmp.push_back(odd[0]);
	//-----------
	std::cout << "-------------" << std::endl;
	std::cout << "tmp:" << std::endl;
	for (int i = 0; i < tmp.size(); i++)
		std::cout << " " << tmp[i];
	std::cout << std::endl;
	//-----------
	chain = binary_ins(chain, tmp, a_i, ite);
	return (chain);
}

void	swap_elem(std::vector<std::vector<int> > &tmp, std::vector<int> v_2)
{
	std::vector<int>	elem;
	int			j;
	int			len;

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

std::vector<int>	sort(std::vector<int> v)
{
	int				len;
	std::vector<int>		odd;
	std::vector<int>		elem;
	std::vector<int>		v_2;
	std::vector<std::vector<int> >	tmp;

	len = v.size();
	if (len <= 1)
		return (v);
	if (len % 2 == 1)
	{
		odd.push_back(v.back());
		v.pop_back();
		len = v.size();
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (v[i] < v[i + len / 2])
		{
			elem.push_back(v[i + len / 2]);
			elem.push_back(v[i]);
			v_2.push_back(v[i + len / 2]);
		}
		else
		{
			elem.push_back(v[i]);
			elem.push_back(v[i + len / 2]);
			v_2.push_back(v[i]);
		}
		tmp.push_back(elem);
		elem.clear();
	}	
	v_2 = sort(v_2);
	swap_elem(tmp, v_2);
	v = binary_ins_sort(tmp, odd);
	//-----------
	std::cout << "-------------" << std::endl;
	std::cout << "v:" << std::endl;
	for (int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << std::endl;
	//-----------
	return (v);
}

int main (void) 
{
	int			myInt[] = {15, 80, 22, 63, 91, 3, 64, 44, 28, 70};
	std::vector<int>	v(myInt, myInt + 10);
	std::cout << "v:" << std::endl;
	for (int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << std::endl;
	v = sort(v);
	std::cout << "v:" << std::endl;
	for (int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << std::endl;
	return (0);
}
