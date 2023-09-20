/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:42:18 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:36 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class	Intern
{

	public :
    
    Intern();
    Intern(Intern const & cpy);
	virtual ~Intern();

	Intern& operator=(Intern const& cpy);

    Form*   makeForm(std::string formName, std::string formTarget);
    Form*   makeShrubbery(std::string formTarget);
    Form*   makeRobotomy(std::string formTarget);
    Form*   makePresidential(std::string formTarget);

    class	FormNotFound : public std::exception
	{
		public :
		     virtual const char* what() const throw();
	};
};


#endif