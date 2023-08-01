#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->setName(name);
	std::cout << "DiamondTrap " << this->getName();
	std::cout << " default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj),
	ScavTrap(obj), FragTrap(obj)
{
	*this = obj;
	std::cout << "DiamondTrap " << this->getName();
	std::cout << " copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->getName();
	std::cout << " destructor called" << std::endl;
	return;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->setName(obj.getName());
	this->setHP(obj.getHP());
	this->setEP(obj.getEP());
	this->setAD(obj.getAD());
	return (*this);
}

void		DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name: " << this->getName() << std::endl;
	std::cout << "Clap name: " << ClapTrap::_name << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}

void		DiamondTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}
