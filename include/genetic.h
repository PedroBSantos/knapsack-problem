#pragma once

#include <vector>
#include <ctime>
#include "item.h"

class Genetic
{
private:
	float capacity;
	int numberGenerations;
	int populationInitialLength;
	int genesNumber;
	float probReproduction;
	float probMutation;
	float probCrossover;
	std::vector<std::vector<Item>> population;
	float fitness(std::vector<Item>& items);
	int bestConfiguration();
	void crossover(std::vector<Item>& father, std::vector<Item>& mother, std::vector<Item>& son);
	void mutation(std::vector<Item>& individuo);
	void startPopulation(std::vector<Item>& items);
public:
	Genetic(std::vector<Item>& initialPopulation, float capacity);
	Genetic(const Genetic& genetic);
	~Genetic() = default;
	std::vector<Item> exec();
};