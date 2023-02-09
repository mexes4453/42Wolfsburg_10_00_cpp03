/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:13:19 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/06 18:33:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"



FragTrap::FragTrap( void ) : ClapTrap()
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    COUT << "Call default constructor - FragTrap: " << name << ENDL;
}



FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    COUT << "Call parametric constructor - FragTrap: " << this->name << ENDL;
}



FragTrap::FragTrap( FragTrap const &other)
: ClapTrap(other)
{
    
    *this = other;
    COUT << "Call copy constructor - FragTrap: " << this->name << ENDL;
}



FragTrap &FragTrap::operator=( FragTrap const &other )
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    COUT << "Call copy assignment constructor - FragTrap: " << this->name << ENDL;
    return (*this);    
}



FragTrap::~FragTrap( void )
{
    COUT << "Call destructor - FragTrap: " << name << ENDL;
}





void    FragTrap::attack(const std::string& target)
{
    if ( hit_points > CLAPTRAP_MIN_LEVEL && (energy_points > CLAPTRAP_MIN_LEVEL) )
    {
        COUT << "FragTrap " << name << " attacks " << target << ", causing " \
             << attack_damage << " points of damage\n";
        energy_points--;
    }  
    else
    {
        COUT << "FragTrap " << name << " can't attack " << target << ENDL;
        
    }
    COUT << "FragTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



void FragTrap::takeDamage(unsigned int amount)
{
    if (hit_points == CLAPTRAP_MIN_LEVEL && (energy_points == CLAPTRAP_MIN_LEVEL))
    {
        COUT << "FragTrap " << name << " is destroyed\n";
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
        COUT << "FragTrap " << name << " took " << amount << " amount of damage\n";
    }
    COUT << "FragTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}



void    FragTrap::beRepaired(unsigned int amount)
{
    if (energy_points > CLAPTRAP_MIN_LEVEL)
    {
        energy_points--;
        hit_points += amount;
        COUT << "FragTrap " << name << " repaired self by " << amount << " points\n";
    }
    else
    {
        COUT << "FragTrap " << name << " cannot repair self." << ENDL;
    }
    COUT << "FragTrap " << name << " has hp: " << hit_points \
            << ",ep: " << energy_points << "\n\n" << ENDL;
}




void    FragTrap::highFiveGuys( void )
{
    COUT << "FragTrap " << name << " requesting high five\n";
}
