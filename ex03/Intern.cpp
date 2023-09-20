/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:42:27 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 17:46:10 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

/*******************************************************************************************/

Intern & Intern::operator=(Intern const & cpy)
{
	(void) cpy;
	return (*this);
}

/*******************************************************************************************/

Form*	Intern::makeShrubbery(std::string formTarget)
{
	Form	*form = new ShrubberyCreationForm(formTarget);
	return (form);
}

Form*	Intern::makeRobotomy(std::string formTarget)
{
	Form	*form = new RobotomyRequestForm(formTarget);
	return (form);
}

Form*	Intern::makePresidential(std::string formTarget)
{
	Form	*form = new PresidentialPardonForm(formTarget);
	return (form);
}

Form*	Intern::makeForm(std::string formName, std::string formTarget)
{
	Form	*form;

	Form	*(Intern::*ptr_fct[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
	std::string	names[3] = {"shruberry form", "robotomy request", "presidential pardon"};
	
	if (!formTarget.empty())
		throw Intern::FormNotFound();
	for(int i = 0; i < 3; i++)
	{
		if (!formName.compare(names[i]))
		{
			std::cout<<"Intern creates "<<formName<<std::endl;
			form = (this->*ptr_fct[i])(formTarget);
			return (form);
		}
	}
	throw Intern::FormNotFound();
	return (form);
}


/*******************************************************************************************/

const char*    Intern::FormNotFound::what() const throw()
{
    return ("Le Formulaire n'existe pas.");
}