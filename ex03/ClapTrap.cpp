/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:24 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/06 18:34:28 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"



ClapTrap::ClapTrap( void ) 
: name(""), hit_points(10), energy_points(10), attack_damage(0)
{
    COUT << "Call default constructor - ClapTrap: " << name << ENDL;
}



ClapTrap::ClapTrap( std::string name ) 
: name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    COUT << "Call parametric constructor - ClapTrap: " << this->name << ENDL;
}



ClapTrap::ClapTrap( ClapTrap const &other)
{
    COUT << "Call copy constructor - ClapTrap: " << name << ENDL;
    *this = other;
}



ClapTrap &ClapTrap::operator=( ClapTrap const &other )
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    COUT << "Call copy assignment constructor - ClapTrap: " << this->name << ENDL;
    return (*this);    
}



ClapTrap::~ClapTrap( void )
{
    COUT << "Call destructor - ClapTrap: " << name << ENDL;
}


void    ClapTrap::attack(const std::string& target)
{
    if ( hit_points > CLAPTRAP_MIN_LEVEL && (energy_points > CLAPTRAP_MIN_LEVEL) )
    {
        COUT << "ClapTrap " << name << " attacks " << target << ", causing " \
             << attack_damage << " points of damage\n";
        energy_points--;
    }  
    else
    {
        COUT << "ClapTrap " << name << " can't attack " << target << ENDL;
        
    }
    COUT << "ClapTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == CLAPTRAP_MIN_LEVEL && (energy_points == CLAPTRAP_MIN_LEVEL))
    {
        COUT << "ClapTrap " << name << " is destroyed\n";
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
        COUT << "ClapTrap " << name << " took " << amount << " amount of damage\n";
    }
    COUT << "ClapTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > CLAPTRAP_MIN_LEVEL)
    {
        energy_points--;
        hit_points += amount;
        COUT << "ClapTrap " << name << " repaired self by " << amount << " points\n";
    }
    else
    {
        COUT << "ClapTrap " << name << " cannot repair self." << ENDL;
    }
    COUT << "ClapTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



unsigned int    ClapTrap::getHitPoints( void )
{
    return (hit_points);
}




unsigned int    ClapTrap::getEnergyPoints( void )
{
    return (energy_points);
}




unsigned int    ClapTrap::getAttackDamage( void )
{
    return (attack_damage);
}




std::string const   ClapTrap::getName( void )
{
    return (name);
}