#pragma once

#include "Animal.h"

class Eagle : public Animal
{
public:
	std::string GetName() override;
	bool isAFish() override;
	bool isABird() override;
	bool isAMammal() override;
};