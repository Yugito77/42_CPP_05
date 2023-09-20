/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:48:11 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/25 14:07:18 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	jeanMichel("Jean-Michel", 3);
		// Bureaucrat	jeanMichel("Jean-Michel", 1);  //test 1
		Bureaucrat	jeanPierre("Jean-Pierre", 98);
		Bureaucrat	jeanPascal("Jean-Pascal", 150);
		// Bureaucrat	jeanPascal("Jean-Pascal", 152);   //test 2


		std::cout << jeanMichel.getName() << " a l'echelon " << jeanMichel.getGrade() << std::endl;
		std::cout << jeanPierre.getName() << " a l'echelon " << jeanPierre.getGrade() << std::endl;
		std::cout << jeanPascal.getName() << " a l'echelon " << jeanPascal.getGrade() << std::endl;

		jeanMichel.increment();
		jeanMichel.increment();
		jeanPascal.decrement();
	
		std::cout << jeanMichel << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}