/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:48:11 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 17:44:12 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{

	{
		std::cout << std::endl;
		std::cout << "*******************************" << std::endl;
		std::cout << "Intern creates differents Forms" << std::endl;
		std::cout << "*******************************" << std::endl;
		std::cout << std::endl;

		{
			try
			{
				Intern		A;
				Form		*B;
				Bureaucrat	Bob("Bob", 1);

				B = A.makeForm("shruberry form", "Bob");
				B->beSigned(Bob);
				B->execute(Bob);
				std::cout << "Form = " << B->getName() << " Grade to sign = " << B->getGradeSigne() << std::endl;
				delete B;
				B = NULL;

				std::cout << std::endl;
				B = A.makeForm("presidential pardon", "Leo");
				B->beSigned(Bob);
				B->execute(Bob);
				std::cout << "Form = " << B->getName() << " Grade to sign = " << B->getGradeSigne() << std::endl;
				delete B;
				B = NULL;

				std::cout << std::endl;
				B = A.makeForm("robotomy request", "Leo");
				B->beSigned(Bob);
				B->execute(Bob);
				std::cout << "Form = " << B->getName() << " Grade to sign = " << B->getGradeSigne() << std::endl;
				delete B;
				B = NULL;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		{
			Intern		A;
			Form		*B;
			Bureaucrat	Bob("Bob", 1);
			try
			{
				std::cout << std::endl;
				B = A.makeForm("robotomy request", "");
				B->beSigned(Bob);
				B->execute(Bob);
				std::cout << "Form = " << B->getName() << " Grade to sign = " << B->getGradeSigne() << std::endl;
				delete B;
				B = NULL;
				std::cout << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		{
			Intern		A;
			Form		*B;
			Bureaucrat	Bob("Bob", 1);
			try
			{
				std::cout << std::endl;
				B = A.makeForm("robotomy request", "");
				B->beSigned(Bob);
				B->execute(Bob);
				std::cout << "Form = " << B->getName() << " Grade to sign = " << B->getGradeSigne() << std::endl;
				delete B;
				B = NULL;
				std::cout << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
	}

	return (0);
}