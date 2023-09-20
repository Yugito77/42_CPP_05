/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:48 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:14:31 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5), s_target("Unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential", 25, 5), s_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& cpy) :  Form(cpy)
{
    *this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*******************************************************************************************************/

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& cpy)
{
	if (this == &cpy)
		return (*this);
	this->Form::operator=(cpy);
	return (*this);
}

/*******************************************************************************************************/

std::string	PresidentialPardonForm::getTarget() const
{
	return(s_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeSigne())
	{
		throw Form::GradeTooLowException();
	}
	else if (!this->getSigne())
	{
		throw Form::FormNotSigned();
	}
	else
	{
		std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox." << std::endl;
	}
}