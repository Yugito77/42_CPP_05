/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:32:26 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/16 20:15:11 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class	Form
{

	public :

	Form();
	Form(std::string const name, int const grade_signe, int const grade_exec);
	Form(Form const& cpy);
	~Form();

	Form& operator=(Form const& cpy);
	virtual std::string	getName() const;
	virtual	bool		getSigne() const;
	virtual int			getGradeSigne() const;
	virtual int			getGradeExec() const;
	virtual	void		beSigned(Bureaucrat& obj);
	
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
	
	private :

	std::string const	s_name;
	bool				s_signe;
	int	const			s_grade_signe;
	int	const			s_grade_exec;

};

std::ostream&	operator<<(std::ostream& flux, Form const& cpy);

#endif