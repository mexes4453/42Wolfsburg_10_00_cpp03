/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/11 16:17:52 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

# define SHW_TRAP_STATE(TRAPTYPE,TRAP_OBJ) \
    COUT << "TEST: "#TRAPTYPE" " <<  TRAP_OBJ.getName() << " has HP: " \
         << TRAP_OBJ.getHitPoints() << ",EP: " \
         << TRAP_OBJ.getEnergyPoints() << "\n\n" << ENDL;  \

int main (void)
{
    ClapTrap c("berlin"); SHW_TRAP_STATE(CLAPTRAP,c);
    ScavTrap s("wolfsburg"); SHW_TRAP_STATE(SCAVTRAP,s);
    
    COUT << ENDL;
    COUT << "\033[1;33mScavTrap is attacked and damaged\n\033[0m";
    c.attack(s.getName()); SHW_TRAP_STATE(CLAPTRAP,c);
    s.takeDamage(c.getAttackDamage()); SHW_TRAP_STATE(SCAVTRAP,s);
    s.takeDamage(15); SHW_TRAP_STATE(SCAVTRAP,s);
    

    COUT << "\033[1;33mScavTrap attacks and causes damage\n\033[0m";
    s.attack(c.getName()); SHW_TRAP_STATE(SCAVTRAP,s);
    c.takeDamage(s.getAttackDamage()); SHW_TRAP_STATE(CLAPTRAP,c);


    COUT << "\033[1;33mScavTrap repairs self\n\033[0m";
    s.beRepaired(5); SHW_TRAP_STATE(SCAVTRAP,s);
    
    COUT << "\033[1;33mScavTrap uses special method\n\033[0m";
    s.guardGate();
    
    COUT << "\033[1;33m\nScavTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        c.attack(s.getName()); SHW_TRAP_STATE(SCAVTRAP,c);
        s.takeDamage(20); SHW_TRAP_STATE(SCAVTRAP,s);
    }

    COUT << "\033[1;33m\nScavTrap is powerless and cannot attack anymore\n\033[0m";
    s.attack(c.getName()); SHW_TRAP_STATE(SCAVTRAP,s);

    COUT << "\033[1;33m\nScavTrap has no energy point, it can't repair self\n\033[0m";
    s.beRepaired(15); SHW_TRAP_STATE(SCAVTRAP,s);
    
    return (0);
}
