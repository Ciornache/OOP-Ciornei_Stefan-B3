#pragma once


#include "Feline.h"

class Lion : public Feline
{
public:
	std::string GetName() override;
	bool isAFish() override;
	bool isABird() override;
	bool isAMammal() override;
	int GetSpeed() override;
};