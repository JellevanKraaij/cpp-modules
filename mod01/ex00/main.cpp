#include "Zombie.hpp"
void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main(void) {
    Zombie *zombie = newZombie("zombie heap");

    randomChump("zombie stack");

    zombie->announce();

    delete zombie;
}
