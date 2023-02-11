/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:56:22 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/11 15:45:33 by cudoh            ###   ########.fr       */
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
        virtual void    takeDamage(unsigned int amount);
        virtual void    beRepaired(unsigned int amount);
        void    highFiveGuys( void );
};



#endif // FRAGTRAP_HPP