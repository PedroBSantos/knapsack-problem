#include "../include/genetic.h"

Genetic::Genetic(std::vector<Item>& initialPopulation, float capacity)
	: capacity(capacity), numberGenerations(5), populationInitialLength(10),
	genesNumber(signed(initialPopulation.size())), probReproduction(0.2f), probMutation(0.3f), probCrossover(0.7f)
{
	this->startPopulation(initialPopulation);
}

Genetic::Genetic(const Genetic& genetic) : capacity(genetic.capacity), numberGenerations(genetic.numberGenerations),
populationInitialLength(genetic.populationInitialLength), genesNumber(genetic.genesNumber), probCrossover(genetic.probCrossover),
probMutation(genetic.probMutation), probReproduction(genetic.probReproduction) {}

void Genetic::startPopulation(std::vector<Item>& items)
{
	int aux1 = 0;
	for (int i = 0; i < this->populationInitialLength; i++)
	{
		std::vector<Item> aux2;
		for (Item item : items)
		{
			aux1 = rand() % 2;
			item.setBelongsKnackpack((bool)aux1);
			aux2.push_back(item);
		}
		this->population.push_back(aux2);
	}
}

float Genetic::fitness(std::vector<Item>& items)
{
	float totalWeight = 0.0f;
	float totalUtilitValue = 0.0f;
	for (int i = 0; i < this->genesNumber; i++)
	{
		if (items[i].getBelongsKnackpack())
		{
			totalWeight += items[i].getWeight();
			totalUtilitValue += items[i].getUtilitValue();
		}
	}
	if (totalWeight > this->capacity)
	{
		return 0.0f;
	}
	return totalWeight + totalUtilitValue;
}

int Genetic::bestConfiguration()
{
	int best = 0;
	float score = -1.0f;
	float aux = 0.0f;
	for (int i = 0; i < signed(this->population.size()); i++)
	{
		aux = this->fitness(this->population[i]);
		if (aux > score)
		{
			best = i;
			score = aux;
		}
	}
	return best;
}

std::vector<Item> Genetic::exec()
{
	std::vector<std::vector<Item>> selectedsTournament;
	int father;
	int mother;
	int selected1;
	int selected2;
	float fitnessValue1;
	float fitnessValue2;
	float prob;
	int acctualLengthPopulation;
	int selectedsTournamentLength;
	for (int i = 0; i < this->numberGenerations; i++)
	{
		acctualLengthPopulation = signed(this->population.size());
		for (int j = 0; j < acctualLengthPopulation; j++)
		{
			selected1 = rand() % acctualLengthPopulation;
			selected2 = rand() % acctualLengthPopulation;
			while (selected2 == selected1)
			{
				selected2 = rand() % acctualLengthPopulation;
			}
			fitnessValue1 = this->fitness(this->population[selected1]);
			fitnessValue2 = this->fitness(this->population[selected2]);
			if (fitnessValue1 > fitnessValue2)
			{
				selectedsTournament.push_back(this->population[selected1]);
			}
			else
			{
				selectedsTournament.push_back(this->population[selected2]);
			}
		}
		selectedsTournamentLength = signed(selectedsTournament.size());
		for (int j = 0; j < selectedsTournamentLength; j++)
		{
			prob = ((float)rand() / (float)RAND_MAX);
			if (prob > this->probMutation && prob <= this->probCrossover)
			{
				std::vector<Item> son;
				father = rand() % selectedsTournamentLength;
				mother = rand() % selectedsTournamentLength;
				while (father == mother)
				{
					mother = rand() % selectedsTournamentLength;
				}
				this->crossover(selectedsTournament[father], selectedsTournament[mother], son);
				this->population.push_back(son);
			}
			else if (prob > this->probReproduction && prob <= this->probMutation)
			{
				this->mutation(selectedsTournament[j]);
			}
			else if (prob <= this->probReproduction)
			{
				this->population.push_back(selectedsTournament[j]);
			}
		}
		selectedsTournament.clear();
	}
	return this->population[this->bestConfiguration()];
}

void Genetic::crossover(std::vector<Item>& father, std::vector<Item>& mother, std::vector<Item>& son)
{
	int crossoverPoint = this->genesNumber / 2;
	for (int i = 0; i < crossoverPoint; i++)
	{
		son.push_back(father[i]);
	}
	for (int i = crossoverPoint; i < this->genesNumber; i++)
	{
		son.push_back(mother[i]);
	}
}

void Genetic::mutation(std::vector<Item>& individuo)
{
	int pos = rand() % this->genesNumber;
	individuo[pos].setBelongsKnackpack(!individuo[pos].getBelongsKnackpack());
}