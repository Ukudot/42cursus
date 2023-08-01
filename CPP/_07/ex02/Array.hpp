/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:30:25 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 16:16:39 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <typename T>
class	Array
{
	private:
		T	*_array;
		int	_size;
	public:
		// funcitons
		Array(void);
		Array(int n);
		~Array(void);
		Array(Array const &obj);
		Array	&operator=(Array const &obj);
		T	&operator[](int pos);
		T const	&operator[](int pos) const;
		int	size(void) const;
	public:
		//class
		class	OutOfBoundsException: public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("index out of bounds");
			}
		};
};

template <typename T>
Array<T>::Array(void): _size(0), _array(0)
{
	return;
}

template <typename T>
Array<T>::Array(int n): _size(n)
{
	this->_array = new T[n];
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
}

template <typename T>
Array<T>::Array(Array<T> const &obj): _array(0), _size(0)
{
	*this = obj;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &obj)
{
	if (this == &obj)
		return (*this);
	this->_size = obj.size();
	delete [] this->_array;
	if (this->_size)
	{
		this->_array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = obj[i];
	}
	else
		this->_array = 0;
	return (*this);
}

template <typename T>
T		&Array<T>::operator[](int pos)
{
	if (pos >= this->_size || pos < 0)
		throw (Array<T>::OutOfBoundsException());
	return (this->_array[pos]);
}

template <typename T>
T const		&Array<T>::operator[](int pos) const
{
	if (pos >= this->_size || pos < 0)
		throw (Array<T>::OutOfBoundsException());
	return (this->_array[pos]);
}

template <typename T>
int		Array<T>::size(void) const
{
	return (this->_size);
}
#endif
