/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:56:22 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/14 21:27:26 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( void );                               // constructor - default 
        FragTrap( std::string name );                   // constructor - parametric
        FragTrap( FragTrap const &other );              // constructor - copy
        FragTrap &operator=( FragTrap const &other );   // constructor - copy assign
        ~FragTrap( void );                              // destructor
        void    attack(const std::string& target);
        void    highFiveGuys( void );
};



#endif // FRAGTRAP_HPP