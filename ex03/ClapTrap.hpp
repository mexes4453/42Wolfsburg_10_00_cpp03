/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:27 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/04 00:36:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# define COUT std::cout
# define ENDL std::endl
# define CLAPTRAP_MIN_LEVEL (0)

class ClapTrap
{
    protected:
        std::string     name;
        unsigned int    hit_points;
        unsigned int    energy_points;
        unsigned int    attack_damage;

    public:
        ClapTrap( void );                               // constructor - default 
        ClapTrap( std::string name );                   // constructor - parametric
        ClapTrap( ClapTrap const &other );              // constructor - copy
        ClapTrap &operator=( ClapTrap const &other );   // constructor - copy assign
        ~ClapTrap( void );                              // destructor
        void                attack(const std::string& target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
        unsigned int        getHitPoints( void );
        unsigned int        getEnergyPoints( void );
        unsigned int        getAttackDamage( void );
        std::string const   getName( void );
};

#endif // CLAPTRAP