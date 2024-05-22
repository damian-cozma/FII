#include <iostream>
#include "Zoo.h"
#include "Shark.h"
#include "Eagle.h"
#include "Lion.h"
#include "Tiger.h"
#include "Cow.h"
int main()
{
    Zoo z;
    z += new Shark();
    z += new Eagle();
    z += new Tiger();
    z += new Lion();
    z += new Cow();
    std::cout << "Total animals in zoo: " << z.GetTotalAnimals() << std::endl;
    for (auto a : z.GetFishes())
        std::cout << "Fish: " << a->GetName() << std::endl;
    for (auto a : z.GetBirds())
        std::cout << "Bird: " << a->GetName() << std::endl;
    for (auto a : z.GetMammals())
        std::cout << "Mammal: " << a->GetName() << std::endl;
    for (auto a : z.GetFelines())
        std::cout << "Feline: " << a->GetName() << ", speed: " << a->GetSpeed() << std::endl;
    std::cout << "Zoo contains a tiger  : " << std::boolalpha << z("Tiger") << std::endl;
    std::cout << "Zoo contains a monkey : " << std::boolalpha << z("Monkey") << std::endl;
    return 0;
}


