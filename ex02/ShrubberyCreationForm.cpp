/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:10 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:14:17 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137), s_target("Unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", 145, 137), s_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cpy) :  Form(cpy)
{
    *this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*******************************************************************************************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& cpy)
{
	if (this == &cpy)
		return (*this);
	this->Form::operator=(cpy);
	return (*this);
}

/*******************************************************************************************************/

std::string	ShrubberyCreationForm::getTarget() const
{
	return(s_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
		std::ofstream fs;
		fs.open(ShrubberyCreationForm::getTarget().append("_shruberry").c_str());
		
		if (fs.fail())
		{
			std::cerr << "Error!" << std::endl;
			return ;
		}
		
		fs << "       _-_" << std::endl \
		<< "   /~~    ~~ \\" << std::endl \
		<< " /~~         ~~\\" << std::endl \
		<< "{               }" << std::endl \
		<< " \\  _-     -_  /" << std::endl \
		<< "   ~  \\ //  ~" << std::endl \
		<< "_- -   | | _- _" << std::endl \
		<< "  _ -  | |   -_" << std::endl \
		<< "      // \\\\" << std::endl;
		
		fs.close();

		std::cout << this->getName() << " file has been created" << std::endl;
	}
}