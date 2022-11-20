#include <string>
#include <sstream>
#include <iostream>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *zombies = zombieHorde(42, "test");

	for (int i = 0; i < 42; i++)
		zombies[i].announce();
	for(int i = 0; i < 42; i++)
	{
		std::ostringstream strstream;
		strstream << "test" << i;
		zombies[i].setName(strstream.str());
	}
	for (int i = 0; i < 42; i++)
		zombies[i].announce();

	delete [] zombies;
}
