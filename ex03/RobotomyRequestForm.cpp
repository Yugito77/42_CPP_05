/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:27 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:14:29 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int	RobotomyRequestForm::_i = 1;

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45), s_target("Unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45), s_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& cpy) :  Form(cpy)
{
    *this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*******************************************************************************************************/

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& cpy)
{
	if (this == &cpy)
		return (*this);
	this->Form::operator=(cpy);
	return (*this);
}

/*******************************************************************************************************/

std::string	RobotomyRequestForm::getTarget() const
{
	return(s_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
		std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << std::endl;
		if (_i % 2)
			std::cout << getTarget() << " has been robotomied" << std::endl;
		else
			std::cout << "Robotomy has failed" << std::endl;
		_i++;
	}
}