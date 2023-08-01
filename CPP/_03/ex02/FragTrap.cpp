#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << this->getName();
	std::cout << " constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	std::cout << "FragTrap " << this->getName();
	std::cout << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName();
	std::cout << " destructor called" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->setName(obj.getName());
	this->setHP(obj.getHP());
	this->setEP(obj.getEP());
	this->setAD(obj.getAD());
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName();
	std::cout << " ask for some beautiful high fives to others" << std::endl;
	return ;
}
