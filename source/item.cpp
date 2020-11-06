#include "../include/item.h"

Item::Item(float utilitValue, float weight, std::string name) :
    utilitValue(utilitValue), weight(weight), name(name), belongs(false) {}

Item::Item(const Item& item) :
    utilitValue(item.utilitValue), weight(item.weight), name(item.name), belongs(item.belongs) {}

float Item::getUtilitValue()
{
    return this->utilitValue;
}

void Item::setUtilitValue(float utilitValue)
{
    this->utilitValue = utilitValue;
}

float Item::getWeight()
{
    return this->weight;
}

void Item::setWeight(float weight)
{
    this->weight = weight;
}

std::string Item::getName()
{
    return this->name;
}

void Item::setName(std::string name)
{
    this->name = name;
}

bool Item::getBelongsKnackpack()
{
    return this->belongs;
}

void Item::setBelongsKnackpack(bool belongs)
{
    this->belongs = belongs;
}

bool operator==(const Item& item1, const Item& item2)
{
    return item1.name == item2.name;
}
