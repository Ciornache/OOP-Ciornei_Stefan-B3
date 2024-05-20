#pragma once

#include "Animal.h"

class Shark : public Animal
{
	std::string GetName() override;
	bool isAFish() override;
	bool isABird() override;
	bool isAMammal() override;
	
};