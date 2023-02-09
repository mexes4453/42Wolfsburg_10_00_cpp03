/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:13:19 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/06 18:35:35 by cudoh            ###   ########.fr       */
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
    COUT << "ScavTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



void ScavTrap::takeDamage(unsigned int amount)
{
    if (hit_points == CLAPTRAP_MIN_LEVEL && (energy_points == CLAPTRAP_MIN_LEVEL))
    {
        COUT << "ScavTrap " << name << " is destroyed\n";
    }
    else if (hit_points == CLAPTRAP_MIN_LEVEL && (energy_points > CLAPTRAP_MIN_LEVEL))
    {
        energy_points--;
    }
    else
    {
        if (hit_points > amount)
        {
            hit_points -= amount;
        }
        else
        {
            hit_points = 0;
        }
        COUT << "ScavTrap " << name << " took " << amount << " amount of damage\n";
    }
    COUT << "ScavTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



void    ScavTrap::beRepaired(unsigned int amount)
{
    if (energy_points > CLAPTRAP_MIN_LEVEL)
    {
        energy_points--;
        hit_points += amount;
        COUT << "ScavTrap " << name << " repaired self by " << amount << " points\n";
    }
    else
    {
        COUT << "ScavTrap " << name << " cannot repair self." << ENDL;
    }
    COUT << "ScavTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}




void    ScavTrap::guardGate( void )
{
    COUT << "ScavTrap " << name << " is now in Gate Keeper mode\n";
}
