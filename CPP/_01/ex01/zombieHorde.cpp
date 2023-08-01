#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie_list;

	zombie_list = new Zombie[N];
	for (int n = 0; n < N; n++)
		zombie_list[n].set_name(name);
	return (zombie_list);
}
