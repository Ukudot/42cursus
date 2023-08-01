#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1, *z2, *z3;

	z1 = newZombie("Giovanni");
	z2 = newZombie("Alessandro");
	z3 = newZombie("Marco");
	randomChump("Andrea");
	randomChump("Dario");
	randomChump("Flavio");
	delete (z1);
	delete (z2);
	delete (z3);
	return (0);
}
