#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class	FragTrap: public virtual ClapTrap
{
	public:

		FragTrap(std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);
		FragTrap&	operator=(const FragTrap &obj);
		void		highFivesGuys(void);
};

#endif
