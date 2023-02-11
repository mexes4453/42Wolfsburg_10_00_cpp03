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

# define SHW_TRAP_STATE(TRAPTYPE,TRAP_OBJ) \
    COUT << "TEST: "#TRAPTYPE" " <<  TRAP_OBJ.getName() << " has HP: " \
         << TRAP_OBJ.getHitPoints() << ",EP: " \
         << TRAP_OBJ.getEnergyPoints() << "\n\n" << ENDL;  \
        

int main (void)
{
    FragTrap f("frankfurt"); SHW_TRAP_STATE(FRAGTRAP,f);
    DiamondTrap d("wolfsburg", "berlin"); SHW_TRAP_STATE(DIAMONDTRAP,d);
    
    COUT << ENDL;
    COUT << "\033[1;33mDiamond attack using ScavTrap method\n\033[0m";
    d.attack(f.getName()); SHW_TRAP_STATE(DIAMONDTRAP,d);
    f.takeDamage(d.getAttackDamage()); SHW_TRAP_STATE(FRAGTRAP,f);
    
    COUT << "\033[1;33mDiamondTrap gets attacked and takes damage\n\033[0m";
    f.attack(d.getName()); SHW_TRAP_STATE(FRAGTRAP,f);
    d.takeDamage(f.getAttackDamage()); SHW_TRAP_STATE(DIAMONDTRAP,d);

    COUT << "\033[1;33mDiamondTrap repairs self\n\033[0m";
    d.beRepaired(10); SHW_TRAP_STATE(DIAMONDTRAP,d);

    COUT << "\033[1;33m\nDiamondTrap gets attacked multiple times\n\033[0m";
    for (int x = 0; x < 110; x++)
    {
        f.attack(d.getName()); SHW_TRAP_STATE(FRAGTRAP,f);
        d.takeDamage(f.getAttackDamage()); SHW_TRAP_STATE(DIAMONDTRAP,d);
    }

    COUT << "\033[1;33m\nDiamondTrap is powerless and cannot attack anymore\n\033[0m";
    d.attack(f.getName()); SHW_TRAP_STATE(DIAMONDTRAP,d);

    COUT << "\033[1;33m\nDiamondTrap has no energy point, it can't repair self\n\033[0m";
    d.beRepaired(15); SHW_TRAP_STATE(DIAMONDTRAP,d);

    COUT << "\033[1;33m\nDiamond uses special function of ScavTrap (guardGate)\n\033[0m";
    d.guardGate(); SHW_TRAP_STATE(DIAMONDTRAP,d);

    COUT << "\033[1;33m\nDiamond uses special function of DiamondTrap (highFive)\n\033[0m";
    d.highFiveGuys(); SHW_TRAP_STATE(DIAMONDTRAP,d);


    COUT << "\033[1;33m\nDiamond uses its special function\n\033[0m";
    d.whoAmI(); SHW_TRAP_STATE(DIAMONDTRAP,d);
    COUT << ENDL;
    
    return (0);
}
