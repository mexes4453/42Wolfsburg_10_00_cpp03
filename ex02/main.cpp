/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:11:10 by cudoh             #+#    #+#             */
/*   Updated: 2023/02/11 14:56:59 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

# define SHW_TRAP_STATE(TRAPTYPE,TRAP_OBJ) \
    COUT << "TEST: "#TRAPTYPE" " <<  TRAP_OBJ.getName() << " has HP: " \
         << TRAP_OBJ.getHitPoints() << ",EP: " \
         << TRAP_OBJ.getEnergyPoints() << "\n\n" << ENDL;  \

int main (void)
{
    FragTrap f("frankfurt"); SHW_TRAP_STATE(FRAGTRAP,f);
    ScavTrap s("berlin"); SHW_TRAP_STATE(SCAVTRAP,s);
    
    COUT << ENDL;
    COUT << "\033[1;33mFragTrap attacks ScavTrap and causes damage\n\033[0m";
    f.attack(s.getName()); SHW_TRAP_STATE(FRAGTRAP,f);
    s.takeDamage(f.getAttackDamage()); SHW_TRAP_STATE(SCAVTRAP,s);
    

    COUT << "\033[1;33mFragTrap gets attacked and takes damage\n\033[0m";
    s.attack(f.getName());
    f.takeDamage(s.getAttackDamage()); SHW_TRAP_STATE(FRAGTRAP,f);


    COUT << "\033[1;33mFragTrap repairs self\n\033[0m";
    f.beRepaired(10); SHW_TRAP_STATE(FRAGTRAP,f);
    
    COUT << "\033[1;33mFragTrap uses special method\n\033[0m";
    f.highFiveGuys(); SHW_TRAP_STATE(FRAGTRAP,f);
    
    COUT << "\033[1;33m\nFragTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        s.attack(f.getName()); SHW_TRAP_STATE(SCAVTRAP,s);
        f.takeDamage(s.getAttackDamage()); SHW_TRAP_STATE(FRAGTRAP,f);
    }

    COUT << "\033[1;33m\nFragTrap is powerless and cannot attack anymore\n\033[0m";
    f.attack(s.getName()); SHW_TRAP_STATE(FRAGTRAP,f);

    COUT << "\033[1;33m\nFragTrap has no energy point, it can't repair self\n\033[0m";
    f.beRepaired(15); SHW_TRAP_STATE(FRAGTRAP,f);
    
    
    return (0);
}
