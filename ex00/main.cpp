/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/ by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

# define SHW_TRAP_STATE(TRAPTYPE,TRAP_OBJ) \
    COUT << "TEST: "#TRAPTYPE" " <<  TRAP_OBJ.getName() << " has HP: " \
         << TRAP_OBJ.getHitPoints() << ",EP: " \
         << TRAP_OBJ.getEnergyPoints() << "\n\n" << ENDL;  \

int main (void)
{
    ClapTrap b("berlin"); SHW_TRAP_STATE(CLAPTRAP,b);
    
    COUT << ENDL;
    COUT << "\033[1;33mClapTrap attacks\n\033[0m";
    b.attack("wolfsburg");
    SHW_TRAP_STATE(CLAPTRAP,b);
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(5);
    SHW_TRAP_STATE(CLAPTRAP,b);
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(5);
    SHW_TRAP_STATE(CLAPTRAP,b);
    
    COUT << "\033[1;33m\nClapTrap attacks\n\033[0m";
    b.attack("koln");
    SHW_TRAP_STATE(CLAPTRAP,b);

    COUT << "\033[1;33m\nClapTrap repairs self\n\033[0m";
    b.beRepaired(15);
    SHW_TRAP_STATE(CLAPTRAP,b);

    COUT << "\033[1;33m\nClapTrap attacks multiple times\n\033[0m";
    for (int x = 0; x < 10; x++)
    {
        b.attack("wolfsburg");
        SHW_TRAP_STATE(CLAPTRAP,b);
    }

    COUT << "\033[1;33m\nClapTrap is powerless and cannot attack again \n\033[0m";
    b.attack("koln");
    SHW_TRAP_STATE(CLAPTRAP,b);

    COUT << "\033[1;33m\nClapTrap is powerless and cannot repair self\n\033[0m";
    b.beRepaired(15);
    SHW_TRAP_STATE(CLAPTRAP,b);
    
    COUT << "\033[1;33m\nClapTrap takes damage\n\033[0m";
    b.takeDamage(15);
    SHW_TRAP_STATE(CLAPTRAP,b);

    COUT << "\033[1;33m\nClapTrap has no points cant take anymore damage\n\033[0m";
    b.takeDamage(1);
    SHW_TRAP_STATE(CLAPTRAP,b);
    COUT << b.getName() << ENDL;
    
    return (0);
}
