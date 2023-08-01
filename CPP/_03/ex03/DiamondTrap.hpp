#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap(void);
		DiamondTrap&	operator=(const DiamondTrap &obj);
		void		whoAmI(void);
		std::string	getName(void) const;
		void		setName(std::string);
		using		ScavTrap::attack;

	private:

		std::string	_name;
		using		FragTrap::_HP;
		using		ScavTrap::_EP;
		using		FragTrap::_AD;
};

#endif
