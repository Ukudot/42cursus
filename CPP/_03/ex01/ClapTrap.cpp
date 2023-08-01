#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _HP(100), _EP(50), _AD(20)
{
	std::cout << "ClapTrap "<< this->getName();
	std::cout <<" constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap "<< this->getName();
	std::cout <<" copy constructor called" << std::endl;
	*this = obj;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< this->getName();
	std::cout <<" destructor called" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->setName(obj.getName());
	this->setHP(obj.getHP());
	this->setEP(obj.getEP());
	this->setAD(obj.getAD());
	return (*this);
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

void			ClapTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}

int				ClapTrap::getHP(void) const
{
	return (this->_HP);
}

void			ClapTrap::setHP(int HP)
{
	this->_HP = HP;
	return ;
}

int				ClapTrap::getEP(void) const 
{
	return (this->_EP);
}

void			ClapTrap::setEP(int EP)
{
	this->_EP = EP;
	return ;
}

int				ClapTrap::getAD(void) const
{
	return (this->_AD);
}

void			ClapTrap::setAD(int AD)
{
	this->_AD = AD;
	return ;
}

void			ClapTrap::attack(const std::string &target)
{
	if (this->getEP() <= 0 || this->getHP() <= 0)
	{
		std::cout << "ClapTrap " << this->getName();
		std::cout << " hasn't energy left" << std::endl;
		return ;
	}
	this->setEP(this->getEP() - 1);
	std::cout << "ClapTrap " << this->getName();
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->getAD();
	std::cout << " points of damage!" << std::endl;
	return ;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	this->setHP(this->getHP() - amount);
	if (this->getHP() <= 0)
		std::cout << this->getName() << " has fainted!!!" << std::endl;
	return ;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEP() <= 0)
	{
		std::cout << "ClapTrap " << this->getName();
		std::cout << " hasn't energy left" << std::endl;
		return ;
	}
	this->setEP(this->getEP() - 1);
	this->setHP(this->getHP() + amount);
	return ;
}
