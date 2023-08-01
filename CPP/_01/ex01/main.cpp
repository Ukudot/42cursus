#include "Zombie.hpp"
#include <stdlib.h>
int	main(int argc,char *argv[])
{
	Zombie	*zombies;
	int		N;

	if (argc != 2)
	{
		std::cout << "Usage error: ./horde [number of zombies]" << std::endl;
		return (1);
	}
	N = std::atoi(argv[1]);
	zombies = zombieHorde(N, "SS");
	for (int n = 0; n < N; n++)
		zombies[n].announce();
	delete [] zombies;
	return (0);
}
