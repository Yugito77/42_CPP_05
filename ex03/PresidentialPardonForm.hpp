/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:43:26 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:26:40 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESDENTIALPARDONFORM_HPP
#define PRESDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define PRESDENTIAL_RANK_SIGNE 25
#define PRESDENTIAL_RANK_EXEC 5

class	PresidentialPardonForm : public Form
{

	public :

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& cpy);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(PresidentialPardonForm const& cpy);
	std::string	getTarget() const;
	
	virtual void		execute(Bureaucrat const & executor) const;
	
    private :

    std::string s_target;
};


#endif