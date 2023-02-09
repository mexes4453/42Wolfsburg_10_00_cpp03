/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/09 21:55:29 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
    ClapTrap c("berlin");
    ScavTrap s("wolfsburg");
    
    COUT << ENDL;
    COUT << "\033[1;33mScavTrap is attacked and damaged\n\033[0m";
    c.attack(s.getName());
    s.takeDamage(c.getAttackDamage());
    s.takeDamage(15);
    

    COUT << "\033[1;33mScavTrap attacks and causes damage\n\033[0m";
    s.attack(c.getName());
    c.takeDamage(s.getAttackDamage());


    COUT << "\033[1;33mScavTrap repairs self\n\033[0m";
    s.beRepaired(5);
    
    COUT << "\033[1;33mScavTrap uses special method\n\033[0m";
    s.guardGate();
    
    COUT << "\033[1;33m\nScavTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        c.attack(s.getName());
        s.takeDamage(20);
    }

    COUT << "\033[1;33m\nScavTrap is powerless and cannot attack anymore\n\033[0m";
    s.attack(c.getName());

    COUT << "\033[1;33m\nScavTrap has no energy point, it can't repair self\n\033[0m";
    s.beRepaired(15);
    
    return (0);
}
