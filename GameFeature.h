// GameFeature.h

#ifndef GAMEFEATURE_H
#define GAMEFEATURE_H

#include <string>
#include <unordered_map>
#include <iostream>

class Item {
private:
    std::string name;
    int value;
    float weight;

public:
    Item(const std::string& name = "", int value = 0, float weight = 0.0f)
        : name(name), value(value), weight(weight) {}

    std::string getName() const { return name; }
    int getValue() const { return value; }
    float getWeight() const { return weight; }

    void display() const {
        std::cout << "Item: " << name << ", Value: " << value << ", Weight: " << weight << "\n";
    }
};

class Inventory {
private:
    std::unordered_map<std::string, Item> items; // Key = Item name

public:
    void addItem(const Item& item) {
        items[item.getName()] = item;
    }

    void removeItem(const std::string& itemName) {
        auto it = items.find(itemName);
        if (it != items.end()) {
            items.erase(it);
            std::cout << "Item '" << itemName << "' removed from inventory.\n";
        } else {
            std::cout << "Item '" << itemName << "' not found in inventory.\n";
        }
    }

    int getItemCount() const {
        return static_cast<int>(items.size());
    }

    void displayItems() const {
        if (items.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }
        for (const auto& pair : items) {
            pair.second.display();
        }
    }
};

#endif // GAMEFEATURE_H
