/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:16 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:26:34 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

#define SHRUBBERY_RANK_SIGNE 145
#define SHRUBBERY_RANK_EXEC 137

class	ShrubberyCreationForm : public Form
{

	public :
    
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& cpy);
	virtual ~ShrubberyCreationForm();
    
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& cpy);
	std::string	getTarget() const;
   
    virtual void		execute(Bureaucrat const & executor) const;
	
    private :

    std::string s_target;
};


#endif