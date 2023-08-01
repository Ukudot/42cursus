#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << " turns into dirt." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
