/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:56:22 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/14 21:29:36 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap( void );                               // constructor - default 
        ScavTrap( std::string name );                   // constructor - parametric
        ScavTrap( ScavTrap const &other );              // constructor - copy
        ScavTrap &operator=( ScavTrap const &other );   // constructor - copy assign
        ~ScavTrap( void );                              // destructor
        void                attack(const std::string& target);
        void guardGate( void );
};



#endif // SCAVTRAP_HPP