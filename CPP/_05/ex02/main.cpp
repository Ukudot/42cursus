/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:22:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:02:26 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int	main(void)
{
	// scf tests
	Bureaucrat	robert("Robert", 15), james("James", 150), micheal("Micheal", 1);
	AForm		*scf;

	scf = new PresidentialPardonForm("Arthur");
	std::cout << "\033[1mSCF: " << *scf << "\033[0m" << std::endl;
	std::cout << "\033[1m" << robert.getName() << " tries to execute form " << scf->getName() << "\033[0m" << std::endl;
	robert.executeForm(*scf);
	std::cout << "\033[1m" << james.getName() << " tries to execute form " << scf->getName() << "\033[0m" << std::endl;
	james.executeForm(*scf);
	std::cout << "\033[1m" << robert.getName() << " tries to sign form " << scf->getName() << "\033[0m" << std::endl;
	robert.signForm(*scf);
	std::cout << "\033[1m" << james.getName() << " tries to execute form " << scf->getName() << "\033[0m" << std::endl;
	james.executeForm(*scf);
	std::cout << "\033[1m" << micheal.getName() << " tries to execute form " << scf->getName() << "\033[0m" << std::endl;
	micheal.executeForm(*scf);


	delete scf;
	return (0);
}
