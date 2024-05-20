#pragma once

#include "Feline.h"

class Tiger : public Feline
{
public:
	std::string GetName() override;
	bool isAFish() override;
	bool isABird() override;
	bool isAMammal() override;
	int GetSpeed() override;
	
};