/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:42:36 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/18 16:26:38 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define ROBOTOMY_RANK_SIGNE 72
#define ROBOTOMY_RANK_EXEC 45

class	RobotomyRequestForm : public Form
{

	public :
    
    RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& cpy);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm& operator=(RobotomyRequestForm const& cpy);
	std::string	getTarget() const;
	
	virtual void		execute(Bureaucrat const & executor) const;
	
    private :

    std::string s_target;
	static int		_i;
};


#endif