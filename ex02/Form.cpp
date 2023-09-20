/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:32:32 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 15:31:33 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : s_signe(0), s_grade_signe(0), s_grade_exec(0)
{
}

Form::Form(Form const& cpy) : s_name(cpy.s_name), s_signe(cpy.s_signe), s_grade_signe(cpy.s_grade_signe), s_grade_exec(cpy.s_grade_exec)
{

}

Form::Form(std::string const name, int const grade_signe, int const grade_exec) : s_name(name), s_signe(0), s_grade_signe(grade_signe), s_grade_exec(grade_exec)
{
	if (grade_signe < 1 || grade_exec < 1)
	{
        throw Form::GradeTooHighException();
	}
    else if (grade_signe > 150 || grade_exec > 150)
	{
        throw Form::GradeTooLowException();
	}
}


Form::~Form()
{
}

/*******************************************************************************************************/

Form& Form::operator=(Form const& cpy)
{
	if (this == &cpy)
		return (*this);
	s_signe = cpy.s_signe;
	return (*this);
}

std::ostream&	operator<<(std::ostream& flux, Form const& cpy)
{
	flux<<"The Form : "<<cpy.getName();
	if (cpy.getSigne()) 
		flux<<" is signed !";
	else
		flux<<" is not signed and require a grade of "<<cpy.getGradeSigne()<<" to be signed and a grade of "<<cpy.getGradeExec()<<" to be executed"<<std::endl;
	return (flux);
}

/*******************************************************************************************************/

std::string	Form::getName() const
{
	return (s_name);
}

bool	Form::getSigne() const
{
	return (s_signe);
}

int	Form::getGradeSigne() const
{
	return (s_grade_signe);
}

int	Form::getGradeExec() const
{
	return (s_grade_exec);
}

/*******************************************************************************************************/

void	Form::beSigned(Bureaucrat& obj)
{	
	if (obj.getGrade() > this->s_grade_signe)
	{
        throw Form::GradeTooLowException();
	}
	this->s_signe = 1;
	std::cout<<this->getName()<<" has been signed by "<<obj.getName()<<std::endl;
}

/***************************************************************************************/

const char*    Form::GradeTooHighException::what() const throw()
{
    return ("Le grade demande pour signer ou executer est trop haut.");
}

const char*    Form::GradeTooLowException::what() const throw()
{
    return ("Le grade demande pour signer ou executer est trop bas.");
}

const char*    Form::FormNotSigned::what() const throw()
{
    return ("Le Formulaire n'est pas signe.");
}