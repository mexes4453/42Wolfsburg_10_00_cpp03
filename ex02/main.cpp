/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/09 21:21:19 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
    FragTrap f("frankfurt");
    ScavTrap s("berlin");
    
    COUT << ENDL;
    COUT << "\033[1;33mFragTrap attacks ScavTrap and causes damage\n\033[0m";
    f.attack(s.getName());
    s.takeDamage(f.getAttackDamage());
    

    COUT << "\033[1;33mFragTrap gets attacked and takes damage\n\033[0m";
    s.attack(f.getName());
    f.takeDamage(s.getAttackDamage());


    COUT << "\033[1;33mFragTrap repairs self\n\033[0m";
    f.beRepaired(10);
    
    COUT << "\033[1;33mFragTrap uses special method\n\033[0m";
    f.highFiveGuys();
    
    COUT << "\033[1;33m\nFragTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        s.attack(f.getName());
        f.takeDamage(s.getAttackDamage());
    }

    COUT << "\033[1;33m\nFragTrap is powerless and cannot attack anymore\n\033[0m";
    f.attack(s.getName());

    COUT << "\033[1;33m\nFragTrap has no energy point, it can't repair self\n\033[0m";
    f.beRepaired(15);
    
    
    return (0);
}
