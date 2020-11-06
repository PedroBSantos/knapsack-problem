#include "../include/genetic.h"
#include "../include/item.h"
#include <ctime>
#include <iostream>

void execute(std::vector<Item>& items, float capacity)
{
	Genetic genetic(items, capacity);
	auto bestConfiguration = genetic.exec();
	float totalWeight = 0.0f;
	float totalUtilitValue = 0.0f;
	for (Item& item : bestConfiguration)
	{
		if (item.getBelongsKnackpack())
		{
			std::cout << item << std::endl;
			totalWeight += item.getWeight();
			totalUtilitValue += item.getUtilitValue();
		}
	}
	std::cout << "--------------------------------\nPeso Total: "
		<< totalWeight << "\nValor de utilidade total: " << totalUtilitValue << std::endl;
}

int main()
{
	srand((unsigned)time(NULL));
	std::vector<Item> items;
	items.push_back(Item(15, 10, "Object 1"));
	items.push_back(Item(90, 40, "Object 2"));
	items.push_back(Item(50, 26, "Object 3"));
	items.push_back(Item(60, 36, "Object 4"));
	items.push_back(Item(12, 8, "Object 5"));
	execute(items, 80.0f);
	items.clear();
	items.push_back(Item(10, 2, "Object 1"));
	items.push_back(Item(7, 1, "Object 2"));
	items.push_back(Item(25, 6, "Object 3"));
	items.push_back(Item(24, 5, "Object 4"));
	std::cout << "\n"
		<< std::endl;
	execute(items, 7.0f);
	items.clear();
	items.push_back(Item(5, 7, "Object 1"));
	items.push_back(Item(8, 8, "Object 2"));
	items.push_back(Item(3, 4, "Object 3"));
	items.push_back(Item(2, 10, "Object 4"));
	items.push_back(Item(7, 4, "Object 5"));
	items.push_back(Item(9, 6, "Object 6"));
	items.push_back(Item(4, 4, "Object 7"));
	std::cout << "\n"
		<< std::endl;
	execute(items, 22.0f);
	system("pause");
	return 0;
}
