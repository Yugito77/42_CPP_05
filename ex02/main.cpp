/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:48:11 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/25 14:23:01 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Form	*myShrub = new ShrubberyCreationForm("FirstTarget");
	try
	{
		std::cout << " \e[0;33m****** creation des bureaucrats  ******\e[0m " << std::endl << std::endl;

		Bureaucrat	jeanMichel("Jean-Michel", 14);
		Bureaucrat	jeanPierre("Jean-Pierre", 10);
		Bureaucrat	jeanPascal("Jean-Pascal", 10);

		std::cout << " \e[0;33m****** creation des Shrubbery forms  ******\e[0m " << std::endl;
		std::cout << " \e[0;33m******  Target 1  ******\e[0m " << std::endl << std::endl;


		// ShrubberyCreationForm	myShrub("FirstTarget");
		myShrub->beSigned(jeanMichel); //test 1
		jeanMichel.signForm(*myShrub);
		myShrub->execute(jeanMichel);
		jeanMichel.executeForm(*myShrub);
		// delete (myShrub);
		
		std::cout << std::endl << " \e[0;33m******  Target 2  ******\e[0m " << std::endl << std::endl;


		RobotomyRequestForm		myRoboto("SecondTarget");
		myRoboto.beSigned(jeanMichel); //test 2
		myRoboto.execute(jeanMichel);
		myRoboto.execute(jeanPascal);  //test3

		std::cout << std::endl << " \e[0;33m******  Target 3  ******\e[0m " << std::endl << std::endl;


		PresidentialPardonForm	myPresidentialForm("ThirdTarget");
		myPresidentialForm.beSigned(jeanMichel); //test 4
		myPresidentialForm.execute(jeanMichel);
		myPresidentialForm.execute(jeanPascal);  //test 5

	}
	catch (std::exception & e) 
	{
		std::cerr << e.what() << std::endl;
	}
	delete (myShrub);
	return (0);
}