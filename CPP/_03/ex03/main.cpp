#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	solid("Solid"), liquid("Liquid");

	solid.setAD(0);
	liquid.setAD(0);
	for (int i = 0; i < 9; i++)
	{
		solid.attack(liquid.getName());
		liquid.takeDamage(solid.getAD());
		liquid.attack(solid.getName());
		solid.takeDamage(liquid.getAD());
	}

	ScavTrap	ocelot("Ocelot");
	ocelot.guardGate();
	ocelot.attack(solid.getName());
	solid.takeDamage(ocelot.getAD());
	ocelot.attack(liquid.getName());
	liquid.takeDamage(ocelot.getAD());

	FragTrap	boss("The Boss");
	boss.highFivesGuys();
	for (int i = 0; i < 4; i++)
	{
		boss.attack(ocelot.getName());
		ocelot.takeDamage(boss.getAD());
	}

	DiamondTrap	bigBoss("Big Boss");
	bigBoss.whoAmI();
	DiamondTrap	venomSnake(bigBoss);
	std::cout << std::endl;
	std::cout << "Venom snake ask himself some questions" << std::endl;
	std::cout << std::endl;
	venomSnake.whoAmI();
	return (0);
}
