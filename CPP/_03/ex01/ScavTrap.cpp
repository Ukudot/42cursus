#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " copy constructor called" << std::endl;
	*this = obj;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " destructor called" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->setName(obj.getName());
	this->setHP(obj.getHP());
	this->setEP(obj.getEP());
	this->setAD(obj.getAD());
	return (*this);
}

void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Revolver mode" << std::endl;
	this->setAD(100);
	return ;
}
