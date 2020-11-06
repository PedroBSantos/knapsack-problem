#pragma once

#include <ostream>
#include <string>

class Item
{
private:
    float utilitValue;
    float weight;
    std::string name;
    bool belongs;

public:
    Item(float utilitValue, float weight, std::string name);
    Item(const Item& item);
    ~Item() = default;
    float getUtilitValue();
    void setUtilitValue(float utilitValue);
    float getWeight();
    void setWeight(float weight);
    std::string getName();
    void setName(std::string name);
    bool getBelongsKnackpack();
    void setBelongsKnackpack(bool belongs);
    friend std::ostream& operator<<(std::ostream& os, const Item& item)
    {
        os << "Nome do item: " << item.name << "\nPeso: " << item.weight << "\nValor de utilidade: " << item.utilitValue << std::endl;
        return os;
    }
    friend bool operator==(const Item& item1, const Item& item2);
};
