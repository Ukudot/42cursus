#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	solid("Solid"), liquid("Liquid");

	solid.setAD(1);
	liquid.setAD(1);
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	solid.takeDamage(liquid.getAD());
	
	solid.attack(liquid.getName());
	liquid.takeDamage(solid.getAD());
	liquid.attack(solid.getName());
	return (0);
}
