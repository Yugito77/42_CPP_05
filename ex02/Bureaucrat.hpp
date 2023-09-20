/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:49:28 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 15:59:59 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Form;

class	Bureaucrat
{
	public :

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& cpy);
	virtual ~Bureaucrat();
	
	virtual Bureaucrat&	operator=(Bureaucrat const& cpy);
	virtual std::string	getName() const;
	virtual int			getGrade() const;
	void increment();
	void decrement();
	void	signForm(Form& form);
	void	executeForm(Form const & form);
	
	class	GradeTooHighException : public std::exception
	{
		public :
		     virtual const char* what() const throw();
	};
	
	class	GradeTooLowException : public std::exception
	{
		public :
		     virtual const char* what() const throw();
	};

	protected :

	std::string s_name;
	int			s_grade;
};

std::ostream& operator<<(std::ostream& flux, Bureaucrat const& cpy);

#endif