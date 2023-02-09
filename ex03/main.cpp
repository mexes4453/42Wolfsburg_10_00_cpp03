/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/09 20:19:3 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
    FragTrap f("frankfurt");
    DiamondTrap d("wolfsburg", "berlin");
    
    COUT << ENDL;
    COUT << "\033[1;33mDiamond attack using ScavTrap method\n\033[0m";
    d.attack(f.getName());
    f.takeDamage(d.getAttackDamage());
    
    COUT << "\033[1;33mDiamondTrap gets attacked and takes damage\n\033[0m";
    f.attack(d.getName());
    d.takeDamage(f.getAttackDamage());

    COUT << "\033[1;33mDiamondTrap repairs self\n\033[0m";
    d.beRepaired(10);

    COUT << "\033[1;33m\nDiamondTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        f.attack(d.getName());
        d.takeDamage(f.getAttackDamage());
    }

    COUT << "\033[1;33m\nDiamondTrap is powerless and cannot attack anymore\n\033[0m";
    d.attack(f.getName());

    COUT << "\033[1;33m\nDiamondTrap has no energy point, it can't repair self\n\033[0m";
    d.beRepaired(15);

    COUT << "\033[1;33m\nDiamond uses special function of ScavTrap (guardGate)\n\033[0m";
    d.guardGate();

    COUT << "\033[1;33m\nDiamond uses special function of DiamondTrap (highFive)\n\033[0m";
    d.highFiveGuys();


    COUT << "\033[1;33m\nDiamond uses its special function\n\033[0m";
    d.whoAmI();
    COUT << ENDL;
    
    return (0);
}
