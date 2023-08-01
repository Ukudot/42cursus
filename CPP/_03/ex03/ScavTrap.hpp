#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class	ScavTrap: public virtual ClapTrap
{
	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap &obj);
		void		guardGate(void);
};

#endif
