/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:13:19 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/06 18:34:53 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap( void ) 
: ClapTrap(), ScavTrap(), FragTrap()
{
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    COUT << "Call default constructor - DiamondTrap: " << name << ENDL;
}



DiamondTrap::DiamondTrap(std::string name, std::string _clapTrap_name)
: ClapTrap(_clapTrap_name), ScavTrap(), FragTrap()
{
    this->name = name;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    COUT << "Call parametric constructor - DiamondTrap: " << this->name << ENDL;
}



DiamondTrap::DiamondTrap( DiamondTrap const &other)
: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    
    *this = other;
    COUT << "Call copy constructor - DiamondTrap: " << this->name << ENDL;
}



DiamondTrap &DiamondTrap::operator=( DiamondTrap const &other )
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    COUT << "Call copy assignment constructor - DiamondTrap: " << this->name << ENDL;
    return (*this);    
}



DiamondTrap::~DiamondTrap( void )
{
    COUT << "Call destructor - DiamondTrap: " << name << ENDL;
}




void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}



void DiamondTrap::whoAmI( void )
{
    COUT << "DiamondTrap " << this->name << "; ClapTrap: " << ClapTrap::name << "\n";
}


