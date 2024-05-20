#include "Zoo.h"

std::vector<Animal*> Zoo::GetFishes()
{
	int nrFishes = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isAFish()) nrFishes++;
	std::vector<Animal*> fishes(nrFishes);
	int j = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isAFish()) fishes[j++] = animals[i];
	return fishes;
}

std::vector<Animal*> Zoo::GetBirds()
{
	int nrBirds = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isAFish()) nrBirds++;
	std::vector<Animal*> birds(nrBirds);
	int j = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isABird()) birds[j++] = animals[i];
	return birds;
}

std::vector<Animal*> Zoo::GetMammals()
{
	int nrMammals = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isAMammal()) nrMammals++;
	std::vector<Animal*> mammals(nrMammals);
	int j = 0;
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->isAMammal()) mammals[j++] = animals[i];
	return mammals;
}

std::vector<Animal*> Zoo::GetFelines()
{
	int nrFelines = 0;
	for (int i = 0; i < animals.size(); i++)
		if (dynamic_cast<Feline*>(animals[i]) != nullptr)
			nrFelines++;
	std::vector<Animal*> felines(nrFelines);
	int j = 0;
	std::cout << nrFelines << '\n';
	for (int i = 0; i < animals.size(); i++)
		if (dynamic_cast<Feline*>(animals[i]) != nullptr) 
			felines[j++] = animals[i];
	return felines;
}

int Zoo::GetTotalAnimals()
{
	return animals.size();
}

void Zoo::operator+=(Animal* animal)
{
	animals.push_back(animal);
}

bool Zoo::operator()(std::string name)
{
	for (int i = 0; i < animals.size(); i++)
		if (animals[i]->GetName() == name)
			return true;
	return false;
}
