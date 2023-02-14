/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:13:19 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/14 21:30:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



ScavTrap::ScavTrap( void ) : ClapTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    COUT << "Call default constructor - ScavTrap: " << name << ENDL;
}



ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    COUT << "Call parametric constructor - ScavTrap: " << this->name << ENDL;
}



ScavTrap::ScavTrap( ScavTrap const &other)
: ClapTrap(other)
{
    
    *this = other;
    COUT << "Call copy constructor - ScavTrap: " << this->name << ENDL;
}



ScavTrap &ScavTrap::operator=( ScavTrap const &other )
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    COUT << "Call copy assignment constructor - ScavTrap: " << this->name << ENDL;
    return (*this);    
}



ScavTrap::~ScavTrap( void )
{
    COUT << "Call destructor - ScavTrap: " << name << ENDL;
}





void    ScavTrap::attack(const std::string& target)
{
    if ( hit_points > CLAPTRAP_MIN_LEVEL && (energy_points > CLAPTRAP_MIN_LEVEL) )
    {
        COUT << "ScavTrap " << name << " attacks " << target << ", causing " \
             << attack_damage << " points of damage\n";
        energy_points--;
    }  
    else
    {
        COUT << "ScavTrap " << name << " can't attack " << target << ENDL;
    }
}



void    ScavTrap::guardGate( void )
{
    COUT << "ScavTrap " << name << " is now in Gate Keeper mode\n";
}
