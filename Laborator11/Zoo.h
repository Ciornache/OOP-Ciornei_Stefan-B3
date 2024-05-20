#pragma once

#include "Feline.h"
#include <vector>

class Zoo
{
	std::vector<Animal*> animals;
public:
	std::vector<Animal*> GetFishes();
	std::vector<Animal*> GetBirds();
	std::vector<Animal*> GetMammals();
	std::vector<Animal*> GetFelines();
	int GetTotalAnimals();
	void operator += (Animal* animal);
	bool operator ()(std::string name);
};