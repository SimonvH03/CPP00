#include "ScavTrap.hpp"
#include <iostream>

// Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "> ScavTrap Constructor called for " << name << '\n';
	HP = 100;
	Energy = 50;
	ATK = 20;
	guardState = false;
}

// Copy Constructor
ScavTrap::ScavTrap(ScavTrap const &original) : ClapTrap(original)
{
	std::cout	<< "> ScavTrap Copy Constructor called on " << original.Name << '\n';
	guardState = false;
}

// Assignment Operator Overload
ScavTrap& ScavTrap::operator=(ScavTrap const &original)
{
	std::cout	<< "> ScavTrap Assignment Operator called on " << original.Name << '\n';
	if (this != &original)
	{
		ClapTrap::operator=(original);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "> ScavTrap Destructor called for " << Name << '\n';
}

// ScavTrap's unique ability
void	ScavTrap::guardGate()
{
	guardState = !guardState;
	if (guardState)
		std::cout << Name << " is Guarding, incoming damage reduced\n";
	else
		std::cout << Name << " is no longer Guarding\n";
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (guardState)
	{
		ClapTrap::takeDamage(amount / 2);
		guardGate();
	}
	else
		ClapTrap::takeDamage(amount);
}

std::string	ScavTrap::status()
{
	std::string	status = ClapTrap::status();

	if (guardState)
		status += " G";
	return (status);
}