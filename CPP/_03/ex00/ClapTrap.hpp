#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

class ClapTrap
{
	public:

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &obj);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap &obj);
		std::string	getName(void) const;
		void		setName(std::string name);
		int			getHP(void) const;
		void		setHP(int HP);
		int			getEP(void) const;
		void		setEP(int EP);
		int			getAD(void) const;
		void		setAD(int AD);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		
	private:

		std::string	_name;
		int			_HP;
		int			_EP;
		int			_AD;
};

#endif
