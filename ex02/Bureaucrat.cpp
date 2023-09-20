/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:49:26 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:05:35 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : s_name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    s_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& cpy)
{
    *this = cpy;
}

Bureaucrat::~Bureaucrat()
{
}

/***************************************************************************************/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& cpy)
{
    if (this == &cpy)
        return (*this);
    s_name = cpy.s_name;
    s_grade = cpy.s_grade;
    return (*this);
}

std::ostream& operator<<(std::ostream& flux, Bureaucrat const& cpy)
{
    flux<<cpy.getName()<<" bureaucrat grade "<<cpy.getGrade()<<std::endl;
    return (flux);
}

/***************************************************************************************/

std::string	Bureaucrat::getName() const
{
    return (s_name);
}

int	Bureaucrat::getGrade() const
{
    return (s_grade);
}

void	Bureaucrat::increment()
{
    if ((s_grade - 1) < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
	s_grade -= 1;
}

void	Bureaucrat::decrement()
{

    if ((s_grade + 1) > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
	s_grade += 1;
}

void	Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (std::exception & e)
    {
		std::cerr << e.what() << std::endl;
        std::cout<<this->getName()<<" couldn’t sign "<<form.getName()<<" because the grade was too low..."<<std::endl;
    }
}

void	Bureaucrat::executeForm(Form const & form)
{
	try 
	{
		form.execute(*this);
	}
	catch (std::exception & e) 
	{
		std::cerr << e.what() << std::endl;
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because his grade is too low." << std::endl;
	}
}

/***************************************************************************************/

const char*    Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Le grade est trop haut...");
}

const char*    Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Le grade est trop bas...");
}
