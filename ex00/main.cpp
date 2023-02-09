/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/09 22:01:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap b("berlin");
    
    COUT << ENDL;
    COUT << "\033[1;33mClapTrap attacks\n\033[0m";
    b.attack("wolfsburg");
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(5);
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(5);
    
    COUT << "\033[1;33m\nClapTrap attacks\n\033[0m";
    b.attack("koln");

    COUT << "\033[1;33m\nClapTrap repairs self\n\033[0m";
    b.beRepaired(15);

    COUT << "\033[1;33m\nClapTrap attacks multiple times\n\033[0m";
    for (int x = 0; x < 10; x++)
    {
        b.attack("wolfsburg");
    }

    COUT << "\033[1;33m\nClapTrap is powerless and cannot attack again \n\033[0m";
    b.attack("koln");

    COUT << "\033[1;33m\nClapTrap is powerless and cannot repair self\n\033[0m";
    b.beRepaired(15);
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(15);

    COUT << "\033[1;33m\nClapTrap has no points cant take anymore damage\n\033[0m";
    b.takeDamage(1);
    COUT << b.getName() << ENDL;
    
    return (0);
}
